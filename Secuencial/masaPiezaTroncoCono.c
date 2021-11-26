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
#define DENSIDAD 0.00786 /* Kg/cm3 */
#define PI 4 * atan(1)

int main()
{
	char cc;
	float a, b, h, v, m;

	do
	{
		system("cls||clear");
		printf("MASA PIEZA DE HIERRO TRONCO CONO CIRCULAR RECTO\n");
		printf("===============================================\n\n");
		printf("Introduzca longitudes de los radios (cm):\n");
		printf("\tRadio mayor (b): ");
		scanf(" %f", &a);
		printf("\tRadio menor (a): ");
		scanf(" %f", &b);
		printf("\tAltura: ");
		scanf(" %f", &h);
		v = PI * h * (a * a + a * b + b * b) / 3;
		m = DENSIDAD * v;
		printf("\nMasa: %.3f Kg", m);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &cc);
	} while ((cc != 'N') && (cc != 'n'));
	return 0;
}