#include "Images.h"

void Images::initTexture() {

	texture = new sf::Texture(this->getSize());
}
void Images::initSprite() {

	sprite = new sf::Sprite(*texture);
}
Images::Images(sf::Vector2u image_size) {

	this->resize(image_size);
	initTexture();
	initSprite();
}
Images::~Images() {

	delete texture;
	delete sprite;
}
void Images::updateTexture() {

	texture->update(*this);
}
sf::Sprite Images::getSprite() {

	return *sprite;
}
