#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include "GameScreen.h"
#include "MenuScreen.h"
#include "ChooseScreen.h"
#include "Game.h"

using namespace sfSnake;

BackGround::BackGround() {
	back_.setFillColor(sf::Color::Black);
	back_.setOutlineThickness(-1.f);
	grid_.setOutlineColor(sf::Color::White);
	grid_.setOutlineThickness(-1.f);

};
void BackGround::setGridColor(const sf::Color& color) {
	grid_.setOutlineColor(color);
};
void BackGround::setBackColor(const sf::Color & color) {
	back_.setFillColor(color);
};

void BackGround::drawBack(sf::RenderWindow& window) {
	back_.setSize(sf::Vector2f(window.getSize()));
	window.draw(back_);
};

void BackGround::drawGrid(sf::RenderWindow& window) {
	for (auto i = 0; i < Game::Height ; i+=10.0f) {
		grid_.setSize(sf::Vector2f(window.getSize().x, 0.5f));
		grid_.setPosition(0, i);
		window.draw(grid_);
	}
	for (auto i = 0; i < Game::Width; i += 10.0f) {
		grid_.setSize(sf::Vector2f(0.5f, window.getSize().y));
		grid_.setPosition(i,0);
		window.draw(grid_);
	}
};
