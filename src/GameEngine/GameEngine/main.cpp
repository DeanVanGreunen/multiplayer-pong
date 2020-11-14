#include "game.h";

using namespace softartstudios;

int main()
{
	Game game = Game();
	game.setGameName("Pong by SoftArt Studios");
	game.setDebugMode(true);
	game.Run();

	return 0;
}