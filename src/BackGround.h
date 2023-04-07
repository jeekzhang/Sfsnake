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
        void setGridColor(const sf::Color& color);//����������ɫ
        void setBackColor(const sf::Color &color);//���ñ�����ɫ
        void drawGrid(sf::RenderWindow& window);//��������
        void drawBack(sf::RenderWindow& window);//���Ʊ���
    private:
        sf::RectangleShape back_,grid_;
    };
}

