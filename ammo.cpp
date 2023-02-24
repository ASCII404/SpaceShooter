#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ammo.h"
#include "Ship.h"

void ammo::ammo_movement(sf::RenderWindow &windowRef) {
	for (int i = 0; i < bullet.size(); ++i) {
		windowRef.draw(bullet[i]->ammo_sprite);
		bullet[i]->ammo_sprite.move(0, -3);
	}
}