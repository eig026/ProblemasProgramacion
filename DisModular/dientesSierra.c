/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa saludara al usuario incorporando su nombre y apellidos al saludo
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
		c=toupper(getch());
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
