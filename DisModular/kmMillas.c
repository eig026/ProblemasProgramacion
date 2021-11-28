/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <ctype.h>
#include <math.h>

void convertir_velocidad(void);

int main(){
	char c;

	do{ 	 system("cls||clear");
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
