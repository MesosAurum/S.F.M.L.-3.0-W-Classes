#include "Game.h"

void Game::initWindow() {

	windowSize.x = 640.0f;
	windowSize.y = 360.0f;
	title = "SFML with classes";
	vm = sf::VideoMode(sf::Vector2u(windowSize));
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}
void Game::initGOL() {

	gol = new GOL(sf::Vector2u(windowSize));
}
void Game::initSpaceRocks() {

	spaceRocks = new SpaceRocks(windowSize);
}
void Game::pollEvents() {

	while(const std::optional event = window->pollEvent()) {

		if(event->is<sf::Event::Closed>()) {

			window->close();
		}
		else if(const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {

			if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {

				window->close();
			}
		}
	}
}
void Game::updating() {

	pollEvents();

	//gol->update();
	spaceRocks->update(windowSize);
}
void Game::rendering() {

	window->clear();

	//Draw here!!!
	//window->draw(gol->getSprite());
	spaceRocks->render(*window);

	window->display();
}
Game::Game() {

	initWindow();
	//initGOL();
	initSpaceRocks();
}
Game::~Game() {

	//delete gol;
	delete window;
	delete spaceRocks;
}
void Game::running() {

	while(window->isOpen()) {

		updating();
		rendering();
	}
}
