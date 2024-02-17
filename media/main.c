#include "main.h"

int main(void){
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	SDL_Texture *textureMenu;
	bool continuer = true;

	 /* Initialisation SDL */
    if((SDL_Init(SDL_INIT_VIDEO))!=0) {
        printf("oups");
    }
    /* Creaton fenêtre + renderer */
    if ((SDL_CreateWindowAndRenderer(408, 408, SDL_WINDOW_OPENGL, &window, &renderer))==-1) {
	    printf("oups");
    }

    /* Render Menu & Display it on screen */
    surface = IMG_Load("media/menu.jpg");
    textureMenu = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, textureMenu, NULL, NULL);
    SDL_DestroyTexture(textureMenu);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    
    while (continuer){
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type){	
    	case SDL_QUIT:
    	SDL_DestroyWindow(window);
	SDL_DestroyTexture(textureMenu);
	SDL_Quit();
	return EXIT_SUCCESS;
    }
    }
}

