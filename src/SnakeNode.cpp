#include <SFML/Graphics.hpp>

#include "SnakeNode.h"

using namespace sfSnake;

const float SnakeNode::Width = 10.f;
const float SnakeNode::Height = 10.f;

SnakeNode::SnakeNode(sf::Vector2f position)
    : position_(position)
{
    shape_.setPosition(position_);
    shape_.setFillColor(sf::Color::Black);
    shape_.setSize(sf::Vector2f(SnakeNode::Width / 2, SnakeNode::Height / 2));
    shape_.setOutlineColor(sf::Color::Black);
    shape_.setOutlineThickness(-1.f);

    circle_.setPosition(position_);
    circle_.setFillColor(sf::Color::Yellow);
    circle_.setRadius(5.0f);
    circle_.setOutlineColor(sf::Color::Yellow);
    circle_.setOutlineThickness(-1.f);
}

void SnakeNode::setPosition(sf::Vector2f position)
{
    position_ = position;
    shape_.setPosition(position_.x + 2.5f, position_.y + 2.5f);
    circle_.setPosition(position_);
    
}

void SnakeNode::setPosition(float x, float y)
{
    position_.x = x;
    position_.y = y;
    shape_.setPosition(position_.x + 2.5f, position_.y + 2.5f);
    circle_.setPosition(position_);
    
}

void SnakeNode::move(float xOffset, float yOffset)
{
    position_.x += xOffset;
    position_.y += yOffset;
    shape_.setPosition(position_.x + 2.5f, position_.y + 2.5f);
    circle_.setPosition(position_);
}

sf::FloatRect SnakeNode::getBounds() const
{
    return shape_.getGlobalBounds();
}

sf::Vector2f SnakeNode::getPosition() const
{
    return position_;
}

void SnakeNode::render(sf::RenderWindow& window)
{
    window.draw(circle_);
    window.draw(shape_);
}

void SnakeNode::render_(sf::RenderWindow& window)
{
    tex_.loadFromFile("../img/head.png");
    sf::CircleShape rectShape(5.0f);
    rectShape.setTexture(&tex_);
    rectShape.setPosition(position_);
    window.draw(rectShape);
}