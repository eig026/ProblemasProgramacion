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

int main()
{
	char c;
	float x, y, r, a;

	do
	{
		system("cls||clear");
		printf("COORDENADAS CARTESIANAS --> POLARES\n");
		printf("===================================\n\n");
		printf("Introduzca x: ");
		scanf(" %f", &x);
		printf("Introduzca y: ");
		scanf(" %f", &y);
		r = sqrt(x * x + y * y);
		if (r == 0)
			a = 0;
		else
		{
			a = asin(y / r);
			if (x < 0)
				a = M_PI - a;
		}
		if (a < 0)
			a = 2 * M_PI + a;
		a = 180 * a / M_PI;
		printf("\nCoordenadas polares: r=%.3f, ang=%.1f grados", r, a);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}
