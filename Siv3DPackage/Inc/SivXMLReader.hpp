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
	*	@brief XML �h�L�������g�̎��
	*/
	enum class XMLDocumentType
	{
		/**
		*	�w�肵�Ȃ�
		*	@note ������ L".xml" �ŏI���ꍇ File, ����ȊO�̏ꍇ�� Text �Ƃ݂Ȃ�
		*/
		Unspecified,

		/**
		*	XML �t�@�C���̃p�X
		*/
		File,

		/**
		*	XML ���L�q����������
		*/
		Text,
	};

	/**
	*	@brief XML �h�L�������g�̓ǂݍ���
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
	*	@brief XML �̗v�f
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
