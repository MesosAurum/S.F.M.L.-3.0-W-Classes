#pragma once
#include <string.h>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GOL.h"
#include "SpaceRocks.h"

class Game {

private:

	sf::Vector2f windowSize;
	std::string title;
	sf::VideoMode vm;
	sf::RenderWindow *window;

	GOL *gol;
	SpaceRocks *spaceRocks;

	void initWindow();
	void initGOL();
	void initSpaceRocks();

	void pollEvents();

	void updating();
	void rendering();

public:

	Game();
	~Game();

	void running();
};
