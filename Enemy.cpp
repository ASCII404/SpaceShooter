#include "Enemy.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <SFML/Graphics.hpp>

float Enemy::Lerp(float x, float y, float z) {
	return ((1.0f - z) * x) + (z * y);
}

//CHANGE THIS SHIT
void Enemy::enemy_movement(sf::RenderWindow &windowRef) {
	Enemy* ent;

	ent = new Enemy();
	entity.push_back(ent);
	float curr_speed = Lerp(-1.0f, -20.0f, 0.5f);
	for (int i = 0; i < entity.size(); ++i) {

		windowRef.draw(entity[i]->get_enemy_sprite());
		entity[i]->enemy_sprite.move(rand() % 100 + 300, 10);
	}
}