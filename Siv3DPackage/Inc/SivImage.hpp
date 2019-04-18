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
# include <vector>
# include <functional>
# include "SivForward.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief 画像フォーマット
	*/
	enum class ImageFormat
	{
		/**
		*
		*/
		Unknown,

		/**
		*
		*/
		DDS,

		/**
		*
		*/
		PNG,

		/**
		*
		*/
		JPEG,

		/**
		*
		*/
		JPEG2000,

		//JPEGXR,
		//ICO,

		/**
		*
		*/
		BMP,

		/**
		*
		*/
		WebP,

		/**
		*
		*/
		GIF,

		/**
		*
		*/
		TIFF,

		/**
		*
		*/
		TGA,

		/**
		*
		*/
		PPM,

		/**
		*
		*/
		NumberOfFormats,

		/**
		*
		*/
		Unspecified = Unknown,
	};

	/**
	*	@brief DDS フォーマット
	*/
	enum class DDSFormat
	{
		/**
		*
		*/
		ABGR8,

		/**
		*
		*/
		BC1,

		/**
		*
		*/
		BC2,

		/**
		*
		*/
		BC3,

		/**
		*
		*/
		DXT1 = BC1,

		/**
		*
		*/
		DXT3 = BC2,

		/**
		*
		*/
		DXT5 = BC3,
	};

	/**
	*	@brief PNG フィルタ
	*/
	struct PNGFilter
	{
		enum Flag
		{
			/**
			*
			*/
			None	= 0x08,

			/**
			*
			*/
			Sub		= 0x10,

			/**
			*
			*/
			Up		= 0x20,

			/**
			*
			*/
			Avg		= 0x40,

			/**
			*
			*/
			Paeth	= 0x80,

			/**
			*
			*/
			Default	= None | Sub | Up | Avg | Paeth,
		};
	};

	/**
	*	@brief 塗りつぶしの連結性
	*/
	enum class FloodFillConnectivity
	{
		/**
		*
		*/
		Value4 = 4,

		/**
		*
		*/
		Value8 = 8,
	};

	/**
	*	@brief WebP の圧縮方法
	*/
	enum class WebPMethod
	{
		/**
		*	高速圧縮	(圧縮率と品質： 最低、	速度： 早い)
		*/
		Fast,

		/**
		*	通常圧縮	(圧縮率と品質： 普通、	速度： 普通)
		*/
		Default,

		/**
		*	高圧縮	(圧縮率と品質： 高、	速度： 遅い)
		*/
		Quality,

		/**
		*	最高圧縮	(圧縮率と品質： 最高、	速度： 非常に遅い)
		*/
		BestQuality,
	};

	/**
	*	@brief 画像拡大縮小の手法
	*/
	enum class Interpolation
	{
		/**
		*	最近傍補間
		*/
		Nearest,

		/**
		*	バイリニア補間
		*/
		Linear,

		/**
		*	バイキュービック補間
		*/
		Cubic,

		/**
		*	エリア（画像の大幅な縮小に適している手法）
		*/
		Area,

		/**
		*	Lanczos 法の補間（拡大や、小幅な縮小に適している手法）
		*/
		Lanczos,

		/**
		*	最適な手法を自動選択
		*/
		Unspecified,
	};

	/**
	*	@brief イメージ
	*
	*	メモリ上に確保される画像データです。
	*	ピクセル単位のアクセスや、変形、エフェクト処理を適用できます。
	*	イメージを描画する場合は Texture に変換する必要があります。
	*/
	class Image
	{
	private:

		std::vector<Color> m_data;

		unsigned m_width, m_height;

	public:

		enum
		{
			/**
			*
			*/
			MaxSize = 8192
		};

		/**
		*
		*/
		Image(
			);

		/**
		*
		*/
		~Image(
			);

		/**
		*
		*	@param width
		*	@param height
		*/
		Image(
			unsigned width,
			unsigned height
			);

		/**
		*
		*	@param width
		*	@param height
		*	@param color
		*/
		Image(
			unsigned width,
			unsigned height,
			const Color& color
			);

		/**
		*
		*	@param path
		*/
		explicit
			Image(
			const FilePath& path
			);

		/**
		*
		*	@param rgb
		*	@param alpha
		*/
		Image(
			const FilePath& rgb,
			const FilePath& alpha
			);

		/**
		*
		*	@param rgb
		*	@param alpha
		*/
		Image(
			const Color& rgb,
			const FilePath& alpha
			);

		/**
		*
		*	@param image
		*/
		Image(
			const Image& image
			);

		/**
		*
		*	@param image
		*/
		Image(
			Image && image
			);

		/**
		*
		*	@param image
		*	@return
		*/
		Image&
			operator =(
			const Image& image
			);

		/**
		*
		*	@param image
		*	@return
		*/
		Image&
			operator =(
			Image && image
			);

		/**
		*
		*/
		void
			clear(
			);

		/**
		*
		*	@param color
		*/
		void
			fill(
			const Color& color
			);

		/**
		*
		*	@return
		*/
		explicit operator bool(
			) const;

		/**
		*
		*	@param width
		*	@param height
		*/
		void
			resize(
			unsigned width,
			unsigned height
			);

		/**
		*
		*	@param width
		*	@param height
		*	@param fillColor
		*/
		void
			resize(
			unsigned width,
			unsigned height,
			const Color& fillColor
			);

		/**
		*
		*	@param rect
		*	@return
		*/
		Image
			getRect(
			const Rect& rect
			) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param w
		*	@param h
		*	@return
		*/
		Image
			getRect(
			int x,
			int y,
			int w,
			int h
			) const;

		/**
		*
		*	@param y
		*	@param x
		*	@return
		*/
		Color&
			getPixel(
			int y,
			int x
			);

		/**
		*
		*	@param y
		*	@param x
		*	@return
		*/
		const Color&
			getPixel(
			int y,
			int x
			) const;

		/**
		*
		*	@param y
		*	@param x
		*	@return
		*/
		ColorF
			sample(
			double y,
			double x
			) const;

		/**
		*
		*	@param y
		*	@return
		*/
		Color*
			operator [](
			unsigned y
			)
		{
			return &m_data[m_width*y];
		}

		/**
		*
		*	@param y
		*	@return
		*/
		const Color*
			operator [](
			unsigned y
			) const
		{
			return &m_data[m_width*y];
		}

		/**
		*
		*	@return
		*/
		void*
			data(
			);

		/**
		*
		*	@return
		*/
		const void*
			data(
			) const;

		/**
		*
		*	@return
		*/
		std::vector<Color>::iterator
			begin(
			);

		/**
		*
		*	@return
		*/
		std::vector<Color>::const_iterator
			begin(
			) const;

		/**
		*
		*	@return
		*/
		std::vector<Color>::iterator
			end(
			);

		/**
		*
		*	@return
		*/
		std::vector<Color>::const_iterator
			end(
			) const;

		/**
		*
		*	@return
		*/
		std::vector<Color>::reverse_iterator
			rbegin(
			);

		/**
		*
		*	@return
		*/
		std::vector<Color>::const_reverse_iterator
			rbegin(
			) const;

		/**
		*
		*	@return
		*/
		std::vector<Color>::reverse_iterator
			rend(
			);

		/**
		*
		*	@return
		*/
		std::vector<Color>::const_reverse_iterator
			rend(
			) const;

		/**
		*
		*	@param image
		*/
		void
			swap(
			Image& image
			);

		/**
		*
		*	@return
		*/
		Image
			clone(
			) const;

		/**
		*	イメージの幅（ピクセル）
		*/
		Property_Get(int, width) const;

		/**
		*	イメージの高さ（ピクセル）
		*/
		Property_Get(int, height) const;

		/**
		*
		*/
		Property_Get(unsigned, stride) const;

		/**
		*	イメージのデータサイズ（バイト）
		*/
		Property_Get(unsigned, dataSize) const;

		/**
		*
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*
		*	@param alpha
		*	@return
		*/
		bool
			applyAlphaFromRChannel(
			const FilePath& alpha
			);

		/**
		*
		*	@param path
		*	@param format
		*	@return
		*/
		bool
			save(
			const FilePath& path,
			ImageFormat format = ImageFormat::Unspecified
			) const;

		/**
		*
		*	@param path
		*	@param ddsFormat
		*	@return
		*/
		bool
			saveDDS(
			const FilePath& path,
			DDSFormat ddsFormat = DDSFormat::ABGR8
			) const;

		/**
		*
		*	@param path
		*	@param filterFlag
		*	@return
		*/
		bool
			savePNG(
			const FilePath& path,
			PNGFilter::Flag filterFlag = PNGFilter::Default
			) const;

		/**
		*
		*	@param path
		*	@param quality
		*	@return
		*/
		bool
			saveJPEG(
			const FilePath& path,
			int quality = 90
			) const;

		/**
		*
		*	@param path
		*	@param quality
		*	@return
		*/
		bool
			saveGIF(
			const FilePath& path,
			bool dither = true
			) const;

		/**
		*
		*	@param path
		*	@param compressionRatio
		*	@return
		*/
		bool
			saveJPEG2000(
			const FilePath& path,
			double compressionRatio = 10.0
			) const;

		/**
		*
		*	@param path
		*	@param quality
		*	@param method
		*	@return
		*/
		bool
			saveWebP(
			const FilePath& path,
			double quality = 95.0,
			WebPMethod method = WebPMethod::Default
			) const;

		/**
		*
		*	@param format
		*	@return
		*/
		Blob
			encode(
			ImageFormat format
			) const;

		/**
		*
		*	@param ddsFormat
		*	@return
		*/
		Blob
			encodeDDS(
			DDSFormat ddsFormat = DDSFormat::ABGR8
			) const;

		/**
		*
		*	@param filterFlag
		*	@return
		*/
		Blob
			encodePNG(
			PNGFilter::Flag filterFlag = PNGFilter::Default
			) const;

		/**
		*
		*	@param quality
		*	@return
		*/
		Blob
			encodeJPEG(
			int quality = 90
			) const;

		/**
		*
		*	@param compressionRatio
		*	@return
		*/
		Blob
			encodeJPEG2000(
			double compressionRatio = 10.0
			) const;

		/**
		*
		*	@param quality
		*	@param method
		*	@return
		*/
		Blob
			encodeWebP(
			double quality = 95.0,
			WebPMethod method = WebPMethod::Default
			) const;

		/**
		*
		*	@param function
		*	@return
		*/
		void
			forEach(
			std::function<void(Color&)> function
			);

		/**
		*
		*	@return
		*/
		Image&
			negative(
			);

		/**
		*
		*	@return
		*/
		Image&
			grayscale(
			);

		/**
		*
		*	@param level
		*	@return
		*/
		Image&
			sepia(
			int level = 25
			);

		/**
		*
		*	@param level
		*	@return
		*/
		Image&
			postarize(
			int level
			);

		/**
		*
		*	@param level
		*	@return
		*/
		Image&
			brightness(
			int level
			);

		/**
		*
		*	@return
		*/
		Image&
			flip(
			);

		/**
		*
		*	@return
		*/
		Image&
			mirror(
			);

		/**
		*
		*	@return
		*/
		Image&
			rotate90(
			);

		/**
		*
		*	@return
		*/
		Image&
			rotate180(
			);

		/**
		*
		*	@return
		*/
		Image&
			rotate270(
			);

		/**
		*
		*	@param gamma
		*	@return
		*/
		Image&
			gamma(
			double gamma
			);

		/**
		*
		*	@param threshold
		*	@return
		*/
		Image&
			threshold(
			unsigned char threshold
			);

		/**
		*
		*	@param horizontal
		*	@param vertical
		*	@return
		*/
		Image&
			mosaic(
			int horizontal,
			int vertical
			);

		/**
		*
		*	@param horizontal
		*	@param vertical
		*	@return
		*/
		Image&
			spread(
			unsigned horizontal,
			unsigned vertical
			);

		/**
		*
		*	@param horizontal
		*	@param vertical
		*	@return
		*/
		Image&
			gaussian(
			unsigned horizontal,
			unsigned vertical
			);

		/**
		*
		*	@param _width
		*	@param _height
		*	@param interpolation
		*	@return
		*/
		Image&
			scale(
			unsigned _width,
			unsigned _height,
			Interpolation interpolation = Interpolation::Unspecified
			);

		/**
		*
		*	@param scaling
		*	@param interpolation
		*	@return
		*/
		Image&
			scale(
			double scaling,
			Interpolation interpolation = Interpolation::Unspecified
			);

		/**
		*
		*	@param _width
		*	@param _height
		*	@return
		*/
		Image&
			fit(
			unsigned _width,
			unsigned _height,
			Interpolation interpolation = Interpolation::Unspecified
			);

		/**
		*
		*	@param src
		*	@param pos
		*	@param alpha
		*	@return
		*/
		Image&
			blend(
			const Image& src,
			const Point& pos,
			double alpha = 1.0
			);

		/**
		*
		*	@param src
		*	@param pos
		*	@param rect
		*	@param alpha
		*	@return
		*/
		Image&
			blend(
			const Image& src,
			const Point& pos,
			const Rect& rect,
			double alpha = 1.0
			);

		/**
		*
		*	@param src
		*	@param pos
		*	@return
		*/
		Image&
			overwrite(
			const Image& src,
			const Point& pos
			);

		/**
		*
		*	@param src
		*	@param pos
		*	@param rect
		*	@return
		*/
		Image&
			overwrite(
			const Image& src,
			const Point& pos,
			const Rect& rect
			);

		/**
		*
		*	@param pos
		*	@param col
		*	@param flag
		*	@param lowerDifference
		*	@param upperDifference
		*	@return
		*/
		Image&
			floodFill(
			const s3d::Point& pos,
			const Color& col,
			FloodFillConnectivity flag = FloodFillConnectivity::Value4,
			int lowerDifference = 0,
			int upperDifference = 0
			);

		/**
		*
		*	@return
		*/
		Image&
			swapARGBtoABGR(
			);
	};

	/**
	*	@brief
	*/
	namespace Imaging
	{
		/**
		*
		*	@param path
		*	@return
		*/
		ImageFormat
			GetFormat(
			const FilePath& path
			);

		/**
		*
		*	@param path
		*	@return
		*/
		Point
			GetSize(
			const FilePath& path
			);

		/**
		*
		*	@param path
		*	@return
		*/
		std::vector<Image>
			LoadAnimatedGIF(
			const FilePath& path
			);

		/**
		*
		*	@param path
		*	@param frameRects
		*	@return
		*/
		Image
			ExpandAnimatedGIF(
			const FilePath& path,
			std::vector<Rect>& frameRects
			);

		/**
		*
		*	@param path
		*	@param images
		*	@param delay
		*	@return
		*/
		bool
			SaveAnimatedGIF(
			const FilePath& path,
			const std::vector<Image>& images,
			unsigned short delay,
			bool dither = true,
			bool hasAlpha = true
			);

		/**
		*
		*	@param image
		*	@param function
		*	@return
		*/
		Image
			ForEach(
			const Image& image,
			std::function<void(Color&)> function
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			Negative(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			GrayScale(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@param level
		*	@return
		*/
		Image
			Sepia(
			const Image& img,
			int level = 25
			);
 
		/**
		*	level [2,32]
		*	@param img
		*	@param level
		*	@return
		*/
		Image
			Postarize(
			const Image& img,
			int level = 6
			);

		/**
		*
		*	@param img
		*	@param level
		*	@return
		*/
		Image
			Brightness(
			const Image& img,
			int level
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			Flip(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			Mirror(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			Rotate90(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			Rotate180(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@return
		*/
		Image
			Rotate270(
			const Image& img
			);

		/**
		*
		*	@param img
		*	@param gamma
		*	@return
		*/
		Image
			Gamma(
			const Image& img,
			double gamma
			);

		/**
		*
		*	@param img
		*	@param threshold
		*	@return
		*/
		Image
			Threshold(
			const Image& img,
			unsigned char threshold
			);

		/**
		*
		*	@param img
		*	@param horizontal
		*	@param vertical
		*	@return
		*/
		Image
			Mosaic(
			const Image& img,
			int horizontal,
			int vertical
			);

		/**
		*
		*	@param img
		*	@param horizontal
		*	@param vertical
		*	@return
		*/
		Image
			Spread(
			const Image& img,
			unsigned horizontal,
			unsigned vertical
			);

		/**
		*
		*	@param img
		*	@param horizontal
		*	@param vertical
		*	@return
		*/
		Image
			Gaussian(
			const Image& img,
			unsigned horizontal,
			unsigned vertical
			);

		/**
		*
		*	@param img
		*	@param width
		*	@param height
		*	@param interpolation
		*	@return
		*/
		Image
			Scale(
			const Image& img,
			unsigned width,
			unsigned height,
			Interpolation interpolation = Interpolation::Unspecified
			);

		/**
		*
		*	@param img
		*	@param scaling
		*	@param interpolation
		*	@return
		*/
		Image
			Scale(
			const Image& img,
			double scaling,
			Interpolation interpolation = Interpolation::Unspecified
			);

		/**
		*
		*	@param img
		*	@param width
		*	@param height
		*	@param interpolation
		*	@return
		*/
		Image
			Fit(
			const Image& img,
			unsigned width,
			unsigned height,
			Interpolation interpolation = Interpolation::Unspecified
			);

		/**
		*
		*	@param dst
		*	@param src
		*	@param pos
		*	@param alpha
		*	@return
		*/
		Image
			Blend(
			const Image& dst,
			const Image& src,
			const Point& pos,
			double alpha = 1.0
			);

		/**
		*
		*	@param dst
		*	@param src
		*	@param pos
		*	@param rect
		*	@param alpha
		*	@return
		*/
		Image
			Blend(
			const Image& dst,
			const Image& src,
			const Point& pos,
			const Rect& rect,
			double alpha = 1.0
			);

		/**
		*
		*	@param dst
		*	@param src
		*	@param result
		*	@param pos
		*	@param alpha
		*	@return
		*/
		void
			Blend(
			const Image& dst,
			const Image& src,
			Image& result,
			const Point& pos,
			double alpha = 1.0
			);

		/**
		*
		*	@param dst
		*	@param src
		*	@param result
		*	@param pos
		*	@param rect
		*	@param alpha
		*	@return
		*/
		void
			Blend(
			const Image& dst,
			const Image& src,
			Image& result,
			const Point& pos,
			const Rect& rect,
			double alpha = 1.0
			);

		/**
		*
		*	@param dst
		*	@param src
		*	@param pos
		*	@return
		*/
		Image
			Overwrite(
			const Image& dst,
			const Image& src,
			const Point& pos
			);

		/**
		*
		*	@param dst
		*	@param src
		*	@param pos
		*	@param rect
		*	@return
		*/
		Image
			Overwrite(
			const Image& dst,
			const Image& src,
			const Point& pos,
			const Rect& rect
			);

		/**
		*
		*	@param in
		*	@param pos
		*	@param col
		*	@param flag
		*	@param lowerDifference
		*	@param upperDifference
		*	@return
		*/
		Image
			FloodFill(
			const Image& in,
			const s3d::Point& pos,
			const Color& col,
			FloodFillConnectivity flag = FloodFillConnectivity::Value4,
			int lowerDifference = 0,
			int upperDifference = 0
			);

		/**
		*
		*	@param src
		*	@return
		*/
		Image
			SwapARGBtoABGR(
			const Image& src
			);

		/**
		*
		*	@param src
		*	@return
		*/
		Image
			GenerateMip(
			const Image& src
			);
	}
}
