#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "ammo.h"

//IMPLEMENT AMMO CLASS
//IMPLEMENT MORE DIRECTIONS FOR SHIP

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
        window.draw(sprite_bg);
        s.ship_movement();
        window.draw(s.get_ship_sprite());
        window.draw(a.get_ammo_sprite());
        a.bullet_movement();
        window.display();
    }

    return 0;
}

