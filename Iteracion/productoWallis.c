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

int main(){
	char c;
	double pre;
	double wal;
	double fac;
	double num,den,aux;
	long  i;

	do{	system("cls");
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
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
