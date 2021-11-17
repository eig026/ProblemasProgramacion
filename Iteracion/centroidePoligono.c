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
	int n,i;
	double x,y,xant,yant,x1,y1;
	double a,xcentro,ycentro;
	double suma,sumax,sumay;

	do{	system("cls||clear");
		printf("CENTROIDE DE UN POLIGONO REGULAR\n");
		printf("================================\n\n");
		do{	printf("Introduzca nº de lados: ");
			scanf(" %d", &n);
		}while(n<3);
		suma=sumax=sumay=0;
		printf("Vertice 1:\n");
		printf("\tx: ");
		scanf(" %lf",&x);
		printf("\ty: ");
		scanf(" %lf",&y);
		x1=x;
		y1=y;
		i=2;
		while(i<=n){
			xant=x;
			yant=y;
			printf("Vertice %d:\n",i);
			printf("\tx: ");
			scanf(" %lf",&x);
			printf("\ty: ");
			scanf(" %lf",&y);
			suma+=(xant*y-x*yant);
			sumax+=((x+xant)*(xant*y-x*yant));
			sumay+=((y+yant)*(xant*y-x*yant));
			++i;
		}
		suma+=(x*y1-x1*y);
		sumax+=((x1+x)*(x*y1-x1*y));
		sumay+=((y1+y)*(x*y1-x1*y));
		a=suma/2;
		if (a){
			xcentro=sumax/(6*a);
			ycentro=sumay/(6*a);
			printf("Area del poligono: %.3f\n",a);
			printf("Centroide: (%.3f,%.3f)",xcentro,ycentro);
		}else{
			printf("Poligono no valido");
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
