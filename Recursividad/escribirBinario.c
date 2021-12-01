/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06


 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

void escribir_binario(int n);

int main()
{
	char c;
	int n;

	do
	{
		printf("CONVERSION DECIMAL --> BINARIO\n");
		printf("==============================\n\n");
		do
		{
			printf("Introduzca entero positivo: ");
			scanf(" %d", &n);
		} while (n < 0);
		escribir_binario(n);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}

void escribir_binario(int n)
{
	if (n < 2)
		printf("%d", n);
	else
	{
		escribir_binario(n / 2);
		printf("%d", n % 2);
	}
}