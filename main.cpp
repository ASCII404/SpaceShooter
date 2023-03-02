#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "ammo.h"
#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
//IMPLEMENT LIMITS (kind of did but I have to work on it)
//IMPLEMENT AUTO DESTROY FOR BULLETS TO FREE MEMORY //Working on it
//DOCUMENT YOUR CODE
//SOLVE ENEMY

int main()
{
	Ship s;
	ammo a;
	Enemy e;

	sf::Texture texture_bg;
	sf::Sprite sprite_bg;
	texture_bg.loadFromFile("bg2.jpg");
	sprite_bg.setTexture(texture_bg);
	sf::RenderWindow window;

	window.create(sf::VideoMode(1280, 720), "SpaceShooter");
	window.setFramerateLimit(140);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == event.KeyPressed) {
				if (event.key.code == sf::Keyboard::Key::Space) {
					s.shoot(window);
				}
			}

		}

		window.clear();
		window.setKeyRepeatEnabled(true);
		window.draw(sprite_bg);
		window.draw(s.get_ship_sprite());
		s.ship_movement();
		s.ammo_movement(window);
		window.draw(e.get_enemy_sprite());
		window.display();
	}
	return 0;
}

