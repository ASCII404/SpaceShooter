#include "ammo.h"

void ammo::bullet_movement() {

	/*sf::Clock clock;
	sf::Time elapsed = clock.restart();
    sf::Vector2f direction(0, 0);
	const sf::Time update_ms = sf::seconds(1.f / 30.f);

	elapsed += clock.restart();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && get_ammo_position().y<500) {
        while (elapsed >= update_ms) {
            const auto pos = ball.getPosition();
            const auto delta = update_ms.asSeconds() * velocity;
            sf::Vector2f new_pos(pos.x + direction.x * delta, pos.y + direction.y * delta);

            if(ammo_sprite.getPosition().y < 720)
                direction.x
            if (new_pos.x - ball_radius < 0) { // left window edge
                direction.x *= -1;
                new_pos.x = 0 + ball_radius;
            }
            else if (new_pos.x + ball_radius >= window_width) { // right window edge
                direction.x *= -1;
                new_pos.x = window_width - ball_radius;
            }
            else if (new_pos.y - ball_radius < 0) { // top of window
                direction.y *= -1;
                new_pos.y = 0 + ball_radius;
            }
            else if (new_pos.y + ball_radius >= window_height) { // bottom of window
                direction.y *= -1;
                new_pos.y = window_height - ball_radius;
            }
            ball.setPosition(new_pos);

            elapsed -= update_ms;
        }
	}
    */ //SOME STOLEN CODE, DK HOW EXACTLY WORKS YET GOTTA GO TO THE GYM.
}