#pragma once
#include <SFML/Graphics.hpp>

class HealthBar : public sf::RectangleShape {

private:

	sf::Vector2f healthSize;
	sf::RectangleShape background;

	void initBackground();

public:

	HealthBar(int health, sf::Vector2f window_size = { 640.0f, 360.0f });
	~HealthBar();

	void updateHealth(int health);
	void render(sf::RenderWindow &window);

};
