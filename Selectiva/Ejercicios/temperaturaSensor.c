/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(){
	char c;
	float t,v;

	do{	system("cls");
		printf("TEMPERATURA A TRAVES DE SENSOR DE VOLTAJE\n");
		printf("=========================================\n\n");
		printf("Introduzca voltaje proporcionado por sensor (voltios): ");
		scanf(" %f", &v);
		if ((v<5)||(v>10))
			printf("\nError en lectura de temperatura");
		else{
			t=30*(v-5)-30;
			printf("\nTemperatura: %.1f grados centigrados", t);
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
   return 0;
}
