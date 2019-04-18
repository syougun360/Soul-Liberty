//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# pragma once

namespace s3d
{
	template <typename T, size_t Alignment = __alignof(T)>
	struct AlignedAllocator
	{
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;

		template <typename U>
		struct rebind
		{
			typedef AlignedAllocator<U> other;
		};

		AlignedAllocator() throw(){}

		AlignedAllocator(const AlignedAllocator&) throw(){}

		~AlignedAllocator() throw(){};
		
		template <typename _Other>
		AlignedAllocator(const AlignedAllocator<_Other>&){}

		pointer allocate(size_type n, const void *p = nullptr)
		{
			p;

			assert(n);

			return (pointer) _mm_malloc(n*sizeof(T), Alignment);
		}

		void deallocate(pointer p, size_type)
		{
			assert(p);

			_mm_free(p);
		}

		void construct(pointer p, const_reference t)
		{
			*p = t;
		}

		void destroy(pointer)
		{

		}

		pointer address(reference r) const
		{
			return &r;
		}

		const_pointer address(const_reference c) const
		{
			return &c;
		}

		size_type max_size() const
		{
			return std::numeric_limits<size_t>::max() / sizeof(T);
		}

		bool operator==(const AlignedAllocator& other) const
		{
			return true;
		}

		bool operator!=(const AlignedAllocator& other) const
		{
			return !(*this == other);
		}
	};

	template<class Type> using aligned_vector = std::vector<Type, s3d::AlignedAllocator<Type>>;

	template<class Type, size_t Alignment = __alignof(Type)> using vector
		= typename std::conditional<(Alignment >= 16), aligned_vector<Type>, std::vector<Type>>::type;

	template <typename Type>
	inline
	void
		Formatter(
		FormatData& formatData,
		const s3d::aligned_vector<Type>& v
		)
	{
		formatData.str.push_back(L'{');

		const size_t N = v.size();

		for (size_t i = 0; i < N; ++i)
		{
			Formatter(formatData, v[i]);

			if (i + 1 != N)
			{
				formatData.str.push_back(L',');
			}
		}

		formatData.str.push_back(L'}');
	}
}
