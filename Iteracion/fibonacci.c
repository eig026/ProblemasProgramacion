/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

int main(){
	int n;
	long fib;
	int i;
	long fib_1,fib_2;
	char c;

	do{ system("cls");
		printf("SERIE DE FIBONACCI\n");
		printf("==================\n\n");
		do{ printf("\tNumero de termino: ");
			scanf(" %d",&n);
		}while(n<0);
		fib_1=0;
		fib_2=1;
		i=1;
		while(i<=n){
			fib=fib_1+fib_2;
			fib_2=fib_1;
			fib_1=fib;
			++i;
		}
		printf("\n\tTermino %d de Fibonacci: %ld",n,fib);
		printf("\n\n");
		printf("\t\tContinuar (S/N):");
		c=toupper(getch());
	}while(c!='N');
	return 0;
}
