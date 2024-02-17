/*
level_editor.h
-----
Par Valentin Wissler

Prototypes pour fonctions dans level_editor.c
*/ 

#ifndef DEF_EDITEUR
#define DEF_EDITEUR


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h"
#include "file.h"
#include "game.h"
#include "function.h"

void level_editor(SDL_Renderer*);
int manuelEditeur(SDL_Renderer*renderer, TTF_Font*font);

#endif

