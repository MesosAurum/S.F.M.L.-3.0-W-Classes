#include "Texts.h"

void Texts::initFont(std::string font_address) {

	fonts = new Fonts(font_address);
	this->setFont(*fonts);
}
void Texts::initString(std::string str) {

	orignalStr = str;
	this->setString(orignalStr);
}
Texts::Texts(std::string str, std::string font_address) : sf::Text(*fonts) {

	initFont(font_address);
	initString(str);
}
Texts::~Texts() {

	delete fonts;
}
void Texts::streamText(std::string str, float var) {

	//Time: 1.2345
	std::stringstream sStream;
	sStream << str << var;

	this->setString(sStream.str());
}
