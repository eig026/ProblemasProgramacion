/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int i,n;
	float suma;

	do{	system("cls||clear");
		printf("SUMA DE NUMEROS IMPARES MULTIPLOS DE 3\n");
		printf("======================================\n\n");
		do{	printf("Introduzca limite superior: ");
			scanf(" %d", &n);
		}while(n<0);
		i=3;
		suma=0;
		while(i<=n){
			suma+=i;
			i+=6;
		}
		printf("\nLa suma vale: %.0f",suma);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
