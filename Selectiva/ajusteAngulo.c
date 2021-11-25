/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*/


#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float ang;

	do{ system("cls||clear");
			printf("ANGULO ENTRE 0 y 360 grados\n");
			printf("===========================\n\n");
			printf("Introduzca un angulo (grados): ");
			scanf(" %f",&ang);
			if(ang>=360)
				ang-=360*(int)(ang/360);
			else if(ang<0)
					ang+=360*(int)(fabs(ang)/360)+360;
			printf("\nAngulo (0-360): %.2f",ang);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		  scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
   return 0;
}