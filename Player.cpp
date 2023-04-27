#include "Player.h"
#include <cmath>
#include <iostream>
#include <memory>

void Player::Draw(sf::RenderWindow &window) {
	window.draw(player);
}
extern sf::FloatRect top_b, left_b, right_b, bot_b;
float Player::lerp(float  x, float y, float z)
{
	return ((1.0f - z) * x) + (z * y);
}


void Player::set_boundaries() {
	boundingBox = player.getGlobalBounds();
}

void Player::update(sf::Time dt, sf::RenderWindow& window) {
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && !left_b.contains(player.getPosition()))
		this->player.move(lerp(-800.0f, -2.0f, 0.1f) * dt.asSeconds(), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !right_b.contains(player.getPosition()))
		this->player.move(lerp(800.0f, -2.0f, 0.1f) * dt.asSeconds(), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !top_b.contains(player.getPosition()))
		this->player.move(0, lerp(-800.0f, -2.0f, 0.1f) * dt.asSeconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !bot_b.contains(player.getPosition()))
		this->player.move(0, lerp(800.0f, -2.0f, 0.1f) * dt.asSeconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) make_bullet();

}

void Player::make_bullet() {

	time += cl.getElapsedTime();
	if (this->time.asSeconds() > 2) {
		time = sf::Time::Zero;
		this->bullet_list.emplace_back(std::make_unique<Ammo>(player.getPosition().x + 65, player.getPosition().y - 5));
		cl.restart();
	}

}

void Player::shoot(sf::RenderWindow& window) {
	for (auto it = bullet_list.begin(); it != bullet_list.end();) {
		(*it)->move_bullet();
		(*it)->setBoundaries();
		(*it)->Draw(window);
		
		if ((*it)->check_collision()) {
			it = bullet_list.erase(it);
		}
		else
		{
			++it;
		}
	}
}
