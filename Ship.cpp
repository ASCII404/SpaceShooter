#include "Ship.h"
#include "ammo.h"
#include <memory>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

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

bool Ship::check_boundaries() {

	std::cout << get_ship_position().x << " " << get_ship_position().y << std::endl;
	if (ship_sprite.getPosition().x < -55.f) return true;
	if (ship_sprite.getPosition().x > 1080.f) return true;
	if (ship_sprite.getPosition().y < -42.f) return true;
	if (ship_sprite.getPosition().y > 513.f) return true;
	
	return false;
}	

void Ship::ship_movement() {

	sf::Vector2f acceleration{}, velocity_{};
	float x{}, y{};
	const float dAcc = 4.5f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
		ship_sprite.setPosition(520, 490);
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


	if (check_boundaries()) {
		ship_sprite.setPosition(520, 490);
	}
	else
	{
		ship_sprite.move(x, y);
	}

}

void Ship::shoot(sf::RenderWindow& windowRef) {

	ammo* b;
	//If space is pressed then the ship shoots a bullet

	b = new ammo();
	b->set_ammo_origin(get_ship_position());
	bullet.push_back(b);
	ammo_movement(windowRef);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
		bullet.clear();
		bullet.shrink_to_fit();
	}
}