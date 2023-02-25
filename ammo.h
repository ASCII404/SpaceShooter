#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class ammo
{
private: 
	sf::Texture ammo_texture;
	sf::Sprite ammo_sprite;
	sf::Vector2f acceleration;
	sf::RenderWindow window;
	
public:

	ammo() {
		if (!ammo_texture.loadFromFile("sh_ammo.png")) {}
		else {
			ammo_sprite.setTexture(ammo_texture);
		}
	}
	void ammo_movement(sf::RenderWindow& windowRef);
	void set_ammo_sprite(sf::Texture texture) { ammo_sprite.setTexture(texture); }
	sf::Sprite get_ammo_sprite() { return ammo_sprite; }

	void set_ammo_position(sf::Vector2f newpos) {
		ammo_sprite.setPosition(newpos.x, newpos.y);
	}
	sf::Vector2f get_ammo_position() { return ammo_sprite.getPosition(); }

	void set_ammo_origin(sf::Vector2f newpos) {
		ammo_sprite.setPosition(newpos.x, newpos.y - 98);
	}
	sf::Vector2f get_ammo_origin() { return ammo_sprite.getOrigin(); }
	float Lerp(float x, float y, float z);

protected:
	std::vector<ammo*> bullet;

};

