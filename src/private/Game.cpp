#include <SFML/Graphics.hpp>
#include "Animation/Frame.h"
#include "Ik/Segment.h"

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World");

    // Create a text object
    // sf::Font font;

    Segment segment(400, 300, 0, 100);


    // if (!font.loadFromFile("arial/arial.ttf")) // You need to have a font file (arial.ttf) in the same directory as your source code
    // {
    //     return EXIT_FAILURE;
    // }

    // sf::Text text("Hello, World!", font, 50);
    // text.setFillColor(sf::Color::White);
    // text.setPosition(250, 250);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(text);
        segment.draw(window);
        segment.follow(window);
        window.display();
    }

    return 0;
}
