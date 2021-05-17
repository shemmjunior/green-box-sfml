#include "Logic.h"

void Logic::initVariables() {
    this->window = nullptr;
	this->spawnTimerMax = 1000.f;
	this->spawnTimer = this->spawnTimerMax;

}

void Logic::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game Mode", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	this->window->setFramerateLimit(60); 
}


// Main Constructor
Logic::Logic() {
    this->initVariables();
    this->initWindow();
    this->drawGreen();
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

void Logic::drawGreen() {
    this->green.setSize(sf::Vector2f(100.f, 100.f));
	this->green.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->green.getSize().x)), rand() % static_cast<int>(this->window->getSize().y - this->green.getSize().y));
	this->green.setScale(sf::Vector2f(0.5f, 0.5f));
	this->green.setFillColor(sf::Color::Green);
}

void Logic::renderGreen() {
	this->window->draw(this->green);
}

void Logic::drawEnemies() {
		this->box.setSize(sf::Vector2f(10.f, 10.f));
		this->box.setScale(sf::Vector2f(0.5f, 0.5f));
		this->box.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->box.getSize().x)), rand() % static_cast<int>(this->window->getSize().y - this->box.getSize().y));
		this->box.setFillColor(sf::Color::Red);
		this->enemies.push_back(this->box);
}



void Logic::updateEnemies() {
	if (this->enemies.size() < 100) {
			this->drawEnemies();

		// if (this->spawnTimer >= this->spawnTimerMax) {
		// 	this->drawEnemies();
		// 	this->spawnTimer = 0.f;
		// } else {
		// 	this->spawnTimer += 1.f;
		// }
	}
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
	this->renderGreen();
	this->renderEnemies();
	this->window->display();
}

void Logic::updateCollision() {
	
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
				this->green.move(0,-10);
			}
			if (this->ev.key.code == sf::Keyboard::Down) {
				this->green.move(0,10);
					// for (size_t i = 0; i < this->enemies.size(); i++) {
					// 		if(this->green.getGlobalBounds().intersects(this->enemies[i]->getGlobalBounds()))
					// 		this->green.move(0,-10);
					// }
				
			}
	
			if (this->ev.key.code == sf::Keyboard::Left) {
				this->green.move(-10,0);
			}
			if (this->ev.key.code == sf::Keyboard::Right) {
				this->green.move(10,0);
			}
			if (this->ev.key.code == sf::Keyboard::Space) {
				this->green.move(0,-50);
				// this->green.move(0,50);

			}
			break;
		
	}
}
}