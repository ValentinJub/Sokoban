
/* 
file.c 
--------
Par Valentin 

Fonctions chargement et sauvegarde de file 

 */

#include "file.h"



int chargerNiveau(int niveau[][NB_BLOC_HAUTEUR], int*level) {
    FILE* file = NULL;
    char ligneFichier[NB_BLOC_LARGEUR * NB_BLOC_HAUTEUR + 1] = {0};
    int i = 0, j = 0;
    long deplacement = 0;

    file = fopen("src/niveaux.lvl", "r");
    if (file == NULL)
        return 0;

    // definie la valeur de la position du curseur  
    deplacement= *level*(NB_BLOC_HAUTEUR*NB_BLOC_LARGEUR + 1);
    // positionne le curser 
    fseek(file, deplacement, SEEK_SET);
    // recupere la position des sprites dans ligneFichier
    fgets(ligneFichier, NB_BLOC_LARGEUR * NB_BLOC_HAUTEUR + 1, file);

    /*lit le file niveaux et positionne les sprites dans la carte  */ 
    for (i = 0 ; i < NB_BLOC_HAUTEUR; i++)
    {
        for (j = 0 ; j < NB_BLOC_LARGEUR; j++)
        {
            switch (ligneFichier[(i * NB_BLOC_LARGEUR) + j])
            {
                case '0':
                    niveau[i][j] = 0;
                    break;
                case '1':
                    niveau[i][j] = 1;
                    break;
                case '2':
                    niveau[i][j] = 2;
                    break;
                case '3':
                    niveau[i][j] = 3;
                    break;
                case '4':
                    niveau[i][j] = 4;
                    break;
            }
        }
    }

    fclose(file);
    return 1;
}

int sauvegarderNiveau(int niveau[][NB_BLOC_HAUTEUR])
{
    FILE* file = NULL;
    int i = 0, j = 0;

    file = fopen("src/editeur.lvl", "a");
    if (file == NULL)
        return 0;

    for (i = 0 ; i < NB_BLOC_LARGEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOC_HAUTEUR ; j++)
        {
            fprintf(file, "%d", niveau[i][j]);
        }
    }

    fclose(file);
    return 1;
}
