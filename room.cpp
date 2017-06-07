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

void room::LoadLayout(string file_path)
{
	tm.LoadLayout(file_path);
}
