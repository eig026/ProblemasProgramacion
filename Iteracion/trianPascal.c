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
#define MAX 20

int main(){
	char c;
	int n,m;
	int filas;
	int coef;

	do{ system("cls||clear");
		printf("TRIANGULO DE PASCAL\n");
		printf("===================\n\n");
		do{	printf("Nº de filas: ");
			scanf(" %d",&filas);
		}while((filas<0)||(filas>MAX));
		printf("\n\n");
		n=0;
		while(n<=filas){
			m=filas-n;
			while(m>0){
				printf("%3s","");
				m--;
			}
			printf("%6d",1);
			coef=1;
			m=1;
			while(m<=n){
				coef=coef*(n-m+1)/m;
				printf("%6d",coef);
				m++;
			}
			printf("\n");
			++n;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
