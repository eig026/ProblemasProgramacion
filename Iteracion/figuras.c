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
	int n;
	int i,j;

	do{	system("cls||clear");
		printf("FIGURAS: ROMBOS y TRIANGULOS\n");
		printf("============================\n\n");
		do{	printf("Introduzca numero positivo (0-%d): ",MAX);
			scanf(" %d",&n);
		}while((n<=0)||(n>=MAX));
		printf("\n\n");
		if(n%2){
			for(i=1;i<=n;++i){
				for(j=1;j<=abs(n/2-i+1);++j){
					printf(" ");
				}
				for(j=1;j<=(n/2+1-abs(n/2+1-i));++j){
					printf("* ");
				}
				printf("\n");
			}
		}else{
			for(i=1;i<=n;++i){
				for(j=1;j<=i;++j){
					printf("* ");
				}
				printf("\n");
			}
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
