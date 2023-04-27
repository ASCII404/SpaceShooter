#include "Ammo.h"
#include <iostream>

extern sf::FloatRect top_b, left_b, right_b, bot_b;

void Ammo::Draw(sf::RenderWindow& window) {
	window.draw(bullet);
}

sf::Vector2f Ammo::getBulletPos() {
	return bullet.getPosition();
}
void Ammo::setBulletPos(float pos_x, float pos_y) {
	this->bullet.setPosition(pos_x, pos_y);
}

sf::Sprite Ammo::getBulletSprite() {
	return this->bullet;
}

void Ammo::move_bullet() { 
	bullet.move(offset.x, offset.y * speed); 
}

void Ammo::setBoundaries() {
	this->boundaries = bullet.getGlobalBounds();
}

sf::FloatRect Ammo::getBoundaries() {
	return boundaries;
}

bool Ammo::check_collision() {
	if (bullet.getPosition().y < -100)
	{
		return true;
	}

	return false;
}
