#pragma once
#include "Textures.h"

class Sprites : public sf::Sprite {

private:
	
	sf::Texture tempTex;

public:

	Textures *textures;

	Sprites(std::string sprite_address = "", sf::Vector2u sprite_size = { 16, 16 });
	~Sprites();
	
	void animate(float dt = 0.016667);
};
