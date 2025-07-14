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

	float nextX = texCoord.x + this->getFrameSize().x;
	this->texCoord.x = fmod(nextX, this->getSize().x);
}
void Textures::frameLeft() {

	float nextX = texCoord.x - this->getFrameSize().x;
	this->texCoord.x = fmod(nextX, frameSize.x + this->getSize().x);
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
void Textures::changeAnimation(unsigned int animation_number) {

	sf::Vector2i coordinate;
	coordinate.x = 0.0f;
	coordinate.y = animation_number * this->getFrameSize().y;

	texCoord = coordinate;
}
sf::Vector2i Textures::getTexCoord() const {

	return texCoord;
}
void Textures::setTexCoord(sf::Vector2i coord) {

	texCoord = coord;
}
sf::Vector2u Textures::getFrameSize() const {

	return frameSize;
}
