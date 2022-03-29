#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"
#include "LcdDriver/msp432p4111_classic.h"

/* Graphic library context */
Graphics_Context g_sContext;

/*
 * Main function
 */

#define INIT -1
#define DOWN 0
#define UP 1
#define TH 100000

void main(void)
{
    int x=10, y=8;
    int z=48, k=60;
    int bs1state=INIT;
    int bs1state2=INIT;
    int bs1count=0;
    int state=5;
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);

    /* Configuring S1 & S2 buttons in boostxl-edumkii */
    P3->DIR &= ~BIT5;
    P5->DIR &= ~BIT1;
    P3->REN |= BIT5;
    P5->REN |= BIT1;
    P3->OUT |= BIT5;
    P5->OUT |= BIT1;

    Graphics_drawString(&g_sContext, (int8_t *)"|", 1, x*2, y*7, OPAQUE_TEXT);

    Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);

    while(1)
    {
        if (!(P5->IN & BIT1)) {
            if ((++bs1count) == TH) {
                bs1count=0;
                Graphics_drawString(&g_sContext, (int8_t *)" ", 1, x*2, y*7, OPAQUE_TEXT);
                if (y>=0) y--;
                Graphics_drawString(&g_sContext, (int8_t *)"|", 1, x*2, y*7, OPAQUE_TEXT);
            }
            bs1state=DOWN;
        }
        else if (P5->IN & BIT1){
            if (bs1state==DOWN) {
                bs1count=0;
               Graphics_drawString(&g_sContext, (int8_t *)" ", 1, x*2, y*7, OPAQUE_TEXT);
               if (y>=0) y--;
               Graphics_drawString(&g_sContext, (int8_t *)"|", 1, x*2, y*7, OPAQUE_TEXT);
               bs1state=UP;
            }
        }

        if (!(P3->IN & BIT5)) {
                    if ((++bs1count) == TH) {
                        bs1count=0;
                        Graphics_drawString(&g_sContext, (int8_t *)" ", 1, x*2, y*7, OPAQUE_TEXT);
                        if (y>=0) y++;
                        Graphics_drawString(&g_sContext, (int8_t *)"|", 1, x*2, y*7, OPAQUE_TEXT);
                    }
                    bs1state2=DOWN;
                }
                else if (P3->IN & BIT5){
                    if (bs1state2==DOWN) {
                        bs1count=0;
                       Graphics_drawString(&g_sContext, (int8_t *)" ", 1, x*2, y*7, OPAQUE_TEXT);
                       if (y>=0) y++;
                       Graphics_drawString(&g_sContext, (int8_t *)"|", 1, x*2, y*7, OPAQUE_TEXT);
                       bs1state2=UP;
                    }
                }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int i;
        int t=x*2;
        int w=y*7;

        if(z==t){
            if(((w<=k)&&(k<=w+1)))//ºÎµúÈû

        {
                  state=0;
            }
        }
            if(state==0){

                Graphics_drawString(&g_sContext, (int8_t *)" ", 1, z, k, OPAQUE_TEXT);
                                for(i=0;i<1000;i++);
                                z=z+3;
                                k=k+3;
                                Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);
                                for(i=0;i<1000;i++);
                                state=0;
                                if(z>127){
                                    state=1;

                                }
                                if(k>127){
                                    state=2;

                                }
                                if(z<1){
                                    state=3;

                                }
                                if(k<1){
                                    state=4;

                                }
                                else{
                                    state=5;

                                }


        }




            else if((state==1)){

            Graphics_drawString(&g_sContext, (int8_t *)" ", 1, z, k, OPAQUE_TEXT);
                    for(i=0;i<1000;i++);
                    z=z-1;
                    k=k-1;
                    Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);
                    for(i=0;i<1000;i++);
                    state=1;

                                                            if(k>127){
                                                                state=2;

                                                            }
                                                            if(z<1){
                                                                state=3;

                                                            }
                                                            if(k<1){
                                                                state=4;

                                                            }

        }
        else if((state==2)){
                    Graphics_drawString(&g_sContext, (int8_t *)" ", 1, z, k, OPAQUE_TEXT);
                            for(i=0;i<1000;i++);
                            z=z+1;
                            k=k-1;

                            Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);
                            for(i=0;i<1000;i++);
                            state=2;
                            if(z>127){
                                                                        state=1;

                                                                    }

                                                                    if(z<1){
                                                                        state=3;

                                                                    }
                                                                    if(k<1){
                                                                        state=4;

                                                                    }

                }
        else if(state==3){
                                    Graphics_drawString(&g_sContext, (int8_t *)" ", 1, z, k, OPAQUE_TEXT);
                                            for(i=0;i<1000;i++);
                                            z=z+1;
                                            k=k+1;
                                            Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);
                                            for(i=0;i<1000;i++);
                                            state=3;

                                            break;



                                }
        else if(state==4){
                            Graphics_drawString(&g_sContext, (int8_t *)" ", 1, z, k, OPAQUE_TEXT);
                                    for(i=0;i<1000;i++);
                                    z=z-1;
                                    k=k+1;
                                    Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);
                                    for(i=0;i<1000;i++);
                                    state=4;
                                    if(z>127){
                                                                                state=1;

                                                                            }
                                                                            if(k>127){
                                                                                state=2;

                                                                            }
                                                                            if(z<1){
                                                                                state=3;

                                                                            }


                        }
        else if(state==5) {
        Graphics_drawString(&g_sContext, (int8_t *)" ", 1, z, k, OPAQUE_TEXT);
        for(i=0;i<1000;i++);
        z=z+1;
        k=k+1;
        Graphics_drawString(&g_sContext, (int8_t *)"o", 1, z, k, OPAQUE_TEXT);
        for(i=0;i<1000;i++);
        state=5;
        if(z>127){
                                            state=1;

                                        }
                                        if(k>127){
                                            state=2;

                                        }
                                        if(z<1){
                                            state=3;

                                        }
                                        if(k<1){
                                            state=4;

                                        }


        }

    }
    Graphics_drawString(&g_sContext, (int8_t *)"end", 3, x*3, y*3, OPAQUE_TEXT);


}

