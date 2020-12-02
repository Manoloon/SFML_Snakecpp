#include "game.h"

int main(int argc,char** argv[])
{
	game Newgame;

	
	while (!Newgame.GetWindow()->IsDone())
	{
		// game loop
		Newgame.HandleInput();
		Newgame.Update();
		Newgame.Render();
		Newgame.RestartClock();
	}
}