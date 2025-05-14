#pragma once
#include "Entity.h"

class Ship : public Entity {

private:

	const float halfPi = 1.5707963f;

	float thrustAmount;
	float turnAmount;

	void initVariables();
	void moveShip(float dt);

public:

	Ship();
	~Ship();

	void update(float dt, sf::Vector2f window_size);
	void render(sf::RenderWindow &window);
};
