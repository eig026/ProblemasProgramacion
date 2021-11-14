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
	float fah,cel;

	do{	
		printf("CONVERSION DE GRADOS CENTIGRADOS A FAHRENHEIT\n");
		printf("=============================================\n\n");
		printf("Introduzca temperatura (grados celsius): ");
		scanf(" %f", &cel);
		fah=9*cel/5+32;
		printf("\nTemperatura (grados fahrenheit): %.1f",fah);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
   return 0;
}