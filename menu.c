

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "functions.h"
#define LARGEURECRAN 640
#define HAUTEURECRAN 480
#define TITREECRAN "Ma fenetre SDL"
#define ICONE "icon.png"


 



int main()
{
    int i=0;
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
    SDL_Surface *ecran =NULL,*imageDeFond = NULL,*image=NULL,*image2=NULL,*image3=NULL,*image4=NULL,*image9=NULL,*image10=NULL;
    ecran=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_FULLSCREEN); // Ouverture de la fenêtre
    SDL_Rect positionFond,positionim,positionim2,positionim3,positionim4,positionim5,positionim6;//bach yefhem les cordonnée
    SDL_WM_SetCaption("Menu", NULL);// esm l fenetre 
    SDL_Rect positionImg1={0,0},positionImg2={320,240}; //initialisation des deux images 
    int typeCollision;//type de la collision 
    int continuer = 1; //tkamel taaleb baed l collision
    int vitX=2, vitY=2; //vitesse 






    SDL_Event event;

    ecran = initEcran(TITREECRAN, ICONE,LARGEURECRAN , HAUTEURECRAN);

    while(continuer)
    {
        SDL_PollEvent(&event);
        continuer = attendreAvantDeQuitter(event.type);
        backgroundColorSurface(ecran, 0, 0, 0);

        blitImageSurSurface(ecran, "icon.png", &positionImg2);
        blitImageSurSurface(ecran, "icon.png", &positionImg1);
        if(testCollision(positionImg1, positionImg2, &typeCollision))
        {
            deplacement(&positionImg1, event, vitX, vitY);
        }
        else
        {
            deplacementAutorise(typeCollision, &positionImg1, event, vitX, vitY);
        }

        attendreTemps(5);

        SDL_Flip(ecran);
    }
    SDL_Quit();
}

   
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    positionim.x =0 ;
    positionim.y = 0 ;
    positionim2.x =0 ;
    positionim2.y = 0 ;
    positionim3.x =0 ;
    positionim3.y = 0 ;
    positionim4.x =0 ;
    positionim4.y = 0 ;
    positionim5.x =0 ;
    positionim5.y = 0 ;
 positionim6.x =0 ;
    positionim6.y = 0 ;
    imageDeFond = IMG_Load("menu.gif");// hata wahda matech3el
    image= IMG_Load("play.gif");// l play tech3el
    image2= IMG_Load("setting.gif");//setting tech3el
    image3= IMG_Load("help.gif");//l help tech3el
    image4= IMG_Load("exit.gif");//l exit tech3el

    SDL_Flip(ecran);// mise a jours
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;//pointeur musique jeux
    Mix_AllocateChannels(20);//
    musique = Mix_LoadMUS("musique.mp3");//musique jeux
    Mix_PlayMusic(musique, -1);//repeter la music de jeux (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//MIX_MAX_VOLUME se defere de chaque pc (peut etre 1 ou 2 selement)
    Mix_Chunk *MB;//pointeur music boutton(chunk se defere de formart) chunk pour format wav ; Music pour format mp3
    MB = Mix_LoadWAV("button.wav");// clique de bouton
    SDL_Event event;//clavier et souris
    int continuer = 1;//si continuer=1 il reste dans la boucle while ; si 0 il quite la boucle

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);//affichage de menu

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:// nzelt ala felsa f souris
           if (event.button.button == SDL_BUTTON_LEFT)// itha kan nzelt ysar
            {

                if ( event.button.x >60 && event.button.y >290 && event.button.x < 230 && event.button.y <340)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);//l play tech3el
                    SDL_Flip(ecran);//mise a jours 
                    SDL_Delay(400);//tech3el w tetfa w tehseb bel ms ;ex: SDL_Delay(ms)
                    Mix_PlayChannel(1, MB, 0); //l9itha akeka w mefhemthech donc a9ra w oskot
                
                 image9=IMG_Load("khra.jpg"); 
               SDL_BlitSurface(image9, NULL, ecran, &positionim5); 
                SDL_Flip(ecran); 
               }

                if ( event.button.x >60 && event.button.y >365 && event.button.x <230 && event.button.y <395)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);//settings tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);

                 image10=IMG_Load("setting.jpg"); 
               SDL_BlitSurface(image10, NULL, ecran, &positionim6); 
                SDL_Flip(ecran); 
                   
                }
                if ( event.button.x >60 && event.button.y >430 && event.button.x < 230 && event.button.y <485)

                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);//help tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);

                }
                if ( event.button.x >60 && event.button.y >510 && event.button.x < 230 && event.button.y <585)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);//exit tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);
                    continuer=0;
                }
            }
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)// win teta9ra l click
            {

            case SDLK_RETURN: //bouton entrer
                if (i==1)
                {

                }
                else if (i==2)
                {
                }
                else if (i==3)
                {

                }
                else if (i==4)
                {
                    continuer=0;
                };
                break;

            case SDLK_DOWN:
                i++;
                if(i==5)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);

                }
                if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);
                }
                
                break;
            case SDLK_UP:
                i--;
                if(i==-1)
                {
                    i=5;
                }
                if(i==5)
                {
                    i=4;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(500) ;  
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }


                break;
            }
        }
          
        SDL_Flip(ecran);//mise a jours
    }
    Mix_FreeMusic(musique);//free espace memoire
    Mix_CloseAudio();//tsakr e sout 
    SDL_Quit(); // Arrêt de la SDL


    return EXIT_SUCCESS; // Fermeture du programme
}






