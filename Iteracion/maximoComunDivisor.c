/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */
/* MaximoComunDivisor                             */
/* Programa que calcula el mayor de los divisores */
/* comunes de dos numeros enteros positivos       */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(){
    char c;
    int n1,n2;        /* dos enteros positivos    */
    int mcd;          /* maximo comun denominador */

    do{ system("cls");
        printf("MAXIMO COMUN DENOMINADOR\n");
        printf("========================\n\n");
        do{ printf("Introduzca un numero positivo: ");
            scanf(" %d", &n1);
        }while(n1<=0);
        do{ printf("Introduzca otro numero positivo: ");
            scanf(" %d", &n2);
        }while(n2<=0);
        mcd=n1;
        while((n1%mcd)||(n2%mcd))
            mcd--;
        printf("\n\nMaximo comun denominador: %d",mcd);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while(c!='N');
    return 0;
}
