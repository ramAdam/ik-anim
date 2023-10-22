#include <SFML/Graphics.hpp>
#include <cassert>
#include <list>
#include "Animation/Frame.h"
#include "Ik/Segment.h"

sf::Vector2f getMousePosition(sf::RenderWindow &window);
void cleanUp(std::list<Segment *> &segments);

int main()
{

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World");


    Segment *parent = new Segment(400, 300, 0, 100, sf::Color::Green);
    

    std::list<Segment *> segments;
    segments.push_front(parent);

    // add 10 segments
    for (int i = 0; i < 5; i++){
        Segment *seg = new Segment(400, 300, 0, 100, parent);
        segments.push_back(seg);
        parent = seg;
    }


    // assert(seg2->getParent() != nullptr && "seg2 parent is null");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        auto mousePos = getMousePosition(window);


        segments.front()->follow(mousePos);

        for(auto &seg : segments)
        {
            seg->draw(window);
        }



        window.display();
    }

    cleanUp(segments);

    return 0;
}

// get mouse postion in world coordinates
sf::Vector2f getMousePosition(sf::RenderWindow &window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f target = window.mapPixelToCoords(mousePosition);

    return target;
    
}

void cleanUp(std::list<Segment *> &segments)
{
    for(auto &seg : segments)
    {
        delete seg;
    }
}