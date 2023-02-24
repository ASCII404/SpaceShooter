#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <memory>
#include "ammo.h"

class Ship:ammo
{
private:
	sf::Texture ship_texture;
	sf::Sprite ship_sprite;
	
public:

	Ship() {
		if (!ship_texture.loadFromFile("sh.png")) {}
		else {
			ship_sprite.setTexture(ship_texture);
			ship_sprite.setPosition(sf::Vector2f(520, 490));
		}
	}


	void set_ship_sprite(sf::Texture texture) { ship_sprite.setTexture(texture); }
	sf::Sprite get_ship_sprite() { return ship_sprite; }

	void set_ship_position() { ship_sprite.setPosition(0, 0); }
	sf::Vector2f get_ship_position() { return ship_sprite.getPosition(); }

	void ship_movement();
	void shoot(sf::RenderWindow &windowRef);
	~Ship(){}
};

