#pragma once
#include <SDL.h>
#include <map>
namespace GUI {
	class GUI {
	protected:
			SDL_Window* mWindow;
			SDL_Surface* mScreenSurface;
			SDL_Renderer* mRenderer;
			void render(SDL_Texture* pTexture, int x, int y);
			GUI(const char* pTitle, int pW, int pH);
			SDL_Texture* loadTexture(const char* pFilePath);
	public:			
		virtual void clear();
		virtual void display();
		virtual ~GUI();
		};

	class gameGUI : public GUI {
	private:
		std::map<uint8_t, SDL_Texture*> textureMap;
	public:
		gameGUI(const char* pTitle, int pW, int pH) : GUI(pTitle, pW, pH) {}
		void loadTextures();
		void renderTile(int val, int x, int y);
		~gameGUI();
	};
}