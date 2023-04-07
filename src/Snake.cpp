#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <math.h>

#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "SnakeNode.h"
#include "GameOverScreen.h"

using namespace sfSnake;

const int Snake::InitialSize = 5;

Snake::Snake() : direction_(Direction::Up), hitSelf_(false)
{
    initNodes();

    pickupBuffer_.loadFromFile("../Sounds/pickup.wav");
    pickupSound_.setBuffer(pickupBuffer_);
    pickupSound_.setVolume(30);

    dieBuffer_.loadFromFile("../Sounds/die.wav");
    dieSound_.setBuffer(dieBuffer_);
    dieSound_.setVolume(50);
}

void Snake::initNodes()
{
    for (int i = 0; i < Snake::InitialSize; ++i)
    {
        nodes_.push_back(SnakeNode(sf::Vector2f(
            Game::Width / 2 - SnakeNode::Width / 2,
            Game::Height / 2 - (SnakeNode::Height / 2) + (SnakeNode::Height * i))));
    }
}

void Snake::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction_ = Direction::Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction_ = Direction::Down;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction_ = Direction::Left;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction_ = Direction::Right;
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        direction_ = Direction::Mouse_direction;
        sf::Vector2f head_pos = nodes_[0].getPosition();
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        mouse_move.x = 10 * (mouse_pos.x - head_pos.x) /
            sqrt((mouse_pos.x - head_pos.x) * (mouse_pos.x - head_pos.x) + (mouse_pos.y - head_pos.y) * (mouse_pos.y - head_pos.y));
        mouse_move.y = 10 * (mouse_pos.y - head_pos.y) /
            sqrt((mouse_pos.x - head_pos.x) * (mouse_pos.x - head_pos.x) + (mouse_pos.y - head_pos.y) * (mouse_pos.y - head_pos.y));
    }
}

void Snake::update(sf::Time delta)
{
    move();
    checkEdgeCollisions();
    checkSelfCollisions();
}

void Snake::checkFruitCollisions(std::vector<Fruit>& fruits)
{
    decltype(fruits.begin()) toRemove = fruits.end();

    for (auto it = fruits.begin(); it != fruits.end(); ++it)
    {
        if (it->getBounds().intersects(nodes_[0].getBounds()))
            toRemove = it;
    }

    if (toRemove != fruits.end())
    {
        auto it = fruits.begin();
        pickupSound_.play();
        if (it->Score() >= 1)
            grow();
        if (it->Score() >= 2)
            grow();
        if (it->Score() == 3)
            grow();
        fruits.erase(toRemove);
    }
}

void Snake::grow()
{
    switch (direction_)
    {
    case Direction::Up:
        nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
            nodes_[nodes_.size() - 1].getPosition().y + SnakeNode::Height)));
        break;
    case Direction::Down:
        nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
            nodes_[nodes_.size() - 1].getPosition().y - SnakeNode::Height)));
        break;
    case Direction::Left:
        nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x + SnakeNode::Width,
            nodes_[nodes_.size() - 1].getPosition().y)));
        break;
    case Direction::Right:
        nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x - SnakeNode::Width,
            nodes_[nodes_.size() - 1].getPosition().y)));
        break;
    case Direction::Mouse_direction:
        nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x - mouse_move.x,
            nodes_[nodes_.size() - 1].getPosition().y - mouse_move.y)));
        break;
    }
}

unsigned Snake::getSize() const
{
    return nodes_.size();
}

bool Snake::hitSelf() const
{
    return hitSelf_;
}

void Snake::checkSelfCollisions()
{
    SnakeNode& headNode = nodes_[0];

    for (decltype(nodes_.size()) i = 1; i < nodes_.size(); ++i)
    {
        if (pow((headNode.getPosition().x - (nodes_[i].getPosition().x)), 2) + pow((headNode.getPosition().y - (nodes_[i].getPosition().y)), 2) < 10.0f)
        {
            dieSound_.play();
            sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
            hitSelf_ = true;
        }
        else if (nodes_[i].getPosition().x==Game::Width|| nodes_[i].getPosition().x == 0||nodes_[i].getPosition().y == Game::Height|| nodes_[i].getPosition().y == 0) {
            dieSound_.play();
            sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
            hitSelf_ = true;
        }
    }
}

void Snake::checkEdgeCollisions()
{
    SnakeNode& headNode = nodes_[0];

    if (headNode.getPosition().x <= 0)
        headNode.setPosition(Game::Width, headNode.getPosition().y);
    else if (headNode.getPosition().x >= Game::Width)
        headNode.setPosition(0, headNode.getPosition().y);
    else if (headNode.getPosition().y <= 0)
        headNode.setPosition(headNode.getPosition().x, Game::Height);
    else if (headNode.getPosition().y >= Game::Height)
        headNode.setPosition(headNode.getPosition().x, 0);
}

void Snake::move()
{
    for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
    {
        nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
    }

    switch (direction_)
    {
    case Direction::Up:
        nodes_[0].move(0, -SnakeNode::Height);
        break;
    case Direction::Down:
        nodes_[0].move(0, SnakeNode::Height);
        break;
    case Direction::Left:
        nodes_[0].move(-SnakeNode::Width, 0);
        break;
    case Direction::Right:
        nodes_[0].move(SnakeNode::Width, 0);
        break;
    case Direction::Mouse_direction:
        nodes_[0].move(mouse_move.x, mouse_move.y);
        break;
    }
}

void Snake::render(sf::RenderWindow& window)
{ 
    nodes_[0].render_(window);
    for (decltype(nodes_.size()) i = 1; i < nodes_.size(); ++i)
        nodes_[i].render(window);
}