#include "Textures.h"

void Textures::initTexture(std::string address) {

	if(!this->loadFromFile(address)) {

		std::cerr << "ERROR::TEXTURES::INITTEXTURE::COULD NOT LOAD FILE" << address << std::endl;
	}
}
void Textures::initTimers() {

	frameTimer = 0.0f;
	frameTimerMax = 0.0f;
}
Textures::Textures(std::string address, sf::Vector2u size) {

	initTimers();

	texCoord = { 0,0 };

	this->frameSize = size;
	initTexture(address);
}
Textures::~Textures() {
}
void Textures::frameRight() {

	this->texCoord.x += this->getFrameSize().x;
	if(this->texCoord.x >= this->getSize().x) {

		this->texCoord.x = 0;
	}
}
void Textures::frameLeft() {

	this->texCoord.x -= this->getFrameSize().x;
	if(this->texCoord.x < 0) {

		this->texCoord.x = this->getSize().x - this->getFrameSize().x;
	}
}
float Textures::getFrameTimer() const {

	return frameTimer;
}
void Textures::setFrameTimer(float frame_time) {

	frameTimer = frame_time;
}
float Textures::getFrameTimerMax() const {

	return frameTimerMax;
}
void Textures::setFrameTimerMax(float frame_time) {

	frameTimerMax = frame_time;
}
sf::Vector2i Textures::getTexCoord() const {

	return texCoord;
}
sf::Vector2u Textures::getFrameSize() const {

	return frameSize;
}
