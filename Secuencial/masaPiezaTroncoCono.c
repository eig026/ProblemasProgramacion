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
#define DENSIDAD 0.00786  /* Kg/cm3 */
#define PI 4*atan(1)

int main(){
	char cc;
	float a,b,h,v,m;

	do{	system("cls");
		printf("MASA PIEZA DE HIERRO TRONCO CONO CIRCULAR RECTO\n");
		printf("===============================================\n\n");
		printf("Introduzca longitudes de los radios (cm):\n");
		printf("\tRadio mayor (b): ");
		scanf(" %f", &a);
		printf("\tRadio menor (a): ");
		scanf(" %f", &b);
		printf("\tAltura: ");
		scanf(" %f", &h);
		v=PI*h*(a*a+a*b+b*b)/3;
		m=DENSIDAD*v;
		printf("\nMasa: %.3f Kg",m);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		cc=toupper(getch());
	}while (cc!='N');
	return 0;
}
