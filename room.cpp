#include "room.h"

room::room()
{
}

room::~room()
{
}

void room::DrawLayout()
{
	tm.DrawLayout();
}

tilemap * room::getTm()
{
	return &tm;
}

void room::LoadLayout(string file_path)
{
	tm.LoadLayout(file_path);
}
