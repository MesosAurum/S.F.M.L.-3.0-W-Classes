#include "Times.h"

Times::Times() {

	nextDeltaTime();
}
Times::~Times() {
}
void Times::nextDeltaTime() {

	deltaTime = clock.restart().asSeconds();
}
float Times::getDeltaTime() const {

	return deltaTime;
}
int Times::getDtEpoch() {

	return std::chrono::steady_clock::now().time_since_epoch().count();
}
