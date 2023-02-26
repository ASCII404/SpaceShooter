#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
class Enemy
{
private:
	sf::Texture enemy_texture;
	sf::Sprite enemy_sprite;
	sf::FloatRect bounds;
	std::vector<Enemy*> entity;
	float spawn_delay;
public:
	Enemy() {
		if (!enemy_texture.loadFromFile("enemy1.png")) {
			//do smth about it
		}
		else {
			spawn_delay = 0.0f;
			srand(time(NULL));
			bounds = enemy_sprite.getLocalBounds();
			enemy_sprite.setTexture(enemy_texture);
			enemy_sprite.setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
			enemy_sprite.setPosition(sf::Vector2f(rand()%500, 0));
		}
	}

	void set_enemy_texture(sf::Texture enemy_text) {
		enemy_sprite.setTexture(enemy_text);
	}
	sf::Sprite get_enemy_sprite() {
		return enemy_sprite;
	}

	void set_enemy_pos(sf::Vector2f newpos) {
		enemy_sprite.setPosition(newpos.x, newpos.y);
	}
	sf::Vector2f get_enemy_pos() {
		return enemy_sprite.getPosition();
	}

	void enemy_movement(sf::RenderWindow &windowRef);
	float Lerp(float x, float y, float z);
	~Enemy(){}
};

