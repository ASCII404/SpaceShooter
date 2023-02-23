#include "Ship.h"
#include <SFML/Graphics.hpp>

void Ship::ship_movement(sf::Time dt, sf::Clock clk)
{
    sf::Vector2f acceleration{}, velocity_{};
    float x{}, y{};
    const float dAcc = 4.5f;

    // set acceleration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        acceleration.y -= dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        acceleration.x -= dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        acceleration.y += dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        acceleration.x += dAcc;

    velocity_ += acceleration;

    // update position through velocity
    x += velocity_.x;
    y += velocity_.y;

    // apply damping to the velocity
    velocity_ = 0.99f * velocity_;

    ship_sprite.move(x, y);
}
