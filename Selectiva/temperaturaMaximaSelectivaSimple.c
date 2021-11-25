/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
 */
/* temperatura Maxima0           */
/* programa que calcula el mayor */
/* valor de dos temperaturas     */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
    char c;
    float t1,t2;    /* dos valores de temperatura */
    float tmax;     /* temperatura maxima         */

    do{  system("cls||clear");
        printf("TEMPERATURA MAXIMA\n");
        printf("==================\n\n");
        printf("Introduzca temperatura 1: ");
        scanf(" %f", &t1);
        printf("Introduzca temperatura 2: ");
        scanf(" %f", &t2);
        if(t1>=t2)
             tmax=t1;
        else tmax=t2;
        printf("\nTemperatura maxima: %.2f",tmax);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		  scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}
