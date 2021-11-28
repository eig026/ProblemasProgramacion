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

double pulso_triangular(double x);

int main(){
	char c;
	double x;

	do{	system("cls");
		printf("FUNCION DIENTES DE SIERRA\n");
		printf("=========================\n\n");
		printf("Introduzca valor de x: ");
		scanf(" %lf",&x);
		printf("\nf(%.5lf) = %.5lf",x,pulso_triangular(x));
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);  
	}while (c!='N');
	return 0;
}

double pulso_triangular(double x){
	double y;
	if(x<0){
		x=-x;
	}
	x=x-(2*floor(x/2));
	if(x<=1){
		y=x;
	}else{
		y=2-x;
	}
	return(y);
}
