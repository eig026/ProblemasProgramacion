/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa saludara al usuario incorporando su nombre y apellidos al saludo
 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void convertir_velocidad(void);

int main(){
	char c;

	do{ 	      system("cls||clear");
			convertir_velocidad();
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}


void convertir_velocidad(void){
	float v,v1;

	printf("CONVERTIR KM/H --> M/SG\n");
	printf("=======================\n\n");
	printf("Introduzca velocidad en Km/h: ");
	scanf(" %f", &v);
	v1=v/3.6;
	printf("\nLa velocidad en m/sg = %f",v1);
}

