#include <SFML/Graphics.hpp>

sf::FloatRect top_b, left_b, right_b, bot_b;

void make_boundaries() {
	top_b.top = 0;
	top_b.left = 0;
	top_b.height = 10;
	top_b.width = 1280;


	left_b.top = 0;
	left_b.left = 0;
	left_b.height = 800;
	left_b.width = 10;


	bot_b.top = 470;
	bot_b.left = 1280;
	bot_b.height = 10;
	bot_b.width = -1290;


	right_b.top = 720;
	right_b.left = 1100;
	right_b.height = -800;
	right_b.width = -10;
}
