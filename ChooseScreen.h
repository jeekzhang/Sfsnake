#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include <SFML/Graphics.hpp>
#include "BackGround.h"
#include "Screen.h"

namespace sfSnake
{
	class ChooseScreen : public Screen
	{
	public:
		ChooseScreen();
		void handleInput(sf::RenderWindow& window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow& window) override;
		static int back_choose, cell_choose, snake_choose;
	private:
		sf::Font font_;
		sf::Text backText_, gridText_, text1_, text2_,text_;
		BackGround back_ground_;
		
	};
}


#endif
