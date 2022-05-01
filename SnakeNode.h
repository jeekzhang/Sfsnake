#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
    class SnakeNode
    {
    public:
        SnakeNode(sf::Vector2f position = sf::Vector2f(0, 0));
        //SnakeNode(sf::Vector2f position = sf::Vector2f(0, 0), int indx = 1, sf::Vector2f direction = sf::Vector2f(0, -1));

        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);

        void move(float xOffset, float yOffset);

        void render(sf::RenderWindow& window);
        void render_(sf::RenderWindow& window);

        sf::Vector2f getPosition() const;
        sf::FloatRect getBounds() const;

        static const float Width;
        static const float Height;

    private:
        sf::RectangleShape shape_;
        sf::CircleShape circle_;
        sf::Vector2f position_;
        sf::Vector2f direction_;
        sf::Texture tex_;
    };
}

#endif
