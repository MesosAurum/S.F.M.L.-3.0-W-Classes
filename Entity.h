#pragma once
#include <string.h>
#include "Textures.h"
#include "Physics.h"

class Entity : public sf::Drawable, public Physics {

private:

	Textures *textures;

	sf::VertexArray vertArray;

	sf::Vector2f origin;
	sf::Vector2f texSize;

public:

	explicit Entity(std::string address, sf::Vector2u size);
	~Entity();

	void animate(float dt);
	void shiftAnimation(sf::Vector2f shift);

	sf::Color getColor();
	void setColor(sf::Color color);

	void setFrameTimerMax(float time);

	sf::Vector2f getOrigin() const;
	void setOrigin(sf::Vector2f origin);

	void resizeArray();

	sf::FloatRect getLocalBounds();
	sf::FloatRect getGlobalBounds();

	sf::Vector2f getTextureSize() const;

	void updateEntity(float dt, sf::Vector2f window_size);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
