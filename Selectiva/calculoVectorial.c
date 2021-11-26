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
	float v1x, v1y, v1z, v2x, v2y, v2z;
	float e, vx, vy, vz;

	do
	{
		system("cls||clear");
		printf("CALCULO VECTORIAL\n");
		printf("=================\n\n");
		printf("Introduzca primer vector:\n");
		printf("\tx: ");
		scanf(" %f", &v1x);
		printf("\ty: ");
		scanf(" %f", &v1y);
		printf("\tz: ");
		scanf(" %f", &v1z);
		printf("Introduzca segundo vector:\n");
		printf("\tx: ");
		scanf(" %f", &v2x);
		printf("\ty: ");
		scanf(" %f", &v2y);
		printf("\tz: ");
		scanf(" %f", &v2z);
		do
		{
			system("cls");
			printf("Operaciones a realizar:\n");
			printf("=======================\n\n");
			printf("\t+  Suma de vectores\n");
			printf("\t-  Resta de vectores\n");
			printf("\t.  Producto escalar\n");
			printf("\tx  Producto vectorial\n");
			printf("\n\t\tIntroduzca opcion: ");
			scanf(" %c", &c);
			printf("\n\n");
			switch (c)
			{
			case '+':
				printf("Suma de vectores:\n");
				vx = v1x + v2x;
				vy = v1y + v2y;
				vz = v1z + v2z;
				printf("(%.0f,%.0f,%.0f)+", v1x, v1y, v1z);
				printf("(%.0f,%.0f,%.0f)=", v2x, v2y, v2z);
				printf("(%.0f,%.0f,%.0f)", vx, vy, vz);
				break;
			case '-':
				printf("Resta de vectores:\n");
				vx = v1x - v2x;
				vy = v1y - v2y;
				vz = v1z - v2z;
				printf("(%.0f,%.0f,%.0f)-", v1x, v1y, v1z);
				printf("(%.0f,%.0f,%.0f)=", v2x, v2y, v2z);
				printf("(%.0f,%.0f,%.0f)", vx, vy, vz);
				break;
			case '.':
				printf("Producto escalar:\n");
				e = v1x * v2x + v1y * v2y + v1z * v2z;
				printf("(%.0f,%.0f,%.0f).", v1x, v1y, v1z);
				printf("(%.0f,%.0f,%.0f)=", v2x, v2y, v2z);
				printf("%.0f", e);
				break;
			case 'x':
			case 'X':
				printf("Producto vectorial:\n");
				vx = v1y * v2z - v1z * v2y;
				vy = v1z * v2x - v1x * v2z;
				vz = v1x * v2y - v1y * v2x;
				printf("(%.0f,%.0f,%.0f)x", v1x, v1y, v1z);
				printf("(%.0f,%.0f,%.0f)=", v2x, v2y, v2z);
				printf("(%.0f,%.0f,%.0f)", vx, vy, vz);
				break;
			default:
				printf("\aOpcion no valida");
				break;
			}
			printf("\n\nDesea seleccionar otra operacion (s/n)? ");
			c = toupper(getche());
		} while (c != 'N');
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &c);
	} while ((c != 'N') && (c != 'n'));
	return 0;
}
