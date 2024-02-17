/*
main.c
------

Par Valentin Wissler

Main game menu - allows to chose from level editor to play mode 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constantes.h"
#include "game.h"
#include "level_editor.h"
#include "file.h"


int main(int argc, char *argv[])
{
	SDL_Surface *surface;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Texture *texture;
	SDL_Event event;
	bool continuer = true;


	 /* Initialisation SDL */
    if((SDL_Init(SDL_INIT_VIDEO))!=0) {
        printf("oups");
    }
    TTF_Init();
    if(TTF_Init() < 0)
    {
    	fprintf(stderr, "Oups error d'ouverture TTF: %s \n", TTF_GetError());
	EXIT_FAILURE;
    }
    /* Creaton fenêtre + renderer */
    if ((SDL_CreateWindowAndRenderer(LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_OPENGL, &window, &renderer))==-1) {
	    printf("oups");
    }

    /* Render Menu & Display it on screen */
    surface = IMG_Load("media/menu.jpg");
	if(surface == NULL) {
		fprintf(stderr, "Erreur de chargement de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
    texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(texture == NULL) {
		fprintf(stderr, "Erreur de chargement de la texture : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

	/* Main Menu */
    while (continuer)
    {
   	 SDL_WaitEvent(&event);
   	 switch (event.type)
	 {	
    	   case SDL_QUIT:
		continuer = false;
		break;
	   case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
		   case SDLK_ESCAPE:
			continuer = false; 
			break;
	       	   case SDLK_1:
			jouer(renderer);
			break;
		   case SDLK_2:
			level_editor(renderer); 
			break;
		}
		break;
	   }
    }
	TTF_Quit();
 	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
		
}
