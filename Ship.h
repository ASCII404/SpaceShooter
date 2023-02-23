#pragma once
#include <SFML/Graphics.hpp>
class Ship
{
private:
	sf::Texture ship_texture, ship_ammo;
	sf::Sprite ship_sprite, ammo_sprite;

public:
	sf::Text error_msg;

	Ship() {
		if (!ship_texture.loadFromFile("sh.png") || !ship_ammo.loadFromFile("sh_ammo.png")) {}
		else {
			ship_sprite.setTexture(ship_texture);
			ammo_sprite.setTexture(ship_ammo);
			ship_sprite.setPosition(sf::Vector2f(520, 490));
			ammo_sprite.setPosition(sf::Vector2f(520, 390));
		}
	}

	void set_ammo_sprite(sf::Texture texture) { ammo_sprite.setTexture(texture); }
	sf::Sprite get_ammo_sprite() { return ammo_sprite; }

	void set_ship_sprite(sf::Texture texture) { ship_sprite.setTexture(texture); }
	sf::Sprite get_ship_sprite() { return ship_sprite; }

	void ship_movement(sf::Event e, sf::Time dt, sf::Clock clk);
};

