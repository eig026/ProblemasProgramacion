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
	int g, m, s, g1, m1, s1, g2, m2, s2;

	do
	{
		system("cls||clear");
		printf("SUMAS DE ANGULOS\n");
		printf("================\n\n");
		printf("Introduzca primer angulo: \n");
		printf("\tGrados: ");
		scanf(" %d", &g1);
		printf("\tMinutos: ");
		scanf(" %d", &m1);
		printf("\tSegundos: ");
		scanf(" %d", &s1);
		printf("Introduzca segundo angulo: \n");
		printf("\tGrados: ");
		scanf(" %d", &g2);
		printf("\tMinutos: ");
		scanf(" %d", &m2);
		printf("\tSegundos: ");
		scanf(" %d", &s2);
		if ((g1 < 0) || (g1 > 359) || (m1 < 0) || (m1 > 59) || (s1 < 0) || (s1 > 59) ||
			(g1 < 0) || (g1 > 359) || (m1 < 0) || (m1 > 59) || (s1 < 0) || (s1 > 59))
		{
			printf("Error: datos no válidos");
		}
		else
		{
			s = s1 + s2;
			m = m1 + m2;
			g = g1 + g2;
			if (s >= 60)
			{
				s -= 60;
				m++;
			}
			if (m >= 60)
			{
				m -= 60;
				g++;
			}
			if (g >= 360)
			{
				g -= 360;
			}
		}
		printf("\n\n%10d grados %3d minutos %3d segundos\n", g1, m1, s1);
		printf("    +%5d grados %3d minutos %3d segundos\n", g2, m2, s2);
		printf("      ====       ====        ====\n");
		printf("%10d grados %3d minutos %3d segundos\n", g, m, s);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}