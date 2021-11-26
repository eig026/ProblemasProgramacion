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
	int n, r;

	do
	{
		system("cls||clear");
		printf("ADIVINAR NUMERO DE UN DIGITO\n");
		printf("============================\n\n");
		do
		{
			printf("Introduzca P (par) o I (impar): ");
			scanf(" %c", &c);
			printf("\n");
		} while ((c != 'P') && (c != 'I'));
		do
		{
			printf("Introduzca resto de division entre 5: ");
			scanf(" %d", &r);
		} while ((r < 0) || (r >= 5));
		if (c == 'P')
			if (r % 2)
				n = r + 5;
			else
				n = r;
		else if (r % 2)
			n = r;
		else
			n = r + 5;
		printf("\nEl numero es: %d", n);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}