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
# include <string>
# include <functional>
# include <vector>
# include "SivStringRef.hpp"
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	@brief ������
	*/
	class String
	{
	private:

		std::wstring m_data;

	public:

		typedef std::wstring::traits_type traits_type;
		typedef std::wstring::allocator_type allocator_type;
		typedef std::wstring::value_type value_type;
		typedef std::wstring::size_type size_type;
		typedef std::wstring::difference_type difference_type;
		typedef std::wstring::pointer pointer;
		typedef std::wstring::const_pointer const_pointer;
		typedef std::wstring::reference reference;
		typedef std::wstring::const_reference const_reference;
		typedef std::wstring::iterator iterator;
		typedef std::wstring::const_iterator const_iterator;
		typedef std::wstring::reverse_iterator reverse_iterator;
		typedef std::wstring::const_reverse_iterator const_reverse_iterator;

		const static size_type npos = size_type(-1);

		/**
		*	�f�t�H���g�R���X�g���N�^
		*/
		String(){}

		/**
		*	��������R�s�[���ĐV������������쐬���܂��B
		*	@param str �R�s�[���镶����
		*/
		String(const String& str) : m_data(str.m_data) {}

		/**
		*	��������R�s�[���ĐV������������쐬���܂��B
		*	@param str �R�s�[���镶����
		*/
		String(const std::wstring& str) : m_data(str){}

		/**
		*	��������R�s�[���ĐV������������쐬���܂��B
		*	@param str �R�s�[���镶����
		*	@note str �� NULL �I�[����Ă���K�v������܂��B
		*/
		String(const wchar_t* str) : m_data(str){}

		/**
		*	���������X�g����V������������쐬���܂��B
		*	@param il �V����������̏��������X�g
		*/
		String(std::initializer_list<value_type> il) : m_data(il) {}

		/**
		*	�������w�肵���������R�s�[������������쐬���܂��B
		*	@param count �R�s�[�����
		*	@param ch �R�s�[���镶��
		*/
		String(
			size_t count,
			wchar_t ch
			) :	m_data(count, ch){}

		/**
		*	�w�肵���͈͂̕�������R�s�[������������쐬���܂��B
		*	@param first �R�s�[���镶����̊J�n�ʒu
		*	@param last �R�s�[���镶����̏I���ʒu
		*/
		template<typename Iterator>
		String(
			Iterator first,
			Iterator last
			) : m_data(first, last){}

		/**
		*	����������[�u���܂��B
		*	@param str
		*/
		String(String && str) : m_data(std::move(str.m_data)){}

		/**
		*	����������[�u���܂��B
		*	@param str
		*/
		String(std::wstring && str) : m_data(std::move(str)){}

		~String(){}

		/**
		*	�����񂩂� StringRef ���쐬���܂��B
		*	@return ���̕������ StringRef
		*/
		operator const StringRef() const { return { m_data }; }

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& operator = (const String& str) { return assign(str); }

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& operator = (const std::wstring& str) { return assign(str); }

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& operator = (String && str) { return assign(std::move(str)); }

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& operator = (std::wstring && str) { return assign(std::move(str)); }

		/**
		*	�V����������ɒu�������܂��B
		*	param str �V����������
		*	@return *this
		*/
		String& operator = (const wchar_t* str) { return assign(str); }

		/**
		*	�V����������ɒu�������܂��B
		*	@param ch �V��������
		*	@return *this
		*/
		String& operator = (wchar_t ch) { return assign(1, ch); }

		/**
		*	�V����������ɒu�������܂��B
		*	@param il �V����������̏��������X�g
		*	@return *this
		*/
		String& operator = (std::initializer_list<value_type> il) {	return assign(il); }

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& assign(const String& str)
		{
			m_data.assign(str.m_data);
			return *this;
		}

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& assign(const std::wstring& str)
		{
			m_data.assign(str);
			return *this;
		}

		/**
		*	�V����������ɒu�������܂��B
		*	@param str �V����������
		*	@note str �� NULL �I�[����Ă���K�v������܂��B
		*	@return *this
		*/
		String& assign(const wchar_t* str)
		{
			m_data.assign(str);
			return *this;
		}

		/**
		*	�������w�肵���������R�s�[�����V����������ɒu�������܂��B
		*	@param count �������R�s�[�����
		*	@param ch �R�s�[���镶��
		*	@return *this
		*/
		String&
			assign(
			size_t count,
			wchar_t ch
			)
		{
			m_data.assign(count, ch);
			return *this;
		}

		/**
		*	�V����������Ƀ��[�u�Œu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& assign(String && str)
		{
			m_data.assign(std::move(str.m_data));
			return *this;
		}

		/**
		*	�V����������Ƀ��[�u�Œu�������܂��B
		*	@param str �V����������
		*	@return *this
		*/
		String& assign(std::wstring && str)
		{
			m_data.assign(std::move(str));
			return *this;
		}

		/**
		*	�V����������ɒu�������܂��B
		*	@param il �V����������̏��������X�g
		*	@return *this
		*/
		String& assign(std::initializer_list<value_type> il)
		{
			m_data.assign(il);
			return *this;
		}

		/**
		*	�w�肵���͈͂̐V����������ɒu�������܂��B
		*	@param first �R�s�[���镶����̊J�n�ʒu
		*	@param last �R�s�[���镶����̏I���ʒu
		*	@return *this
		*/
		template<typename Iterator>
		String&
			assign(
			Iterator first,
			Iterator last
			)
		{
			m_data.assign(first, last);
			return *this;
		}

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param str �ǉ����镶����
		*	@return *this
		*/
		String& operator += (const String& str) { return append(str); }

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param str �ǉ����镶����
		*	@return *this
		*/
		String& operator += (const std::wstring& str) { return append(str); }

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param str �ǉ����镶����
		*	@note str �� NULL �I�[����Ă���K�v������܂��B
		*	@return *this
		*/
		String& operator += (const wchar_t* str) { return append(str); }

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param il �ǉ����镶����̏��������X�g
		*	@return *this
		*/
		String& operator += (std::initializer_list<value_type> il) { return append(il); }

		/**
		*	�������I�[�ɒǉ����܂��B
		*	@param ch �ǉ����镶��
		*	@return *this
		*/
		String& operator += (wchar_t ch) { return append(1, ch); }

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param str �ǉ����镶����
		*	@return *this
		*/
		String& append(const String& str)
		{
			m_data.append(str.m_data);
			return *this;
		}

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param str �ǉ����镶����
		*	@return *this
		*/
		String& append(const std::wstring& str)
		{
			m_data.append(str);
			return *this;
		}

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param str �ǉ����镶����
		*	@note str �� NULL �I�[����Ă���K�v������܂��B
		*	@return *this
		*/
		String& append(const wchar_t* str)
		{
			m_data.append(str);
			return *this;
		}

		/**
		*	��������I�[�ɒǉ����܂��B
		*	@param il �ǉ����镶����̏��������X�g
		*	@return *this
		*/
		String& append(std::initializer_list<value_type> il)
		{
			m_data.append(il);
			return *this;
		}

		/**
		*	�������w�肵���������I�[�ɒǉ����܂��B
		*	@param count �����̌�
		*	@param ch �ǉ����镶��
		*	@return *this
		*/
		String&
			append(
			size_t count,
			wchar_t ch
			)
		{
			m_data.append(count, ch);
			return *this;
		}

		/**
		*	�w�肵���͈͂̕�������I�[�ɒǉ����܂��B
		*	@param first �ǉ����镶����̊J�n�ʒu
		*	@param last �ǉ����镶����̏I���ʒu
		*	@return *this
		*/
		template<typename Iterator>
		String&
			append(
			Iterator first,
			Iterator last
			)
		{
			m_data.append(first, last);
			return *this;
		}

		/**
		*	�w�肵���ʒu�ɕ������}�����܂��B
		*	@param offset �}������ʒu
		*	@param str �}�����镶����
		*	@return *this
		*/
		String&
			insert(
			size_t offset,
			const String& str
			)
		{
			m_data.insert(offset, str.m_data);
			return *this;
		}

		/**
		*	�w�肵���ʒu�ɕ������}�����܂��B
		*	@param offset �}������ʒu
		*	@param il �}�����镶����̏��������X�g
		*	@return *this
		*/
		String&
			insert(
			size_t offset,
			std::initializer_list<value_type> il
			)
		{
			m_data.insert(offset,il);
			return *this;
		}

		/**
		*	�w�肵���ʒu�ɕ������}�����܂��B
		*	@param offset �}������ʒu
		*	@param str �}�����镶����
		*	@return *this
		*/
		String&
			insert(
			size_t offset,
			const wchar_t* str
			)
		{
			m_data.insert(offset, str);
			return *this;
		}

		/**
		*	�w�肵���ʒu�ɕ�����C�ӂ̌��}�����܂��B
		*	@param offset �}������ʒu
		*	@param count �����̌�
		*	@param ch �}�����镶��
		*	@return *this
		*/
		String&
			insert(
			size_t offset,
			size_t count,
			wchar_t ch
			)
		{
			m_data.insert(offset, count, ch);
			return *this;
		}

		/**
		*	�w�肵���ʒu�ɕ������}�����܂��B
		*	@param _where �}������ʒu
		*	@param ch �}�����镶��
		*	@return �}�������ʒu�ւ̃C�e���[�^
		*/
		iterator
			insert(
			const_iterator _where,
			wchar_t ch
			)
		{
			return m_data.insert(_where, ch);
		}

		/**
		*	�w�肵���ʒu�ɕ�����C�ӂ̌��}�����܂��B
		*	@param _where �}������ʒu
		*	@param count �����̌�
		*	@param ch �}�����镶��
		*/
		void
			insert(
			const_iterator _where,
			size_t count,
			wchar_t ch
			)
		{
			m_data.insert(_where, count, ch);
		}

		/**
		*	�w�肵���ʒu�ɕ������}�����܂��B
		*	@param _where �}������ʒu
		*	@param first �}�����镶����̊J�n�ʒu
		*	@param last �}�����镶����̏I���ʒu
		*/
		template<typename Iterator>
		void
			insert(
			const_iterator _where,
			Iterator first,
			Iterator last
			)
		{
			m_data.insert(_where, first, last);
		}

		/**
		*	�w�肵���͈͂��폜���A�V�����������}�����܂��B
		*	@param first1 �폜����͈͂̊J�n�ʒu
		*	@param last1 �폜����͈͂̏I���ʒu
		*	@param first2 �}�����镶����̊J�n�ʒu
		*	@param last2 �}�����镶����̏I���ʒu
		*	@return *this
		*/
		template<typename Iterator>
		String&
			insert(
			const_iterator first1,
			const_iterator last1,
			Iterator first2,
			Iterator last2
			)
		{
			m_data.insert(first1, last1, first2, last2);
			return *this;
		}

		/**
		*	�w�肵���ʒu����C�ӂ̌��̕������폜���܂��B
		*	@param offset �폜���镶����̊J�n�ʒu
		*	@param count �폜���镶���̌�
		*	@return *this
		*/
		String&
			erase(
			size_t offset = 0,
			size_t count = npos
			)
		{
			m_data.erase(offset, count);
			return *this;
		}

		/**
		*	�w�肵���ʒu�̕������폜���܂��B
		*	@param _where �폜���镶���̈ʒu
		*	@return �폜��������̈ʒu�ւ̃C�e���[�^
		*/
		iterator erase(const_iterator _where)
		{
			return m_data.erase(_where);
		}

		/**
		*	�w�肵���͈͂̕�������폜���܂��B
		*	@param first �폜���镶����̊J�n�ʒu
		*	@param last �폜���镶����̏I���ʒu
		*	@return �폜��������̈ʒu�ւ̃C�e���[�^
		*/
		iterator
			erase(
			const_iterator first,
			const_iterator last
			)
		{
			return m_data.erase(first, last);
		}

		/**
		*	��������������A��̕�����ɂ��܂��B
		*	@note	�������͐V����������̂��߂Ɋm�ۂ��ꂽ�܂܂ł��B
		*			���̃�����������������ꍇ�� String::shrink_to_fit() ���Ă��������B
		*/
		void clear() { m_data.clear(); }

		/**
		*	������̐擪�ʒu�̃C�e���[�^���擾���܂��B
		*	@return ������̐擪�ʒu�̃C�e���[�^
		*/
		iterator begin() { return m_data.begin(); }

		/**
		*	������̐擪�ʒu�̃C�e���[�^���擾���܂��B
		*	@return ������̐擪�ʒu�̃C�e���[�^
		*/
		const_iterator begin() const { return m_data.begin(); }

		/**
		*	������̐擪�ʒu�̃C�e���[�^���擾���܂��B
		*	@return ������̐擪�ʒu�̃C�e���[�^
		*/
		const_iterator cbegin() const { return m_data.cbegin(); }

		/**
		*	������̏I���ʒu�̃C�e���[�^���擾���܂��B
		*	@return ������̏I���ʒu�̃C�e���[�^
		*/
		iterator end() { return m_data.end(); }

		/**
		*	������̏I���ʒu�̃C�e���[�^���擾���܂��B
		*	@return ������̏I���ʒu�̃C�e���[�^
		*/
		const_iterator end() const { return m_data.end(); }

		/**
		*	������̏I���ʒu�̃C�e���[�^���擾���܂��B
		*	@return ������̏I���ʒu�̃C�e���[�^
		*/
		const_iterator cend() const { return m_data.cend(); }

		/**
		*	������̖����ւ̃��o�[�X�C�e���[�^���擾���܂��B
		*	@return ������̖����ւ̃��o�[�X�C�e���[�^
		*/
		reverse_iterator rbegin() { return m_data.rbegin(); }

		/**
		*	������̖����ւ̃��o�[�X�C�e���[�^���擾���܂��B
		*	@return ������̖����ւ̃��o�[�X�C�e���[�^
		*/
		const_reverse_iterator rbegin() const { return m_data.rbegin(); }

		/**
		*	������̖����ւ̃��o�[�X�C�e���[�^���擾���܂��B
		*	@return ������̖����ւ̃��o�[�X�C�e���[�^
		*/
		const_reverse_iterator crbegin() const { return m_data.crbegin(); }

		/**
		*	������̐擪�̑O�ւ̃��o�[�X�C�e���[�^���擾���܂��B
		*	@return ������̐擪�̑O�ւ̃��o�[�X�C�e���[�^
		*/
		reverse_iterator rend() { return m_data.rend(); }

		/**
		*	������̐擪�̑O�ւ̃��o�[�X�C�e���[�^���擾���܂��B
		*	@return ������̐擪�̑O�ւ̃��o�[�X�C�e���[�^
		*/
		const_reverse_iterator rend() const { return m_data.rend(); }

		/**
		*	������̐擪�̑O�ւ̃��o�[�X�C�e���[�^���擾���܂��B
		*	@return ������̐擪�̑O�ւ̃��o�[�X�C�e���[�^
		*/
		const_reverse_iterator crend() const { return m_data.crend(); }

		/**
		*	������̕s�v�ȃX�g���[�W���폜���܂��B
		*/
		void shrink_to_fit() { m_data.shrink_to_fit(); }

		/**
		*	�w�肵�������ւ̎Q�Ƃ�Ԃ��܂��B�͈͊O�A�N�Z�X������� out_of_range ��O�𑗏o���܂��B
		*	@param offset �C���f�b�N�X
		*	@return �����ւ̎Q��
		*/
		wchar_t& at(size_t offset) { return m_data.at(offset); }

		/**
		*	�w�肵�������ւ� const �Q�Ƃ�Ԃ��܂��B�͈͊O�A�N�Z�X������� out_of_range ��O�𑗏o���܂��B
		*	@param offset �C���f�b�N�X
		*	@return �����ւ� const �Q��
		*/
		const wchar_t& at(size_t offset) const { return m_data.at(offset); }

		/**
		*	�w�肵�������ւ̎Q�Ƃ�Ԃ��܂��B
		*	@param offset �C���f�b�N�X
		*	@return �����ւ̎Q��
		*/
		wchar_t& operator[](size_t offset) { return m_data[offset]; }

		/**
		*	�w�肵�������ւ� const �Q�Ƃ�Ԃ��܂��B
		*	@param offset �C���f�b�N�X
		*	@return �����ւ� const �Q��
		*/
		const wchar_t& operator[](size_t offset) const { return m_data[offset]; }

		/**
		*	�����ɕ�����ǉ����܂��B
		*	@param ch �ǉ����镶��
		*/
		void push_back(wchar_t ch) { m_data.push_back(ch); }

		/**
		*	�����̕������폜���܂��B
		*/
		void pop_back() { m_data.pop_back(); }

		/**
		*	�擪�̕����ւ̎Q�Ƃ�Ԃ��܂��B
		*	@return �擪�̕����ւ̎Q��
		*/
		wchar_t& front() { return m_data.front(); }

		/**
		*	�擪�̕����ւ� const �Q�Ƃ�Ԃ��܂��B
		*	@return �擪�̕����ւ� const �Q��
		*/
		const wchar_t& front() const { return m_data.front(); }

		/**
		*	�����̕����ւ̎Q�Ƃ�Ԃ��܂��B
		*	@return �����̕����ւ̎Q��
		*/
		wchar_t& back() { return m_data.back(); }

		/**
		*	�����̕����ւ� const �Q�Ƃ�Ԃ��܂��B
		*	@return �����̕����ւ� const �Q��
		*/
		const wchar_t& back() const { return m_data.back(); }

		/**
		*	C�X�^�C��������̐擪�|�C���^��Ԃ��܂��B
		*	@return C�X�^�C���̕�����̐擪�ւ� const �|�C���^
		*/
		const wchar_t* c_str() const { return m_data.c_str(); }

		/**
		*	������̐擪�̃|�C���^��Ԃ��܂��B
		*	@return ������̐擪�ւ� const �|�C���^
		*/
		const wchar_t* data() const { return m_data.data(); }

		/**
		*	������f�[�^�ւ̎Q�Ƃ�Ԃ��܂��B
		*	@return std::wstring �^�ւ̎Q��
		*/
		std::wstring& str() { return m_data; }

		/**
		*	������f�[�^�ւ� const �Q�Ƃ�Ԃ��܂��B
		*	@return std::wstring �^�ւ� const �Q��
		*/
		const std::wstring& str() const { return m_data; }

		/**
		*	������̒���
		*/
		Property_Get(size_t, length) const { return m_data.length(); }

		/**
		*	��̕�����ł��邩
		*/
		Property_Get(bool, isEmpty) const { return m_data.empty(); }

		/**
		*	��������Ɋm�ۉ\�ȍő�̕�����̒���
		*/
		Property_Get(size_t, maxSize) const { return m_data.max_size(); }

		/**
		*	���������Ċm�ۂ����Ɋm�ۉ\�ȍő�̕�����̒���
		*/
		Property_Get(size_t, capacity) const { return m_data.capacity(); }

		/**
		*	������̃T�C�Y��ύX���܂��B
		*	@param newSize ������̐V�����T�C�Y
		*/
		void resize(size_t newSize) { m_data.resize(newSize); }

		/**
		*	������̃T�C�Y��ύX���܂��B
		*	@param newSize ������̐V�����T�C�Y
		*	@param ch �ǉ������̈�����������镶��
		*/
		void resize(size_t newSize, wchar_t ch) { m_data.resize(newSize, ch); }

		/**
		*	������p�̃��������w�肵���T�C�Y�Ŋm�ۂ��܂��B
		*	@param newCapacity �m�ۂ��镶����̃T�C�Y
		*/
		void reserve(size_t newCapacity) { m_data.reserve(newCapacity); }

		/**
		*	����������ւ��܂��B
		*	@param str ����ւ��镶����
		*/
		void swap(String& str) { m_data.swap(str.m_data); }

		/**
		*	�w�肵���ʒu����C�ӂ̒�����؂������������Ԃ��܂��B
		*	@param offset �؂���̊J�n�ʒu
		*	@param count �؂��镶����
		*	@return �J�n�ʒu����w�肵�����������؂�����������
		*/
		String
			substr(
			size_t offset = 0,
			size_t count = npos
			) const
		{
			return m_data.substr(offset, count);
		}

		/**
		*	��������w�肵���ʒu���猟�����A�ŏ��Ɍ����ʒu��Ԃ��܂��B
		*	@param str �������镶����
		*	@param offset �������J�n����ʒu
		*	@return �����񂪍ŏ��Ɍ��ꂽ�ʒu
		*/
		size_t
			indexOf(
			const StringRef& str,
			size_t offset = 0
			) const
		{
			return m_data.find(str.data(), offset, str.length());
		}

		/**
		*	�������w�肵���ʒu���猟�����A�ŏ��Ɍ����ʒu��Ԃ��܂��B
		*	@param ch �������镶��
		*	@param offset �������J�n����ʒu
		*	@return �������ŏ��Ɍ��ꂽ�ʒu
		*/
		size_t
			indexOf(
			wchar_t ch,
			size_t offset = 0
			) const
		{
			return m_data.find(ch, offset);
		}

		/**
		*	�������w�肵���ʒu���猟�����A�ŏ��ɈႤ���������ꂽ�ʒu��Ԃ��܂��B
		*	@param ch �������镶��
		*	@param offset �������J�n����ʒu
		*	@return �ŏ��Ɏw�肵�������ȊO�̕��������ꂽ�ʒu
		*/
		size_t
			indexOfNot(
			wchar_t ch,
			size_t offset = 0
			) const
		{
			return m_data.find_first_not_of(ch, offset);
		}

		/**
		*	�w�肵�������񂪍Ō�Ɍ����ʒu��Ԃ��܂��B�����͋t���ɍs���܂��B
		*	@param str �������镶����
		*	@param offset �������J�n����ʒu
		*	@return �Ō�Ɏw�肵�������񂪌����ʒu
		*/
		size_t
			lastIndexOf(
			const StringRef& str,
			size_t offset = npos
			) const
		{
			return m_data.rfind(str.data(), offset, str.length());
		}

		/**
		*	�w�肵���������Ō�Ɍ����ʒu��Ԃ��܂��B�����͋t���ɍs���܂��B
		*	@param ch �������镶��
		*	@param offset �������J�n����ʒu
		*	@return �Ō�Ɏw�肵�������������ʒu
		*/
		size_t
			lastIndexOf(
			wchar_t ch,
			size_t offset = npos
			) const
		{
			return m_data.rfind(ch, offset);
		}

		/**
		*	�w�肵�������ȊO�̕������Ō�Ɍ����ʒu��Ԃ��܂��B�����͋t���ɍs���܂��B
		*	@param ch �������镶��
		*	@param offset �������J�n����ʒu
		*	@return �Ō�Ɏw�肵�������ȊO�̕����������ʒu
		*/
		size_t
			lastIndexNotOf(
			wchar_t ch,
			size_t offset = npos
			) const
		{
			return m_data.find_last_not_of(ch, offset);
		}

		/**
		*	�w�肵��������Ɋ܂܂�镶�����ŏ��Ɍ����ʒu��Ԃ��܂��B
		*	@param anyof �������镶����
		*	@param offset �������J�n����ʒu
		*	@return �ŏ��Ɏw�肵��������Ɋ܂܂�镶���������ʒu
		*/
		size_t
			indexOfAny(
			const StringRef& anyof,
			size_t offset = 0
			) const
		{
			return m_data.find_first_of(anyof.data(), offset, anyof.length());
		}

		/**
		*	�w�肵��������Ɋ܂܂�镶�����ŏ��Ɍ����ʒu��Ԃ��܂��B�����͋t���ɍs���܂��B
		*	@param anyof �������镶����
		*	@param offset �������J�n����ʒu
		*	@return �Ō�Ɏw�肵��������Ɋ܂܂�镶���������ʒu
		*/
		size_t
			lastIndexOfAny(
			const StringRef& anyof,
			size_t offset = npos
			) const
		{
			return m_data.find_last_of(anyof.data(), offset, anyof.length());
		}

		/**
		*	�w�肵��������Ɋ܂܂�Ȃ��������ŏ��Ɍ����ʒu��Ԃ��܂��B
		*	@param anyof �������镶����
		*	@param offset �������J�n����ʒu
		*	@return �ŏ��Ɏw�肵��������Ɋ܂܂�Ȃ������������ʒu
		*/
		size_t
			indexNotOfAny(
			const StringRef& anyof,
			size_t offset = 0
			) const
		{
			return m_data.find_first_not_of(anyof.data(), offset, anyof.length());
		}

		/**
		*	�w�肵��������Ɋ܂܂�Ȃ��������Ō�Ɍ����ʒu��Ԃ��܂��B�����͋t���ɍs���܂��B
		*	@param anyof �������镶����
		*	@param offset �������J�n����ʒu
		*	@return �Ō�Ɏw�肵��������Ɋ܂܂�Ȃ������������ʒu
		*/
		size_t
			lastIndexNotOfAny(
			const StringRef& anyof,
			size_t offset = npos
			) const
		{
			return m_data.find_last_not_of(anyof.data(), offset, anyof.length());
		}

		/**
		*	������̑召���r���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		int compare(const String& str) const
		{
			return m_data.compare(str.m_data);
		}

		/**
		*	������̑召���r���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		int compare(const wchar_t* str) const
		{
			return m_data.compare(str);
		}

		/**
		*	�����񂪈�v���邩���r���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		bool operator == (const String& str) const
		{
			return m_data == str.m_data;
		}

		/**
		*	�����񂪈�v���Ȃ������r���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		bool operator != (const String& str) const
		{
			return m_data != str.m_data;
		}

		/**
		*	������� < ��r���s���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		bool operator < (const String& str) const
		{
			return m_data < str.m_data;
		}

		/**
		*	������� > ��r���s���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		bool operator > (const String& str) const
		{
			return m_data > str.m_data;
		}

		/**
		*	������� <= ��r���s���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		bool operator <= (const String& str) const
		{
			return m_data <= str.m_data;
		}

		/**
		*	������� >= ��r���s���܂��B
		*	@param str ��r�Ώۂ̕�����
		*	@return ��r����
		*/
		bool operator >= (const String& str) const
		{
			return m_data >= str.m_data;
		}

		/**
		*	�}���`�o�C�g�ɕϊ������������Ԃ��܂��B
		*	@return �ϊ����ꂽ�}���`�o�C�g������
		*/
		std::string narrow() const;

		/**
		*	�w�肵�������ŉE�l�߂����������Ԃ��܂��B
		*	@param length �V����������̒���
		*	@param fillChar �l�ߕ����A�f�t�H���g�ł͔��p��
		*	@return �V����������
		*	@note length �����̕�����̒�����菬�����ꍇ�A���̕������Ԃ��܂��B
		*/
		String
			padLeft(
			size_t length,
			wchar_t fillChar = L' '
			) const;

		/**
		*	�w�肵�������ō��l�߂����������Ԃ��܂��B
		*	@param length �V����������̒���
		*	@param fillChar �l�ߕ����A�f�t�H���g�ł͔��p��
		*	@return �V����������
		*	@note length �����̕�����̒�����菬�����ꍇ�A���̕������Ԃ��܂��B
		*/
		String
			padRight(
			size_t length,
			wchar_t fillChar = L' '
			) const;

		/**
		*	�擪�ɂ���󔒂Ɛ��䕶�������������������Ԃ��܂��B
		*	@return �V����������
		*	@note �󔒂␧�䕶�����A�����Ă���ꍇ�́A����炪�܂Ƃ߂ď�������܂��B
		*/
		String trimLeft() const;

		/**
		*	�����ɂ���󔒂Ɛ��䕶�������������������Ԃ��܂��B
		*	@return �V����������
		*	@note �󔒂␧�䕶�����A�����Ă���ꍇ�́A����炪�܂Ƃ߂ď�������܂��B
		*/
		String trimRight() const;

		/**
		*	�擪�Ɩ����ɂ���󔒂Ɛ��䕶�������������������Ԃ��܂��B
		*	@return �V����������
		*	@note �󔒂␧�䕶�����A�����Ă���ꍇ�́A����炪�܂Ƃ߂ď�������܂��B
		*/
		String trim() const;

		/**
		*	���]�����������Ԃ��܂��B
		*	@return �V����������
		*/
		String reverse() const;

		/**
		*	�ŏ��ɓo�ꂷ��p����啶���ɂ����������Ԃ��܂��B
		*	@return �V����������
		*/
		String capitalize() const;

		/**
		*	�p�������ׂđ啶���ɂ����������Ԃ��܂��B
		*	@return �V����������
		*/
		String upper() const;

		/**
		*	�p�������ׂď������ɂ����������Ԃ��܂��B
		*	@return �V����������
		*/
		String lower() const;

		/**
		*	�p���̑啶���Ə����������ւ����������Ԃ��܂��B
		*	@return �V����������
		*/
		String swapCase() const;

		/**
		*	XML �G�X�P�[�v�����������Ԃ��܂��B
		*	@return �V����������
		*	@note ", \, &, >, < ���G�X�P�[�v�����ɒu�����܂�
		*/
		String xmlEscape() const;

		/**
		*	�w�肵���������ŉ��s�����������Ԃ��܂��B
		*	@param width 1 �s�̕�����
		*	@return �V����������
		*/
		String layout(size_t width) const;

		/**
		*	�^�u�𔼊p�󔒂ɒu�������������Ԃ��܂��B
		*	@param tabSize �^�u�u����̔��p�󔒂̐��A�f�t�H���g�ł� 4
		*	@return �V����������
		*/
		String expandTabs(const size_t tabSize = 4) const;

		/**
		*	�w�肵�������̌��𐔂��܂��B
		*	@param ch �������镶��
		*	@return �������������̌�
		*/
		size_t count(wchar_t ch) const;

		/**
		*	�w�肵��������̌��𐔂��܂��B
		*	@param str �������镶����
		*	@return ��������������̌�
		*	@note L"aaa" ���� L"aa" ����������Ɩ߂�l�� 2 �ɂȂ�܂��B
		*/
		size_t count(const StringRef& str) const;

		/**
		*	�����ɍ��������̌��𐔂��܂��B
		*	@param function �������L�q�����֐�
		*	@return �������������̌�
		*/
		size_t count_if(std::function<bool(wchar_t)> function) const;

		/**
		*	�w�肵���������܂܂�Ă��邩�������܂��B
		*	@param ch �������镶��
		*	@return ������������������������ true�A������Ȃ������� false
		*/
		bool includes(wchar_t ch) const;

		/**
		*	�w�肵�������񂪊܂܂�Ă��邩�������܂��B
		*	@param str �������镶����
		*	@return �������������񂪌��������� true�A������Ȃ������� false
		*/
		bool includes(const StringRef& str) const;

		/**
		*	�w�肵�������ɍ����������܂܂�Ă��邩�������܂��B
		*	@param function �������L�q�����֐�
		*	@return ������������������������ true�A������Ȃ������� false
		*/
		bool includes_if(std::function<bool(wchar_t)> function) const;

		/**
		*	�w�肵����������n�܂邩�������܂��B
		*	@param ch �������镶��
		*	@return �����񂪌���������������n�܂�ꍇ true�A�����łȂ������� false
		*/
		bool startsWith(wchar_t ch) const;

		/**
		*	�w�肵�������񂩂�n�܂邩�������܂��B
		*	@param str �������镶����
		*	@return �����񂪌������������񂩂�n�܂�ꍇ true�A�����łȂ������� false
		*/
		bool startsWith(const StringRef& str) const;

		/**
		*	�w�肵�������ŏI��邩�������܂��B
		*	@param ch �������镶��
		*	@return �����񂪌������������ŏI���ꍇ true�A�����łȂ������� false
		*/
		bool endsWith(wchar_t ch) const;

		/**
		*	�w�肵��������ŏI��邩�������܂��B
		*	@param str �������镶����
		*	@return �����񂪌�������������ŏI���ꍇ true�A�����łȂ������� false
		*/
		bool endsWith(const StringRef& str) const;

		/**
		*	�w�肳�ꂽ������u�������������Ԃ��܂��B
		*	@param oldChar �u���Ώۂ̕���
		*	@param newChar �u����̕���
		*	@return �V����������
		*/
		String
			replace(
			wchar_t oldChar,
			wchar_t newChar
			) const;

		/**
		*	�w�肳�ꂽ�������u�������������Ԃ��܂��B
		*	@param oldChar �u���Ώۂ̕�����
		*	@param newChar �u����̕�����
		*	@return �V����������
		*/
		String
			replace(
			const String& oldStr,
			const String& newStr
			) const;

		/**
		*	�w�肳�ꂽ���������������������Ԃ��܂��B
		*	@param ch �������镶��
		*	@return �V����������
		*/
		String remove(wchar_t ch) const;

		/**
		*	�w�肳�ꂽ����������������������Ԃ��܂��B
		*	@param str �������镶����
		*	@return �V����������
		*/
		String remove(const StringRef& str) const;

		/**
		*	�����ɍ������������������������Ԃ��܂��B
		*	@param function �������L�q�����֐�
		*	@return �V����������
		*/
		String remove_if(std::function<bool(wchar_t)> function) const;

		/**
		*	�w�肳�ꂽ��؂蕶���ŕ�����𕪊����܂��B
		*	@param ch ��؂蕶��
		*	@return �������ꂽ������
		*/
		std::vector<String> split(wchar_t ch) const;
	};

	/**
	*	���̓X�g���[���ɕ������n���܂��B
	*	@param input ���̓X�g���[��
	*	@param str �n��������
	*	@return �n������̓��̓X�g���[��
	*/
	inline
	std::wistream&
		operator >> (
		std::wistream& input,
		String& str
		)
	{
		return input >> str.str();
	}

	/**
	*	�o�̓X�g���[���ɕ������n���܂��B
	*	@param output �o�̓X�g���[��
	*	@param c �n��������
	*	@return �n������̏o�̓X�g���[��
	*/
	inline
	std::wostream&
		operator << (
		std::wostream& output,
		const String& str
		)
	{
		return output << str.str();
	}

	/**
	*	@brief �t�@�C���p�X
	*	�t�@�C���ւ̃p�X��\�� String �������܂��B
	*/
	typedef String FilePath;

	inline String operator + (const String& lhs, const String& rhs)
	{
		return lhs.str() + rhs.str();
	}

	inline String operator + (const wchar_t* lhs, const String& rhs)
	{
		return lhs + rhs.str();
	}

	inline String operator + (const wchar_t lhs, const String& rhs)
	{
		return String({ lhs }).append(rhs);
	}

	inline String operator + (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() + rhs;
	}

	inline String operator + (const String& lhs, const wchar_t rhs)
	{
		return String(lhs).append({ rhs });
	}

	inline bool operator == (const wchar_t* lhs, const String& rhs)
	{
		return lhs == rhs.str();
	}

	inline bool operator == (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() == rhs;
	}

	inline bool operator != (const wchar_t* lhs, const String& rhs)
	{
		return lhs != rhs.str();
	}

	inline bool operator != (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() != rhs;
	}

	inline bool operator < (const wchar_t* lhs, const String& rhs)
	{
		return lhs < rhs.str();
	}

	inline bool operator < (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() < rhs;
	}

	inline bool operator > (const wchar_t* lhs, const String& rhs)
	{
		return lhs > rhs.str();
	}

	inline bool operator > (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() > rhs;
	}

	inline bool operator <= (const wchar_t* lhs, const String& rhs)
	{
		return lhs <= rhs.str();
	}

	inline bool operator <= (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() <= rhs;
	}

	inline bool operator >= (const wchar_t* lhs, const String& rhs)
	{
		return lhs >= rhs.str();
	}

	inline bool operator >= (const String& lhs, const wchar_t* rhs)
	{
		return lhs.str() >= rhs;
	}
}

template<>
struct std::hash<s3d::String>
{
	size_t operator()(const s3d::String& keyVal) const
	{
		return std::hash<std::wstring>()(keyVal.str());
	}
};
