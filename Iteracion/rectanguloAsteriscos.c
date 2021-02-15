/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

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

	do{	system("cls");
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
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
