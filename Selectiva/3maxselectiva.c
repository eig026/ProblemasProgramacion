/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

/* temperaturaMaxima                                  */
/* programa que calcula la mayor de tres temperaturas */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(){
    char c;
    float t1,t2,t3;    /* temperaturas le�das */
    float tmax;        /* temperatura m�xima  */

    do{ system("cls");
        printf("MAXIMA DE TRES TEMPERATURAS\n");
        printf("===========================\n\n");
        printf("Introduzca tres temperaturas:\n");
        printf("\tt1: ");
        scanf(" %f",&t1);
        printf("\tt2: ");
        scanf(" %f",&t2);
        printf("\tt3: ");
        scanf(" %f",&t3);
        if(t1>=t2)
            if(t1>=t3)
                 tmax=t1;
            else tmax=t3;
        else if(t2>=t3)
                  tmax=t2;
             else tmax=t3;
        printf("\nTemperatura maxima: %.1f", tmax);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
