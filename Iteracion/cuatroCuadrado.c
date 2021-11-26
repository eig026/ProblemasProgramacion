/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
	int n, a, b, c, d;
	int amax, bmax, cmax, dmax;
	char cc;

	do
	{
		system("cls||clear");
		printf("TEOREMA DE LOS CUATRO CUADRADOS\n");
		printf("===============================\n\n");
		do
		{
			printf("Introduzca un num. natural: ");
			scanf(" %d", &n);
		} while (n <= 0);
		a = 0;
		amax = sqrt(n);
		while (a <= amax)
		{
			b = a;
			bmax = sqrt(n - a * a);
			while (b <= bmax)
			{
				c = b;
				cmax = sqrt(n - a * a - b * b);
				while (c <= cmax)
				{
					d = c;
					dmax = sqrt(n - a * a - b * b - c * c);
					while (d <= dmax)
					{
						if (n == a * a + b * b + c * c + d * d)
						{
							printf("%d=%d+%d+%d+%d\n", n, a * a, b * b, c * c, d * d);
						}
						++d;
					}
					++c;
				}
				++b;
			}
			++a;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &cc);
	} while ((cc != 'N') && (cc != 'n'));
	return 0;
}