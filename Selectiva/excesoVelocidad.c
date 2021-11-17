/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
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

    do{ system("cls||clear");
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
		  scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}
