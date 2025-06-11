#pragma once
#include "Entity.h"

class Pellets {

private:

	const float pi = 3.141593f;

	std::vector<Entity *> pellets;

	float pelletTimer;
	float pelletTimerMax;
	float baseVelocity;
	unsigned int maxPellets;

	void outOfBounds(unsigned int index, sf::Vector2f window_size);

public:

	Pellets();
	~Pellets();

	void firePellet(float angle, sf::Vector2f position);
	std::vector<Entity *> &getPellets();

	void update(float dt, sf::Vector2f window_size);
	void render(sf::RenderWindow &window);
};
