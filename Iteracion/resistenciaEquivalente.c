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
#define MAX 3

int main(){
	char c;
	int i;
	double r,rt;

	do{	system("cls");
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
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
