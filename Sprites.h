#pragma once
#include "Textures.h"

class Sprites : public sf::Sprite {

private:

	Textures *textures;
	sf::Texture tempTex;

	sf::Vector2i texCoord;

	float frameTimer;
	float frameTimerMax;

	void initTimers();

public:

	Sprites(std::string sprite_address = "", sf::Vector2u sprite_size = { 16, 16 });
	~Sprites();

	void frameRight();
	void frameLeft();
	void animate(float dt = 0.016667);

	void setFrameTimer(float frame_time);
};
