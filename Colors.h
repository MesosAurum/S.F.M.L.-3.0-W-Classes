#pragma once
#include <SFML/Graphics.hpp>

class Colors : sf::Color {

private:
public:

	Colors() {
	}
	~Colors() {
	}

	//Hue 0 - 360
	//Saturation 0 - 1
	//Value 0 - 1
	sf::Color HSVToRGB(float h, float s, float v) {

		float hPrime = h / 60.0f;
		unsigned int hIndex = unsigned int(hPrime) % 6;

		float chroma = s * v;
		float min = v - chroma;
		float x = chroma * (1.0f - abs(fmod(hPrime, 2.0f) - 1.0f));

		float outRGB[6][3] = {

			{chroma,x,0.0f},
			{x,chroma,0.0f},
			{0.0f,chroma,x},
			{0.0f,x,chroma},
			{x,0.0f,chroma},
			{chroma,0.0f,x}
		};
		float rF = outRGB[hIndex][0] + min;
		float gF = outRGB[hIndex][1] + min;
		float bF = outRGB[hIndex][2] + min;
		rF *= 255.0f;
		gF *= 255.0f;
		bF *= 255.0f;

		std::uint8_t rI = std::uint8_t(rF);
		std::uint8_t gI = std::uint8_t(gF);
		std::uint8_t bI = std::uint8_t(bF);

		return sf::Color(rI, gI, bI);
	}
};
