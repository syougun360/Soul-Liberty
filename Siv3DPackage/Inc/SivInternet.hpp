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
# include "SivOptional.hpp"

namespace s3d
{
	/**
	*	@brief インターネット
	*
	*	インターネット上のデータにアクセスします。
	*/
	namespace Internet
	{
		/**
		*	コンピューターがインターネットに接続されているかを返します。
		*	@return 接続されていれば true, されていなければ false
		*/
		bool IsConnected();

		/**
		*	指定した URL のファイルに接続します。
		*	@param url http:// もしくは https:// で始まる URL
		*	@return 接続できれば true, 失敗した場合 false
		*/
		bool Connect(const FilePath& url);

		/**
		*	指定した URL のファイルに接続し、ファイルのサイズを取得します。
		*	@param url http:// もしくは https:// で始まる URL
		*	@param fileSize サイズを格納する変数
		*	@return 成功フラグ
		*/
		bool Connect(const FilePath& url, long long& fileSize);

		/**
		*	接続した URL のファイルをダウンロードします。
		*	@param output 保存するファイル名
		*	@return ダウンロードを開始したか
		*	@note この関数は、ダウンロードが完了するか、途中でエラーが発生するまで制御を返しません。
		*/
		bool DownloadTo(const FilePath& output);

		/**
		*	接続した URL のファイルのダウンロードを開始します。
		*	@param output 保存するファイル名
		*	@return ダウンロード開始に成功した場合 true, 失敗した場合 false
		*/
		bool BeginDownloadTo(const FilePath& output);

		/**
		*	ダウンロードの進行状況を [0,100] の値で返します。
		*	@return ダウンロードの進行状況
		*	@note ダウンロード中の場合はその進度を [0,99] で、完了したり、それ以外の場合は 100 を返します。
		*/
		int GetDownloadProgress();

		/**
		*	ダウンロードを中止します。
		*/
		void CancelDownload();

		/**
		*	指定した URL を Internet Explorer で開きます。
		*	@param url http:// もしくは https:// で始まる URL
		*	@return 成功した場合 true, 失敗した場合 false
		*/
		bool LaunchIE(const FilePath& url);

		/**
		*	指定した URL をユーザの既定のブラウザで開きます。
		*	@param url http:// もしくは https:// で始まる URL
		*	@return 成功した場合 true, 失敗した場合 false
		*/
		bool LaunchWebBrowser(const FilePath& url);
	}
}
