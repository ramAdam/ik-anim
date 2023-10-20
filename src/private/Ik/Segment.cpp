#include "Ik/Segment.h"
#include <SFML/Graphics.hpp>

Segment::Segment(float x, float y, float angle, float length)
{
    a.x = x;
    a.y = y;
    this->angle = angle;
    this->length = length;
}

void Segment::draw(sf::RenderWindow& window)
{
    sf::RectangleShape line(sf::Vector2f(length, 1));
    line.setPosition(a);
    line.setFillColor(sf::Color::White);
    line.setRotation(angle);
    window.draw(line);
}

void Segment::setAngle(float angle)
{
    this->angle = angle;
}