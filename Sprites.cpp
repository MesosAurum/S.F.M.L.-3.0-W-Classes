#include "Sprites.h"

void Sprites::initTimers() {

	frameTimer = 0.0f;
	frameTimerMax = 0.0f;
}
Sprites::Sprites(std::string sprite_address, sf::Vector2u sprite_size) : sf::Sprite(tempTex) {

	initTimers();

	texCoord = { 0,0 };

	textures = new Textures(sprite_address, sprite_size);
	this->setTexture(*textures);
	this->setOrigin({ sprite_size.x / 2.0f, sprite_size.y / 2.0f });
	this->setTextureRect({ texCoord, sf::Vector2i(sprite_size) });
}
Sprites::~Sprites() {

	delete textures;
}
void Sprites::frameRight() {

	this->texCoord.x += textures->getFrameSize().x;
	if(this->texCoord.x >= textures->getSize().x) {

		this->texCoord.x = 0;
	}
}
void Sprites::frameLeft() {

	this->texCoord.x -= textures->getFrameSize().x;
	if(this->texCoord.x < 0) {

		this->texCoord.x = textures->getSize().x - textures->getFrameSize().x;
	}
}
void Sprites::animate(float dt) {

	frameTimer += dt;
	if(frameTimer >= frameTimerMax) {

		frameRight();
		this->setTextureRect(sf::IntRect(texCoord, sf::Vector2i(textures->getFrameSize())));

		frameTimer = 0.0f;
	}
}
void Sprites::setFrameTimer(float frame_time) {

	frameTimerMax = frame_time;
}
