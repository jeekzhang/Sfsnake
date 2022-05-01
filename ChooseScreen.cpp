#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include "GameScreen.h"
#include "MenuScreen.h"
#include "ChooseScreen.h"
#include "Game.h"
#include "BackGround.h"

using namespace sfSnake;

ChooseScreen::ChooseScreen()
{
    font_.loadFromFile("Fonts\\game_over.ttf");
    text1_.setFont(font_);
    text1_.setString(
        "\n[A]white\n[B]black\n[C]Brown");
    text1_.setCharacterSize(20);
    text2_.setFont(font_);
    text2_.setString(
        "\n[W]Not to set\n[X]white\n[Y]black\n[Z]Brown");
    text2_.setCharacterSize(20);

    backText_.setFont(font_);
    backText_.setString("Choose Back_Color");
    backText_.setColor(sf::Color::Red);
    backText_.setCharacterSize(40);
    backText_.setStyle(sf::Text::Bold);

    gridText_.setFont(font_);
    gridText_.setString("Set Grid");
    gridText_.setColor(sf::Color::Green);
    gridText_.setCharacterSize(40);
    gridText_.setStyle(sf::Text::Bold);

    text_.setFont(font_);
    text_.setString("Press [Enter] to play");
    text_.setColor(sf::Color::Blue);
    text_.setCharacterSize(32);
    text_.setStyle(sf::Text::Bold);

    sf::FloatRect text1Bounds = text1_.getLocalBounds();
    text1_.setOrigin(text1Bounds.left + text1Bounds.width / 2,
        text1Bounds.top + text1Bounds.height / 2);
    text1_.setPosition(Game::Width / 2, Game::Height / 4);

    sf::FloatRect text2Bounds = text2_.getLocalBounds();
    text2_.setOrigin(text2Bounds.left + text2Bounds.width / 2,
        text2Bounds.top + text2Bounds.height / 2);
    text2_.setPosition(Game::Width / 2, Game::Height / 1.5);

    sf::FloatRect gridTextBounds = gridText_.getLocalBounds();
    gridText_.setOrigin(gridTextBounds.left + gridTextBounds.width / 2,
        gridTextBounds.top + gridTextBounds.height / 2);
    gridText_.setPosition(Game::Width / 2, Game::Height / 2);

    sf::FloatRect backTextBounds = backText_.getLocalBounds();
    backText_.setOrigin(backTextBounds.left + backTextBounds.width / 2,
        backTextBounds.top + backTextBounds.height / 2);
    backText_.setPosition(Game::Width / 2, Game::Height / 10);

    sf::FloatRect textBounds = text_.getLocalBounds();
    text_.setOrigin(textBounds.left + textBounds.width / 2,
        textBounds.top + textBounds.height / 2);
    text_.setPosition(Game::Width / 2, Game::Height / 1.1);
}

void ChooseScreen::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::B) || sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            text1_.setString("\nwhite");
            color_num = 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        {
            text1_.setString("\nblack");
            color_num = 2;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            text1_.setString("\nbrown");
            color_num = 3;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::Y) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            text2_.setString("\n  Not to set");
            grid_num = 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            text2_.setString("\n\twhite");
            grid_num = 2;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            text2_.setString("\n\tblack");
            grid_num = 3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            text2_.setString("\n\tbrown");
            grid_num = 4;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        Game::Screen = std::make_shared<GameScreen>();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
};
void ChooseScreen::update(sf::Time delta) {

};

void ChooseScreen::render(sf::RenderWindow& window)
{
    back_ground_.drawBack(window);
    window.draw(text1_);
    window.draw(text2_);
    window.draw(text_);
    window.draw(backText_);
    window.draw(gridText_);
}