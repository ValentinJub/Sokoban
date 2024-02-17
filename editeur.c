/* 
 editeur.c
 -----
 Par Valentin Wissler

 Fonctions principales de l'editeur

 
*/

#include "editeur.h"


int manuelEditeur(SDL_Renderer*renderer, TTF_Font*font)
{
	SDL_Surface*surface; 
	SDL_Texture*texture;
	SDL_Rect rect, rectMid;
	SDL_Event event;
	SDL_Color couleurRouge = {0,0,0};
	char phrase[100];
	int resultat=2;
	bool continuer = true;
	
	// standard rec centered
	rectMid.h=TAILLE_BLOC*2;
	rectMid.w=TAILLE_BLOC*13;
	rectMid.y=(((TAILLE_BLOC*13)/2)-(rectMid.h/2));
	rectMid.x=(((TAILLE_BLOC*13)/2)-(rectMid.w/2));

	// creation fond  uni 
	SDL_SetRenderDrawColor(renderer,175,0,255,255);
	SDL_RenderClear(renderer);

	sprintf(phrase, "To select a sprite press:");
	surface = TTF_RenderText_Blended(font,phrase,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect.h=rectMid.h;
	rect.w=rectMid.w;
	rect.y=rectMid.y-(rectMid.h*2);
	rect.x=rectMid.x;
	SDL_RenderCopy(renderer,texture,NULL,&rect);
	
	sprintf(phrase, "1>Wall 2>Mario 3>Box 4>Obj 5>B_OK");
	surface = TTF_RenderText_Blended(font,phrase,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect.h=rectMid.h;
	rect.w=rectMid.w;
	rect.y=rectMid.y-(rectMid.h*1);
	rect.x=rectMid.x;
	SDL_RenderCopy(renderer,texture,NULL,&rect);
	
	//MID~~~~~~~~~~~~~~~~~~
	sprintf(phrase, "Mouse left click to insert on map");
	surface = TTF_RenderText_Blended(font,phrase,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_RenderCopy(renderer,texture,NULL,&rectMid);
	//MIDEND~~~~~~~~~~~~~~~
	
	sprintf(phrase, "Mouse right click to delete sprite");
	surface = TTF_RenderText_Blended(font,phrase,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect.h=rectMid.h;
	rect.w=rectMid.w;
	rect.y=rectMid.y+(rectMid.h*1);
	rect.x=rectMid.x;
	SDL_RenderCopy(renderer,texture,NULL,&rect);
	
	sprintf(phrase, "Press S to save");
	surface = TTF_RenderText_Blended(font,phrase,couleurRouge);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	rect.h=rectMid.h;
	rect.w=rectMid.w;
	rect.y=rectMid.y+(rectMid.h*2);
	rect.x=rectMid.x;
	SDL_RenderCopy(renderer,texture,NULL,&rect);


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

void editeur(SDL_Renderer*renderer)
{
	SDL_Surface*surface = NULL;
	SDL_Texture*textureMur = NULL,
		   *textureCaisse = NULL,
		   *textureCaisseOk = NULL,
		   *textureObjectif = NULL,
		   *textureVide=NULL,
		   *textureMario = NULL; 
	SDL_Rect position = {0}, positionTexture = {0};
	SDL_Event event;
	TTF_Font *font;
	int whichTexture = 7; 	
	bool jouer = true, continuer = true, clickG = false, clickD = false;  
	int i = 0, j = 0; // vont permettre de parcourir carte 
	int carte[NB_BLOC_LARGEUR][NB_BLOC_HAUTEUR]={0}; // carte du jeu 
	int mario=0;
	SDL_Rect posMario = {0};

	/*Chargement des sprites */
        surface = IMG_Load("/ResourcesNew/mur.png");
	textureMur = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
        surface = IMG_Load("/ResourcesNew/ground_06.png");
	textureVide = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
        surface = IMG_Load("/ResourcesNew/box.png");
	textureCaisse = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);		
        surface = IMG_Load("/ResourcesNew/boxOK.png");
	textureCaisseOk = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
        surface = IMG_Load("/ResourcesNew/objAlt.png");
	textureObjectif = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("/ResourcesNew/mario_bas.png");
	textureMario = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);

	// Chargement font 
	font = TTF_OpenFont("hackbold.ttf",500);
	
	position.h=TAILLE_BLOC;
	position.w=TAILLE_BLOC;

	posMario.h=TAILLE_BLOC;
	posMario.w=TAILLE_BLOC;

	if(!manuelEditeur(renderer, font))
	{
		jouer=false;
	}
	
	while(jouer)
	{


	// Fill background in white  
	SDL_SetRenderDrawColor(renderer,255,255,255,255);	
	SDL_RenderClear(renderer);

	
	// on affiche les texutes qui sont dans la map 
	for(i=0;i<NB_BLOC_HAUTEUR;i++)
	{
		for(j=0;j<NB_BLOC_LARGEUR;j++)
		{
			positionTexture.y=i*TAILLE_BLOC;
			positionTexture.x=j*TAILLE_BLOC;
			positionTexture.h=TAILLE_BLOC;
			positionTexture.w=TAILLE_BLOC;

			switch(carte[i][j])
			{
				case VIDE:
				   SDL_RenderCopy(renderer,textureVide,NULL,&positionTexture);
				   break;
				case MUR:
				   SDL_RenderCopy(renderer,textureMur,NULL,&positionTexture);
				   break;
				case CAISSE:
				   SDL_RenderCopy(renderer,textureCaisse,NULL,&positionTexture);
				   break;
				case CAISSE_OK:
				   SDL_RenderCopy(renderer,textureCaisseOk,NULL,&positionTexture);
				   break;
				case OBJECTIF:
				   SDL_RenderCopy(renderer,textureObjectif,NULL,&positionTexture);
				   break;
				case MARIO:
				   if(mario != 1)
				   {
				   	SDL_RenderCopy(renderer,textureMario,NULL,&positionTexture);
					posMario.y=i;
					posMario.x=j;
					mario=1;
				   }
				   else if(mario==1)
			        {
					carte[posMario.y][posMario.x]=VIDE;
					SDL_RenderCopy(renderer,textureMario,NULL,&positionTexture);
					posMario.y=i;
					posMario.x=j;
					carte[positionTexture.y/TAILLE_BLOC][positionTexture.x/TAILLE_BLOC]=MARIO;
					mario = 0;

				}
				   break;
			}
		}	
	} 
	 
	
	

	// on affiche les textures en suivant la souris avant qu'ils soient place a lecran 
	switch(whichTexture)
	{
		case VIDE:
			SDL_RenderCopy(renderer,textureVide,NULL,&position);
			break;
		case MUR:
			SDL_RenderCopy(renderer,textureMur,NULL,&position);
			break;
		case MARIO:
			SDL_RenderCopy(renderer,textureMario,NULL,&position);
			break;
		case CAISSE:
			SDL_RenderCopy(renderer,textureCaisse,NULL,&position);
			break;
		case CAISSE_OK:
			SDL_RenderCopy(renderer,textureCaisseOk,NULL,&position);
			break;
		case OBJECTIF:
			SDL_RenderCopy(renderer,textureObjectif,NULL,&position);
			break;
		default:
			break;
	}

	SDL_RenderPresent(renderer);
	continuer = true;
	while(continuer)
	{
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
		   jouer=false;
		   break;
		case SDL_MOUSEMOTION:
			position.x=event.motion.x;
			position.y=event.motion.y;
			if(clickG)
			{
				carte[event.motion.y/TAILLE_BLOC][event.motion.x/TAILLE_BLOC]=whichTexture;
				break;
			}
			if(clickD)
			{
				carte[event.motion.y/TAILLE_BLOC][event.motion.x/TAILLE_BLOC]=VIDE;
				break;
				
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button==SDL_BUTTON_LEFT)
			{
				carte[event.button.y/TAILLE_BLOC][event.button.x/TAILLE_BLOC]=whichTexture;
				clickG=true;
				break;
			}
			if(event.button.button==SDL_BUTTON_RIGHT)
			{
				carte[event.button.y/TAILLE_BLOC][event.button.x/TAILLE_BLOC]=VIDE;
				clickD=true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if(event.button.button==SDL_BUTTON_LEFT)
			{
				clickG=false;
				break;
			}	
			if(event.button.button==SDL_BUTTON_RIGHT)
			{
				clickD=false;
				break;
			}	
			break;
		case SDL_KEYDOWN:
		   switch(event.key.keysym.sym)
		   {
		      case SDLK_ESCAPE:
			 jouer = false;
			 break;
		      case SDLK_1:
	        	whichTexture=MUR;
			 break;
		      case SDLK_2:
	        	whichTexture=MARIO;
			 break;
		      case SDLK_3:
	        	whichTexture=CAISSE;
			 break;
		      case SDLK_4:
	        	whichTexture=OBJECTIF;
			 break;
		      case SDLK_5:
	        	whichTexture=CAISSE_OK;
			 break;
		      case SDLK_6:
	        	whichTexture=VIDE;
			 break;
		      case SDLK_s:
			 sauvegarderNiveau(carte);
			 break;
		   } 

	} // switch event.type end 

	continuer=false;

	} // continuer end
	
	}// jouer end 

	TTF_CloseFont(font);
	SDL_DestroyTexture(textureMur);
	SDL_DestroyTexture(textureCaisse);
	SDL_DestroyTexture(textureCaisseOk);
	SDL_DestroyTexture(textureObjectif);
	SDL_DestroyTexture(textureMario);
}

