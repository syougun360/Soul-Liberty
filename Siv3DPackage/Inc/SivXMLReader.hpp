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
# include <memory>
# include <vector>
# include "SivForward.hpp"
# include "SivPropertyMacro.hpp"
# include "SivOptional.hpp"

namespace s3d
{
	/**
	*	@brief XML ドキュメントの種類
	*/
	enum class XMLDocumentType
	{
		/**
		*	指定しない
		*	@note 文字列が L".xml" で終わる場合 File, それ以外の場合は Text とみなす
		*/
		Unspecified,

		/**
		*	XML ファイルのパス
		*/
		File,

		/**
		*	XML を記述した文字列
		*/
		Text,
	};

	/**
	*	@brief XML ドキュメントの読み込み
	*/
	class XMLReader
	{
	private:

		class CXMLReader;

		std::shared_ptr<CXMLReader> m_reader;

		friend class s3d::XMLElement;

		struct XMLInternal;

	public:

		XMLReader();

		explicit XMLReader(const String& document, XMLDocumentType type = XMLDocumentType::Unspecified);

		bool loadFile(const FilePath& path);

		bool parse(const String& text);

		explicit operator bool() const;

		bool isValid() const;

		XMLElement root() const;
	};

	/**
	*	@brief XML の要素
	*/
	class XMLElement
	{
	private:

		class CXMLElement;

		std::shared_ptr<CXMLElement> m_element;

	public:

		XMLElement();

		explicit XMLElement(const XMLReader::XMLInternal& xmlInternal);

		~XMLElement();

		explicit operator bool() const;

		bool isNull() const;

		Property_Get(String, name) const;

		Property_Get(String, text) const;

		XMLElement firstChild() const;

		XMLElement nextSibling() const;

		XMLElement parent() const;

		std::vector<std::pair<String, String>> attributes() const;

		optional<String> attribute(const String& name) const;
	};
}
