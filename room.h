#pragma once
#include "tilemap.h"

class room
{
public:
	room();
	~room();

	void LoadLayout(string file_path);
	void DrawLayout();

private:

	tilemap tm;
	room* rooms;
};

