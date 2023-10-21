#include <SFML/Graphics.hpp>
#include <cassert>
#include "Animation/Frame.h"
#include "Ik/Segment.h"

sf::Vector2f getMousePosition(sf::RenderWindow &window);

int main()
{

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World");


    Segment segment(400, 300, 0, 100);
    Segment seg2(400, 300, 0, 100);

    assert(seg2.getParent() == nullptr && "seg2 parent is null");


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
        segment.draw(window);
        // seg2.draw(window);
        segment.follow(mousePos);
        seg2.follow(segment.getA());

        seg2.draw(window);
        window.display();
    }

    return 0;
}

// get mouse postion in world coordinates
sf::Vector2f getMousePosition(sf::RenderWindow &window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f target = window.mapPixelToCoords(mousePosition);

    return target;
    
}