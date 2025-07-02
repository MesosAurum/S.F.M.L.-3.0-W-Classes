#include "Rocks.h"

void Rocks::initVariables() {

	maxRocks = 15;
	rockTimerMax = 2.5f;
	rockTimer = rockTimerMax;
	baseVelocity = 60.0f;
	textureSize = { 27,27 };
}
void Rocks::initRandomize() {

	randomize = new Randomize();
}
void Rocks::initColors() {

	colors = new Colors();
}
void Rocks::spawnRock(sf::Vector2f pos, sf::Vector2f rock_size, sf::Vector2f window_size) {

	rocks.push_back(new Entity("Sprites/meteoroid.png", textureSize));

	unsigned int index = rocks.size() - 1;

	rocks.at(index)->setEntitySize(rock_size);
	rocks.at(index)->setOrigin(rocks.at(index)->getEntitySize() / 2.0f);

	rocks.at(index)->setPosition(pos);

	randomize->randomizeFloat(0.0f, 360.0f);
	float h = randomize->randomF();
	float s = randomize->randomF() / 360.0f;
	float v = randomize->randomF() / 360.0f;
	rocks.at(index)->setColor(colors->HSVToRGB(h, s, v));

	randomize->randomizeFloat(-1.0f, 1.0f);
	float x = randomize->randomF();
	float y = randomize->randomF();
	sf::Vector2f vel = { x,y };
	vel *= baseVelocity;
	rocks.at(index)->setVelocity(vel);
	rocks.at(index)->setAngVelocity(randomize->randomF());

	rocks.at(index)->setHasLooping(true);
}
void Rocks::deleteRock(unsigned int index) {

	delete rocks.at(index);
	rocks.erase(rocks.begin() + index);
}
Rocks::Rocks() {

	initVariables();
	initRandomize();
	initColors();
}
Rocks::~Rocks() {

	delete randomize;
	delete colors;
	for(int i = rocks.size() - 1; i >= 0; --i) {

		deleteRock(i);
	}
}
void Rocks::update(float dt, sf::Vector2f window_size, Entity &ship, Pellets &pellets, std::uint16_t &score, int &health) {

	rockTimer -= dt;

	if(rockTimer <= 0.0f && rocks.size() < maxRocks) {

		sf::Vector2f pos;
		randomize->randomizeFloat(0.0f, window_size.x);

		pos.x = randomize->randomF();
		pos.y = -2.0f * float(textureSize.y);

		randomize->randomizeInt(0, 1);

		if(randomize->randomI()) {

			randomize->randomizeFloat(0.0f, window_size.y);

			pos.x = -2.0f * float(textureSize.x);
			pos.y = randomize->randomF();
		}
		spawnRock(pos, sf::Vector2f(textureSize), window_size);
		rockTimer = rockTimerMax;
	}
	for(int i = rocks.size() - 1; i >= 0; --i) {

		rocks.at(i)->updateEntity(dt, window_size);

		if(ship.getGlobalBounds().findIntersection(rocks.at(i)->getGlobalBounds())) {

			health -= rocks.at(i)->getEntitySize().x;
			deleteRock(i);
			break;
		}
		for(int j = pellets.getPellets().size() - 1; j >= 0; --j) {
		
			if(pellets.getPellets().at(j)->getGlobalBounds().findIntersection(rocks.at(i)->getGlobalBounds())) {
		
				score += 16;
		
				delete pellets.getPellets().at(j);
				pellets.getPellets().erase(pellets.getPellets().begin() + j);
		
				if(rocks.at(i)->getEntitySize().x < 10.0f) {
		
					deleteRock(i);
					break;
				}
				rocks.at(i)->setEntitySize(rocks.at(i)->getEntitySize() / 2.0f);
				spawnRock(rocks.at(i)->getPosition(), rocks.at(i)->getEntitySize(), window_size);
				rocks.at(rocks.size() - 1)->setColor(rocks.at(i)->getColor());
				rocks.at(rocks.size() - 1)->updateEntity(dt, window_size);
				break;
			}
		}
	}
}
void Rocks::render(sf::RenderWindow &window) {

	for(unsigned int i = 0; i < rocks.size(); ++i) {

		window.draw(*rocks.at(i));
	}
}
