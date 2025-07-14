#include "Entity.h"

Entity::Entity(std::string address, sf::Vector2u size) : texSize(size) {

	this->setRadii(sf::Vector2f(size));

	vertArray.setPrimitiveType(sf::PrimitiveType::TriangleStrip);
	vertArray.resize(4);

	this->setMomentOfInertia(sf::Vector2f(size));

	shiftAnimation({ 0.0f, 0.0f });

	this->setOrigin(texSize / 2.0f);

	resizeArray();

	textures = new Textures(address, size);
}
Entity::~Entity() {

	delete textures;
}
void Entity::animate(float dt) {

	this->textures->setFrameTimer(this->textures->getFrameTimer() - dt);
	if(this->textures->getFrameTimer() <= 0.0f) {

		this->textures->frameRight();
		sf::Vector2i texCoord = this->textures->getTexCoord();

		shiftAnimation(sf::Vector2f(texCoord));

		this->textures->setFrameTimer(this->textures->getFrameTimerMax());
	}
}
void Entity::shiftAnimation(sf::Vector2f shift) {

	float cx = shift.x + texSize.x;
	float cy = shift.y + texSize.y;

	vertArray[0].texCoords = { shift.x, shift.y };
	vertArray[1].texCoords = { shift.x, cy };
	vertArray[2].texCoords = { cx, shift.y };
	vertArray[3].texCoords = { cx, cy };
}
sf::Color Entity::getColor() {

	return vertArray[0].color;
}
void Entity::setColor(sf::Color color) {

	for(int i = 0; i < 4; ++i) {

		vertArray[i].color = color;
	}
}
void Entity::setFrameTimerMax(float time) {

	this->textures->setFrameTimerMax(time);
}
sf::Vector2f Entity::getOrigin() const {

	return this->origin;
}
void Entity::setOrigin(sf::Vector2f origin) {

	this->origin = origin;
	resizeArray();
}
void Entity::resizeArray() {

	float x = -this->getOrigin().x;
	float y = -this->getOrigin().y;
	float w = texSize.x;
	float h = texSize.y;

	vertArray[0].position = { x, y };
	vertArray[1].position = { x , y + h };
	vertArray[2].position = { x + w, y };
	vertArray[3].position = { x + w, y + h };
}
sf::FloatRect Entity::getLocalBounds() {

	return vertArray.getBounds();
}
sf::FloatRect Entity::getGlobalBounds() {

	sf::FloatRect globalBounds = getLocalBounds();
	globalBounds.position = this->getPosition() + this->getOrigin();
	return globalBounds;
}
sf::Vector2f Entity::getTextureSize() const {

	return texSize;
}
void Entity::updateEntity(float dt, sf::Vector2f window_size) {

	update(dt, window_size);
}
void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const{

	states.transform *= getTransform();
	states.texture = &*textures;
	target.draw(vertArray, states);
}
