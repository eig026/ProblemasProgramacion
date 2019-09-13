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
	int n,i ;
	double fac;
	//int fac;

	do{	system("cls");
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
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
