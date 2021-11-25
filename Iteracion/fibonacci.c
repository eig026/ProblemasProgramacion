/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(){
	int n;
	long fib;
	int i;
	long fib_1,fib_2;
	char c;

	do{ system("cls||clear");
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
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
