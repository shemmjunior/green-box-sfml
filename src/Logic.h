#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Logic {
    private:
        sf::RenderWindow* window;
        sf::Event ev;
        sf::RectangleShape box;
        sf::CircleShape enemies[50];

        void initVariables();
        void initWindow();
    public:
        Logic();
        virtual ~Logic();
        const bool running();
        void pollEvent();
        void update();
        void render();
        void drawBox();
        void renderBox();
        void drawEnemies();
        void renderEnemies();

};