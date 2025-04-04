#include "Textures.h"

void Textures::initTexture(std::string address) {

	if(!this->loadFromFile(address)) {

		std::cerr << "ERROR::TEXTURES::INITTEXTURE::COULD NOT LOAD FILE" << address << std::endl;
	}
}
Textures::Textures(std::string address, sf::Vector2u size) {

	this->frameSize = size;
	initTexture(address);
}
Textures::~Textures() {
}
sf::Vector2u Textures::getFrameSize() const {

	return frameSize;
}
