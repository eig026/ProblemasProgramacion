/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */
/* raizCuartaNumeroPositivo     */
/* Programa que calcula x**0.25 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAX 10   /* Numero maximo de cifras decimales */

int main(){
    char c;
    double n;          /* numero real positivo        */
    int d;             /* numero de decimales (0-MAX) */
    double raiz;       /* raiz cuarta                 */
    double inc;        /* incremento del numero       */
    int i;             /* contador de iteraciones     */

    do{ system("cls");
        printf("RAIZ CUARTA DE UN NUMERO REAL\n");
        printf("=============================\n\n");
        do{ printf("Introduzca un numero real positivo: ");
            scanf(" %lf", &n);
        }while(n<0);
        do{ printf("Introduzca num. de decimales (0-%d): ",MAX);
            scanf(" %d", &d);
        }while((d<0)||(d>MAX));
        raiz=0;
        i=0;
        inc=10;
        while(i<=d){
            inc=inc/10;
            while(raiz*raiz*raiz*raiz<n)
                raiz=raiz+inc;
            if(raiz*raiz*raiz*raiz>n)
                raiz=raiz-inc;
            ++i;
        }
        printf("\n\nRaiz cuarta de %.15f = %.15f", n,raiz);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
