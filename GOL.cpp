#include "GOL.h"

void GOL::initRandomize() {

	randomize = new Randomize();
	randomize->randomizeInt(0, 1);
}
void GOL::initNeighbors() {

	neighbors = new unsigned int[size.x * size.y];
}
void GOL::initBoard() {

	board = new unsigned int[size.x * size.y];

	for(unsigned int y = 0; y < size.y; ++y) {
		for(unsigned int x = 0; x < size.x; ++x) {

			unsigned int index = y * size.x + x;

			board[index] = randomize->randomI();
			neighbors[index] = 0;
		}
	}
}
void GOL::initImages() {

	images = new Images(size);
}
void GOL::initDirections() {

	//Right
	dir[0] = 1;
	//Down + Right
	dir[1] = size.x + 1;
	//Down
	dir[2] = size.x;
	//Down + Left
	dir[3] = size.x - 1;
	//Left
	dir[4] = -1;
	//Up + Left
	dir[5] = -int(size.x) - 1;
	//Up
	dir[6] = -int(size.x);
	//Up + Right
	dir[7] = -int(size.x) + 1;
}
GOL::GOL(sf::Vector2u board_size) {

	size = board_size;
	initRandomize();
	initNeighbors();
	initBoard();
	initImages();
	initDirections();
}
GOL::~GOL() {

	delete randomize;
	delete images;
	delete[] neighbors;
	delete[] board;
}
void GOL::checkNeighbors() {

	for(unsigned int i = 0; i < size.x * size.y; ++i) {

		if(board[i] == 0) {

			continue;
		}
		for(int j = 0; j < 8; ++j) {

			int index = i + dir[j];
			if(index < 0) {

				index += size.x * size.y;
			}
			else if(index > size.x * size.y - 1) {

				index -= size.x * size.y;
			}
			++neighbors[index];
		}
	}
}
void GOL::checkBoard() {

	for(unsigned int i = 0; i < size.x * size.y; ++i) {

		//If on && neighbors != 2 || 3 -> off
		//If off && neighbors == 3 -> on

		if(board[i] == 0 && neighbors[i] == 3) {

			board[i] = 1;
		}
		else if(board[i] == 1 && (neighbors[i] < 2 || neighbors[i] > 3)) {

			board[i] = 0;
		}
		sf::Color color = board[i] == 1 ? sf::Color::Black : sf::Color::White;

		unsigned int x = i % size.x;
		unsigned int y = floor(i / size.x);

		sf::Vector2u pos = sf::Vector2u(x, y);

		images->setPixel(pos, color);
		neighbors[i] = 0;
	}
	images->updateTexture();
}
void GOL::update() {

	checkNeighbors();
	checkBoard();
}
sf::Sprite GOL::getSprite() {

	return images->getSprite();
}
