#pragma once
#include "Times.h"
#include "Texts.h"
#include "Ship.h"

class SpaceRocks {

private:

	Times times;
	Texts *scoreText;

	Ship ship;

	float dt;
	std::uint16_t score;

	void initScoreText(sf::Vector2f window_size);

	void initShip(sf::Vector2f window_size);

public:

	SpaceRocks(sf::Vector2f window_size);
	~SpaceRocks();

	void update(sf::Vector2f window_size);
	void render(sf::RenderWindow &window);
};
