#pragma once
#include <SFML/Graphics.hpp>

class Times {

private:

	sf::Clock clock;
	float deltaTime;

public:

	Times();
	~Times();

	void nextDeltaTime();
	float getDeltaTime() const;
	int getDtEpoch();
};
