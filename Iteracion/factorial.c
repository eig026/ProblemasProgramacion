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
	int n,i ;
	double fac;
	//int fac;

	do{	system("cls||clear");
		printf("FACTORIAL\n");
		printf("=========\n\n");
		do{	printf("Introduzca numero natural: ");
			scanf(" %d", &n);
		}while (n<0);
		fac=1;
		i=1;
		while(i<=n){
			fac=fac*i;
			i++;
		}
		printf("\nFactorial:  %d! = %.lf",n,fac);
		//printf("\nFactorial:  %d! = %d",n,fac);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
