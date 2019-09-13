/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06

 */
/* programa que calcula el exceso de velocidad    */
/* con respecto a un limite dado                  */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define LIMITE 120  /* velocidad maxima permitida */

int main(){
    char c;
    float v;               /* velocidad (km/h)    */
    float exceso;          /* exceso de velocidad */

    do{ system("cls");
        printf("COMPROBACION EXCESO VELOCIDAD\n");
        printf("=============================\n\n");
        printf("Introducir velocidad (Km/h): ");
        scanf(" %f", &v);
        if(v>LIMITE){
            exceso=v-LIMITE;
            printf("\nSobepasado limite de velocidad");
            printf(" en %.2f Km/h",exceso);
        }
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
