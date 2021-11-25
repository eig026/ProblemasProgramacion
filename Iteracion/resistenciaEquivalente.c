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
#define MAX 3

int main(){
	char c;
	int i;
	double r,rt;

	do{	system("cls||clear");
		printf("RESISTENCIA EQUIVALENTE CONJUNTO DE RESISTENCIAS EN PARALELO\n");
		printf("============================================================\n\n");
		rt=0;
		i=0;
		do{	printf("Introduzca valor resistencia R%d (ohmios): ",i+1);
			scanf(" %lf", &r);
		}while(r<0);
		while((i<MAX)&&(r)){
			++i;
			rt+=1/r;
			if(i<MAX){
				do{	printf("Introduzca valor resistencia R%d (ohmios): ",i+1);
					scanf(" %lf", &r);
				}while(r<0);
			}
		}
		if(i){
 			rt=1/rt;
			printf("\nResistencia equivalente (ohmios): %.2f",rt);
		}else
			printf("\nNo hay ninguna resistencia");
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
