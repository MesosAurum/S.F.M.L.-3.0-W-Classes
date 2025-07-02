#include "Pellets.h"

void Pellets::outOfBounds(unsigned int index, sf::Vector2f window_size) {

	if((pellets.at(index)->getPosition().x < 0.0f) ||
	(pellets.at(index)->getPosition().x >= window_size.x) ||
	(pellets.at(index)->getPosition().y < 0.0f) || 
	(pellets.at(index)->getPosition().y >= window_size.y)) {

		delete pellets.at(index);
		pellets.erase(pellets.begin() + index);
	}
}
Pellets::Pellets() {

	pelletTimerMax = 0.3f;
	pelletTimer = pelletTimerMax;

	baseVelocity = 256.0f;

	maxPellets = 3;
}
Pellets::~Pellets() {

	for(int i = pellets.size() - 1; i >= 0; --i) {

		delete pellets.at(i);
		pellets.erase(pellets.begin() + i);
	}
}
void Pellets::firePellet(float angle, sf::Vector2f position) {

	if((pelletTimer < 0.0f) &&
		(pellets.size() < maxPellets) &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))) {

		angle -= pi / 2.0f;

		pellets.push_back(new Entity("Sprites/pellet.png", { 16,16 }));

		unsigned int index = pellets.size() - 1;
		sf::Vector2f direction = { cos(angle), sin(angle) };
		pellets.at(index)->setRotation(angle);
		pellets.at(index)->setVelocity(baseVelocity * direction);
		pellets.at(index)->setOrigin(pellets.at(index)->getEntitySize() / 2.0f);
		pellets.at(index)->setPosition(position);

		pelletTimer = pelletTimerMax;
	}
}
std::vector<Entity *> &Pellets::getPellets() {

	return pellets;
}
void Pellets::update(float dt, sf::Vector2f window_size) {

	pelletTimer -= dt;
	for(int i = pellets.size() - 1; i >= 0; --i) {

		pellets.at(i)->updateEntity(dt, window_size);
		pellets.at(i)->animate(dt);

		if(pellets.at(i) != NULL) {

			outOfBounds(i, window_size);
		}
	}
}
void Pellets::render(sf::RenderWindow &window) {

	for(unsigned int i = 0; i < pellets.size(); ++i) {

		window.draw(*pellets.at(i));
	}
}
