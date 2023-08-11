#pragma once
#include <SDL.h>
#include "GUI.h"
#include "GameLogic.h"
namespace Game
{
	struct ButtonBounds {
		int startX, startY, endX, endY;
		ButtonBounds(int sx, int sy, int ex, int ey)
			: startX(sx), startY(sy), endX(ex), endY(ey) {}
		bool withinBounds(int, int);
	};

	class Game {
	private:
		GUI::gameGUI gGUI;
		GameLogic::Board* board;
		ButtonBounds redoBtn{ 851, 502, 1011, 567 };
		ButtonBounds undoBtn{ 1045, 502, 1205, 567 };
		ButtonBounds restartBtn{ 826, 586, 1230, 651 };
		void PressButton();
		GameLogic::Direction keyEvent(SDL_Event& E);
		void restartGame();
	public:
		Game();
		void run();
	};


};

