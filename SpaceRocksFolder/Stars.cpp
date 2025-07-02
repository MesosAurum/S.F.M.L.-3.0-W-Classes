#include "Stars.h"

void Stars::initRandomize() {

	randomize = new Randomize();
}
void Stars::initStars(sf::Vector2f window_size) {

	numStars = 50;
	for(unsigned int i = 0; i < numStars; ++i) {

		stars.push_back(new Sprites("Sprites/stars.png", { 8, 8 }));

		randomize->randomizeFloat(0.0f, window_size.x);
		float x = randomize->randomF();
		randomize->randomizeFloat(0.0f, window_size.y);
		float y = randomize->randomF();

		stars.at(i)->setPosition({x,y});

		randomize->randomizeFloat(0.7f, 2.3f);
		randomize->randomizeInt(0, 6);

		stars.at(i)->textures->setFrameTimerMax(randomize->randomF());
		for(int j = 0; j < randomize->randomI(); ++j) {

			stars.at(i)->animate(randomize->randomF());
		}
	}
}
Stars::Stars(sf::Vector2f window_size) {

	initRandomize();
	initStars(window_size);
}
Stars::~Stars() {

	for(int i = stars.size() - 1; i >= 0; --i) {

		delete stars.at(i);
		stars.erase(stars.begin() + i);
	}
}
void Stars::update(float dt) {

	for(int i = 0; i < stars.size(); ++i) {

		stars.at(i)->animate(dt);
	}
}
void Stars::render(sf::RenderWindow &window) {

	for(int i = 0; i < stars.size(); ++i) {

		window.draw(*stars.at(i));
	}
}
