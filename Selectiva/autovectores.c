/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main()
{
	char cc;
	double a11, a12, a13, a21, a22, a23, a31, a32, a33;
	double a, b, c, d, e, f;
	double x, y, z, x2, y2, z2, norma;
	int rango;

	do
	{
		system("cls");
		printf("CALCULO DE AUTOVECTORES\n");
		printf("=======================\n\n");
		/* Lectura matriz de coeficientes */
		printf("Introduzca coeficientes: \n");
		printf("  a11  a12  a13: ");
		scanf(" %lf %lf %lf", &a11, &a12, &a13);
		printf("  a21  a22  a23: ");
		scanf(" %lf %lf %lf", &a21, &a22, &a23);
		printf("  a31  a32  a33: ");
		scanf(" %lf %lf %lf", &a31, &a32, &a33);
		if (a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 -
			a11 * a23 * a32 - a21 * a12 * a33 - a31 * a22 * a13)
		{
			rango = 3;
		}
		else
		{
			if ((a11 * a22 - a12 * a21) || (a11 * a23 - a13 * a21) ||
				(a12 * a23 - a13 * a22))
			{
				a = a11;
				b = a12;
				c = a13;
				d = a21;
				e = a22;
				f = a23;
				rango = 2;
			}
			else
			{
				if ((a11 * a32 - a12 * a31) || (a11 * a33 - a13 * a31) ||
					(a12 * a33 - a13 * a32))
				{
					a = a11;
					b = a12;
					c = a13;
					d = a31;
					e = a32;
					f = a33;
					rango = 2;
				}
				else
				{
					if ((a21 * a32 - a22 * a31) || (a21 * a33 - a23 * a31) ||
						(a22 * a33 - a23 * a32))
					{
						a = a21;
						b = a22;
						c = a23;
						d = a31;
						e = a32;
						f = a33;
						rango = 2;
					}
					else
					{
						if (a11 || a12 || a13)
						{
							a = a11;
							b = a12;
							c = a13;
							rango = 1;
						}
						else
						{
							if (a21 || a22 || a23)
							{
								a = a21;
								b = a22;
								c = a23;
								rango = 1;
							}
							else
							{
								if (a31 || a32 || a33)
								{
									a = a31;
									b = a32;
									c = a33;
									rango = 1;
								}
								else
								{
									rango = 0;
								}
							}
						}
					}
				}
			}
		}
		switch (rango)
		{
		case 3:
			printf("No hay autovectores\n");
			break;
		case 2:
			printf("Un autovector\n");
			/* a*x+b*y+c*z=0
		           d*x+e*y+f*z=0 */
			if (a * e - b * d)
			{
				x = (-c * e + b * f) / (a * e - b * d);
				y = (-a * f + c * d) / (a * e - b * d);
				z = 1;
			}
			else
			{
				if (a * f - c * d)
				{
					x = (-b * f + e * c) / (a * f - c * d);
					z = (-a * e + d * b) / (a * f - c * d);
					y = 1;
				}
				else
				{
					x = 1;
					y = (-a * f + d * c) / (b * f - c * e);
					z = (-b * d + e * a) / (b * f - c * e);
				}
			}
			norma = sqrt(x * x + y * y + z * z);
			x /= norma;
			y /= norma;
			z /= norma;
			printf("  (%.2f,%.2f,%.2f)\n", x, y, z);
			break;
		case 1:
			printf("Dos autovectores:\n");
			/* a*x+b*y+c*z=0 */
			if (a)
			{
				x = (-b * 1 - c * 0) / a;
				norma = sqrt(x * x + 1);
				x = x / norma;
				y = 1 / norma;
				z = 0;
				x2 = (-b * 0 - c * 1) / a;
				norma = sqrt(x2 * x2 + 1);
				x2 = x2 / norma;
				y2 = 0;
				z2 = 1 / norma;
			}
			else
			{
				if (b)
				{
					y = (-a * 1 - c * 0) / b;
					norma = sqrt(y * y + 1);
					x = 1 / norma;
					y = y / norma;
					z = 0;
					y2 = (-a * 0 - c * 1) / b;
					norma = sqrt(y2 * y2 + 1);
					x2 = 0;
					y2 = y2 / norma;
					z2 = 1 / norma;
				}
				else
				{
					z = (-a * 1 - b * 0) / c;
					norma = sqrt(z * z + 1);
					x = 1 / norma;
					y = 0;
					z = z / norma;
					z2 = (-a * 0 - b * 1) / c;
					norma = sqrt(z2 * z2 + 1);
					x2 = 0;
					y2 = 1 / norma;
					z2 = z2 / norma;
				}
			}
			printf(" (%.2f,%.2f,%.2f) y (%.2f,%.2f,%.2f)",
				   x, y, z, x2, y2, z2);
			break;
		case 0:
			printf("Tres autovectores:\n");
			printf(" (1,0,0),(0,1,0) y (0,0,1)\n");
			break;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c", &cc);
	} while (cc != 'N');
	return 0;
}
