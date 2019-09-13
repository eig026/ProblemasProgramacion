/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa saludara al usuario incorporando su nombre y apellidos al saludo
 
 */

#include <stdio.h>

int main(){
	char nombre[30];

	printf("Por favor, introduzca su nombre: ");
	scanf(" %[^\n]s",nombre);
	printf("\n\nSaludos D. %s", nombre);
	printf("\nBienvenido al fantastico mundo de la programacion");
	printf("\n\nPulse una tecla para finalizar");
	getch();
	return 0;
}
