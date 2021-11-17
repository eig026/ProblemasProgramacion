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
	int i,e;
	double pot,b;

	do{	system("cls||clear");
		printf("POTENCIA\n");
		printf("========\n\n");
		printf("Introduzca numero base: ");
		scanf(" %lf", &b);
		printf("Introduzca exponente: ");
		scanf(" %d", &e);
		printf("\nPotencia: %.3f ** %d = ",b,e);
		if (b==0)
			if(e==0)
				printf("Indeterminacion");
			else
				if(e>0)
					printf("0");
				else
					printf("infinito");
		else{
			if(e<0){
				b=1/b;
				e=-e;
			}
			pot=1;
			i=1;
			while(i<=e){
				pot=pot*b;
				i++;
			}
			printf("%.3f",pot);
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
