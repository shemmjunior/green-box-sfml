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
	this->drawEnemies();
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
	this->box.setFillColor(sf::Color::Green);
}

void Logic::drawEnemies() {
	for (int i = 0; i < 10; i++) {
		this->enemies[i].setRadius(rand() % 50 + 5);
		this->enemies[i].setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->box.getSize().x)), rand() % static_cast<int>(this->window->getSize().y - this->box.getSize().y));
		this->enemies[i].setFillColor(sf::Color::Red);

			// Prevent Collision When Drawing the Enemies
			for (int j = 0; j < i - 1; j++) {
				if (enemies[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
					{
						enemies[i].setPosition(rand() % 1870 + 50, rand() % 1030 + 50);
						j = 0;
					}
			}
	}
}

void Logic::renderBox() {
    this->window->draw(this->box);
}

void Logic::updateEnemies() {
	// for(auto& e : this->enemies) {
	// 	e.move(0.f, 1.f);
		
	// }
}

void Logic::renderEnemies() {
	for(auto& e : this->enemies) {
		this->window->draw(e);
	}
}

void Logic::update() {
    this->pollEvent();
	this->updateEnemies();
}

void Logic::render() {
    this->window->clear();
	this->renderBox();
	this->renderEnemies();
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
			if (this->ev.key.code == sf::Keyboard::Up) {
				this->box.move(0,-10);
			}
			if (this->ev.key.code == sf::Keyboard::Down) {
				this->box.move(0,10);
					for (unsigned int i = 0; i < 10; i++) {
							if(this->box.getGlobalBounds().intersects(this->enemies->getGlobalBounds()))
							this->box.move(0,-10);
					}
				
				}
	
			if (this->ev.key.code == sf::Keyboard::Left) {
				this->box.move(-10,0);
			}
			if (this->ev.key.code == sf::Keyboard::Right) {
				this->box.move(10,0);
			}
			break;
		
	}
}
}