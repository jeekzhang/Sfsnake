#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"

extern int color_num,grid_num;

namespace sfSnake
{
	class GameScreen : public Screen
	{
	public:
		GameScreen();

		void handleInput(sf::RenderWindow& window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow& window) override;
		void generateFruit();

	private:
		Snake snake_;
		std::vector<Fruit> fruit_;
		BackGround back_ground_;

	};
}

#endif
