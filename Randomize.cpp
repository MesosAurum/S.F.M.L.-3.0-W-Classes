#include "Randomize.h"

void Randomize::initRandomEngine() {

	randomEngine.seed(times.getDtEpoch());
}
Randomize::Randomize() {

	initRandomEngine();
}
Randomize::~Randomize() {
}
void Randomize::randomizeInt(int min, int max) {

	randomInt = std::uniform_int_distribution<int>(min, max);
}
void Randomize::randomizeFloat(float min, float max) {

	randomFloat = std::uniform_real_distribution<float>(min, max);
}
int Randomize::randomI() {

	return randomInt(randomEngine);
}
float Randomize::randomF() {

	return randomFloat(randomEngine);
}
