/* 
file.h 
--------
Par Valentin 

Prototype de fonctions chargement et sauvegarde de file 
*
 */


#ifndef DEF_FILE
#define DEF_FILE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "constantes.h"


int chargerNiveau(int niveau[][NB_BLOC_HAUTEUR], int*);
int sauvegarderNiveau(int niveau[][NB_BLOC_HAUTEUR]);


#endif
