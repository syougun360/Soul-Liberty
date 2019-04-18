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
	namespace Dialog
	{
		inline
			optional<FilePath>
			GetOpenBasicImage(
			const String& title
			)
		{
			return GetOpen({
				ExtensionFilter::BasicImage,
				ExtensionFilter::BMP,
				ExtensionFilter::PNG,
				ExtensionFilter::JPEG,
				ExtensionFilter::GIF
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetOpenImage(
			const String& title
			)
		{
			return GetOpen({
				ExtensionFilter::AllImage,
				ExtensionFilter::BMP,
				ExtensionFilter::PNG,
				ExtensionFilter::JPEG,
				ExtensionFilter::GIF,
				ExtensionFilter::TGA,
				ExtensionFilter::DDS,
				ExtensionFilter::WebP,
				ExtensionFilter::JPEG2000,
				ExtensionFilter::TIFF,
				ExtensionFilter::PPM,
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetOpenSound(
			const String& title
			)
		{
			return GetOpen({
				ExtensionFilter::AllSound,
				ExtensionFilter::WAVE,
				ExtensionFilter::MP3,
				ExtensionFilter::OggVorbis,
				ExtensionFilter::AAC,
				ExtensionFilter::WMA,
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetOpenMidi(
			const String& title
			)
		{
			return GetOpen({
				ExtensionFilter::MIDI
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetOpenText(
			const String& title
			)
		{
			return GetOpen({
				ExtensionFilter::Text
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetOpenAll(
			const String& title
			)
		{
			return GetOpen({
				ExtensionFilter::All
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetSaveBasicImage(
			const String& title
			)
		{
			return GetSave({
				ExtensionFilter::PNG,
				ExtensionFilter::BMP,
				ExtensionFilter::JPEG,
				ExtensionFilter::GIF,
				ExtensionFilter::BasicImage
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetSaveImage(
			const String& title
			)
		{
			return GetSave({
				ExtensionFilter::PNG,
				ExtensionFilter::BMP,
				ExtensionFilter::JPEG,
				ExtensionFilter::GIF,
				ExtensionFilter::TGA,
				ExtensionFilter::DDS,
				ExtensionFilter::WebP,
				ExtensionFilter::JPEG2000,
				ExtensionFilter::TIFF,
				ExtensionFilter::PPM,
				ExtensionFilter::AllImage
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetSaveSound(
			const String& title
			)
		{
			return GetSave({
				ExtensionFilter::WAVE,
				ExtensionFilter::OggVorbis,
				ExtensionFilter::MP3,
				ExtensionFilter::AAC,
				ExtensionFilter::WMA,
				ExtensionFilter::AllSound
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetSaveText(
			const String& title
			)
		{
			return GetSave({
				ExtensionFilter::Text
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetSaveVideo(
			const String& title
			)
		{
			return GetSave({
				ExtensionFilter::AVI
			},
			title
			);
		}

		inline
			optional<FilePath>
			GetSaveAll(
			const String& title
			)
		{
			return GetSave({
				ExtensionFilter::All
			},
			title
			);
		}
	}
}
