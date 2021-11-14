/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define BORRADO "cls"  // para windows
// #define BORRADO "clear"  // linux

int main(){
	char c;

	do{ system(BORRADO);
			printf("\n");
			printf("======\n\n");


			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);
	}while (c!='N');
	return 0;
}
