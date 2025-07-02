#pragma once
#include "Sprites.h"
#include "Randomize.h"

class Stars {

private:

	std::vector<Sprites *> stars;
	Randomize *randomize;

	unsigned int numStars;

	void initRandomize();
	void initStars(sf::Vector2f window_size);

public:

	Stars(sf::Vector2f window_size = {640.0f, 360.0f});
	~Stars();
	void update(float dt);
	void render(sf::RenderWindow &window);
};
