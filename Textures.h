#pragma once
#include <iostream>
#include <string.h>

#include <SFML/Graphics.hpp>

class Textures : public sf::Texture {

private:

	sf::Vector2u frameSize;
	void initTexture(std::string address);

public:

	Textures(std::string address, sf::Vector2u size);
	~Textures();
	sf::Vector2u getFrameSize() const;
};
