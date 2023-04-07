#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "Fruit.h"

using namespace sfSnake;

const float Fruit::Radius = 5.f;

sf::Color Fruit::Set_Color()
{
    static std::default_random_engine engine;
    engine.seed(time(NULL));
    static std::uniform_int_distribution<int> set_;
    if (set_(engine) % 4 == 0)
    {
        if (set_(engine) % 1 == 0)
            color_ = sf::Color::White;
        else
            color_ = sf::Color(90, 57, 18);
        score_ = 0;
    }
    else
    {
        engine.seed(time(NULL));
        int i = set_(engine);
        if (i % 3 == 0)
        {
            color_ = sf::Color::Green;
            score_ = 1;
        }

        else if (i % 3 == 1)
        {
            color_ = sf::Color::Blue;
            score_ = 2;
        }

        else
        {
            color_ = sf::Color::Red;
            score_ = 3;
        }
    }
    return color_;
}
Fruit::Fruit(sf::Vector2f position)
{
    shape_.setPosition(position);
    shape_.setRadius(Fruit::Radius);
    shape_.setFillColor(Set_Color());
}

void Fruit::render(sf::RenderWindow& window)
{
    window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const
{
    return shape_.getGlobalBounds();
}