#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <memory>
#include "ammo.h"

class Ship: public ammo
{
private:
	sf::Texture ship_texture;
	sf::Sprite ship_sprite;
	sf::FloatRect bounds;
public:

	Ship() {


		if (!ship_texture.loadFromFile("sh.png")) {}
		else {
			bounds = ship_sprite.getLocalBounds();
			ship_sprite.setTexture(ship_texture);
			ship_sprite.setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
			ship_sprite.setPosition(sf::Vector2f(520, 490));
		}
	}


	void set_ship_sprite(sf::Texture texture) { ship_sprite.setTexture(texture); }
	sf::Sprite get_ship_sprite() { return ship_sprite; }

	void set_ship_position(sf::Vector2f newpos) { ship_sprite.setPosition(newpos.x, newpos.y); }
	sf::Vector2f get_ship_position() { return ship_sprite.getPosition(); }

	void ship_movement();
	void shoot(sf::RenderWindow& windowRef);
	bool check_boundaries();
	~Ship(){}
};

