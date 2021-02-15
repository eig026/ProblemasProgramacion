/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06
*  */
/* calculoSumatoria                           */
/* programa que calcula:    sumatoria(i/2**i) */
/* donde el numero de terminos de la suma     */
/* se introduce por teclado                   */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(){
    char c;
    int i;         /* contador de iteraciones */
    int n;         /* numero de terminos suma */
    double suma;   /* valor de la suma        */
    double p;      /* potencia: 1/2**i        */

    do{ system("cls");
        printf("SUMATORIA DE i/2**i\n");
        printf("===================\n\n");
        do{ printf("Introduzca numero de sumandos: ");
            scanf(" %d",&n);
        }while(n<=0);
        suma=0;
        p=1;
        i=1;
        while(i<=n){
            p=p/2;
            suma=suma+i*p;
            i=i+1;
        }
        printf("\n\nSumatoria= %.15f",suma);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
