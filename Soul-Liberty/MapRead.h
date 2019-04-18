
/**
*
*	@author	yamada masamitsu
*	@date	2014.10.00
*
*/
#pragma once
#include "Actor.h"

class CMapRead
{
public:
	CMapRead(const FilePath mappath);

	void ObjectRead(const Point index, const int type, std::shared_ptr<CActor> actor, std::shared_ptr<CActor> constructor);
	
	static const int Width = 300;
	static const int Height = 8;

	static const int Size = 100;
	static const Float3 FloorSize;
	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);
	int GetElement(Point pos)const{ return MapDate[pos.y][pos.x]; }
private:
	void WidthRead(TextReader& reader, const int y);
	void HeightRead(TextReader& reader);
	void ReadUpdate(TextReader& reader, const int x, const int y);
	
	int MapDate[Height][Width];
	String map_str;


};

