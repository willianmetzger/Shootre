#pragma once
#include "enemy.h"

class room
{
public:
	room();
	~room();

	void LoadLayout(string file_path);
	void DrawLayout();
	tilemap* getTm();

private:

	tilemap tm;
	room* rooms;
};

