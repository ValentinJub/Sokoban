/* 
 jeu.c
 -----
 Par Valentin Wissler

 Fonctions principales du jeu, affichage sprites, mouvements et collisions et boucle du jeu

 
*/

#include "jeu.h"

void compteurMouvement(SDL_Renderer*renderer, int mouvement, TTF_Font*font)
{
	SDL_Surface*surface; 
	SDL_Texture*texture;
	SDL_Rect rect;
	SDL_Color couleurRouge = {0,0,0};
	char compteur[100];

	sprintf(compteur, "%d",mouvement);

	surface = TTF_RenderText_Blended(font,compteur,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);

	rect.h=TAILLE_BLOC;
	rect.w=TAILLE_BLOC;
	rect.y=TAILLE_BLOC*12;
	rect.x=TAILLE_BLOC*12;

	SDL_RenderCopy(renderer,texture,NULL,&rect);
	
	
}

int manuelJeu(SDL_Renderer*renderer, TTF_Font*font)
{
	SDL_Surface*surface; 
	SDL_Texture*texture;
	SDL_Rect rect1, rect2,rect3;
	SDL_Event event;
	SDL_Color couleurRouge = {0,0,0};
	char phrase1[100],phrase2[100],phrase3[100];
	int resultat=2;
	bool continuer = true;

	texture = loadTexture(renderer,"media/bgintro.png");
	SDL_RenderCopy(renderer,texture,NULL,NULL);


	sprintf(phrase1, "Use arrow keys to move Mario");
	surface = TTF_RenderText_Blended(font,phrase1,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect1.h=TAILLE_BLOC*2;
	rect1.w=TAILLE_BLOC*13;
	rect1.y=(((TAILLE_BLOC*13)/2)-(rect1.h/2))-rect1.h;
	rect1.x=0;

	SDL_RenderCopy(renderer,texture,NULL,&rect1);
	
	sprintf(phrase2, "Press 1 to continue");
	surface = TTF_RenderText_Blended(font,phrase2,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect2.h=TAILLE_BLOC*2;
	rect2.w=TAILLE_BLOC*9;
	rect2.y=(((TAILLE_BLOC*13)/2)-(rect2.h/2));
	rect2.x=(((TAILLE_BLOC*13)/2)-(rect2.w/2));
	SDL_RenderCopy(renderer,texture,NULL,&rect2);
	
	sprintf(phrase3, "Press ESC to exit");
	surface = TTF_RenderText_Blended(font,phrase3,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect3.h=TAILLE_BLOC*2;
	rect3.w=TAILLE_BLOC*8;
	rect3.y=rect2.y+rect2.h;
	rect3.x=(((TAILLE_BLOC*13)/2)-(rect3.w/2));
	SDL_RenderCopy(renderer,texture,NULL,&rect3);


	SDL_RenderPresent(renderer);

	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
			resultat = 0;
			continuer=false;
			break;
			case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				resultat = 0;
				continuer=false;
				break;
				case SDLK_1:
				resultat = 1;
				continuer=false;
				break;
				case SDLK_0:
				resultat = 0;
					continuer=false;
				break;
			} 
		}
	}
	return resultat;	
	
}




int nextOrQuit(SDL_Renderer*renderer, int mouvement, TTF_Font*font, int level)
{
	SDL_Surface*surface; 
	SDL_Texture*texture;
	SDL_Rect rect1, rect2,rect3;
	SDL_Event event;
	SDL_Color couleurRouge = {0,0,0};
	char phrase1[100],phrase2[100],phrase3[100];
	int resultat=2;
	bool continuer = true;

	/* creation fond  uni 
	SDL_SetRenderDrawColor(renderer,175,0,255,255);
	SDL_RenderClear(renderer); */

	sprintf(phrase1, "Level %d complete in %d moves!",level, mouvement);
	surface = TTF_RenderText_Blended(font,phrase1,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect1.h=TAILLE_BLOC*2;
	rect1.w=TAILLE_BLOC*13;
	rect1.y=(((TAILLE_BLOC*13)/2)-(rect1.h/2))-rect1.h;
	rect1.x=0;

	SDL_RenderCopy(renderer,texture,NULL,&rect1);
	
	sprintf(phrase2, "Press 1 for next level");
	surface = TTF_RenderText_Blended(font,phrase2,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect2.h=TAILLE_BLOC*2;
	rect2.w=TAILLE_BLOC*9;
	rect2.y=(((TAILLE_BLOC*13)/2)-(rect2.h/2));
	rect2.x=(((TAILLE_BLOC*13)/2)-(rect2.w/2));
	SDL_RenderCopy(renderer,texture,NULL,&rect2);
	
	sprintf(phrase3, "Press 0 to exit");
	surface = TTF_RenderText_Blended(font,phrase3,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect3.h=TAILLE_BLOC*2;
	rect3.w=TAILLE_BLOC*8;
	rect3.y=rect2.y+rect2.h;
	rect3.x=(((TAILLE_BLOC*13)/2)-(rect3.w/2));
	SDL_RenderCopy(renderer,texture,NULL,&rect3);


	SDL_RenderPresent(renderer);

	while(continuer)
	{
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
		   resultat = 0;
		   continuer=false;
		   break;
		case SDL_KEYDOWN:
		   switch(event.key.keysym.sym)
		   {
		      case SDLK_ESCAPE:
			 resultat = 0;
			 continuer=false;
			 break;
		      case SDLK_1:
			 resultat = 1;
			 continuer=false;
			 break;
		      case SDLK_0:
			 resultat = 0;
		         continuer=false;
			 break;
		   } 
	}
	
	}
	return resultat;	
	
}

void gameOver(SDL_Renderer*renderer, TTF_Font*font)
{
	SDL_Surface*surface; 
	SDL_Texture*texture;
	SDL_Rect rect1; 
	SDL_Color couleurRouge = {0,0,0};
	char phrase1[100];
	
	surface = IMG_Load("media/bgintro.png");
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_RenderCopy(renderer,texture,NULL,NULL);


	sprintf(phrase1, ":( Play again soon!");
	surface = TTF_RenderText_Blended(font,phrase1,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect1.h=TAILLE_BLOC*2;
	rect1.w=TAILLE_BLOC*13;
	rect1.y=(((TAILLE_BLOC*13)/2)-(rect1.h/2));
	rect1.x=0;

	SDL_RenderCopy(renderer,texture,NULL,&rect1);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);

}

void pauseAh(void)
{
SDL_Event event;
bool jouer = true;

while (jouer)
	{
	SDL_WaitEvent(&event);
	switch (event.type)
		{
			case SDL_QUIT:
				jouer = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					jouer = false;
					break;

				}
		}	
	}
}

void jouer(SDL_Renderer*renderer)
{
	SDL_Surface*surface;
	SDL_Texture *textureMarioActuel; //Pointeur sur *mario 
	SDL_Texture *mario[4]={NULL}; // Tableau de textures pour chaque sprite de mario
	SDL_Rect position = {0}, positionJoueur = {0};
	SDL_Event event;
	TTF_Font *font;
	
	bool jouer = true, continuer = true, playAgain = true, win = true;  
	int i = 0, j = 0, objectifsRestants =0; // vont permettre de parcourir carte 
	int carte[NB_BLOC_LARGEUR][NB_BLOC_HAUTEUR]={0}; // carte du jeu 
	int level = 0, mouvement = 0;
	int *plevel = &level;

	SDL_Texture *textureMur = loadTexture(renderer,"media/mur.png"),
		    *textureVide = loadTexture(renderer,"media/ground_01.png"),
		    *textureCaisse= loadTexture(renderer,"media/box.png"),
		    *textureCaisseOk = loadTexture(renderer,"media/boxOK.png"),
		    *textureObjectif = loadTexture(renderer,"media/objAlt.png");
		    mario[HAUT]= loadTexture(renderer,"media/mario_haut.png");
		    mario[BAS]= loadTexture(renderer,"media/mario_bas.png");
		    mario[GAUCHE]= loadTexture(renderer,"media/mario_gauche.png");
		    mario[DROITE]= loadTexture(renderer,"media/mario_droite.png");

	textureMarioActuel = mario[BAS];

	// Chargement font 
	font = loadFont("media/hackbold.ttf",500); 
	
	if(!manuelJeu(renderer, font))
	{
		playAgain=false;
	}

	while(playAgain)
	{
	
	//Chargement du niveau
	if(!(chargerNiveau(carte, plevel))) {
		fprintf(stderr, "Erreur de chargement du niveau\n");
		exit(EXIT_FAILURE);
	}

	level++;
	
	/*Check for Mario's starting position on the map */ 

	mouvement = 0;
	jouer = true;
	while(jouer)
	{

	// Fill background in white  
	SDL_SetRenderDrawColor(renderer,255,255,255,255);	
	SDL_RenderClear(renderer);
	
	// Look for Mario on the map 
	for(i=0;i<NB_BLOC_HAUTEUR;i++)
		{
			for(j=0;j<NB_BLOC_LARGEUR;j++)
			{
				if(carte[i][j] == MARIO)
				{
					positionJoueur.x = j;
					positionJoueur.y = i;
					positionJoueur.h = TAILLE_BLOC;
					positionJoueur.w = TAILLE_BLOC;
					carte[i][j] = VIDE;
				}

			}
		}
	
	// Placement des objects a l'ecran 
	objectifsRestants=0;
	
	for(i=0;i<NB_BLOC_HAUTEUR;i++)
	{
		for(j=0;j<NB_BLOC_LARGEUR;j++)
		{
			position.y=i*TAILLE_BLOC;
			position.x=j*TAILLE_BLOC;
			position.h=TAILLE_BLOC;
			position.w=TAILLE_BLOC;

			switch(carte[i][j])
			{
				case VIDE:
				   SDL_RenderCopy(renderer,textureVide,NULL,&position);
				   break;
				case MUR:
				   SDL_RenderCopy(renderer,textureMur,NULL,&position);
				   break;
				case CAISSE:
				   SDL_RenderCopy(renderer,textureCaisse,NULL,&position);
				   break;
				case CAISSE_OK:
				   SDL_RenderCopy(renderer,textureCaisseOk,NULL,&position);
				   break;
				case OBJECTIF:
				   SDL_RenderCopy(renderer,textureObjectif,NULL,&position);
				   objectifsRestants=1;
				   break;

			}
						
		}	
	}
	// On affiche mario
	position.x = positionJoueur.x*TAILLE_BLOC;
	position.y = positionJoueur.y*TAILLE_BLOC;
	position.h = TAILLE_BLOC;
	position.w = TAILLE_BLOC;
	SDL_RenderCopy(renderer,textureMarioActuel,NULL,&position);

	// on affiche le compteur 
	compteurMouvement(renderer,mouvement,font);


	// on affiche le tout a l'ecran 
	SDL_RenderPresent(renderer);

	// Si on ne trouve pas d'objectif sur la map on a gagné 
	if(!(objectifsRestants))
	{
		jouer = false;
	}


	if(!(jouer))
	{
		SDL_Delay(1500);
	}
		
	continuer = true;
	while(continuer && jouer)
	{
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
		   jouer=false;
		   continuer=false;
		   win = false;
		   break;
		case SDL_KEYDOWN:
		   switch(event.key.keysym.sym)
		   {
		      case SDLK_ESCAPE:
			 jouer = false;
			 continuer=false;
			 win = false;
			 break;
		      case SDLK_UP:
			 textureMarioActuel=mario[HAUT];
			 if(deplacerJoueur(carte, &positionJoueur, HAUT))
			 {
				mouvement ++;
			 }
			 continuer=false;
			 break;
		      case SDLK_DOWN:
			 textureMarioActuel=mario[BAS];
			 if(deplacerJoueur(carte, &positionJoueur, BAS))
			 {
				mouvement ++;
			 }
		         continuer=false;
			 break;
		      case SDLK_LEFT:
			 textureMarioActuel=mario[GAUCHE];
			 if(deplacerJoueur(carte, &positionJoueur, GAUCHE))
			 {
				mouvement ++;
			 }
		         continuer=false;
			 break;
		      case SDLK_RIGHT:
			 textureMarioActuel=mario[DROITE];
			 if(deplacerJoueur(carte, &positionJoueur, DROITE))
			 {
				mouvement ++;
			 }
		         continuer=false;
			 break;
		   break;

		   } 
		   break;
	}

	} // continuer end
	
	}// jouer end 

	if(win)
	{
		if(!nextOrQuit(renderer, mouvement, font, level))
		{
			playAgain = false;
			gameOver(renderer, font);
		}
	} else 
	{
		gameOver(renderer, font);
		playAgain = false;
	}
	} // playAgain end 

	TTF_CloseFont(font);
	SDL_DestroyTexture(textureMur);
	SDL_DestroyTexture(textureCaisse);
	SDL_DestroyTexture(textureCaisseOk);
	SDL_DestroyTexture(textureObjectif);
	SDL_DestroyTexture(textureMarioActuel);

}


int deplacerJoueur(int carte[][NB_BLOC_HAUTEUR], SDL_Rect *pos, int direction)
{
switch(direction)
	{
	case HAUT:
		// PORTAL TIME 
		if(pos->y - 1 < 0) 
		{
			// if portal down is a box and above it is W || B || B_OK > Break 
			if(carte[NB_BLOC_HAUTEUR-1][pos->x] == CAISSE && (carte[NB_BLOC_HAUTEUR-2][pos->x]==MUR ||carte[NB_BLOC_HAUTEUR-2][pos->x]==CAISSE ||carte[NB_BLOC_HAUTEUR-2][pos->x]==CAISSE_OK))
			{
				return 0;
			}
			// if portal down is a W || OBJ || B_OK > Break 
			else if(carte[NB_BLOC_HAUTEUR-1][pos->x] == MUR || carte[NB_BLOC_HAUTEUR-1][pos->x] == OBJECTIF || carte[NB_BLOC_HAUTEUR-1][pos->x] == CAISSE_OK)
			{
				return 0;
			}
			// if portal down is B and above it is OBJ 
			else if(carte[NB_BLOC_HAUTEUR-1][pos->x] == CAISSE && carte[NB_BLOC_HAUTEUR-2][pos->x] ==OBJECTIF)
			{
				carte[NB_BLOC_HAUTEUR-1][pos->x] = MARIO;
				carte[NB_BLOC_HAUTEUR-2][pos->x] = CAISSE_OK;
				return 1;
			}
			else if(carte[NB_BLOC_HAUTEUR-1][pos->x]==CAISSE && carte[NB_BLOC_HAUTEUR-2][pos->x]==VIDE)
			{
				carte[NB_BLOC_HAUTEUR-2][pos->x]=CAISSE; 
				carte[NB_BLOC_HAUTEUR-1][pos->x]=MARIO;
				return 1;
				
			}
			// if portal down is empty 
			else if(carte[NB_BLOC_HAUTEUR-1][pos->x] == VIDE)
			{
			carte[NB_BLOC_HAUTEUR-1][pos->x] = MARIO;
			return 1;
			}
			
		
		}	
		// if above is a wall 
		if(carte[pos->y - 1][pos->x] == MUR || carte[pos->y - 1][pos->x] == OBJECTIF)
		{
			return 0;
		}
		/* If cell above M is a C || Cok && if 2 cells above is W || C || Cok dnt move 
		if ((carte[pos->y - 1][pos->x] == CAISSE || carte[pos->y - 1][pos->x] == CAISSE_OK) &&
    (carte[pos->y - 2][pos->x] == MUR ||
    carte[pos->y - 2][pos->x] == CAISSE || carte[pos->y - 2][pos->x] == CAISSE_OK))    		        
		{
		return 0;
		} */ 
		// on peut deplqcer si all above is false 
		// D'abord on check si une caisse est en haut et la deplace si possible
		deplacerCaisse2(carte, pos, direction);
		// on fait monter mario que si la case du dessus est vide
		if(carte[pos->y-1][pos->x]==CAISSE ||carte[pos->y-1][pos->x]==CAISSE_OK)
		{
			return 0;
		}
		// Mario monte 
		pos->y--;  	
		carte[pos->y][pos->x] = MARIO;
		return 1;
	case BAS:
		// Portal time 
		if(pos->y + 1 > (NB_BLOC_HAUTEUR - 1))
		{		// if portal up is a box and above it is W || B || B_OK > Break 
			if(carte[0][pos->x] == CAISSE && (carte[0+1][pos->x]==MUR ||carte[0+1][pos->x]==CAISSE ||carte[0+1][pos->x]==CAISSE_OK))
			{
				return 0;
			}
			// if portal up is a W || OBJ || B_OK > Break 
			else if(carte[0][pos->x] == MUR || carte[0][pos->x] == OBJECTIF || carte[0][pos->x] == CAISSE_OK)
			{
				return 0;
			}
			// if portal up is B and above it is OBJ 
			else if(carte[0][pos->x] == CAISSE && carte[0+1][pos->x] ==OBJECTIF)
			{
				carte[0][pos->x] = MARIO;
				carte[0+1][pos->x] = CAISSE_OK;
				return 1;
			}
			else if(carte[0][pos->x]==CAISSE && carte[0+1][pos->x]==VIDE)
			{
				carte[0+1][pos->x]=CAISSE; 
				carte[0][pos->x]=MARIO;
				return 1;
				
			}
			// if portal up is empty 
			else if(carte[0][pos->x] == VIDE)
			{
			carte[0][pos->x] = MARIO;
			return 1;
			}
		
		}

		if(carte[pos->y + 1][pos->x] == MUR || carte[pos->y + 1][pos->x] == OBJECTIF)
		{
			return 0;
		}

		/*if ((carte[pos->y + 1][pos->x] == CAISSE || carte[pos->y + 1][pos->x] == CAISSE_OK) &&
    (carte[pos->y + 2][pos->x] == MUR ||
    carte[pos->y + 2][pos->x] == CAISSE || carte[pos->y + 2][pos->x] == CAISSE_OK))    		        
		{	
			return 0;
		} */ 

		// D'abord on check si une caisse est en bas et la deplace si possible
		deplacerCaisse2(carte, pos, direction);
		// on fait descendre mario que si la case du dessous est vide
		if(carte[pos->y+1][pos->x]==CAISSE ||carte[pos->y+1][pos->x]==CAISSE_OK)
		{
			return 0;
		}

		pos->y++;  	
		carte[pos->y][pos->x] = MARIO;
		return 1;

	case GAUCHE:
		if(pos->x - 1 < 0) 
		{	
			// if portal right is a box and above it is W || B || B_OK > Break 
			if(carte[pos->y][NB_BLOC_LARGEUR-1] == CAISSE && (carte[pos->y][NB_BLOC_LARGEUR-2]==MUR ||carte[pos->y][NB_BLOC_LARGEUR-2]==CAISSE ||carte[pos->y][NB_BLOC_LARGEUR-2]==CAISSE_OK))
			{
				return 0;
			}
			// if portal right is a W || OBJ || B_OK > Break 
			else if(carte[pos->y][NB_BLOC_LARGEUR-1]== MUR || carte[pos->y][NB_BLOC_LARGEUR-1] == OBJECTIF || carte[pos->y][NB_BLOC_LARGEUR-1]== CAISSE_OK)
			{
				return 0;
			}
			// if portal right is B and above it is OBJ 
			else if(carte[pos->y][NB_BLOC_LARGEUR-1]== CAISSE && carte[pos->y][NB_BLOC_LARGEUR-2]==OBJECTIF)
			{
				carte[pos->y][NB_BLOC_LARGEUR-1] = MARIO;
				carte[pos->y][NB_BLOC_LARGEUR-2] = CAISSE_OK;
				return 1;
			}
			else if(carte[pos->y][NB_BLOC_LARGEUR-1]==CAISSE && carte[pos->y][NB_BLOC_LARGEUR-2]==VIDE)
			{
				carte[pos->y][NB_BLOC_LARGEUR-2]=CAISSE; 
				carte[pos->y][NB_BLOC_LARGEUR-1]=MARIO;
				return 1;
				
			}
			// if portal right is empty 
			else if(carte[pos->y][NB_BLOC_LARGEUR-1]== VIDE)
			{
			carte[pos->y][NB_BLOC_LARGEUR-1] = MARIO;
			return 1;
			}
		}
		if(carte[pos->y][pos->x - 1] == MUR || carte[pos->y][pos->x - 1] == OBJECTIF)
		{
			return 0;
		}
		/* if ((carte[pos->y][pos->x - 1] == CAISSE || carte[pos->y][pos->x - 1] == CAISSE_OK) &&
    (carte[pos->y][pos->x - 2] == MUR ||
    carte[pos->y][pos->x - 2] == CAISSE || carte[pos->y][pos->x - 2] == CAISSE_OK))   		        
		{
			int wut =carte[pos->y][pos->x-2]; 
			printf("%d",wut);
			return 0;
		} */ 
		// D'abord on check si une caisse est a gauche et la deplace si possible
		deplacerCaisse2(carte, pos, direction);
		// on fait bouger    mario que si la case du gauche est vide
		if(carte[pos->y][pos->x-1]==CAISSE ||carte[pos->y][pos->x-1]==CAISSE_OK)
		{
			return 0;
		}

		pos->x--;  	
		carte[pos->y][pos->x] = MARIO;
		return 1;
		
	break;
	case DROITE:
		if(pos->x + 1 > NB_BLOC_LARGEUR-1)
		{
			// if portal left is a box and above it is W || B || B_OK > Break 
			if(carte[pos->y][0] == CAISSE && (carte[pos->y][0+1]==MUR ||carte[pos->y][0+1]==CAISSE ||carte[pos->y][0+1]==CAISSE_OK))
			{
				return 0;
			}
			// if portal left is a W || OBJ || B_OK > Break 
			else if(carte[pos->y][0]== MUR || carte[pos->y][0] == OBJECTIF || carte[pos->y][0]== CAISSE_OK)
			{
				return 0;
			}
			// if portal left is B and above it is OBJ 
			else if(carte[pos->y][0]== CAISSE && carte[pos->y][0+1]==OBJECTIF)
			{
				carte[pos->y][0] = MARIO;
				carte[pos->y][0+1] = CAISSE_OK;
				return 1;
			}
			else if(carte[pos->y][0]==CAISSE && carte[pos->y][0+1]==VIDE)
			{
				carte[pos->y][0+1]=CAISSE; 
				carte[pos->y][0]=MARIO;
				return 1;
				
			}
			// if portal left is empty 
			else if(carte[pos->y][0]== VIDE)
			{
			carte[pos->y][0] = MARIO;
			return 1;

			}
		}
		if(carte[pos->y][pos->x + 1] == MUR || carte[pos->y][pos->x + 1] == OBJECTIF) 
		{
			return 0;
		}
		/* if ((carte[pos->y][pos->x + 1] == CAISSE || carte[pos->y][pos->x + 1] == CAISSE_OK) &&
    (carte[pos->y][pos->x + 2] == MUR ||
    carte[pos->y][pos->x + 2] == CAISSE || carte[pos->y][pos->x + 2] == CAISSE_OK))    		        
		{
			return 0;
		} */ 
		// D'abord on check si une caisse est a droite et la deplace si possible
		deplacerCaisse2(carte, pos, direction);
		// on fait bouger  mario que si la case du droite  est vide
		if(carte[pos->y][pos->x+1]==CAISSE ||carte[pos->y][pos->x+1]==CAISSE_OK)
		{
			return 0;
		}

		pos->x++;  	
		carte[pos->y][pos->x] = MARIO;
		return 1;
		
	break;
	 } // switch end 
return 0;
}
void deplacerCaisse2(int carte[][NB_BLOC_HAUTEUR], SDL_Rect *pos, int direction)
{
switch(direction)
	{
		case HAUT:
			// if above cell is C and 2 cells up is OOB 
			if(carte[pos->y-1][pos->x]==CAISSE && pos->y-2 < 0)
			{
				// if cell portal down is already occupied by B || B_OK> || W > break 
				if(carte[NB_BLOC_HAUTEUR-1][pos->x] == CAISSE || carte[NB_BLOC_HAUTEUR-1][pos->x] == CAISSE_OK || carte[NB_BLOC_HAUTEUR-1][pos->x] == MUR)
				{
					break;
				}
				// if cell portal down is OBJ 
				else if(carte[NB_BLOC_HAUTEUR-1][pos->x]==OBJECTIF)
				{
					carte[NB_BLOC_HAUTEUR-1][pos->x]=CAISSE_OK;
					carte[pos->y-1][pos->x]=VIDE;
					break;

				}
				// if cell portal down is empty 
				else 
				{
					carte[NB_BLOC_HAUTEUR-1][pos->x]=CAISSE;
					carte[pos->y-1][pos->x]=VIDE;
					break;
				}							
			}

			// if 2 cells above is W || C || C_OK > break  
			else if(carte[pos->y-2][pos->x]==MUR || carte[pos->y-2][pos->x]==CAISSE || carte[pos->y-2][pos->x]==CAISSE_OK) 
			{
				break;
			}
					        // if cell above is Box or  and 2 cells up is empty or objective	
			else if(carte[pos->y-1][pos->x]==CAISSE && (carte[pos->y-2][pos->x]==VIDE || carte[pos->y-2][pos->x]==OBJECTIF))
			{
				// if 2 cells above is empty
				if(carte[pos->y-2][pos->x]==VIDE)
				{
						carte[pos->y-2][pos->x]=CAISSE;
						carte[pos->y-1][pos->x]=VIDE;

				}	
				// if cell above is objectif 
				else
				{
				carte[pos->y-2][pos->x]=CAISSE_OK;;
				carte[pos->y-1][pos->x]=VIDE;
				}
			}
			break;
		case BAS:
			// if below Mario isnt a box > break 
			if(carte[pos->y+1][pos->x]!=CAISSE)
			{
				break;
			}
			// if below cell is C and 2 cells up is OOB 
			else if(carte[pos->y+1][pos->x]==CAISSE && pos->y+2 > NB_BLOC_HAUTEUR-1)
			{
				// if cell portal up is already occupied by B || B_OK> || W > break 
				if(carte[0][pos->x] == CAISSE || carte[0][pos->x] == CAISSE_OK || carte[0][pos->x] == MUR)
				{
					break;
				}
				// if cell portal up is OBJ 
				else if(carte[0][pos->x]==OBJECTIF)
				{
					carte[0][pos->x]=CAISSE_OK;
					carte[pos->y+1][pos->x]=VIDE;
					break;

				}
				// if cell portal up is empty 
				else 
				{
					carte[0][pos->x]=CAISSE;
					carte[pos->y+1][pos->x]=VIDE;
					break;
				}							
			}

			// if 2 cells below is W || C || C_OK > break  
			else if(carte[pos->y+2][pos->x]==MUR || carte[pos->y+2][pos->x]==CAISSE || carte[pos->y+2][pos->x]==CAISSE_OK) 
			{
				break;
			}
					        // if cell below is Box and 2 cells up is empty or objective	
			else if((carte[pos->y+2][pos->x]==VIDE || carte[pos->y+2][pos->x]==OBJECTIF) && carte[pos->y+1][pos->x]==CAISSE)
			{
				// if cell below is empty
				if(carte[pos->y+2][pos->x]==VIDE)
				{
				carte[pos->y+2][pos->x]=CAISSE;
				carte[pos->y+1][pos->x]=VIDE;
				break;
				}
				// if cell below is objectif 
				else
				{
				carte[pos->y+2][pos->x]=CAISSE_OK;;
				carte[pos->y+1][pos->x]=VIDE;
				break;
				}
			}
			break;
		case GAUCHE:
			// if left Mario isnt a box > break 
			if(carte[pos->y][pos->x-1]!=CAISSE)
			{
				break;
			}
			// if left cell is C and 2 cells left is OOB 
			else if(carte[pos->y][pos->x-1]==CAISSE && pos->x-2 < 0)
			{
				// if cell portal right is already occrightied by B || B_OK> || W > break 
				if(carte[pos->y][NB_BLOC_LARGEUR-1] == CAISSE || carte[pos->y][NB_BLOC_LARGEUR-1] == CAISSE_OK || carte[pos->y][NB_BLOC_LARGEUR-1] == MUR)
				{
					break;
				}
				// if cell portal right is OBJ 
				else if(carte[pos->y][NB_BLOC_LARGEUR-1]==OBJECTIF)
				{
					carte[pos->y][NB_BLOC_LARGEUR-1]=CAISSE_OK;
					carte[pos->y][pos->x-1]=VIDE;
					break;

				}
				// if cell portal right is empty 
				else 
				{
					carte[pos->y][NB_BLOC_LARGEUR-1]=CAISSE;
					carte[pos->y][pos->x-1]=VIDE;
					break;
				}							
			}

			// if 2 cells left is W || C || C_OK > break  
			else if(carte[pos->y][pos->x-2] ==MUR || carte[pos->y][pos->x-2]==CAISSE || carte[pos->y][pos->x-2]==CAISSE_OK) 
			{
				int wut =carte[pos->y][pos->x-2]; 
				printf("%d",wut);
				break;
			}
					        // if cell left is Box and 2 cells left  is empty or objective	
			else if((carte[pos->y][pos->x-2]==VIDE || carte[pos->y][pos->x-2]==OBJECTIF) && carte[pos->y][pos->x-1]==CAISSE)
			{
				// if cell left is empty
				if(carte[pos->y][pos->x-2]==VIDE)
				{
				carte[pos->y][pos->x-2]=CAISSE;
				carte[pos->y][pos->x-1]=VIDE;
				break;
				}
				// if cell left is objectif 
				else
				{
				carte[pos->y][pos->x-2]=CAISSE_OK;;
				carte[pos->y][pos->x-1]=VIDE;
				break;
				}
			}
			break;
		case DROITE:

			// if right Mario isnt a box > break 
			if(carte[pos->y][pos->x+1]!=CAISSE)
			{
				break;
			}
			// if right cell is C and 2 cells right is OOB 
			else if(carte[pos->y][pos->x+1]==CAISSE && pos->x+2 > NB_BLOC_LARGEUR-1)
			{
				// if cell portal left is already occrightied by B || B_OK> || W > break 
				if(carte[pos->y][0] == CAISSE || carte[pos->y][0] == CAISSE_OK || carte[pos->y][0] == MUR)
				{
					break;
				}
				// if cell portal left is OBJ 
				else if(carte[pos->y][0]==OBJECTIF)
				{
					carte[pos->y][0]=CAISSE_OK;
					carte[pos->y][pos->x+1]=VIDE;
					break;

				}
				// if cell portal left is empty 
				else 
				{
					carte[pos->y][0]=CAISSE;
					carte[pos->y][pos->x+1]=VIDE;
					break;
				}							
			}

			// if 2 cells right is W || C || C_OK > break  
			else if(carte[pos->y][pos->x+2]==MUR || carte[pos->y][pos->x+2]==CAISSE || carte[pos->y][pos->x+2]==CAISSE_OK) 
			{
				break;
			}
					        // if cell right is Box and 2 cells right  is empty or objective	
			else if((carte[pos->y][pos->x+2]==VIDE || carte[pos->y][pos->x+2]==OBJECTIF) && carte[pos->y][pos->x+1]==CAISSE)
			{
				// if cell right is empty
				if(carte[pos->y][pos->x+2]==VIDE)
				{
				carte[pos->y][pos->x+2]=CAISSE;
				carte[pos->y][pos->x+1]=VIDE;
				break;
				}
				// if cell right is objectif 
				else
				{
				carte[pos->y][pos->x+2]=CAISSE_OK;;
				carte[pos->y][pos->x+1]=VIDE;
				break;
				}
			}
			break;

	 } // switch end 
}
void ecranFin(SDL_Renderer*renderer)
{
	SDL_Surface*surface;
	SDL_Texture*texture;

	surface = IMG_Load("media/PlayAgain.png");
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_RenderCopy(renderer,texture,NULL,NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

}
