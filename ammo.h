#pragma once
#include <SFML/Graphics.hpp>
class ammo
{
private: 
	sf::Texture ammo_texture;
	sf::Sprite ammo_sprite;
	sf::Vector2f acceleration;

public:
	ammo() {
		if (!ammo_texture.loadFromFile("sh_ammo.png")) {}
		else {
			ammo_sprite.setTexture(ammo_texture);
		}
	}

	void set_ammo_sprite(sf::Texture texture) { ammo_sprite.setTexture(texture); }
	sf::Sprite get_ammo_sprite() { return ammo_sprite; }

	void set_ammo_position() { ammo_sprite.setPosition(0, 0); }
	sf::Vector2f get_ammo_position() { return ammo_sprite.getPosition(); }

	void bullet_movement();

	~ammo(){}
};

