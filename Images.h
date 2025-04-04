#pragma once
#include <SFML/Graphics.hpp>

class Images : public sf::Image {

private:

	sf::Texture *texture;
	sf::Sprite *sprite;

	void initTexture();
	void initSprite();

public:

	Images(sf::Vector2u image_size);
	~Images();

	void updateTexture();
	sf::Sprite getSprite();
};
