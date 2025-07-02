#include "SpaceRocks.h"

void SpaceRocks::initScoreText(sf::Vector2f window_size) {

	scoreText = new Texts("Score: ", "Fonts/arial.ttf");
	scoreText->setCharacterSize(window_size.x / 32.0f);
	scoreText->setOrigin(scoreText->getLocalBounds().size / 2.0f);
	scoreText->setPosition({ window_size.x / 10.0f, window_size.y / 25.0f });
}
void SpaceRocks::initEndText(sf::Vector2f window_size) {

	endText = new Texts("Game Over: ", "Fonts/arial.ttf");
	endText->setCharacterSize(window_size.x / 32.0f);
	endText->setOrigin(scoreText->getLocalBounds().size / 2.0f);
	endText->setPosition(window_size / 2.0f);
}
void SpaceRocks::initStars(sf::Vector2f window_size) {

	stars = new Stars(window_size);
}
void SpaceRocks::initShip(sf::Vector2f window_size) {

	ship.setPosition(window_size / 2.0f);
}
void SpaceRocks::initHealth() {

	health = 100;
}
void SpaceRocks::initHealthbar(sf::Vector2f window_size) {

	healthbar = new HealthBar(health, window_size);
}
SpaceRocks::SpaceRocks(sf::Vector2f window_size) {

	dt = 0.0f;
	initScoreText(window_size);
	initEndText(window_size);

	initStars(window_size);
	initHealth();
	initHealthbar(window_size);
	initShip(window_size);
}
SpaceRocks::~SpaceRocks() {

	delete scoreText;
	delete endText;
	delete healthbar;
	delete stars;
}
void SpaceRocks::update(sf::Vector2f window_size) {

	times.nextDeltaTime();
	dt = times.getDeltaTime();

	if(health > 0) {

		stars->update(dt);
		ship.update(dt, window_size);
		pellets.firePellet(ship.getRotation(), ship.getPosition());
		pellets.update(dt, window_size);
		rocks.update(dt, window_size, ship, pellets, score, health);
		healthbar->updateHealth(health);
	}
	scoreText->streamText("Score: ", score);
}
void SpaceRocks::render(sf::RenderWindow &window) {

	stars->render(window);
	window.draw(*scoreText);
	pellets.render(window);
	ship.render(window);
	rocks.render(window);
	healthbar->render(window);
	if(health <= 0) {

		window.draw(*endText);
	}
}
