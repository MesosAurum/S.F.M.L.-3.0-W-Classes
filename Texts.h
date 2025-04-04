#pragma once
#include <sstream>
#include "Fonts.h"

class Texts : public sf::Text {

private:

	std::string orignalStr;
	Fonts *fonts;

	void initFont(std::string font_address);
	void initString(std::string str);

public:

	Texts(std::string str, std::string font_address);
	~Texts();

	void streamText(std::string str = "", float var = 0.0f);
};
