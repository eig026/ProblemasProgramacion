/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
* Calculo de la aceleracion Normal */



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float an,va,r;

	do{	system("cls");
		printf("ACELERACION NORMAL (O CENTRIPETA)\n");
		printf("=================================\n\n");
		printf("Introduzca velocidad angular (rad/sg): ");
		scanf(" %f",&va);
		printf("Introduzca radio de la trayectoria (m): ");
		scanf(" %f",&r);
		an=va*va*r;
		printf("\nLaaceleracion normal vale: %.2f m/sg2",an);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
