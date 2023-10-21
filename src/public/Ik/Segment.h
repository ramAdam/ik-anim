//  create a class name segment
//  this class is used to store the information of a segment

#ifndef SEGMENT_H
#define SEGMENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Segment
{
public:
    Segment(float x , float y, float angle, float length);
    Segment(float x, float y, float angle, float length, Segment* parent);
    ~Segment();

    void draw(sf::RenderWindow& window);
    void setAngle(float angle);
    void follow(const sf::Vector2f target);
    /* follows parent vector A if the parent is set*/
    void follow();

    /* set end points index 0 for endpoint a and index 1 for endpoint b*/
    void setEndPoint(const float x, const float y, const int index);
    void addVectorToA(const float x, const float y);
    void addVectorToB(const float x, const float y);

    void set_a(const sf::Vector2f &a);

    const sf::Vector2f &getA() const { return a; }
    const sf::Vector2f &getB() const { return b; }

    const Segment* getParent() const { return parent; }


private:
    float magnitude(const sf::Vector2f vector);

private:
    sf::Vector2f a;       // First endpoint
    sf::Vector2f b;       // Second endpoint
    sf::VertexArray line; // Vertex array for drawing the line

    Segment *parent;
    // std::weak_ptr<Segment> parent;

    float length;
};

#endif // SEGMENT_H