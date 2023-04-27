#include <SFML/Graphics.hpp>
#include "Game.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    Game g(1280, 720, "SpaceShooter");
    g.make_window();
    g.Run();
    return 0;
}
