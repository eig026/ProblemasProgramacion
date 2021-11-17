/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

/* temperaturaMaxima3_1                         */
/* programa que calcula la mayor temperatura de  un conjunto de datos de temperaturas.        */
/* El numero de datos es conocido a priori      */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(){
    char c;
    int n;            /* numero de datos a leer */
    int i;            /* contador del bucle     */
    float t;          /* temperatura leída      */
    float tmax;       /* temperatura máxima     */

    do{ system("cls||clear");
        printf("TEMPERATURA MAXIMA\n");
        printf("==================\n\n");
        printf("Introduzca numero de datos: ");
        scanf(" %d", &n);
        if(n<=0)
              printf("Sin datos a leer");
        else{ tmax=-1E38;
              i=1;
              while(i<=n){
                  printf ("Introduzca temperatura: ");
                  scanf(" %f", &t);
                  if(t>tmax)
                      tmax=t;
                  i++;
              }
              printf("\nTemperatura maxima: %.0f", tmax);
        }
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}
