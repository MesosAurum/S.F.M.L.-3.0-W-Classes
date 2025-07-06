#pragma once
#include <SFML/Graphics.hpp>

class Times {

private:

	sf::Clock clock;
	float deltaTime;

public:

	Times();
	~Times();

	//To be placed at the start of update loops
	//Will set dt (delta time) as the time elapsed since last function call
	//dt is in seconds
	void nextDeltaTime();
	float getDeltaTime() const;
	//Returns time since epoch
	int getDtEpoch();
};
