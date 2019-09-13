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
#define FIJO 30
#define T1  15
#define T2  10

int main(){
	char c;
	float km,total;

	do{	system("cls");
		printf("TARIFA TAXI\n");
		printf("===========\n\n");
		printf("Introduzca kms recorridos: ");
		scanf(" %f", &km);
		if(km<=0){
			printf("Error: datos de E no validos");
		}else{
			if(km<=30){
				total=FIJO;
			}else{	if(km<=100){
						total=FIJO+(km-30)*T1;
					}else{	total=FIJO+(100-30)*T1+(km-100)*T2;
				}
			}
			printf("\nTotal a pagar: %.1f",total);
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
   return 0;
}
