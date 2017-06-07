#pragma once
#include "tile.h"

class tilemap
{

public:
	tilemap();
	~tilemap();

	void AddTile(int pos, string path, int num_anim, int max_frames);
	void LoadLayout(string file_path);
	void SetTileMapSize(int l, int c);

	//void SetLayout();
	void DrawLayout();

	int TranslateToTile(char type);
	int GetNumTilesX();
	int GetNumTilesY();
	Sprite*** GetTilemap();

private:
	Sprite*** tilemap_grid;
	tile* tileset;
	int tm_l, tm_c;
};

