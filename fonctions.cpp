#include "fonctions.h"
//description des fonctions dans "fonction.h"
//pour définir la variable du déplacement du joystick faire : AnalogIn NomVariable(A0) par exemple
moto A;
moto *Aptr;
moto B;
moto *Bptr;
moto C;
moto *Cptr;
moto D;
moto *Dptr;
int motoenvie=0;
int motoenvie0=0;
int Aalive0;
int Balive0;
int Calive0;
int Dalive0;
int Xpos=4;
int Ypos=1;
int Xpos1=476;
int Ypos1=269;
int tabAx[6000]={0};
int tabAy[6000]={0};
int tabBx[6000]={0};
int tabBy[6000]={0};
int tabCx[6000]={0};
int tabCy[6000]={0};
int tabDx[6000]={0};
int tabDy[6000]={0};
int J1Flag=0;  //on met dans les conditions pr tourner à droite le flag à 1 lorsque J1>seuilD et à 0 lorsque J1 redescend en dessous du seuil
int J2Flag=0;
int *J1ptr=&J1Flag;
int *J2ptr=&J2Flag;
uint16_t seuilD=5000;
uint16_t seuilG=60000;
void init() {
    Aptr=&A;
    Bptr=&B;
    Cptr=&C;
    Dptr=&D;  
    Aptr->x=150;
    Aptr->y=100;
    Aptr->c=0; //0 vert, 1 bleu, 2 rouge, autre gris
    Aptr->direction=10000;
    Bptr->x=200;
    Bptr->y=150;
    Bptr->c=1; 
    Bptr->direction=10000;
    Cptr->x=200;
    Cptr->y=120;
    Cptr->c=2; 
    Dptr->c=3; 
    Cptr->direction=1;
    Dptr->direction=0;
    Aptr->alive=1;
    Bptr->alive=1;
    Cptr->alive=0;
    Dptr->alive=0;
  
    }

void draw_moto2() {
    if (A.alive==1) {
         if (A.c==0) {
              BSP_LCD_DrawPixel(A.x, A.y, LCD_COLOR_GREEN);        
            }
         else if (A.c==1) {
             BSP_LCD_DrawPixel(A.x, A.y, LCD_COLOR_BLUE);
             }
         else if (A.c==2) {
              BSP_LCD_DrawPixel(A.x, A.y, LCD_COLOR_RED);
              }
            else {
                BSP_LCD_DrawPixel(A.x, A.y, LCD_COLOR_GRAY);        
            }
        }
    if (B.alive==1) {
         if (B.c==0) {
              BSP_LCD_DrawPixel(B.x, B.y, LCD_COLOR_GREEN);        
            }
         else if (B.c==1) {
             BSP_LCD_DrawPixel(B.x, B.y, LCD_COLOR_BLUE);
             }
         else if (B.c==2) {
              BSP_LCD_DrawPixel(B.x, B.y, LCD_COLOR_RED);
              }
            else {
                BSP_LCD_DrawPixel(B.x, B.y, LCD_COLOR_GRAY);        
            }
        }
    if (C.alive==1) {
         if (C.c==0) {
              BSP_LCD_DrawPixel(C.x, C.y, LCD_COLOR_GREEN);        
            }
         else if (C.c==1) {
             BSP_LCD_DrawPixel(C.x, C.y, LCD_COLOR_BLUE);
             }
         else if (C.c==2) {
              BSP_LCD_DrawPixel(C.x, C.y, LCD_COLOR_RED);
              }
            else {
                BSP_LCD_DrawPixel(C.x, C.y, LCD_COLOR_GRAY);        
            }
        }
    if (D.alive==1) {
         if (D.c==0) {
              BSP_LCD_DrawPixel(D.x, D.y, LCD_COLOR_GREEN);        
            }
         else if (D.c==1) {
             BSP_LCD_DrawPixel(D.x, D.y, LCD_COLOR_BLUE);
             }
         else if (D.c==2) {
              BSP_LCD_DrawPixel(D.x, D.y, LCD_COLOR_RED);
              }
            else {
                BSP_LCD_DrawPixel(D.x, D.y, LCD_COLOR_GRAY);        
            }
        }
    
    }

/*void draw_moto(int x,int y,int c,int d) { 
    if (c==0) {
        BSP_LCD_DrawPixel(x, y, LCD_COLOR_BLACKGREEN);
        BSP_LCD_DrawPixel(x, y-1, LCD_COLOR_BLACKGREEN);
        BSP_LCD_DrawPixel(x+1, y-1, LCD_COLOR_BLACKGREEN);
        BSP_LCD_DrawPixel(x-1, y-1, LCD_COLOR_BLACKGREEN);
        BSP_LCD_DrawPixel(x, y-2, LCD_COLOR_BLACKGREEN);
        BSP_LCD_DrawPixel(x-1, y-2, LCD_COLOR_BLACKGREEN);
        BSP_LCD_DrawPixel(x+1, y-2, LCD_COLOR_BLACKGREEN);
        for (int i=0;i<5;i++) {
            for (int j=0; j<6; j++) {
                BSP_LCD_DrawPixel(x-2+i, y-8+j, LCD_COLOR_BLACKGREEN);
                }
            }
    }    
    else if (c==1) {
        BSP_LCD_DrawPixel(x, y, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x, y-1, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x+1, y-1, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x-1, y-1, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x, y-2, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x-1, y-2, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x+1, y-2, LCD_COLOR_BLACK);
        for (int i=0;i<5;i++) {
            for (int j=0; j<6; j++) {
                BSP_LCD_DrawPixel(x-2+i, y-8+j, LCD_COLOR_BLACK);
                }
            }
        
    }
    else if (c==2) {
        BSP_LCD_DrawPixel(x, y, LCD_COLOR_RED);
        BSP_LCD_DrawPixel(x, y-1, LCD_COLOR_RED);
        BSP_LCD_DrawPixel(x+1, y-1, LCD_COLOR_RED);
        BSP_LCD_DrawPixel(x-1, y-1, LCD_COLOR_RED);
        BSP_LCD_DrawPixel(x, y-2, LCD_COLOR_RED);
        BSP_LCD_DrawPixel(x-1, y-2, LCD_COLOR_RED);
        BSP_LCD_DrawPixel(x+1, y-2, LCD_COLOR_RED);
        for (int i=0;i<5;i++) {
            for (int j=0; j<6; j++) {
                BSP_LCD_DrawPixel(x-2+i, y-8+j, LCD_COLOR_RED);
                }
            }
        }
    else {
        BSP_LCD_DrawPixel(x, y, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x, y-1, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x+1, y-1, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x-1, y-1, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x, y-2, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x-1, y-2, LCD_COLOR_BLACK);
        BSP_LCD_DrawPixel(x+1, y-2, LCD_COLOR_BLACK);
        for (int i=0;i<5;i++) {
            for (int j=0; j<6; j++) {
                BSP_LCD_DrawPixel(x-2+i, y-8+j, LCD_COLOR_BLACK);
                }
            }
    }
}*/

void draw_wall(int i) {
    if (A.alive==1) {
        tabAx[i]=A.x0;
        tabAy[i]=A.y0;
        if (A.c==0) {
             BSP_LCD_DrawPixel(A.x0, A.y0, LCD_COLOR_DARKGREEN); }
        else if (A.c==1) {
             BSP_LCD_DrawPixel(A.x0, A.y0, LCD_COLOR_DARKBLUE); }
        else if (A.c==2) {
             BSP_LCD_DrawPixel(A.x0, A.y0, LCD_COLOR_DARKRED); }
        else {
            BSP_LCD_DrawPixel(A.x0, A.y0, LCD_COLOR_BLACK); } 
        }
    if (B.alive==1) {
        tabBx[i]=B.x0;
        tabBy[i]=B.y0;
        if (B.c==0) {
             BSP_LCD_DrawPixel(B.x0, B.y0, LCD_COLOR_DARKGREEN); }
        else if (B.c==1) {
             BSP_LCD_DrawPixel(B.x0, B.y0, LCD_COLOR_DARKBLUE); }
        else if (B.c==2) {
             BSP_LCD_DrawPixel(B.x0, B.y0, LCD_COLOR_DARKRED); }
        else {
            BSP_LCD_DrawPixel(B.x0, B.y0, LCD_COLOR_BLACK); } 
        }
    if (C.alive==1) {
        tabCx[i]=C.x0;
        tabCy[i]=C.y0;
        if (C.c==0) {
             BSP_LCD_DrawPixel(C.x0, C.y0, LCD_COLOR_DARKGREEN); }
        else if (C.c==1) {
             BSP_LCD_DrawPixel(C.x0, C.y0, LCD_COLOR_DARKBLUE); }
        else if (C.c==2) {
             BSP_LCD_DrawPixel(C.x0, C.y0, LCD_COLOR_DARKRED); }
        else {
            BSP_LCD_DrawPixel(C.x0, C.y0, LCD_COLOR_BLACK); } 
         }
    if (D.alive==1) {
        tabDx[i]=D.x0;
        tabDy[i]=D.y0;
        if (D.c==0) {
             BSP_LCD_DrawPixel(D.x0, D.y0, LCD_COLOR_DARKGREEN); }
        else if (D.c==1) {
             BSP_LCD_DrawPixel(D.x0, D.y0, LCD_COLOR_DARKBLUE); }
        else if (D.c==2) {
             BSP_LCD_DrawPixel(D.x0, D.y0, LCD_COLOR_DARKRED); }
        else {
            BSP_LCD_DrawPixel(D.x0, D.y0, LCD_COLOR_BLACK); } 
        }
    }

    
    
void draw_zonedejeu(int t) {
    if (t==1) {
        Xpos=80;
        Ypos=30;
        Xpos1=320;
        Ypos1=210;
        BSP_LCD_DrawRect(Xpos,Ypos,Xpos1,Ypos1);
        }
    else if (t==2) {
        Xpos=30;
        Ypos=10;
        Xpos1=420;
        Ypos1=250;
        BSP_LCD_DrawRect(Xpos,Ypos,Xpos1,Ypos1);
        }
    else {
        Xpos=2;
        Ypos=1;
        Xpos1=475;
        Ypos1=269;
        BSP_LCD_DrawRect(Xpos,Ypos,Xpos1,Ypos1);
        }
    }
    
void move() {
    if (A.alive==1) {
        Aptr->x0=A.x;
        Aptr->y0=A.y;
        BSP_LCD_DrawPixel(A.x0,A.y0, LCD_COLOR_WHITE);
        int test=A.direction%4;
        if (test==0) {
            Aptr->y=A.y-1;
            }
        else if (test==1) {
            Aptr->x=A.x+1;
            }
        else if (test==2) {
            Aptr->y=A.y+1;
            }
        else {
            Aptr->x=A.x-1;
            }
        }
    if (B.alive==1) {
        Bptr->x0=B.x;
        Bptr->y0=B.y;
        BSP_LCD_DrawPixel(B.x0,B.y0, LCD_COLOR_WHITE);
        int testb=B.direction%4;
        if (testb==0) {
            Bptr->y=B.y-1;
            }
        else if (testb==1) {
            Bptr->x=B.x+1;
            }
        else if (testb==2) {
            Bptr->y=B.y+1;
            }
        else {
            Bptr->x=B.x-1;
            }
        }
    if (C.alive==1) {
        Cptr->x0=C.x;
        Cptr->y0=C.y;
        BSP_LCD_DrawPixel(C.x0,C.y0, LCD_COLOR_WHITE);
        int testc=C.direction%4;
        if (testc==0) {
            Cptr->y=C.y-1;
            }
        else if (testc==1) {
            Cptr->x=C.x+1;
            }
        else if (testc==2) {
            Cptr->y=C.y+1;
            }
        else {
            Cptr->x=C.x-1;
            }
        }
    if (D.alive==1) {
        Dptr->x0=D.x;
        Dptr->y0=D.y;
        BSP_LCD_DrawPixel(D.x0,D.y0, LCD_COLOR_WHITE);
        int testd=D.direction%4;
        if (testd==0) {
            Dptr->y=D.y-1;
            }
        else if (testd==1) {
            Dptr->x=D.x+1;
            }
        else if (testd==2) {
            Dptr->y=D.y+1;
            }
        else {
            Dptr->x=D.x-1;
            }
        }
    }    
/*void turnR(MOTO a) {
    a.direction+=1;
    }
void turnL(MOTO a) {
    a.direction-=1;
    }  inutile */
void motodestroy(int i) {
    if (A.alive==0) {
        for (int j=0;j<=i;j+=1) {
            BSP_LCD_DrawPixel(tabAx[j],tabAy[j], LCD_COLOR_WHITE);
            tabAx[j]=0;
            tabAy[j]=0;
            }
        }
    if (B.alive==0) {
        for (int j=0;j<=i;j+=1) {
            BSP_LCD_DrawPixel(tabBx[j],tabBy[j], LCD_COLOR_WHITE);
            tabBx[j]=0;
            tabBy[j]=0;
            }
        }
    if (C.alive==0) {
        for (int j=0;j<=i;j+=1) {
            BSP_LCD_DrawPixel(tabCx[j],tabCy[j], LCD_COLOR_WHITE);
            tabCx[j]=0;
            tabCy[j]=0;
            }
        }
    if (D.alive==0) {
        for (int j=0;j<=i;j+=1) {
            BSP_LCD_DrawPixel(tabDx[j],tabDy[j], LCD_COLOR_WHITE);
            tabDx[j]=0;
            tabDy[j]=0;
            }
        }
    
    }
    
void turn(uint16_t J1, uint16_t J2) {
    if (J1Flag==0) {
        if (J1<seuilD) {
            Aptr->direction=A.direction-1;
            *J1ptr=1;
            }
        else if (J1>seuilG) {
            Aptr->direction=A.direction+1;
            *J1ptr=1;
            }
        }
    if (J2Flag==0) {
        if (J2<seuilD) {
            Bptr->direction=B.direction-1;
            *J2ptr=1;
            }
        else if (J2>seuilG) {
            Bptr->direction=B.direction+1;
            *J2ptr=1;
            }
        }
    }
void mur(int i) {
    if (A.alive==1) {
        if (A.x<=Xpos||A.x>=Xpos1) { 
            A.alive=0; }
        else if (A.y<=Ypos||A.y>=Ypos1) {
            A.alive=0; }     
        for (int j=0;j<=i;j++) {
            if (A.x==tabAx[j]&&A.y==tabAy[j]) {
                    A.alive=0;
                    }
            if (B.alive==1) {
                if (A.x==tabBx[j]&&A.y==tabBy[j]) {
                    A.alive=0;
                    }
                if (A.x==B.x&&A.y==B.y) {
                    A.alive=0;
                    B.alive=0;
                    }
                }
            if (C.alive==1) {
                if (A.x==tabCx[j]&&A.y==tabCy[j]) {
                    A.alive=0;
                    }
                if (A.x==C.x&&A.y==C.y) {
                    A.alive=0;
                    C.alive=0;
                    }
                }
            if (D.alive==1) {
                if (A.x==tabDx[j]&&A.y==tabDy[j]) {
                    A.alive=0;
                    }
                if (A.x==D.x&&A.y==D.y) {
                    A.alive=0;
                    D.alive=0;
                    }
                }
            }   
        }
    if (B.alive==1) {
        if (B.x<=Xpos||B.x>=Xpos1) { 
            B.alive=0; }
        else if (B.y<=Ypos||B.y>=Ypos1) {
            B.alive=0; }     
        for (int j=0;j<=i;j++) {
            if (B.x==tabBx[j]&&B.y==tabBy[j]) {
                    B.alive=0;
                    }
            if (A.alive==1) {
                if (B.x==tabAx[j]&&B.y==tabAy[j]) {
                    B.alive=0;
                    }
                if (B.x==A.x&&B.y==A.y) {
                    B.alive=0;
                    A.alive=0;
                    }
                }
            if (C.alive==1) {
                if (B.x==tabCx[j]&&B.y==tabCy[j]) {
                    B.alive=0;
                    }
                if (B.x==C.x&&B.y==C.y) {
                    B.alive=0;
                    C.alive=0;
                    }
                }
            if (D.alive==1) {
                if (B.x==tabDx[j]&&B.y==tabDy[j]) {
                    B.alive=0;
                    }
                if (B.x==D.x&&B.y==D.y) {
                    B.alive=0;
                    D.alive=0;
                    }
                }
            }   
        }
    if (C.alive==1) {
        if (C.x<=Xpos||C.x>=Xpos1) { 
            C.alive=0; }
        else if (C.y<=Ypos||C.y>=Ypos1) {
            C.alive=0; }     
        for (int j=0;j<=i;j++) {
            if (C.x==tabCx[j]&&C.y==tabCy[j]) {
                    C.alive=0;
                    }
            if (B.alive==1) {
                if (C.x==tabBx[j]&&C.y==tabBy[j]) {
                    C.alive=0;
                    }
                if (C.x==B.x&&C.y==B.y) {
                    C.alive=0;
                    B.alive=0;
                    }
                }
            if (A.alive==1) {
                if (C.x==tabAx[j]&&C.y==tabAy[j]) {
                    C.alive=0;
                    }
                if (C.x==A.x&&C.y==A.y) {
                    C.alive=0;
                    A.alive=0;
                    }
                }
            if (D.alive==1) {
                if (C.x==tabDx[j]&&C.y==tabDy[j]) {
                    C.alive=0;
                    }
                if (C.x==D.x&&C.y==D.y) {
                    C.alive=0;
                    D.alive=0;
                    }
                }
            }   
        }
    if (D.alive==1) {
        if (D.x<=Xpos||D.x>=Xpos1) { 
            D.alive=0; }
        else if (D.y<=Ypos||D.y>=Ypos1) {
            D.alive=0; }     
        for (int j=0;j<=i;j++) {
            if (D.x==tabDx[j]&&D.y==tabDy[j]) {
                    D.alive=0;
                    }
            if (B.alive==1) {
                if (D.x==tabBx[j]&&D.y==tabBy[j]) {
                    D.alive=0;
                    }
                if (D.x==B.x&&D.y==B.y) {
                    D.alive=0;
                    B.alive=0;
                    }
                }
            if (C.alive==1) {
                if (D.x==tabCx[j]&&D.y==tabCy[j]) {
                    D.alive=0;
                    }
                if (D.x==C.x&&D.y==C.y) {
                    D.alive=0;
                    C.alive=0;
                    }
                }
            if (A.alive==1) {
                if (D.x==tabAx[j]&&D.y==tabAy[j]) {
                    D.alive=0;
                    }
                if (D.x==A.x&&D.y==A.y) {
                    D.alive=0;
                    A.alive=0;
                    }
                }
            }   
        }
    
    }
    
void gagnant() {
    if (motoenvie==0) {
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
        BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"DRAW !", CENTER_MODE);
        }
    else if (motoenvie>1) {
        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
        BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"DRAW ! Time", CENTER_MODE);
        }
    else if (motoenvie==1) {
        if (Aalive0==1) {
            BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
            BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
            BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"Moto A WON !", CENTER_MODE);
            }
        else if (Balive0==1) {
            BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
            BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
            BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"Moto B WON !", CENTER_MODE);
            }
        else if (Calive0==1) {
            BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
            BSP_LCD_SetBackColor(LCD_COLOR_RED);
            BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"Moto C WON !", CENTER_MODE);
            }
        else if (Dalive0==1) {
            BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
            BSP_LCD_SetBackColor(LCD_COLOR_GRAY);
            BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"Moto D WON !", CENTER_MODE);
            }
        }
    }
    
void debut() {
      uint16_t x, y;
      uint8_t status;
      BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
      BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
      status = BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
      TS_StateTypeDef TS_State;
      BSP_TS_GetState(&TS_State);
      x = TS_State.touchX[0];
      y = TS_State.touchY[0];
      BSP_LCD_Clear(LCD_COLOR_WHITE);
      BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
      BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
      BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
      BSP_LCD_DisplayStringAt(0, 135, (uint8_t *)"APPUYER POUR JOUER", CENTER_MODE);
      while(TS_State.touchDetected==0){
        BSP_TS_GetState(&TS_State);
        }
    }

float al()
{
    float f;

    srand(time(NULL)); // initialise le generateur de maniere aleatoire

    f= rand()/(RAND_MAX+1.0); 
    return(f); }

int 16toPlusMinus(uint16_t J){
    if(J<seuilD){return(-1);}
    if(J>seuilG){return(1);}
    return(0);
}
int digtoPlusMinus(int g,int d){
    if(g==1){return -1);}
    if(d==1){return 1);}
    return 0;        
}
void turn2(int J1,int J2, int J3,int J4){
    if (J1flag ==0){
        Aptr->direction=Aptr.direction+J1;
        //digitalWrite();
    }
    if (J2flag ==0){
        Bptr->direction=Bptr.direction+J2;
        //digitalWrite();
    }
    if (J3flag ==0){
        Cptr->direction=Cptr.direction+J3;
    }
    if (J4flag ==0){
        Dptr->direction=Dptr.direction+J4;
    }  
}



void robot(int x,int i,int p) {
    float seuil=10;
    int d=C.direction%4;
    float D0=1000;
    float D1=1000;
    float D2=1000;
    float D3=1000;
    float temps=0;
    int m0=0;
    int m1=0;
    int m2=0;
    int m3=0;
    int a=1; // a correspond au 'pas' auquel on regarde dans la liste des murs des autres motos
    int xm;
    int ym;
    if (i>50&&i<101) { a=5; } //i est le nombre d'itérations efféctuées, lorsque le nombre est important on ne regarde pas chaque point du mur de la moto A par exemple mais tous les 100 points du mur
    else if (i>99&&i<500) { a=10; }
    else if (i>499&&i<1001) { a=50; }
    else if (i>999) { a=100; }
    int x=C.x;
    int y=C.y;
    if (x==2) { //on dirige moto C A=0 B=1 C=2 D=3
        if (A.alive==1) { //pour chaque moto on fait une recherche de minimum 
            for (int j=0;j<i;j+=a) {
                temp=(x-tabAx[j])**2+(y-tabAy[j])**2
                if (D0>temp) {
                    D0=temp;
                    m0=j;
                    }
                }
            }
        if (B.alive==1) {
            for (int j=0;j<i;j+=a) {
                temp=(x-tabBx[j])**2+(y-tabBy[j])**2
                if (D1>temp) {
                    D1=temp;
                    m1=j;
                    }
            }
        }
        if (D.alive==1) {
            for (int j=0;j<i;j+=a) {
                temp=(x-tabDx[j])**2+(y-tabDy[j])**2
                if (D3>temp) {
                    D3=temp;
                    m3=j;
                    }
            }
        }
        for (int j=2;j<475;j++) {
            for (int k=1;k<269;k++) {
                temp=(x-j)**2+(y-k)**2
                if (D2>temp) {
                    D2=temp;
                    xm=j;  //ici xm et ym signifient 'xmur' et 'ymur' et correspondent au point du mur le plus proche de la moto, 
                    ym=k;  //plus tard dans le code ce sera pour 'xminimal' et 'yminimal' et ça correspondra au point d'un mur le plus proche de la moto quel que soit ce mur
                }
            }
    float tab[4]={D0,D1,D2,D3};
    int min=0;
    for (int j=0;j<4;j++) {
        temp=tab[j];
        if (temp>tab[j]) {
            min=j;
            }
        }
       
    if (min==0) {
        if (D0<seuil) {
            xm=tabAx[m0];
            ym=tabAy[m0];
            if (x<=xm&&y<=ym&&d==0) {
                Cptr.direction=C.direction-1;
                }
            else if (x<=xm&&y<=ym&&d==1) {
                Cptr.direction=C.direction+1;
                }
            
            }
        }
    }


