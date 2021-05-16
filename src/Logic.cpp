#include "Logic.h"

void Logic::initVariables() {
    this->window = nullptr;
}

void Logic::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game Mode", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	this->window->setFramerateLimit(60); 
}


// Main Constructor
Logic::Logic() {
    this->initVariables();
    this->initWindow();
    this->drawBox();
}

// Destructor
Logic::~Logic() {
    delete this->window;
}

const bool Logic::running()
{
	return this->window->isOpen();
}

void Logic::drawBox() {
    this->box.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->box.getSize().x)),0.f);
    this->box.setSize(sf::Vector2f(100.f, 100.f));
	this->box.setScale(sf::Vector2f(0.5f, 0.5f));
	this->box.setFillColor(sf::Color::Cyan);
}

void Logic::renderBox() {
    this->window->draw(this->box);
}

void Logic::update() {
    this->pollEvent();
}

void Logic::render() {
    this->window->clear();
	this->renderBox();
	this->window->display();
}


void Logic::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}