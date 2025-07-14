#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Physics : public sf::Transformable {

private:

	sf::Vector2f gravity;

	float mass;
	sf::Vector2f radii;

	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f force;

	float angVelocity;
	float angAcceleration;
	float torque;
	float momentInertia;

	float friction;
	float angFriction;

	bool hasGravity;
	bool looping;

	void initVariables();

public:

	Physics();
	~Physics();

	void setMass(float mass);

	void setVelocity(sf::Vector2f velocity);

	void addForce(sf::Vector2f force);

	float getAngVelocity() const;
	void setAngVelocity(float angular_velocity);

	void addTorque(float torque);

	void setMomentOfInertia(sf::Vector2f size);

	sf::Vector2f getRadii() const;
	void setRadii(sf::Vector2f radii);

	void setFriction(float friction);
	void setAngFriction(float angular_friction);

	void setHasGravity(bool has_gravity);
	void setHasLooping(bool looping);

	void loop(sf::Vector2f window_size);
	void update(float dt, sf::Vector2f window_size);
};
