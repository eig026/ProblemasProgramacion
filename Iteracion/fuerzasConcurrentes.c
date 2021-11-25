/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

/* resultanteFuerzasConcurrentes                        */
/* programa que calcula la resultante de un conjunto de fuerzas concurrentes cuyas componentes se introducen */
/* por teclado. Finaliza la entrada con una fuerza nula */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char c;
    float fx,fy,fz;       /* componentes de cada fuerza */
    float rx,ry,rz;	      /* componentes de resultante  */
    int n;                /* num. de fuerzas leidas     */

    do{ system("cls||clear");
        printf("RESULTANTE DE UN CONJUNTO DE FUERZAS CONCURRENTES\n");
        printf("=================================================\n\n");
        n=0;
        printf("Introducir componentes de Fuerza(%d):\n",n);
        printf("\tFx: ");
        scanf(" %f", &fx);
        printf("\tFy: ");
        scanf(" %f", &fy);
        printf("\tFz: ");
        scanf(" %f", &fz);
        rx=0;
        ry=0;
        rz=0;
        while((fx!=0)||(fy!=0)||(fz!=0)){
            rx=rx+fx;
            ry=ry+fy;
            rz=rz+fz;
            n=n+1;
            printf("Introducir componentes de Fuerza(%d):\n",n);
            printf("\tFx: ");
            scanf(" %f", &fx);
            printf("\tFy: ");
            scanf(" %f", &fy);
            printf("\tFz: ");
            scanf(" %f", &fz);
        }
        printf("\nResultante de %d fuerzas:",n);
        printf(" (%.1f,%.1f,%.1f)",rx,ry,rz);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");

		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));;
   return 0;
}
