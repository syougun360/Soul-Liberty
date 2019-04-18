#include "MapRead.h"

const Float3 CMapRead::FloorSize = Float3(CMapRead::Size, CMapRead::Size, CMapRead::Size * 5);

CMapRead::CMapRead(const FilePath mappath)
{
	TextReader reader(mappath);
	
	HeightRead(reader);

	reader.close();

}

int CMapRead::TransformMapToScreenX(const int x)
{
	return (x - CMapRead::Width / 2) * CMapRead::Size;
}

int CMapRead::TransformMapToScreenY(const int y)
{
	return (y - CMapRead::Height / 2) * -CMapRead::Size;
}

void CMapRead::HeightRead(TextReader& reader)
{
	for (int y = 0; y < Height; y++)
	{
		WidthRead(reader,y);
	}
}

void CMapRead::WidthRead(TextReader& reader,const int y)
{
	for (int x = 0; x < Width; x++)
	{
		ReadUpdate(reader,x,y);
	}
}

void CMapRead::ReadUpdate(TextReader& reader, const int x, const int y)
{
	while (auto ch = reader.readChar())
	{
		if (ch.get() == ',')
		{
			break;
		}
		map_str.push_back(ch.get());
	}
	MapDate[y][x] = std::atoi(map_str.narrow().c_str());
	map_str.clear();
}

void CMapRead::ObjectRead(const Point index, const int type, std::shared_ptr<CActor> actor, std::shared_ptr<CActor> constructor)
{
	if (MapDate[index.y][index.x] != type) return;
		
	actor->Append(constructor);

}