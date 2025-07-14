#pragma once
#include <iostream>
#include <string.h>

#include <SFML/Graphics.hpp>

class Textures : public sf::Texture {

private:

	sf::Vector2u frameSize;
	void initTexture(std::string address);

	sf::Vector2i texCoord;

	float frameTimer;
	float frameTimerMax;

	void initTimers();

public:

	Textures(std::string address, sf::Vector2u size);
	~Textures();

	void frameRight();
	void frameLeft();

	float getFrameTimer() const;
	void setFrameTimer(float frame_time);

	float getFrameTimerMax() const;
	void setFrameTimerMax(float frame_time);

	void changeAnimation(unsigned int animation_number);

	sf::Vector2i getTexCoord() const;
	void setTexCoord(sf::Vector2i coord);

	sf::Vector2u getFrameSize() const;
};
