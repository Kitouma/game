
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SDL.h>
#include <SDL_mixer.h>

#define BOTTOM 1
#define TOP 2
#define LEFT 3
#define RIGHT 4
#define RIEN 0

int attendreAvantDeQuitter(Uint8 typeEvenement);
SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur);
void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu);
void afficheMessage(SDL_Surface * surfaceBlit, char * texte, int tailleText, char * fontFile, SDL_Color textColor, SDL_Rect position);
int verifEtatToucheClavier();
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position);
SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseCol, int nbCaseLigne );
void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip);
Mix_Music* jouerSon(char *fichierSon);
void attendreTemps(int millisecondes);
void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y);
int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision);
void deplacementAutorise(int typeCol, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y);
#endif // FUNCTIONS_H


Read more at http://librecodesource.e-monsite.com/pages/langage-c/sdl-de-a-a-z/detection-des-collisions.html#i5m15Is2m3F2QzwD.99
