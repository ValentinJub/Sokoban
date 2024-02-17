/*
editeur.h
-----
Par Valentin Wissler

Prototypes pour fonctions dans editeur.c
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
#include "fichier.h"
#include "jeu.h"
#include "function.h"

void editeur(SDL_Renderer*);
int manuelEditeur(SDL_Renderer*renderer, TTF_Font*font);

#endif

