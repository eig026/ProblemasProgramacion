/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

 */


#include <stdio.h>
#include <ctype.h>
#define MAX 20

void main()
{  char c;
	int i,j;

	do{ system("cls||clear");
		 printf("DIVISORES DE LOS PRIMEROS 20 NUMEROS ENTEROS\n");
		 printf("============================================\n\n");
		 i=1;
		 while (i<=MAX){
			printf("\nDivisores de %-5d: ",i);
			j=1;
			while(j<=i){
				if(!(i%j))
					printf("%5d ",j);
				j++;
			}
			i++;
		 }
		 printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
}
