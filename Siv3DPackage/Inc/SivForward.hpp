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
	struct Char;
	class  String;
	struct Calendar;
	struct Date;
	class  BinaryWriter;
	class  BinaryReader;
	class  Blob;
	class  TextWriter;
	class  TextReader;
	class  RNG;
	class  Noise;
	class  CSVReader;
	class  INIReader;
	class  XMLElement;
	class  XMLReader;

	struct Point;
	struct Circular;
	struct LineInt;
	struct Line;
	struct Circle;
	struct Ellipse;
	struct Triangle;
	struct Quad;
	class  LineString;
	class  Polygon;
	struct FloatRect;
	struct FloatQuad;

	union  Color;
	struct ColorF;
	struct HSV;
	enum class ImageFormat;
	enum class DDSFormat;
	enum class WebPMethod;
	enum class Interpolation;
	class  Image;

	union WaveSample;
	enum class AudioFormat;
	struct AudioProperty;
	enum class AACQuality;
	class Wave;

	struct FontProperty;

	class Key;
	struct Touch;
	class CombinedKeysPlus;
	class CombinedKeysOr;

	template<typename Type> struct Vector2D;
	template<typename Type> struct Vector3D;
	template<typename Type> struct Vector4D;
	template<typename SizeType, typename ElementType> struct Rectangle;
	typedef Vector2D<float>	 Float2;
	typedef Vector2D<double> Vec2;
	typedef Vector3D<float>  Float3;
	typedef Vector3D<double> Vec3;
	typedef Vector4D<float>  Float4;
	typedef Vector4D<double> Vec4;
	typedef Rectangle<Point,int>	Rect;
	typedef Rectangle<Vec2,double>	RectF;

	struct Quaternion;
	struct Mat4x4;

	typedef String FilePath;

	enum class OpenMode;
	enum class TextEncoding;
	enum class CopyOption;
	enum class LogLevel;
	enum class LogDescription;

	struct LoopProperty;
	class  Sound;

	enum class TextureFormat;
	class  Texture;
	class  DynamicTexture;
	struct TextureRegion;
	struct TexturedQuad;
	class  Sprite;

	struct FontStyle;
	class  Font;
	class  DrawableString;

	struct GUISkin;
	class  GUI;
	class  GUIButton;
	class  GUIText;
	class  GUIToggleSwitch;
	class  GUISlider;
	class  GUICheckBox;
	class  GUIRadioButton;

	struct Vertex;
	struct MeshObject;
	class  Mesh;
	struct TransformedMesh;
	enum class PrimitiveType;
	struct Plane;
	struct Box;
	struct Sphere;
	struct Disc;
	struct Cylinder;
	struct Cone;
	struct Ray;
	class  Model;

	struct RendererProperty;
	class  Renderer;

	struct Camera;
	struct Light;
	struct Fog;
	enum class AntiAliasing;

	typedef String AssetName;
	typedef String AssetTag;
}

namespace cv
{
	class Mat;
}

namespace DirectX
{
	class Vector;
}
