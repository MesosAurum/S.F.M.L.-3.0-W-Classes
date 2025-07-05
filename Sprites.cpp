#include "Sprites.h"

Sprites::Sprites(std::string sprite_address, sf::Vector2u sprite_size) : sf::Sprite(tempTex) {

	textures = new Textures(sprite_address, sprite_size);
	this->setTexture(*textures);
	this->setOrigin({ sprite_size.x / 2.0f, sprite_size.y / 2.0f });
	this->setTextureRect({ {0, 0}, sf::Vector2i(sprite_size) });
}
Sprites::~Sprites() {

	delete textures;
}
void Sprites::animate(float dt) {

	textures->setFrameTimer(textures->getFrameTimer() - dt);
	if(textures->getFrameTimer() <= 0.0f) {

		textures->frameRight();
		this->setTextureRect(sf::IntRect(this->textures->getTexCoord(), sf::Vector2i(this->textures->getFrameSize())));

		textures->setFrameTimer(textures->getFrameTimerMax());
	}
}
