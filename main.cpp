#include <SFML/Graphics.hpp>
#include "Ship.h"

//IMPLEMENT AMMO CLASS
//IMPLEMENT MORE DIRECTIONS FOR SHIP

int main()
{
    Ship s;
    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "SpaceShooter");

    sf::Time dt;
    sf::Clock clock;
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
        s.ship_movement(dt, clock);
        window.draw(s.get_ship_sprite());
        window.draw(s.get_ammo_sprite());
        window.display();
    }

    return 0;
}