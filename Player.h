#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Ammo.h"
#include <memory>

class Player
{
private:
	sf::Sprite player;
	sf::Texture player_texture;
	sf::Vector2f Velocity;
	sf::FloatRect boundingBox;



	sf::Time time, delay_time;
	sf::Clock cl;

public:
	std::vector<std::unique_ptr<Ammo>> bullet_list;
	Player() {
		try{
			if (!player_texture.loadFromFile("Content/spaceship.png"))
				throw std::runtime_error("Couldn't open spaceship model");
			else{
				player.setTexture(player_texture);
				player.setPosition(570.f, 420.f);
			}
		}
		catch (const std::exception &e){
			std::cout << e.what();
		}
	}

	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPlayerPos() { return player.getPosition(); }
	sf::Sprite getPlayerSprite() { return player; }

	float lerp(float x, float y, float z);
	void set_boundaries();
	sf::FloatRect get_boundaries() { return boundingBox; }

	void update(sf::Time dt, sf::RenderWindow& window);
	void shoot(sf::RenderWindow& window);
	void make_bullet();

};

