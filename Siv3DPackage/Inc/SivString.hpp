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
	*	@brief 文字列
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
		*	デフォルトコンストラクタ
		*/
		String(){}

		/**
		*	文字列をコピーして新しい文字列を作成します。
		*	@param str コピーする文字列
		*/
		String(const String& str) : m_data(str.m_data) {}

		/**
		*	文字列をコピーして新しい文字列を作成します。
		*	@param str コピーする文字列
		*/
		String(const std::wstring& str) : m_data(str){}

		/**
		*	文字列をコピーして新しい文字列を作成します。
		*	@param str コピーする文字列
		*	@note str は NULL 終端されている必要があります。
		*/
		String(const wchar_t* str) : m_data(str){}

		/**
		*	初期化リストから新しい文字列を作成します。
		*	@param il 新しい文字列の初期化リスト
		*/
		String(std::initializer_list<value_type> il) : m_data(il) {}

		/**
		*	文字を指定した数だけコピーした文字列を作成します。
		*	@param count コピーする個数
		*	@param ch コピーする文字
		*/
		String(
			size_t count,
			wchar_t ch
			) :	m_data(count, ch){}

		/**
		*	指定した範囲の文字列をコピーした文字列を作成します。
		*	@param first コピーする文字列の開始位置
		*	@param last コピーする文字列の終了位置
		*/
		template<typename Iterator>
		String(
			Iterator first,
			Iterator last
			) : m_data(first, last){}

		/**
		*	文字列をムーブします。
		*	@param str
		*/
		String(String && str) : m_data(std::move(str.m_data)){}

		/**
		*	文字列をムーブします。
		*	@param str
		*/
		String(std::wstring && str) : m_data(std::move(str)){}

		~String(){}

		/**
		*	文字列から StringRef を作成します。
		*	@return この文字列の StringRef
		*/
		operator const StringRef() const { return { m_data }; }

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& operator = (const String& str) { return assign(str); }

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& operator = (const std::wstring& str) { return assign(str); }

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& operator = (String && str) { return assign(std::move(str)); }

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& operator = (std::wstring && str) { return assign(std::move(str)); }

		/**
		*	新しい文字列に置き換えます。
		*	param str 新しい文字列
		*	@return *this
		*/
		String& operator = (const wchar_t* str) { return assign(str); }

		/**
		*	新しい文字列に置き換えます。
		*	@param ch 新しい文字
		*	@return *this
		*/
		String& operator = (wchar_t ch) { return assign(1, ch); }

		/**
		*	新しい文字列に置き換えます。
		*	@param il 新しい文字列の初期化リスト
		*	@return *this
		*/
		String& operator = (std::initializer_list<value_type> il) {	return assign(il); }

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& assign(const String& str)
		{
			m_data.assign(str.m_data);
			return *this;
		}

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& assign(const std::wstring& str)
		{
			m_data.assign(str);
			return *this;
		}

		/**
		*	新しい文字列に置き換えます。
		*	@param str 新しい文字列
		*	@note str は NULL 終端されている必要があります。
		*	@return *this
		*/
		String& assign(const wchar_t* str)
		{
			m_data.assign(str);
			return *this;
		}

		/**
		*	文字を指定した数だけコピーした新しい文字列に置き換えます。
		*	@param count 文字をコピーする個数
		*	@param ch コピーする文字
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
		*	新しい文字列にムーブで置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& assign(String && str)
		{
			m_data.assign(std::move(str.m_data));
			return *this;
		}

		/**
		*	新しい文字列にムーブで置き換えます。
		*	@param str 新しい文字列
		*	@return *this
		*/
		String& assign(std::wstring && str)
		{
			m_data.assign(std::move(str));
			return *this;
		}

		/**
		*	新しい文字列に置き換えます。
		*	@param il 新しい文字列の初期化リスト
		*	@return *this
		*/
		String& assign(std::initializer_list<value_type> il)
		{
			m_data.assign(il);
			return *this;
		}

		/**
		*	指定した範囲の新しい文字列に置き換えます。
		*	@param first コピーする文字列の開始位置
		*	@param last コピーする文字列の終了位置
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
		*	文字列を終端に追加します。
		*	@param str 追加する文字列
		*	@return *this
		*/
		String& operator += (const String& str) { return append(str); }

		/**
		*	文字列を終端に追加します。
		*	@param str 追加する文字列
		*	@return *this
		*/
		String& operator += (const std::wstring& str) { return append(str); }

		/**
		*	文字列を終端に追加します。
		*	@param str 追加する文字列
		*	@note str は NULL 終端されている必要があります。
		*	@return *this
		*/
		String& operator += (const wchar_t* str) { return append(str); }

		/**
		*	文字列を終端に追加します。
		*	@param il 追加する文字列の初期化リスト
		*	@return *this
		*/
		String& operator += (std::initializer_list<value_type> il) { return append(il); }

		/**
		*	文字を終端に追加します。
		*	@param ch 追加する文字
		*	@return *this
		*/
		String& operator += (wchar_t ch) { return append(1, ch); }

		/**
		*	文字列を終端に追加します。
		*	@param str 追加する文字列
		*	@return *this
		*/
		String& append(const String& str)
		{
			m_data.append(str.m_data);
			return *this;
		}

		/**
		*	文字列を終端に追加します。
		*	@param str 追加する文字列
		*	@return *this
		*/
		String& append(const std::wstring& str)
		{
			m_data.append(str);
			return *this;
		}

		/**
		*	文字列を終端に追加します。
		*	@param str 追加する文字列
		*	@note str は NULL 終端されている必要があります。
		*	@return *this
		*/
		String& append(const wchar_t* str)
		{
			m_data.append(str);
			return *this;
		}

		/**
		*	文字列を終端に追加します。
		*	@param il 追加する文字列の初期化リスト
		*	@return *this
		*/
		String& append(std::initializer_list<value_type> il)
		{
			m_data.append(il);
			return *this;
		}

		/**
		*	文字を指定した個数だけ終端に追加します。
		*	@param count 文字の個数
		*	@param ch 追加する文字
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
		*	指定した範囲の文字列を終端に追加します。
		*	@param first 追加する文字列の開始位置
		*	@param last 追加する文字列の終了位置
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
		*	指定した位置に文字列を挿入します。
		*	@param offset 挿入する位置
		*	@param str 挿入する文字列
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
		*	指定した位置に文字列を挿入します。
		*	@param offset 挿入する位置
		*	@param il 挿入する文字列の初期化リスト
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
		*	指定した位置に文字列を挿入します。
		*	@param offset 挿入する位置
		*	@param str 挿入する文字列
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
		*	指定した位置に文字を任意の個数挿入します。
		*	@param offset 挿入する位置
		*	@param count 文字の個数
		*	@param ch 挿入する文字
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
		*	指定した位置に文字列を挿入します。
		*	@param _where 挿入する位置
		*	@param ch 挿入する文字
		*	@return 挿入した位置へのイテレータ
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
		*	指定した位置に文字を任意の個数挿入します。
		*	@param _where 挿入する位置
		*	@param count 文字の個数
		*	@param ch 挿入する文字
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
		*	指定した位置に文字列を挿入します。
		*	@param _where 挿入する位置
		*	@param first 挿入する文字列の開始位置
		*	@param last 挿入する文字列の終了位置
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
		*	指定した範囲を削除し、新しい文字列を挿入します。
		*	@param first1 削除する範囲の開始位置
		*	@param last1 削除する範囲の終了位置
		*	@param first2 挿入する文字列の開始位置
		*	@param last2 挿入する文字列の終了位置
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
		*	指定した位置から任意の個数の文字を削除します。
		*	@param offset 削除する文字列の開始位置
		*	@param count 削除する文字の個数
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
		*	指定した位置の文字を削除します。
		*	@param _where 削除する文字の位置
		*	@return 削除した直後の位置へのイテレータ
		*/
		iterator erase(const_iterator _where)
		{
			return m_data.erase(_where);
		}

		/**
		*	指定した範囲の文字列を削除します。
		*	@param first 削除する文字列の開始位置
		*	@param last 削除する文字列の終了位置
		*	@return 削除した直後の位置へのイテレータ
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
		*	文字列を消去し、空の文字列にします。
		*	@note	メモリは新しい文字列のために確保されたままです。
		*			このメモリを解放したい場合は String::shrink_to_fit() してください。
		*/
		void clear() { m_data.clear(); }

		/**
		*	文字列の先頭位置のイテレータを取得します。
		*	@return 文字列の先頭位置のイテレータ
		*/
		iterator begin() { return m_data.begin(); }

		/**
		*	文字列の先頭位置のイテレータを取得します。
		*	@return 文字列の先頭位置のイテレータ
		*/
		const_iterator begin() const { return m_data.begin(); }

		/**
		*	文字列の先頭位置のイテレータを取得します。
		*	@return 文字列の先頭位置のイテレータ
		*/
		const_iterator cbegin() const { return m_data.cbegin(); }

		/**
		*	文字列の終了位置のイテレータを取得します。
		*	@return 文字列の終了位置のイテレータ
		*/
		iterator end() { return m_data.end(); }

		/**
		*	文字列の終了位置のイテレータを取得します。
		*	@return 文字列の終了位置のイテレータ
		*/
		const_iterator end() const { return m_data.end(); }

		/**
		*	文字列の終了位置のイテレータを取得します。
		*	@return 文字列の終了位置のイテレータ
		*/
		const_iterator cend() const { return m_data.cend(); }

		/**
		*	文字列の末尾へのリバースイテレータを取得します。
		*	@return 文字列の末尾へのリバースイテレータ
		*/
		reverse_iterator rbegin() { return m_data.rbegin(); }

		/**
		*	文字列の末尾へのリバースイテレータを取得します。
		*	@return 文字列の末尾へのリバースイテレータ
		*/
		const_reverse_iterator rbegin() const { return m_data.rbegin(); }

		/**
		*	文字列の末尾へのリバースイテレータを取得します。
		*	@return 文字列の末尾へのリバースイテレータ
		*/
		const_reverse_iterator crbegin() const { return m_data.crbegin(); }

		/**
		*	文字列の先頭の前へのリバースイテレータを取得します。
		*	@return 文字列の先頭の前へのリバースイテレータ
		*/
		reverse_iterator rend() { return m_data.rend(); }

		/**
		*	文字列の先頭の前へのリバースイテレータを取得します。
		*	@return 文字列の先頭の前へのリバースイテレータ
		*/
		const_reverse_iterator rend() const { return m_data.rend(); }

		/**
		*	文字列の先頭の前へのリバースイテレータを取得します。
		*	@return 文字列の先頭の前へのリバースイテレータ
		*/
		const_reverse_iterator crend() const { return m_data.crend(); }

		/**
		*	文字列の不要なストレージを削除します。
		*/
		void shrink_to_fit() { m_data.shrink_to_fit(); }

		/**
		*	指定した文字への参照を返します。範囲外アクセスをすると out_of_range 例外を送出します。
		*	@param offset インデックス
		*	@return 文字への参照
		*/
		wchar_t& at(size_t offset) { return m_data.at(offset); }

		/**
		*	指定した文字への const 参照を返します。範囲外アクセスをすると out_of_range 例外を送出します。
		*	@param offset インデックス
		*	@return 文字への const 参照
		*/
		const wchar_t& at(size_t offset) const { return m_data.at(offset); }

		/**
		*	指定した文字への参照を返します。
		*	@param offset インデックス
		*	@return 文字への参照
		*/
		wchar_t& operator[](size_t offset) { return m_data[offset]; }

		/**
		*	指定した文字への const 参照を返します。
		*	@param offset インデックス
		*	@return 文字への const 参照
		*/
		const wchar_t& operator[](size_t offset) const { return m_data[offset]; }

		/**
		*	末尾に文字を追加します。
		*	@param ch 追加する文字
		*/
		void push_back(wchar_t ch) { m_data.push_back(ch); }

		/**
		*	末尾の文字を削除します。
		*/
		void pop_back() { m_data.pop_back(); }

		/**
		*	先頭の文字への参照を返します。
		*	@return 先頭の文字への参照
		*/
		wchar_t& front() { return m_data.front(); }

		/**
		*	先頭の文字への const 参照を返します。
		*	@return 先頭の文字への const 参照
		*/
		const wchar_t& front() const { return m_data.front(); }

		/**
		*	末尾の文字への参照を返します。
		*	@return 末尾の文字への参照
		*/
		wchar_t& back() { return m_data.back(); }

		/**
		*	末尾の文字への const 参照を返します。
		*	@return 末尾の文字への const 参照
		*/
		const wchar_t& back() const { return m_data.back(); }

		/**
		*	Cスタイル文字列の先頭ポインタを返します。
		*	@return Cスタイルの文字列の先頭への const ポインタ
		*/
		const wchar_t* c_str() const { return m_data.c_str(); }

		/**
		*	文字列の先頭のポインタを返します。
		*	@return 文字列の先頭への const ポインタ
		*/
		const wchar_t* data() const { return m_data.data(); }

		/**
		*	文字列データへの参照を返します。
		*	@return std::wstring 型への参照
		*/
		std::wstring& str() { return m_data; }

		/**
		*	文字列データへの const 参照を返します。
		*	@return std::wstring 型への const 参照
		*/
		const std::wstring& str() const { return m_data; }

		/**
		*	文字列の長さ
		*/
		Property_Get(size_t, length) const { return m_data.length(); }

		/**
		*	空の文字列であるか
		*/
		Property_Get(bool, isEmpty) const { return m_data.empty(); }

		/**
		*	メモリ上に確保可能な最大の文字列の長さ
		*/
		Property_Get(size_t, maxSize) const { return m_data.max_size(); }

		/**
		*	メモリを再確保せずに確保可能な最大の文字列の長さ
		*/
		Property_Get(size_t, capacity) const { return m_data.capacity(); }

		/**
		*	文字列のサイズを変更します。
		*	@param newSize 文字列の新しいサイズ
		*/
		void resize(size_t newSize) { m_data.resize(newSize); }

		/**
		*	文字列のサイズを変更します。
		*	@param newSize 文字列の新しいサイズ
		*	@param ch 追加した領域を初期化する文字
		*/
		void resize(size_t newSize, wchar_t ch) { m_data.resize(newSize, ch); }

		/**
		*	文字列用のメモリを指定したサイズで確保します。
		*	@param newCapacity 確保する文字列のサイズ
		*/
		void reserve(size_t newCapacity) { m_data.reserve(newCapacity); }

		/**
		*	文字列を入れ替えます。
		*	@param str 入れ替える文字列
		*/
		void swap(String& str) { m_data.swap(str.m_data); }

		/**
		*	指定した位置から任意の長さを切り取った文字列を返します。
		*	@param offset 切り取りの開始位置
		*	@param count 切り取る文字数
		*	@return 開始位置から指定した長さだけ切り取った文字列
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
		*	文字列を指定した位置から検索し、最初に現れる位置を返します。
		*	@param str 検索する文字列
		*	@param offset 検索を開始する位置
		*	@return 文字列が最初に現れた位置
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
		*	文字を指定した位置から検索し、最初に現れる位置を返します。
		*	@param ch 検索する文字
		*	@param offset 検索を開始する位置
		*	@return 文字が最初に現れた位置
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
		*	文字を指定した位置から検索し、最初に違う文字が現れた位置を返します。
		*	@param ch 検索する文字
		*	@param offset 検索を開始する位置
		*	@return 最初に指定した文字以外の文字が現れた位置
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
		*	指定した文字列が最後に現れる位置を返します。検索は逆順に行います。
		*	@param str 検索する文字列
		*	@param offset 検索を開始する位置
		*	@return 最後に指定した文字列が現れる位置
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
		*	指定した文字が最後に現れる位置を返します。検索は逆順に行います。
		*	@param ch 検索する文字
		*	@param offset 検索を開始する位置
		*	@return 最後に指定した文字が現れる位置
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
		*	指定した文字以外の文字が最後に現れる位置を返します。検索は逆順に行います。
		*	@param ch 検索する文字
		*	@param offset 検索を開始する位置
		*	@return 最後に指定した文字以外の文字が現れる位置
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
		*	指定した文字列に含まれる文字が最初に現れる位置を返します。
		*	@param anyof 検索する文字列
		*	@param offset 検索を開始する位置
		*	@return 最初に指定した文字列に含まれる文字が現れる位置
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
		*	指定した文字列に含まれる文字が最初に現れる位置を返します。検索は逆順に行います。
		*	@param anyof 検索する文字列
		*	@param offset 検索を開始する位置
		*	@return 最後に指定した文字列に含まれる文字が現れる位置
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
		*	指定した文字列に含まれない文字が最初に現れる位置を返します。
		*	@param anyof 検索する文字列
		*	@param offset 検索を開始する位置
		*	@return 最初に指定した文字列に含まれない文字が現れる位置
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
		*	指定した文字列に含まれない文字が最後に現れる位置を返します。検索は逆順に行います。
		*	@param anyof 検索する文字列
		*	@param offset 検索を開始する位置
		*	@return 最後に指定した文字列に含まれない文字が現れる位置
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
		*	文字列の大小を比較します。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		int compare(const String& str) const
		{
			return m_data.compare(str.m_data);
		}

		/**
		*	文字列の大小を比較します。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		int compare(const wchar_t* str) const
		{
			return m_data.compare(str);
		}

		/**
		*	文字列が一致するかを比較します。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		bool operator == (const String& str) const
		{
			return m_data == str.m_data;
		}

		/**
		*	文字列が一致しないかを比較します。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		bool operator != (const String& str) const
		{
			return m_data != str.m_data;
		}

		/**
		*	文字列の < 比較を行います。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		bool operator < (const String& str) const
		{
			return m_data < str.m_data;
		}

		/**
		*	文字列の > 比較を行います。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		bool operator > (const String& str) const
		{
			return m_data > str.m_data;
		}

		/**
		*	文字列の <= 比較を行います。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		bool operator <= (const String& str) const
		{
			return m_data <= str.m_data;
		}

		/**
		*	文字列の >= 比較を行います。
		*	@param str 比較対象の文字列
		*	@return 比較結果
		*/
		bool operator >= (const String& str) const
		{
			return m_data >= str.m_data;
		}

		/**
		*	マルチバイトに変換した文字列を返します。
		*	@return 変換されたマルチバイト文字列
		*/
		std::string narrow() const;

		/**
		*	指定した長さで右詰めした文字列を返します。
		*	@param length 新しい文字列の長さ
		*	@param fillChar 詰め文字、デフォルトでは半角空白
		*	@return 新しい文字列
		*	@note length が元の文字列の長さより小さい場合、元の文字列を返します。
		*/
		String
			padLeft(
			size_t length,
			wchar_t fillChar = L' '
			) const;

		/**
		*	指定した長さで左詰めした文字列を返します。
		*	@param length 新しい文字列の長さ
		*	@param fillChar 詰め文字、デフォルトでは半角空白
		*	@return 新しい文字列
		*	@note length が元の文字列の長さより小さい場合、元の文字列を返します。
		*/
		String
			padRight(
			size_t length,
			wchar_t fillChar = L' '
			) const;

		/**
		*	先頭にある空白と制御文字を除去した文字列を返します。
		*	@return 新しい文字列
		*	@note 空白や制御文字が連続している場合は、それらがまとめて除去されます。
		*/
		String trimLeft() const;

		/**
		*	末尾にある空白と制御文字を除去した文字列を返します。
		*	@return 新しい文字列
		*	@note 空白や制御文字が連続している場合は、それらがまとめて除去されます。
		*/
		String trimRight() const;

		/**
		*	先頭と末尾にある空白と制御文字を除去した文字列を返します。
		*	@return 新しい文字列
		*	@note 空白や制御文字が連続している場合は、それらがまとめて除去されます。
		*/
		String trim() const;

		/**
		*	反転した文字列を返します。
		*	@return 新しい文字列
		*/
		String reverse() const;

		/**
		*	最初に登場する英字を大文字にした文字列を返します。
		*	@return 新しい文字列
		*/
		String capitalize() const;

		/**
		*	英字をすべて大文字にした文字列を返します。
		*	@return 新しい文字列
		*/
		String upper() const;

		/**
		*	英字をすべて小文字にした文字列を返します。
		*	@return 新しい文字列
		*/
		String lower() const;

		/**
		*	英字の大文字と小文字を入れ替えた文字列を返します。
		*	@return 新しい文字列
		*/
		String swapCase() const;

		/**
		*	XML エスケープした文字列を返します。
		*	@return 新しい文字列
		*	@note ", \, &, >, < をエスケープ文字に置換します
		*/
		String xmlEscape() const;

		/**
		*	指定した文字数で改行した文字列を返します。
		*	@param width 1 行の文字数
		*	@return 新しい文字列
		*/
		String layout(size_t width) const;

		/**
		*	タブを半角空白に置換した文字列を返します。
		*	@param tabSize タブ置換後の半角空白の数、デフォルトでは 4
		*	@return 新しい文字列
		*/
		String expandTabs(const size_t tabSize = 4) const;

		/**
		*	指定した文字の個数を数えます。
		*	@param ch 検索する文字
		*	@return 見つかった文字の個数
		*/
		size_t count(wchar_t ch) const;

		/**
		*	指定した文字列の個数を数えます。
		*	@param str 検索する文字列
		*	@return 見つかった文字列の個数
		*	@note L"aaa" から L"aa" を検索すると戻り値は 2 になります。
		*/
		size_t count(const StringRef& str) const;

		/**
		*	条件に合う文字の個数を数えます。
		*	@param function 条件を記述した関数
		*	@return 見つかった文字の個数
		*/
		size_t count_if(std::function<bool(wchar_t)> function) const;

		/**
		*	指定した文字が含まれているかを示します。
		*	@param ch 検索する文字
		*	@return 検索した文字が見つかったら true、見つからなかったら false
		*/
		bool includes(wchar_t ch) const;

		/**
		*	指定した文字列が含まれているかを示します。
		*	@param str 検索する文字列
		*	@return 検索した文字列が見つかったら true、見つからなかったら false
		*/
		bool includes(const StringRef& str) const;

		/**
		*	指定した条件に合う文字が含まれているかを示します。
		*	@param function 条件を記述した関数
		*	@return 検索した文字が見つかったら true、見つからなかったら false
		*/
		bool includes_if(std::function<bool(wchar_t)> function) const;

		/**
		*	指定した文字から始まるかを示します。
		*	@param ch 検索する文字
		*	@return 文字列が検索した文字から始まる場合 true、そうでなかったら false
		*/
		bool startsWith(wchar_t ch) const;

		/**
		*	指定した文字列から始まるかを示します。
		*	@param str 検索する文字列
		*	@return 文字列が検索した文字列から始まる場合 true、そうでなかったら false
		*/
		bool startsWith(const StringRef& str) const;

		/**
		*	指定した文字で終わるかを示します。
		*	@param ch 検索する文字
		*	@return 文字列が検索した文字で終わる場合 true、そうでなかったら false
		*/
		bool endsWith(wchar_t ch) const;

		/**
		*	指定した文字列で終わるかを示します。
		*	@param str 検索する文字列
		*	@return 文字列が検索した文字列で終わる場合 true、そうでなかったら false
		*/
		bool endsWith(const StringRef& str) const;

		/**
		*	指定された文字を置換した文字列を返します。
		*	@param oldChar 置換対象の文字
		*	@param newChar 置換後の文字
		*	@return 新しい文字列
		*/
		String
			replace(
			wchar_t oldChar,
			wchar_t newChar
			) const;

		/**
		*	指定された文字列を置換した文字列を返します。
		*	@param oldChar 置換対象の文字列
		*	@param newChar 置換後の文字列
		*	@return 新しい文字列
		*/
		String
			replace(
			const String& oldStr,
			const String& newStr
			) const;

		/**
		*	指定された文字を除去した文字列を返します。
		*	@param ch 除去する文字
		*	@return 新しい文字列
		*/
		String remove(wchar_t ch) const;

		/**
		*	指定された文字列を除去した文字列を返します。
		*	@param str 除去する文字列
		*	@return 新しい文字列
		*/
		String remove(const StringRef& str) const;

		/**
		*	条件に合う文字を除去した文字列を返します。
		*	@param function 条件を記述した関数
		*	@return 新しい文字列
		*/
		String remove_if(std::function<bool(wchar_t)> function) const;

		/**
		*	指定された区切り文字で文字列を分割します。
		*	@param ch 区切り文字
		*	@return 分割された文字列
		*/
		std::vector<String> split(wchar_t ch) const;
	};

	/**
	*	入力ストリームに文字列を渡します。
	*	@param input 入力ストリーム
	*	@param str 渡す文字列
	*	@return 渡した後の入力ストリーム
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
	*	出力ストリームに文字列を渡します。
	*	@param output 出力ストリーム
	*	@param c 渡す文字列
	*	@return 渡した後の出力ストリーム
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
	*	@brief ファイルパス
	*	ファイルへのパスを表す String を示します。
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
