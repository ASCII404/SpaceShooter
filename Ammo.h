#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Enemy.h"
class Ammo
{
private:
	sf::Sprite bullet;
	sf::Texture bullet_texture;
	
	sf::Vector2f offset;
	sf::FloatRect boundaries;
	float speed{};
	bool flagged_for_deletion_ = false;

	Enemy e;
public:
	
	Ammo() {}

	Ammo(float pos_x, float pos_y) {
		this->offset.x = 0.f;
		this->offset.y = -1.f;
		this->speed = 5.5f;
		try {
			if (!bullet_texture.loadFromFile("Content/projectile.png"))
				throw std::runtime_error("Couldn't open projectile model");
			else {
				bullet.setTexture(bullet_texture);
				bullet.setPosition(pos_x, pos_y);
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
	void Draw(sf::RenderWindow& window);
	sf::Sprite getBulletSprite();

	sf::Vector2f getBulletPos();
	void setBulletPos(float pos_x, float pos_y);

	void setBoundaries();
	sf::FloatRect getBoundaries();

	void move_bullet();
	bool check_collision();

	void setFlagForDeletion() { flagged_for_deletion_ = true; }
	bool isFlaggedForDeletion() const { return flagged_for_deletion_; }

};

