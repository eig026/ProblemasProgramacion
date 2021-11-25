/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
*/
/* programa que calcula el área de un triángulo */
/* dadas las longitudes de sus lados            */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
    char c;
    float l1,l2,l3;  /* longitudes de los lados */
    float s;         /* semiperimetro           */
    float area;      /* área del triángulo      */

    do{ system("cls||clear");
        printf("CALCULO DEL AREA DE UN TRIANGULO\n");
        printf("================================\n\n");
        printf("Introducir longitudes de lados:\n");
        printf("\tl1: ");
        scanf(" %f",&l1);
        printf("\tl2: ");
        scanf(" %f",&l2);
        printf("\tl3: ");
        scanf(" %f",&l3);
        if((l1<=0)||(l2<=0)||(l3<=0))
             printf("Error en datos de entrada");
        else if((l1<(l2+l3))&&(l2<(l1+l3))&&(l3<(l1+l2))){
                   s=(l1+l2+l3)/2;
                   area=sqrt(s*(s-l1)*(s-l2)*(s-l3));
                   printf("\nArea= %.2f",area);
             }else printf("\nNo es un triangulo");
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		  scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}
