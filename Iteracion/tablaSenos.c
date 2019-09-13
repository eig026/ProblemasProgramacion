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
#define INC 0.1

int main(){
	int n;		/* Número de la tabla n:1-10	*/
	double x;	/* Valor del angulo: 0-90		*/
	int i,j;	/* contadores de iteraciones	*/
	char c;

	do{	system("cls");
		printf("TABLAS DE SENOS\n");
		printf("===============\n");
		n=1;
		while(n<=10){
			system("cls");
			/* Cabecera de la tabla */
			printf("Seno(%d*x)\n",n);
			j=1;
			while(j<=85){
				printf("=");
				++j;
			}
			printf("\n");
			printf("     ");
			j=1;
			x=0;
			while(j<=10){
				x+=INC;
				printf("%8.1f",x);
				++j;
			}
			printf("\n");
			j=1;
			while(j<=85){
				printf("=");
				++j;
			}
			printf("\n");
			/* Bucle intermedio */
			x=0;
			i=0;
			while(i<90){
				printf("%3.0f |",x);
				/* Bucle interior */
				j=1;
				while(j<=10){
					x+=INC;
					printf("%8.4f",sin(n*x*M_PI/180));
					++j;
				}
				printf("\n");
				++i;
			}
			getch();
			++n;
		}
		printf("\n");
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
