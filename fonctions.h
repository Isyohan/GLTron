#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "mbed.h"
#include<time.h>

struct moto {
    int c; // couleur de la moto
    int x0;
    int y0; //position de la moto à l'instant t-1
    int x; 
    int y;
    int direction; //direction de la moto, voir à draw_moto l'explication
    int alive; // alive,  si la moto est en vie, -1 si elle vient de mourir et 0 si elle est morte
     };

/* typedef struct moto * moto_ptr; */


/*     
int joystick1horizontal = 0; //-1 vers la gauche, +1 vers la droite
int joystick1vertical = 0; //-1 vers le bas, +1 vers le haut
int joystick1poussoir =0;
int joystick2horizontal = 0;
int joystick2vertical = 0;
int joystick2poussoir =0; */


/*void draw_moto(int x,int y,int c,int d);
//x,y positions, c pour la couleur et d pour la direction de la moto : congru à 0 mod4 =>Nord, 1mod4=Est 2mod4=Sud 3mod4=Ouest
// ainsi pour faire tourner la moto à droite +1 et tourner à gauche -1 sur d
//cette fonction est abandonnée pour le moment, ne pas en tenir compte */
void draw_moto2();
//x,y positions, c couleur
float al(); //retourne une valeur aléatoire en 0 et 1
void draw_wall(int i);
//x,y positions, c couleur, p pointeur vers le tableau contenant le mur de la moto
void draw_zonedejeu(int t);
//t pour la taille de la zone
void move(); 
// a une moto, déplace la moto de 1 pixel dans la direction de la moto
/* void turnR(MOTO a);
//change la direction de la moto pour qu'elle tourne vers la droite donc ajoute 1 à direction
void turnL(MOTO a);
//change la direction de la moto pour qu'elle tourne vers la gauche donc ajoute -1 à la direction */
void init(); 
//initialise les valeurs des caractéristiques des motos
void motodestroy(int i);
//détruit la moto et ses murs lorsque moto.alive=0
void turn(uint16_t J1,uint16_t J2);
//teste si AnalogIn
void mur(int i);
//teste si une moto doit mourir
void gagnant();
//affiche le ou les gagnants en fin de partie
void debut();
//affiche un écran d'acceuil avec écrit : appuyer pour jouer
void robot(int x, int i,int p);
//dirige une moto automatiquement, l'entier x désigne la moto que l'on commande, l'entier i précise combien d'itération ont eu lieu depuis le début de la partie,
// l'entier p est la probabilité que le robot fasse le bon choix, p=1 le robot est parfait
//il faudra plus tard que la fonction robot ne prenne pas d'argument x, et que l'on définisse dans la classe moto un entier robot qui vaut un si la moto est dirigé par cette fonction
