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
	float curr_speed = Lerp(-1.0f, -20.0f, 0.5f);
	for (int i = 0; i < bullet.size(); ++i) {

		windowRef.draw(bullet[i]->ammo_sprite);
		bullet[i]->ammo_sprite.move(0, curr_speed);
		
		//Implement a timer based on frames time elapsed or smth.
		//Just clears the object itself not the memeory allocated, check line 31.
		if (bullet[i]->ammo_sprite.getPosition().y < -1000) {
			bullet.pop_back();
		}

	}

	//Throws an exception on line 18 bcs it can't draw smth that doesn't exist as it
	//deletes faster than the bullet is being drawn so back to the timer we go!

	/*for (auto& p : bullet) {
		delete p;
	}*/
	std::cout << bullet.size() << std::endl;
	bullet.shrink_to_fit(); //Not sure if this does exactly the same thing as line 31.
							//Google got me confused. :D

}
