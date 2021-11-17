/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int a;
	int h;
	int i,j;

	do{	system("cls||clear");
		printf("RECTANGULO DE ASTERISCOS\n");
		printf("========================\n\n");
		do{
			printf("Introduzca ancho [3-40]: ");
			scanf(" %d",&a);
		}while((a<3)||(a>40));
		do{
			printf("Introduzca altura [3-20]: ");
			scanf(" %d",&h);
		}while((h<3)||(h>40));
		/* Arista superior */
		j=1;
		while(j<=a){
			printf(" *");
			++j;
		}
		printf("\n");
		/* Aristas laterales */
		i=2;
		while(i<h){
			printf(" *");
			j=2;
			while(j<a){
				printf("  ");
				++j;
			}
			printf(" *\n");
			++i;
		}
		/* Arista inferior */
		j=1;
		while(j<=a){
			printf(" *");
			++j;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
