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

void tile::setCanWalk(bool c)
{
	canWalk = c;
}

bool tile::GetDestructible()
{
	return destrucible;
}

bool tile::getCanWalk()
{
	return canWalk;
}

Sprite* tile::GetSprite()
{
	return &s;
}
