/* temperaturaMaxima3_2                            */
/* programa que calcula la mayor temperatura de un */
/* conjunto de datos de temperaturas.              */
/* El numero de datos no es conocido a priori      */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define TFIN -999.0  /* valor centinela: termina E datos */

int main(){
    char c;
    float t;         /* temperatura leída  */
    float tmax;      /* temperatura máxima */

    do{ system("cls");
        printf("TEMPERATURA MAXIMA\n");
        printf("==================\n\n");
        printf("Introduzca Temperatura (Fin=%.0f):",TFIN);
        scanf(" %f",&t);
        tmax=t;
        while(t!=TFIN){
            if(t>tmax)
                tmax=t;
            printf("Introduzca Temperatura (Fin=%.0f):",TFIN);
            scanf(" %f",&t);
        }
        if(tmax!=TFIN)
             printf("\nTemperatura maxima: %.0f", tmax);
        else printf("\nSin datos validos");
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
