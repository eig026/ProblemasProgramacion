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
	int i,n;
	float suma;

	do{	system("cls");
		printf("SUMA DE NUMEROS IMPARES MULTIPLOS DE 3\n");
		printf("======================================\n\n");
		do{	printf("Introduzca limite superior: ");
			scanf(" %d", &n);
		}while(n<0);
		i=3;
		suma=0;
		while(i<=n){
			suma+=i;
			i+=6;
		}
		printf("\nLa suma vale: %.0f",suma);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
