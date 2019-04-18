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
# include "SivString.hpp"
# include "SivOptional.hpp"

namespace s3d
{
	class Serial
	{
	private:

		class CSerial;

		std::shared_ptr<CSerial> pSerial;

	public:

		Serial();

		explicit Serial(int port, int baudRate = 9600);

		~Serial();

		bool setup(int port, int baudRate = 9600);

		explicit operator bool() const;

		bool isOpened() const;

		int available();

		void flushInput();

		void flushOutput();

		void flush();

		optional<unsigned char> readByte();

		optional<std::vector<unsigned char>> readBytes();

		bool readByte(unsigned char& byte);

		bool readBytes(std::vector<unsigned char>& bytes);

		int writeByte(unsigned char byte);

		int writeBytes(const unsigned char* bytes, size_t size);

		int write(const String& str);

		int writeln(const String& str);

		void close();
	};

	struct SerialDeveiceInfo
	{
		String name;

		int port = 0;
	};

	namespace SerialManager
	{
		std::vector<SerialDeveiceInfo> Enumerate();
	}
}
