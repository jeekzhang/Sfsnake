#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
	class Fruit
	{
	public:
		Fruit(sf::Vector2f position = sf::Vector2f(0, 0));

		void render(sf::RenderWindow& window);

		sf::FloatRect getBounds() const;

		int Score() {
			return score_;
		};

		sf::Color Set_Color();

	private:
		sf::CircleShape shape_;
		sf::Color color_;

		static const float Radius;

		int score_;
	};
}

#endif#pragma once
