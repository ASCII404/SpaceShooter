#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ammo.h"
#include "Ship.h"
#include <iostream>

//USED LINEAR INTERPOLATION
float ammo::Lerp(float x, float y, float z) {
	return ((1.0f - z) * x) + (z * y);
}

void ammo::ammo_movement(sf::RenderWindow& windowRef) {

	float curr_speed = Lerp(-1.0f, -30.0f, 0.5f);
	for (int i = 0; i < bullet.size(); ++i) {

		windowRef.draw(bullet[i]->ammo_sprite);

		bullet[i]->ammo_sprite.move(0, curr_speed);
	}
}