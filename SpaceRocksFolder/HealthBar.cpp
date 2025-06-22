#include "HealthBar.h"

void HealthBar::initBackground() {

	background.setFillColor({ 255,0,0,128 });
	background.setSize(this->getSize());
	background.setOrigin(this->getGeometricCenter());
	background.setPosition(this->getPosition());
}
HealthBar::HealthBar(int health, sf::Vector2f window_size) {

	healthSize.x = window_size.x / 640.0f;
	healthSize.y = window_size.y / 20.0f;

	this->setFillColor(sf::Color::Red);
	this->setSize({ float(health), healthSize.y });
	this->setOrigin(this->getGeometricCenter());
	this->setPosition({ window_size.x / 2.0f, healthSize.y });

	initBackground();
}
HealthBar::~HealthBar() {
}
void HealthBar::updateHealth(int health) {

	this->setSize({ float(health) * healthSize.x, healthSize.y });

	if(this->getSize().x < 0.0f) {

		this->setSize({ 0,0 });
	}
}
void HealthBar::render(sf::RenderWindow &window) {

	window.draw(background);
	window.draw(*this);
}
