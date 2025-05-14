#include "Physics.h"

void Physics::initVariables() {

	gravity = { 0.0f, 9.80665f };
	mass = 1.0f;
	position = { 0.0f,0.0f };
	velocity = { 0.0f,0.0f };
	force = { 0.0f,0.0f };
	angVelocity = 0.0f;
	angAcceleration = 0.0f;
	torque = 0.0f;
	friction = 1.0f;
	angFriction = 1.0f;
	radii = { 1.0f,1.0f };
	momentIntertia = 0.166667f;
	hasGravity = false;
	looping = false;
}
Physics::Physics() {

	initVariables();
}
Physics::~Physics() {
}
void Physics::setMass(float mass) {

	this->mass = mass;
}
sf::Vector2f Physics::getPosition() const {

	return position;
}
void Physics::setPosition(sf::Vector2f position) {

	this->position = position;
}
void Physics::setVelocity(sf::Vector2f velocity) {

	this->velocity = velocity;
}
void Physics::addForce(sf::Vector2f force) {

	this->force += force;
}
float Physics::getRotation() const {

	return rotation;
}
void Physics::setRotation(float theta) {

	rotation = theta;
}
void Physics::addRotation(float theta) {

	rotation += theta;
}
float Physics::getAngVelocity() const {

	return angVelocity;
}
void Physics::setAngVelocity(float angular_velocity) {

	angVelocity = angular_velocity;
}
void Physics::addTorque(float torque) {

	this->torque += torque;
}
void Physics::setMomentOfIntertia(sf::Vector2f size) {

	momentIntertia = mass * (size.x * size.x + size.y * size.y) / 12.0f;
}
sf::Vector2f Physics::getRadii() const {

	return radii;
}
void Physics::setRadii(sf::Vector2f radii) {

	this->radii = radii;
}
void Physics::setFriction(float friction) {

	this->friction = abs(1.0 - friction);
}
void Physics::setAngFriction(float angular_friction) {

	angFriction = abs(1.0 - angular_friction);
}
void Physics::setHasGravity(bool has_gravity) {

	hasGravity = has_gravity;
}
void Physics::setHasLooping(bool looping) {

	this->looping = looping;
}
void Physics::loop(sf::Vector2f window_size) {

	sf::Vector2f diameter = radii * 2.0f;
	sf::Vector2f nextPos = this->getPosition();
	float cx = window_size.x + diameter.x;
	float cy = window_size.y + diameter.y;

	if(nextPos.x < -diameter.x) {

		nextPos.x = cx;
	}
	if(nextPos.x > cx) {

		nextPos.x - diameter.x;
	}
	if(nextPos.y < -diameter.y) {

		nextPos.y = cy;
	}
	if(nextPos.y > cy) {

		nextPos.y = -diameter.y;
	}
	setPosition(nextPos);
}
void Physics::update(float dt, sf::Vector2f window_size) {

	float smallNum = 1.0E-12;

	if(looping) {

		loop(window_size);
	}
	if(abs(force.x) > smallNum || abs(force.y) > smallNum) {

		force *= friction;
		if(hasGravity) {

			force += mass * gravity;
		}
		acceleration = force / mass;
	}
	if(abs(acceleration.x) > smallNum || abs(acceleration.y) > smallNum) {

		acceleration *= friction;
		velocity += acceleration * dt;
	}
	if(abs(velocity.x) > smallNum || abs(velocity.y) > smallNum) {

		velocity *= friction;
		setPosition(getPosition() + velocity * dt);
	}
	if(abs(torque) > smallNum){

		torque *= angFriction;
		angAcceleration = (torque / momentIntertia);
	}
	if(abs(angAcceleration) > smallNum) {

		angAcceleration *= angFriction;
		angVelocity += angAcceleration * dt;
	}
	if(abs(angVelocity) > smallNum) {

		angVelocity *= angFriction;
		setRotation(getRotation() + angVelocity * dt);
	}
}
