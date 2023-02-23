#include "Ship.h"
#include "ammo.h"
#include <memory>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

template <typename T>
bool operator <(const sf::Vector2<T>& left, const sf::Vector2<T>& right)
{
    return (left.x < right.x) && (left.y < right.y);
}


template <typename T>
bool operator >(const sf::Vector2<T>& left, const sf::Vector2<T>& right)
{
    return (left.x > right.x) && (left.y > right.y);
}

void Ship::ship_movement(){

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

void Ship::shoot() {

    //If space is pressed then the ship shoots a bullet
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

        //Dinamically instantiate a new ammo object for each bullet
        std::unique_ptr<ammo> bullet(new ammo);

        //A vector to store all the bullets before deleting them
        std::vector<std::unique_ptr<ammo>> b;
        b.push_back(std::move(bullet));
    }

}