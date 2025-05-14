#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Physics {

private:

	sf::Vector2f gravity;

	float mass;
	sf::Vector2f radii;

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f force;

	float rotation;
	float angVelocity;
	float angAcceleration;
	float torque;
	float momentIntertia;

	float friction;
	float angFriction;

	bool hasGravity;
	bool looping;

	void initVariables();

public:

	Physics();
	~Physics();

	void setMass(float mass);

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f position);

	void setVelocity(sf::Vector2f velocity);

	void addForce(sf::Vector2f force);

	float getRotation() const;
	void setRotation(float theta);
	void addRotation(float theta);

	float getAngVelocity() const;
	void setAngVelocity(float angular_velocity);

	void addTorque(float torque);

	void setMomentOfIntertia(sf::Vector2f size);

	sf::Vector2f getRadii() const;
	void setRadii(sf::Vector2f radii);

	void setFriction(float friction);
	void setAngFriction(float angular_friction);

	void setHasGravity(bool has_gravity);
	void setHasLooping(bool looping);

	void loop(sf::Vector2f window_size);
	void update(float dt, sf::Vector2f window_size);
};
