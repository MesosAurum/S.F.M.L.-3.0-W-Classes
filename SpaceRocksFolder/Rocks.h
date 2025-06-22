#pragma once
#include "Randomize.h"
#include "Colors.h"
#include "Entity.h"

class Rocks {

private:

	std::vector<Entity *> rocks;

	Randomize *randomize;
	Colors *colors;

	unsigned int maxRocks;
	float rockTimer;
	float rockTimerMax;
	float baseVelocity;

	sf::Vector2u textureSize;

	void initVariables();
	void initRandomize();
	void initColors();
	void spawnRock(sf::Vector2f pos, sf::Vector2f rock_size, sf::Vector2f window_size);
	void deleteRock(unsigned int index);

public:

	Rocks();
	~Rocks();

	void update(float dt, sf::Vector2f window_size, Entity &ship, Pellets &pellets, std::uint16_t &score, int &health);
	void render(sf::RenderWindow &window);
};
