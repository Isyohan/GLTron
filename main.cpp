#include "fonctions.h"
extern int Xpos;
extern int Ypos;
extern int Xpos1;
extern int Ypos1;
extern moto A;
extern moto* Aptr;
extern moto B;
extern moto* Bptr;
extern moto C;
extern moto* Cptr;
extern moto D;
extern moto* Dptr;
extern uint16_t seuilD;
extern uint16_t seuilG;
extern int tabAx;
extern int tabAy;
extern int tabBx;
extern int tabBy;
extern int tabCx;
extern int tabCy;
extern int tabDx;
extern int tabDy;
extern int Aalive0;
extern int Balive0;
extern int Calive0;
extern int Dalive0;
extern int motoenvie;

extern int J1Flag;
extern int J2Flag;
extern int *J1ptr;
extern int *J2ptr;

AnalogIn GAn_J1(A0);
AnalogIn GAn_J2(A2);
/*

int main() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
      while (1) {
        BSP_LCD_Clear(LCD_COLOR_WHITE);
        BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
        BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
        BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
        draw_moto(100,50,3,1);
        draw_moto(200,150,1,1);
        draw_moto(123,200, 0,1);
        draw_moto(300,160,2,1); 
        BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"MBED EXAMPLE", CENTER_MODE);
        BSP_LCD_DrawRect(2,1,476,269);
        BSP_LCD_DrawRect(30,10,420,250);
        BSP_LCD_DrawRect(80,30,320,210);
        HAL_Delay(8000); }
} 
 tester la fonction qui fait avancer la moto : */
int main() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
    int rejouer=1;
    while (rejouer==1) {
        debut();
        HAL_Delay(1500);
        BSP_LCD_Clear(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
        int compt=0;
        init();
        draw_moto2();
        int i=0;
        draw_zonedejeu(4);
        while (compt<5000) {
            motodestroy(i);
            HAL_Delay(5);
            turn(GAn_J1.read_u16(),GAn_J2.read_u16());
            HAL_Delay(30);
            if (GAn_J1.read_u16()<seuilG&&GAn_J1.read_u16()>seuilD) { *J1ptr=0; }
            if (GAn_J2.read_u16()<seuilG&&GAn_J2.read_u16()>seuilD) { *J2ptr=0; }       
            move();
            mur(i);
            motodestroy(i);
            Aalive0=A.alive;
            Balive0=B.alive;
            Calive0=C.alive;
            Dalive0=D.alive;
            draw_moto2();
            draw_wall(i);
            HAL_Delay(5);
            i+=1;
            compt+=1;
            HAL_Delay(10);
            motoenvie=Aalive0+Balive0+Calive0+Dalive0;
            if (motoenvie==1||motoenvie==0) {
                compt=8000;
                }
            }
        HAL_Delay(2500); //garder ce qui est affiché à l'écran 3secondes 
        move();
        A.alive=0;
        B.alive=0;
        C.alive=0;
        D.alive=0;
        motodestroy(i+1);
        HAL_Delay(1200);   
        gagnant();
        HAL_Delay(2000);
        }
    }
