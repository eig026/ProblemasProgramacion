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
	float m,va,r,i,l;

	do{	system("cls");
		printf("MOMENTO ANGULAR\n");
		printf("===============\n\n");
		printf("Introduzca masa (Kg): ");
		scanf(" %f",&m);
		printf("Introduzca longitud del brazo (m): ");
		scanf(" %f",&r);
		printf("Introduzca velocidad angular (rad/sg): ");
		scanf(" %f",&va);
		i=2*m*r*r;
		l=i*va;
		printf("\nMomento principal de inercia:  %.3f kg*m2",i);
		printf("\nMomento angular: %.3f kg*m2/sg",l);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
