#include "Enemy.h"
sf::Sprite Enemy::getEnemySprite() {
	return this->enemy;
}

void Enemy::setBlank() {
	enemy.setTexture(blank_texture);
}
sf::Vector2f Enemy::getEnemyPos() {
	return this->enemy.getPosition();
}

void Enemy::move_enemy() {
	enemy.move(offset.x, offset.y * speed);
}
void Enemy::setEnemyPos(float pos_x, float pos_y) {
	this->enemy.setPosition(pos_x, pos_y);
}

void Enemy::set_boundaries() {
	this->boundaries = enemy.getGlobalBounds();
}

sf::FloatRect Enemy::getBoundaries() {
	return this->boundaries;
}