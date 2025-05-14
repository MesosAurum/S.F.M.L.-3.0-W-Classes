#include "Entity.h"

void Entity::tranlateEntity() {

	float x = getPosition().x;
	float y = getPosition().y;
	float w = entitySize.x;
	float h = entitySize.y;

	vertArray[0].position = { x - origin.x, y - origin.y };
	vertArray[1].position = { x - origin.x , y + h - origin.y };
	vertArray[2].position = { x + w - origin.x, y - origin.y };
	vertArray[3].position = { x + w - origin.x, y + h - origin.y };
}
void Entity::rotate() {

	float theta = getRotation();
	float c = cos(theta);
	float s = sin(theta);
	float cx = getPosition().x;
	float cy = getPosition().y;
	for(int i = 0; i < 4; ++i) {

		float px = vertArray[i].position.x;
		float py = vertArray[i].position.y;

		px -= cx;
		py -= cy;

		float xNew = px * c - py * s + cx;
		float yNew = px * s + py * c + cy;

		vertArray[i].position = { xNew , yNew };
	}
}
Entity::Entity(std::string address, sf::Vector2u size) : entitySize(size) {

	texSize = entitySize;

	setRadii(sf::Vector2f(size));

	vertArray.setPrimitiveType(sf::PrimitiveType::TriangleStrip);
	vertArray.resize(4);

	tranlateEntity();

	setMomentOfIntertia(sf::Vector2f(size));

	shiftAnimation({ 0.0f, 0.0f });

	textures = new Textures(address, size);
}
Entity::~Entity() {

	delete textures;
}
void Entity::animate(float dt) {

	textures->setFrameTimer(textures->getFrameTimer() - dt);
	if(textures->getFrameTimer() <= 0.0f) {

		textures->frameRight();
		sf::Vector2i texCoord = this->textures->getTexCoord();

		shiftAnimation(sf::Vector2f(texCoord));

		textures->setFrameTimer(textures->getFrameTimerMax());
	}
}
void Entity::shiftAnimation(sf::Vector2f shift) {

	float cx = shift.x + texSize.x;
	float cy = shift.y + texSize.y;

	vertArray[0].texCoords = { shift.x , shift.y };
	vertArray[1].texCoords = { shift.x,cy };
	vertArray[2].texCoords = { cx , shift.y };
	vertArray[3].texCoords = { cx,cy };
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

	textures->setFrameTimerMax(time);
}
sf::Vector2f Entity::getEntitySize() const {

	return entitySize;
}
void Entity::setEntitySize(sf::Vector2f size) {

	entitySize = size;
}
sf::Vector2f Entity::getOrigin() {

	return origin;
}
void Entity::setOrigin(sf::Vector2f origin) {

	this->origin = origin;
}
sf::FloatRect Entity::getLocalBounds() {

	return vertArray.getBounds();
}
sf::FloatRect Entity::getGlobaBounds() {

	sf::FloatRect globalBounds = getLocalBounds();
	globalBounds.position = { 0,0 };
	return globalBounds;
}
void Entity::updateEntity(float dt, sf::Vector2f window_size) {

	tranlateEntity();
	rotate();
	update(dt, window_size);
}
void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const{

	states.texture = &*textures;
	target.draw(vertArray, states);
}
