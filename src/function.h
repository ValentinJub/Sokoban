/*
function.h 
-----
Par Valentin Wissler

Prototypes pour fonctions dans function.c 
*/ 

#ifndef DEF_FUNCTION	
#define DEF_FUNCTION


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h"

SDL_Texture* loadTexture(SDL_Renderer*, char*path);
TTF_Font* loadFont(char*path, int size);

#endif