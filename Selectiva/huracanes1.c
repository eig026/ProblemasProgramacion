/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */
/* huracanes1                                                  */
/* programa que presenta en pantalla la categoria de un huracan*/
/* a partir de su nivel, segun clasificacion de Saffir-Simpson */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
    char c;
    int nivel;   /* nivel del huracan: 1,2,3,4,5 */

    do{ system("cls");
        printf("CLASIFICACION DE HURACANES\n");
        printf("==========================\n\n");
        printf("Introduzca el nivel del huracan: ");
        scanf(" %d", &nivel);
        switch(nivel){
        case 1: printf("\nClasificacion: minimo");
                break;
        case 2: printf("\nClasificacion: moderado");
                break;
        case 3: printf("\nClasificacion: extenso");
                break;
        case 4: printf("\nClasificacion: extremo");
                break;
        case 5: printf("\nClasificacion: catastrofico");
                break;
        default:printf("\nError: nivel no valido");
                break;
        }
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
