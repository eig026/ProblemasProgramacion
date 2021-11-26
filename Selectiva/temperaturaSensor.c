/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char c;
	float t, v;

	do
	{
		system("cls||clear");
		printf("TEMPERATURA A TRAVES DE SENSOR DE VOLTAJE\n");
		printf("=========================================\n\n");
		printf("Introduzca voltaje proporcionado por sensor (voltios): ");
		scanf(" %f", &v);
		if ((v < 5) || (v > 10))
			printf("\nError en lectura de temperatura");
		else
		{
			t = 30 * (v - 5) - 30;
			printf("\nTemperatura: %.1f grados centigrados", t);
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}