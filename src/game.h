/*
game.h 
-----
Par Valentin Wissler

Prototypes pour fonctions dans game.c 
*/ 

#ifndef DEF_GAME	
#define DEF_GAME


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h"
#include "file.h"
#include "function.h"

int manuelJeu(SDL_Renderer*renderer, TTF_Font*font);
void compteurMouvement(SDL_Renderer*renderer, int mouvement, TTF_Font*font);
int nextOrQuit(SDL_Renderer*, int, TTF_Font*, int);
void gameOver(SDL_Renderer*, TTF_Font*);
void jouer(SDL_Renderer*);
void ecranFin(SDL_Renderer*);

void  deplacerCaisse(int *premiereCase, int *deuxiemeCase, int *troisiemeCase);
void deplacerCaisse2(int carte[][NB_BLOC_HAUTEUR], SDL_Rect *pos, int direction);
void pauseAh(void);// pause programs execution  

int deplacerJoueur(int carte[][NB_BLOC_HAUTEUR], SDL_Rect *pos, int direction);
#endif

