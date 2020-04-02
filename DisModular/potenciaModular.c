/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06



 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

float potencia(float b,int e);

int main(){
	char c;
	float b;
   int e;

	do{
			printf("POTENCIA\n");
			printf("========\n\n");
			printf("Introduzca numero base: ");
			scanf(" %f", &b);
			printf("Introduzca exponente: ");
			scanf(" %d", &e);
			printf("\nPotencia: %.1f ** %d = %.4f",b,e,potencia(b,e));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

float potencia(float b,int e){
	int i;
	float pot;

	if (b==0)
		if(e==0)
			//pot=0;
         exit(0);
		else 	if(e>0)
					pot=0;
				else pot=1e37;
	else{	pot=1;
			if(e<0){
				b=1/b;
				e=-e;
			}
			i=1;
			while(i<=e){
				pot=pot*b;
				i++;
			}
	}
	return pot;
}
