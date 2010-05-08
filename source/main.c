// normal includes
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <gccore.h>
#include <wiiuse/wpad.h> 

 
// SDL includes
#include <SDL/sdl.h>
#include <SDL/sdl_image.h>
#include <SDL/SDL_ttf.h>
#include "main.h"





 

 
int main(int argc, char** argv)
{
	int MaxFPS = 30;
	bool done = false;
	GameMode = 1;
	init();
	DoAiMove();
 
	
	while (!done)
        {
		Ticks = SDL_GetTicks();
		SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 23, 125, 54));
        WPAD_ScanPads();
		held = WPAD_ButtonsHeld(0);
		pressed = WPAD_ButtonsDown(0);
		rel     = WPAD_ButtonsUp(0);
		
		if(GameMode == 0) // main menu
		{
		
		}
		
		else if(GameMode == 1) // game
		{
		RenderMap(map);
		DoInput();
		DoMove();
		
		DoCameraUpdate();
		DoAiDraw();
		DoDraw();
		}
		
		else if(GameMode == 2) //pause
		{
		RenderMap(map);
		DoCameraUpdate();
		DoAiDraw();
		DoDraw();
		apply_surface(50,50,menu,screen,NULL);
		DrawMenuItems();
		DoMenuInput();
		UpdateSelected();
		
		}
		
		else if(GameMode == 3) // in depth menu
		{
		}
		
		else if(GameMode == 4) //Battle
		{
		}
		
		else if(GameMode == 5) // Game over
		{
		}
		
		
		
		
		if(held & WPAD_BUTTON_HOME)
		{
			done=true;
			SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
		}
		
		SDL_Flip(screen);
		
		if(SDL_GetTicks() - Ticks < 1000 / MaxFPS)
		{
		SDL_Delay((1000/MaxFPS) - (SDL_GetTicks() - Ticks));
		}
		
        }
 
	cleanup();
 
    return 0;
}