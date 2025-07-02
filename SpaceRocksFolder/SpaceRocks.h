#pragma once
#include "Times.h"
#include "Texts.h"
#include "Ship.h"
#include "Pellets.h"
#include "Rocks.h"
#include "HealthBar.h"
#include "Stars.h"

class SpaceRocks {

private:

	Times times;
	Texts *scoreText;
	Texts *endText;

	Ship ship;
	Pellets pellets;
	Rocks rocks;
	HealthBar *healthbar;
	Stars *stars;

	float dt;
	std::uint16_t score;
	int health;

	void initScoreText(sf::Vector2f window_size);
	void initEndText(sf::Vector2f window_size);

	void initStars(sf::Vector2f window_size);
	void initShip(sf::Vector2f window_size);
	void initHealth();
	void initHealthbar(sf::Vector2f window_size);

public:

	SpaceRocks(sf::Vector2f window_size);
	~SpaceRocks();

	void update(sf::Vector2f window_size);
	void render(sf::RenderWindow &window);
};
