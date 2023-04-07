#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "SnakeNode.h"

namespace sfSnake
{
    class BackGround
    {
    public:
        BackGround();
        void setGridColor(const sf::Color& color);//设置网格颜色
        void setBackColor(const sf::Color &color);//设置背景颜色
        void drawGrid(sf::RenderWindow& window);//绘制网格
        void drawBack(sf::RenderWindow& window);//绘制背景
    private:
        sf::RectangleShape back_,grid_;
    };
}

