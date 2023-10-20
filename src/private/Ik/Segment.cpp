#include "Ik/Segment.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Segment::Segment(float x, float y, float angle, float length)
{
    a.x = x;
    a.y = y;
    this->line = sf::VertexArray(sf::Lines, 2);
    this->length = length;
    // Calculate the position of the second endpoint (b)
    b.x = a.x + length * cos(angle * (3.14f / 180)); // Convert angle to radians
    b.y = a.y + length * sin(angle * (3.14f / 180));

    // Set the positions of the vertices
    line[0].position = a;
    line[1].position = b;

    // Set the color of the line
    line[0].color = sf::Color::White;
    line[1].color = sf::Color::White;
}

void Segment::draw(sf::RenderWindow &window)
{
    window.draw(line);
}

void Segment::setAngle(float angle)
{
    // Update the angle
    this->line[1].position.x = a.x + length * cos(angle * (3.14f / 180));
    this->line[1].position.y = a.y + length * sin(angle * (3.14f / 180));
}