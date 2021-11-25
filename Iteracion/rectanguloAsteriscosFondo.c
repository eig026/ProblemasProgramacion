/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char c;
    int a,h,z;	        /* ancho, alto, profundo*/
    int i,j,k,m, altura;   /*PAra los bucles */

    do{ system("cls||clear");
        printf("proyección paralela axonométrica \n");
        printf("========================================\n\n");
        do{
           printf("Introduzca el ancho: ");
           scanf(" %d", &a);
        }while((a<3)||(a>40));
        do{
           printf("Introduzca el alto: ");
           scanf(" %d", &h);
        }while((h<3)||(h>20));
        do{
           printf("Introduzca profundidad: ");
           scanf(" %d", &z);
        }while((z<3)||(z>20));

	//{ Arista superior }
    for(j=1;j<z;j++)
        printf("  ");
    for(j=1;j<=a;j++)
        printf(" *");

	printf(" \n");
    altura=1;
//	//Cara superior
    for (i=2;i<z;i++){
        for(j=1;j<=z-i;j++)
            printf("  ");
        printf(" *");
        for(k=2;k<a;k++)
            printf("  ");
        printf(" *");
   	//revisar hasta altura
        for(m=1;m<i-1;m++)
            printf("  ");
        printf(" *\n");
    }

	//Arista superior en alzado

        for(j=1;j<=a;j++)
            printf(" *");
        for(j=2;j<z;j++)
            printf("  ");
        printf(" *\n");

	//{ Aristas alzado hasta altura
        for(i=2;i<=h-z;i++){
            printf(" *");
            for(j=2;j<a;j++)
                printf("  ");
            printf(" *");
            for(j=2;j<z;j++)
                printf("  ");
            printf(" *\n");
        }

        for(i=2;i<=z;i++){
           printf(" *");
           for(j=2;j<a;j++)
                printf("  ");
           printf(" *");
           	//comprobar la altura
           for(j=1;j<=z-i;j++)
                printf("  ");
           printf(" *\n");
        }
	//{ Arista inferior }
        for(j=1;j<=a;j++)
            printf(" *");
        printf("\n");

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
 		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}

