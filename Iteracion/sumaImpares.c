/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int i,n;
	float suma;

	do{ system("cls||clear");
			printf("SUMA DE NUMEROS IMPARES ENTRE 0 y 1000\n");
			printf("======================================\n\n");
			do{	printf("Introduzca limite superior: ");
					scanf(" %d", &n);
			}while(n<0);
			i=1;
			suma=0;
			while(i<=n){
				if (!(i%3))
					suma+=i;
				i+=2;
			}
         printf("\nLa suma vale: %.0f",suma);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
   return 0;
}
