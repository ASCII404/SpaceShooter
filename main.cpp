#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "ammo.h"
#include <iostream>

//IMPLEMENT DELAY BETWEEN BULLETS -> CLOCK,DELTA TIME
//IMPLEMENT LIMITS
//IMPLEMENT AUTO DESTROY FOR BULLETS TO FREE MEMORY
//+try to code better

int main()
{
    Ship s;
    ammo a;

    sf::Texture texture_bg;
    sf::Sprite sprite_bg;

    texture_bg.loadFromFile("bg2.jpg");
    sprite_bg.setTexture(texture_bg);
    sf::RenderWindow window;
   
    window.create(sf::VideoMode(1280, 720), "SpaceShooter");
    window.setFramerateLimit(140);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        

        window.clear();
        window.setKeyRepeatEnabled(false);
        window.draw(sprite_bg);
        window.draw(s.get_ship_sprite());
        s.ship_movement();
        s.shoot(window);
        window.display();
    }
    return 0;
}

