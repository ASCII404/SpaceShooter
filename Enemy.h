#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Enemy
{
private:
	sf::Sprite enemy;
	sf::Texture enemy_texture;
	sf::Texture blank_texture;

	sf::Vector2f offset;
	sf::FloatRect boundaries;
	float speed{};
	bool flagged_for_deletion_ = false;

public:
	Enemy() {};

	Enemy(float pos_x, float pos_y) {
		this->offset.x = 0.f;
		this->offset.y = 10.f;
		this->speed = 0.35f;
		if (!blank_texture.loadFromFile("Content/blank.png")) {
			throw std::runtime_error("Couldn't open blank file");
		}
		try {
			if (!enemy_texture.loadFromFile("Content/enemy.png"))
				throw std::runtime_error("Couldn't open enemy file");
			else {
				enemy.setTexture(enemy_texture);
				enemy.scale(1.5f, 1.5f);
				enemy.setPosition(pos_x, pos_y);
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	sf::Sprite getEnemySprite();
	void setBlank();
	sf::Vector2f getEnemyPos();
	void setEnemyPos(float pos_x, float pos_y);

	sf::FloatRect getBoundaries();
	void set_boundaries();
	void move_enemy();

	void setFlagForDeletion() { flagged_for_deletion_ = true; }
	bool isFlaggedForDeletion() const { return flagged_for_deletion_; }
};

