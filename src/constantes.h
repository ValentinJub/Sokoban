/*
constantes.h
------------

Par Valentin Wissler


Define constantes for program such as Window and Bloc size



*/

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define TAILLE_BLOC 34
#define NB_BLOC_LARGEUR 13
#define NB_BLOC_HAUTEUR 13
#define LARGEUR_FENETRE TAILLE_BLOC * NB_BLOC_LARGEUR 
#define HAUTEUR_FENETRE TAILLE_BLOC * NB_BLOC_HAUTEUR 

enum {HAUT, BAS, GAUCHE, DROITE};
enum {VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK};


#endif

