//  create a class name segment
//  this class is used to store the information of a segment

#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Segment
{
public:
    Segment(float x , float y, float angle, float length);
    void draw(sf::RenderWindow& window);
    void setAngle(float angle);
    void follow(sf::RenderWindow& window);

private:
    sf::Vector2f a;       // First endpoint
    sf::Vector2f b;       // Second endpoint
    sf::VertexArray line; // Vertex array for drawing the line

    float length;
};

#endif // SEGMENT_H