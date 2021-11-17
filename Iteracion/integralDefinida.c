/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	double a,b,base;
	int signo;
	double x,suma,area,yizq,yder;

	do{ system("cls||clear");
		printf("INTEGRAL DEFINIDA EN UN INTERVALO\n");
		printf("=================================\n\n");
		printf("Introduzca intervalo de integracion:\n");
		printf("\tlimite izquierdo: ");
		scanf(" %lf",&a);
		printf("\tlimite derecho: ");
		scanf(" %lf",&b);
		signo=1;
		if(b<a){
			x=a;
			a=b;
			b=x;
			signo=-1;
		}
		do{	printf("Introduzca valor de incremento (base): ");
			scanf(" %lf", &base);
		}while ((base<=0)&&(base>b-a));
		suma=0;
		x=a;
		yder=x*x*x-3*x*x+5;
		while(x+base<=b){
			yizq=yder;
			x+=base;
			yder=x*x*x-3*x*x+5;
			area=base*(yizq+yder)/2;
			suma+=area;
		}
		if(x<b){
			yizq=yder;
			yder=b*b*b-3*b*b+5;
			area=(b-x)*(yizq+yder)/2;
			suma+=area;
		}
		suma*=signo;
		printf("\nIntegral definida: %.6lf",suma);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
