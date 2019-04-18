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
# include "SivForward.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief ログファイルの詳細度
	*/
	enum class LogLevel
	{
		/**
		*	低
		*/
		Less,

		/**
		*	通常
		*/
		Normal,

		/**
		*	高
		*/
		More,
	};

	namespace Logger
	{
		/**
		*	ログファイルの詳細度を設定します。
		*	@param level 詳細度
		*	@note 詳細度を高く設定すると、より多くのメッセージが出力されます。
		*		  デフォルトの設定は、Debug ビルド時は More, Release ビルド時は Normal です。
		*/
		void
			SetLevel(
			LogLevel level
			);

		/**
		*	ログファイルに画像とテキストを出力します。
		*	@param image 画像
		*	@param str テキスト
		*	@note 大きい画像は Logger::SetImageSize() で指定したサイズと
		*	Logger::SetImageQuality() で指定した品質まで圧縮されます。
		*/
		void
			Write(
			const Image& image,
			const String& str = L""
			);

		/**
		*	ログファイルに出力する画像の縦横の最大サイズを設定します。
		*	@param maxSize 画像の１辺の最大ピクセル数。デフォルトでは 128
		*	@note このサイズを上回る画像は縮小されて出力されます。maxSize は [1-Image::MaxSize] の範囲にクランプされます。
		*/
		void
			SetImageSize(
			unsigned maxSize
			);

		/**
		*	ログファイルに出力する画像の圧縮品質を[0-100] の範囲で指定します。
		*	@param quality 画像の圧縮品質。[0-99] の場合 JPEG, 100 の場合 PNG 圧縮されます。
		*	@note quality は [0-100] の範囲にクランプされます。
		*/
		void
			SetImageQuality(
			unsigned quality
			);
	}
}

# include "SivFormat.hpp"
# include "SivLogger.inl"

# if defined(_DEBUG) || defined(S3D_LOG_DEBUG)
#  define LOG(...)			s3d::OutputLog(s3d::LogDescription::App,__VA_ARGS__)
#  define LOG_DEBUG(...)	s3d::OutputLog(s3d::LogDescription::Debug,__VA_ARGS__)
#  define LOG_ERROR(...)	s3d::OutputLog(s3d::LogDescription::Error,__VA_ARGS__)
#  define LOG_ONCE(...)		s3d::OutputLogOnce(s3d::LogDescription::App,__COUNTER__,__VA_ARGS__)
# else
#  define LOG(...)			s3d::OutputLog(s3d::LogDescription::App,__VA_ARGS__)
#  define LOG_DEBUG(...)	((void)0)
#  define LOG_ERROR(...)	s3d::OutputLog(s3d::LogDescription::Error,__VA_ARGS__)
#  define LOG_ONCE(...)		s3d::OutputLogOnce(s3d::LogDescription::App,__COUNTER__,__VA_ARGS__)
# endif
