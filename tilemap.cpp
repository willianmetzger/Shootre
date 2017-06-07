#include "tilemap.h"


tilemap::tilemap()
{
}


tilemap::~tilemap()
{
}


void tilemap::AddTile(int pos, string path, int num_anim, int max_frames, bool c)
{
	gRecursos.carregarSpriteSheet("tile_" + to_string(pos), path, num_anim, max_frames);
	tileset[pos]->GetSprite()->setSpriteSheet("tile_" + to_string(pos));
	tileset[pos]->GetSprite()->setAncora(0, 0);
	tileset[pos]->setCanWalk(c);
}

void tilemap::LoadLayout(string file_path)
{
	int ts_size, tile_na, tile_mf;
	bool tile_cw;
	string tile_path;
	ifstream file_read;

	if (!file_read.is_open())
		file_read.open(file_path);

	file_read >> ts_size;
	tileset = new tile*[ts_size];
	for (int i = 0; i < ts_size; i++) {
		tileset[i] = new tile;
	}

	for (int i = 0; i < ts_size; i++) {
		file_read >> tile_path;//caminho para a sprite que compõe o tile
		file_read >> tile_na;//numero de animações da sprite
		file_read >> tile_mf;//numero máximo de frames da sprite
		file_read >> tile_cw;//checa se o tile é caminhavel ou não
		AddTile(i, tile_path, tile_na, tile_mf, tile_cw);
	}
	
	file_read >> tm_l;
	file_read >> tm_c;

	tilemap_grid = new tile**[tm_l];

    //file_matrix = new int* [tm_l];

    for (int l = 0; l < tm_l; l++) {
	   tilemap_grid[l] = new tile*[tm_c];
	   for (int c = 0; c < tm_c; c++) {
		   char tile_symbol;
		   file_read >> tile_symbol;
		   int pos = TranslateToTile(tile_symbol);
		   tilemap_grid[l][c] = tileset[pos];
	   }
	}

	file_read.close();

}

/*void tilemap::SetLayout()
{

	tilemap_grid = new Sprite** [tm_l];

	for (int l = 0; l < tm_l; l++) {
		tilemap_grid[l] = new Sprite* [tm_c];
		for (int c = 0; c < tm_c; c++) {
			//tilemap_grid[l][c] = GetTile(file_matrix[l][c]);
		}
	}
}*/

void tilemap::DrawLayout()
{
	int offset_x = 32, offset_y = 32;

	for (int l = 0; l < tm_l; l++) {
		for (int c = 0; c < tm_c; c++) {
			tilemap_grid[l][c]->GetSprite()->desenhar(offset_x, offset_y);
			offset_x += 32;
		}
		offset_x = 32;
		offset_y += 32;
	}
}

int tilemap::TranslateToTile(char type)
{
	switch (type) { // *** Q, P, Z, M = Cantos das paredes(sempre de 0 a 3) *** < V > ^ = Junções das paredes(sempre de 4 a 7) *** ~ ] U [ = Final de parede(sempre de 8 a 11) *** - | = Meio da parede(Hor e Ver, 12 e 13) *** 0 = chão
		case 'Q':
			return 0; break;
		case 'P': 
			return 1; break;
		case 'M':
			return 2; break;
		case 'Z':
			return 3; break;
		case 'V':
			return 4; break;
		case '<':
			return 5; break;
		case '^':
			return 6; break;
		case '>':
			return 7; break;
		case '~':
			return 8; break;
		case ']':
			return 9; break;
		case 'U':
			return 10; break;
		case '[':
			return 11; break;
		case '-':
			return 12; break;
		case '|':
			return 13; break;
		case '0':
			return 14;
	}
}

int tilemap::GetNumTilesX()
{
	return tm_c;
}

int tilemap::GetNumTilesY()
{
	return tm_l;
}

void tilemap::SetTileMapSize(int l, int c)
{
	this->tm_l = l;
	this->tm_c = c;
}

tile *** tilemap::GetTilemap()
{
	return tilemap_grid;
}
