/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

  Este programa saludara al usuario incorporando su nombre y apellidos al saludo formal

 */

#include <stdio.h>

int main(){
	char nombre[30],apellidos[30];

	printf("Por favor, introduzca su nombre: ");
	scanf(" %[^\n]s",nombre);
        printf("Por favor, introduzca sus apellidos: ");
	scanf(" %[^\n]s",apellidos);
	printf("\n\nSaludos D. %s", nombre);
	printf(" %s/n", apellidos);
	printf("\n\nPulse una tecla para finalizar");
	getch();
	return 0;
}
