#include "Ship.h"

void Ship::initVariables() {

	this->setFriction(0.05f);
	this->setAngFriction(0.125f);
	this->setHasLooping(true);
	this->setFrameTimerMax(0.0f);
	this->setOrigin(this->getEntitySize() / 2.0f);

	thrustAmount = 12.0f;
	turnAmount = 360.0f;
}
void Ship::moveShip(float dt) {

	bool aPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A);
	bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W);
	bool dPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D);

	if(aPressed || dPressed || wPressed) {

		float torque = turnAmount * (dPressed - aPressed);
		this->addTorque(torque);

		float r = this->getRotation() - halfPi;
		sf::Vector2f dir = { cos(r), sin(r) };
		dir *= float(wPressed);
		this->addForce(dir * thrustAmount);
		this->animate(dt);
		return;
	}
	this->shiftAnimation({ 0.0f, 0.0f });
}
Ship::Ship() : Entity("Sprites/ship.png", {32, 32}) {

	initVariables();
}
Ship::~Ship() {}
void Ship::update(float dt, sf::Vector2f window_size) {

	moveShip(dt);
	this->updateEntity(dt, window_size);
}
void Ship::render(sf::RenderWindow &window) {

	window.draw(*this);
}
