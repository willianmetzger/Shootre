#include "tile.h"



tile::tile()
{
}


tile::~tile()
{
}

void tile::SetDestructible(bool d)
{
	this->destrucible = d;
}

bool tile::GetDestructible()
{
	return destrucible;
}

Sprite* tile::GetSprite()
{
	return &s;
}
