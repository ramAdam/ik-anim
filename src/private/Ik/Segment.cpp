#include "Ik/Segment.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Segment::Segment(float x, float y, float angle, float length)
{
    a.x = x;
    a.y = y;

    this->parent = nullptr;


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

Segment::Segment(float x, float y, float angle, float length, Segment* parent)
:Segment(x, y, angle, length)
{
    this->parent = parent;
}

void Segment::follow(const sf::Vector2f target)
{
    // if(this->parent != nullptr)
    // {
    //     set_a(this->parent->getB());
    // }
   
    // Get the mouse coordinates
    // sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    // Convert mouse coordinates to world coordinates
    // sf::Vector2f target = window.mapPixelToCoords(mousePosition);

    // Calculate the direction vector from 'a' to the mouse pointer
    sf::Vector2f direction = target - a;

    // Normalize the direction vector
    float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction = sf::Vector2f(direction.x / magnitude, direction.y / magnitude);

    // Set the magnitude of the direction vector to 'length'
    direction *= length;

    // Reverse the direction vector
    direction.x = -direction.x;
    direction.y = -direction.y;


    // set end point a 
    setEndPoint(target.x + direction.x, target.y + direction.y, 0);

    // set endpoint b
    // setEndPoint(a.x + direction.x, a.y + direction.y, 1);
    setEndPoint(target.x , target.y, 1);
}

void Segment::setEndPoint(float x, float y, const int index )
{
    if (index == 0)
    {
        this->line[0].position.x = x;
        this->line[0].position.y = y;
        this->a.x = this->line[0].position.x;
        this->a.y = this->line[0].position.y;
    }
    else
    {
        this->line[1].position.x = x;
        this->line[1].position.y = y;
        this->b.x = this->line[1].position.x;
        this->b.y = this->line[1].position.y;
    }
}

float Segment::magnitude(const sf::Vector2f vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

void Segment::addVectorToA(const float x, const float y)
{
    setEndPoint(line[0].position.x + x, line[0].position.y + y, 0);
}

void Segment::addVectorToB(const float x, const float y)
{
    setEndPoint(line[1].position.x + x, line[1].position.y + y, 1);
}

void Segment::draw(sf::RenderWindow &window)
{
    window.draw(line);
}

void Segment::setAngle(const float angle)
{
    // Update the angle
    this->line[1].position.x = a.x + length * cos(angle * (3.14f / 180));
    this->line[1].position.y = a.y + length * sin(angle * (3.14f / 180));

    setEndPoint(this->line[1].position.x, this->line[1].position.y, 1);
}

Segment::~Segment()
{
    parent = nullptr;
    std::cout << "Segment destructor called" << std::endl;
}