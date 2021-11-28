/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Prototipos de funciones */
void calcular_aceleracion_normal(void);

/* Definiciones de funciones */
int main(){
    char c;

    do{ system("cls");
        calcular_aceleracion_normal();
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void calcular_aceleracion_normal(void){
	float an,va,r;

	printf("ACELERACION NORMAL (O CENTRIPETA)\n");
	printf("=================================\n\n");
	printf("Introduzca velocidad angular (rad/sg): ");
	scanf(" %f",&va);
	printf("Introduzca radio de la trayectoria (m): ");
	scanf(" %f",&r);
	an=va*va*r;
	printf("\nLa aceleracion normal vale: %.2f m/sg2",an);
}
