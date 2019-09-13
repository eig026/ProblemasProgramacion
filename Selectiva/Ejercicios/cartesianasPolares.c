/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float x,y,r,a;

	do{	system("cls");
		printf("COORDENADAS CARTESIANAS --> POLARES\n");
		printf("===================================\n\n");
		printf("Introduzca x: ");
		scanf(" %f", &x);
		printf("Introduzca y: ");
		scanf(" %f", &y);
		r=sqrt(x*x+y*y);
		if (r==0)
			a=0;
		else{
			a=asin(y/r);
			if(x<0)
				a=M_PI-a;
		}
		if (a<0)
			a=2*M_PI+a;
		a=180*a/M_PI;
		printf("\nCoordenadas polares: r=%.3f, ang=%.1f grados", r, a);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
   return 0;
}
