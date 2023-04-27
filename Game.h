#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ammo.h"
#include "Player.h"
#include "Enemy.h"
class Game
{
private:
	int width{}, height{};
	std::string title;

	bool is_paused = false;


	sf::Sprite background;
	sf::Texture background_texture;

	sf::Clock clck, spawn_clock;
	sf::Time dt, spawn_delay;

	sf::RenderWindow window;
	sf::Text score, counter;
	sf::Font score_font;

	Player p;
	Enemy e;

	std::vector<std::unique_ptr<Enemy>> enemy_list;
	int score_counter{};


public:
	Game() {}
	Game(int width, int height, std::string title) {
		this->width = width;
		this->height = height;
		this->title = title;

		try {
			if (!background_texture.loadFromFile("Content/bg.jpg"))
				throw std::runtime_error("Couldn't open background file");
			else {
				background.setTexture(background_texture);
			}

			if (!score_font.loadFromFile("Content/Text/score.ttf")) {
				throw std::runtime_error("Couldn't open font file");
			}
			else
			{
				this->score.setFont(score_font);
				this->score.setCharacterSize(20);
				this->score.setFillColor(sf::Color::White);
				this->score.setPosition(20, 20);
				this->score.setString("Score :");

				this->counter.setFont(score_font);
				this->counter.setCharacterSize(20);
				this->counter.setFillColor(sf::Color::White);
				this->counter.setPosition(120, 20);
				this->counter.setString(std::to_string(score_counter));
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what();
		}
	}

	void make_window();
	void Run();
	void spawn_enemies();
	bool check_col(int& hit_enemy_index);
	void update_enemies();
};

