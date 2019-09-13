/* temperaturaMaxima3_3                            */
/* programa que calcula la mayor temperatura de un */
/* conjunto de datos de temperaturas               */
/* El numero de datos no es conocido a priori      */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define TFIN -999.0  /* valor centinela: termina E datos */

int main(){
    char c;
    float t;        /* temperatura leída         */
    double tmax;    /* temperatura máxima        */
    int fin;        /* indicador de fin de bucle */

    do{ system("cls");
        printf("TEMPERATURA MAXIMA\n");
        printf("==================\n\n");
        tmax=-1E38;
        fin=0;
        while(!(fin)){
            printf("Introduzca Temperatura (Fin=%.0f):",TFIN);
            scanf(" %f",&t);
            if(t==TFIN)
                 fin=1;
            else if(t>tmax)
                     tmax=t;
        }
        if(tmax!=-1E38)
             printf("\nTemperatura maxima: %.1f", tmax);
        else printf("\nSin datos validos");
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
