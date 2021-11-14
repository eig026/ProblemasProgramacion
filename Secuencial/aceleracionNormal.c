/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 
* Cálculo de la aceleración Normal */



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float an,va,r;

	do{	
		printf("ACELERACION NORMAL (O CENTRIPETA)\n");
		printf("=================================\n\n");
		printf("Introduzca velocidad angular (rad/sg): ");
		scanf(" %f",&va);
		printf("Introduzca radio de la trayectoria (m): ");
		scanf(" %f",&r);
		an=va*va*r;
		printf("\nLaaceleracion normal vale: %.2f m/sg2",an);
	    printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}