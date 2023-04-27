#include "Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

void Game::make_window() {
	this->window.create(sf::VideoMode(this->width, this->height), this->title, sf::Style::Close);
}

void Game::spawn_enemies() {

	this->spawn_delay += this->spawn_clock.getElapsedTime();
	if (spawn_delay.asSeconds() > 50) {
		spawn_delay = sf::Time::Zero;
		this->enemy_list.emplace_back(std::make_unique<Enemy>(rand() % 800 + 30, -1000));
		this->spawn_clock.restart();
	}
}


bool Game::check_col(int& hit_enemy_index) {
	bool collision = false;
	for (int i = 0; i < enemy_list.size(); i++) {
		for (int j = 0; j < p.bullet_list.size(); j++) {
			if (enemy_list[i]->getBoundaries().intersects(p.bullet_list[j]->getBoundaries())) {
				hit_enemy_index = i;
				collision = true;
				break;
			}
		}
		if (collision) {
			break;
		}
	}
	return collision;
}

void Game::update_enemies() {
	int hit_enemy_index = -1;
	for (int i = 0; i < enemy_list.size(); i++) {
		auto& enemy = enemy_list[i];
		enemy->move_enemy();
		enemy->set_boundaries();
		this->window.draw(enemy->getEnemySprite());
		if (enemy->getBoundaries().intersects(p.get_boundaries())) {
			enemy_list.erase(enemy_list.begin() + i);
			this->score_counter = 0;
			break;
		}
		else if (enemy->getEnemyPos().y > 800 || check_col(hit_enemy_index)) {
			if (hit_enemy_index != -1) {
				enemy_list.erase(enemy_list.begin() + hit_enemy_index);
				this->score_counter++;
				break;
			}
			enemy->setFlagForDeletion();
			if (enemy->isFlaggedForDeletion()) {
				this->score_counter--;
			}
		}
	}

	this->counter.setString(std::to_string(score_counter));
	// remove enemies with the flag set
	this->enemy_list.erase(
		std::remove_if(
			this->enemy_list.begin(),
			this->enemy_list.end(),
			[](const auto& enemy) { return enemy->isFlaggedForDeletion(); }),
		this->enemy_list.end()
	);
}

void Game::Run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	this->window.setVerticalSyncEnabled(true);

	while (this->window.isOpen()) {
		sf::Time deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;

		sf::Event event;
		while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				this->is_paused = !this->is_paused;
			}
		}

		if (!this->is_paused) {
			sf::Time TimePerFrame = sf::seconds(1.f / 144.f); // Change to desired framerate

			while (timeSinceLastUpdate >= TimePerFrame) {
				timeSinceLastUpdate -= TimePerFrame;

				this->window.clear();
				this->window.draw(this->background);
				p.set_boundaries();
				p.update(TimePerFrame, window);
				p.Draw(window);
				p.shoot(window);
				spawn_enemies();
				update_enemies();
				this->window.draw(score);
				this->window.draw(counter);
				this->window.display();
			}
		}
	}
}
