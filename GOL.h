#pragma once
#include "Randomize.h"
#include "Images.h"

class GOL {

private:

	Randomize *randomize;
	sf::Vector2u size;
	unsigned int *neighbors;
	unsigned int *board;

	Images *images;

	int dir[8];

	void initRandomize();
	void initNeighbors();
	void initBoard();
	void initImages();
	void initDirections();

public:

	GOL(sf::Vector2u board_size);
	~GOL();

	void checkNeighbors();
	void checkBoard();
	void update();
	sf::Sprite getSprite();
};
