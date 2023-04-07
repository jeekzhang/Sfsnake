#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "GameOverScreen.h"
#include "GameScreen.h"
#include "Game.h"

int color_num = 0;
int grid_num = 0;
using namespace sfSnake;

GameScreen::GameScreen() : snake_()
{

}


void GameScreen::handleInput(sf::RenderWindow& window)
{
	snake_.handleInput(window);
}

void GameScreen::update(sf::Time delta)
{
	if (fruit_.size() == 0)
			generateFruit();


	snake_.update(delta);
	snake_.checkFruitCollisions(fruit_);

	if (snake_.hitSelf())
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize());
}


void GameScreen::render(sf::RenderWindow& window)
{
	if (color_num == 1)back_ground_.setBackColor(sf::Color::White);
	else if (color_num == 2)back_ground_.setBackColor(sf::Color::Black);
	else if (color_num == 3)back_ground_.setBackColor(sf::Color(90, 57, 18));
	back_ground_.drawBack(window);
	
	if (grid_num !=1) {
		if (grid_num == 2)back_ground_.setGridColor(sf::Color::White);
		else if (grid_num == 3)back_ground_.setGridColor(sf::Color::Black);
		else if (grid_num == 4)back_ground_.setGridColor(sf::Color(90, 57, 18));
		back_ground_.drawGrid(window);
	}
	snake_.render(window);

	for (auto fruit : fruit_)
			fruit.render(window);

}

void GameScreen::generateFruit()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(0, Game::Height - SnakeNode::Height);
	fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}

