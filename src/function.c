/*
main.c
------

Par Valentin Wissler

Main game menu - allows to chose from level editor to play mode 
 */ 

#include "function.h"

SDL_Texture* loadTexture(SDL_Renderer*renderer, char*path) {

	SDL_Surface *s = IMG_Load(path);
	if(s==NULL)
	{
		fprintf(stderr, "Erreur de chargement de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Texture *texture= SDL_CreateTextureFromSurface(renderer,s);
	if(texture==NULL)
	{
		fprintf(stderr, "Erreur de chargement de la texture : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(s); 
	return texture;
}

TTF_Font* loadFont(char*path, int size) {
    TTF_Font *font = TTF_OpenFont(path, size);
    if(font==NULL)
    {
        fprintf(stderr, "Erreur de chargement de la police : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    return font;
}