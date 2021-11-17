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
	double pre;
	double wal;
	double fac;
	double num,den,aux;
	long  i;

	do{	system("cls||clear");
		printf("PRODUCTO DE WALLIS\n");
		printf("==================\n\n");
		do{	printf("Introduzca precision: ");
			scanf(" %lf",&pre);
		}while(pre<=0);
		num=2;
		den=1;
		wal=1;
		i=0;
		fac=num/den;
		while(fabs(1-fac)>=pre){
			wal=wal*fac;
			aux=num;
			num=den+1;
			den=aux+1;
			i++;
			fac=num/den;
		}
		printf("\nPrecision: %.15f",pre);
		printf("\nResultado: %.15f",wal);
		printf("\nPI/2:      %.15f",2*atan(1));
		printf("\nNum. de iteraciones: %ld",i);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
