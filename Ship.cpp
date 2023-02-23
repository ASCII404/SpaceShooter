#include "Ship.h"
#include <SFML/Graphics.hpp>

void Ship::ship_movement(sf::Event e, sf::Time dt, sf::Clock clk)
{
    float changeX{}, changeY{};
    dt = clk.restart();
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::S) {
            ship_sprite.move(0, 5 * dt.asSeconds());
        }
        if (e.key.code == sf::Keyboard::A) {
            ship_sprite.move(-5 * dt.asSeconds(),0);
        }
        if (e.key.code == sf::Keyboard::W) {
            ship_sprite.move(0, -5 * dt.asSeconds());
        }
        if (e.key.code == sf::Keyboard::D) {
            ship_sprite.move(5 * dt.asSeconds(), 0);
        }
    }

}