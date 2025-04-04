#pragma once
#include <string.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Times.h"
#include "Texts.h"
#include "Images.h"
#include "Randomize.h"
#include "GOL.h"
#include "Sprites.h"

class Game {

private:

	unsigned int width;
	unsigned int height;
	std::string title;
	sf::VideoMode vm;
	sf::RenderWindow *window;

	Times times;
	Texts *texts;
	Images *images;
	Randomize *randomize;
	GOL *gol;
	Sprites *sprites;

	void initWindow();
	void initTexts();
	void initImages();
	void initRandomize();
	void initGOL();
	void initSprites();

	void pollEvents();

	void updating();
	void rendering();

public:

	Game();
	~Game();

	void running();
};
