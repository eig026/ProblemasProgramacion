/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

double pulso_rectangular(double x,double p,double h,double a,double e,double t);

int main(){
	char c;
	double p,h,a,e,t;
	double x;

	do{	system("cls");
		printf("ANALISIS PULSO RECTANGULAR\n");
		printf("==========================\n\n");
		printf("Parametros pulso rectangular:\n");
		do{	printf("\tPeriodo: ");
			scanf(" %lf", &p);
		}while(p<=0);
		printf("\tAltura: ");
		scanf(" %lf", &h);
		do{	printf("\tAncho: ");
			scanf(" %lf", &a);
		}while((a<0)||(a>p));
		do{	printf("\tEscalon: ");
			scanf(" %lf", &e);
		}while((e<0)||(2*e>p-a));
		printf("\tDesfase centro pulso-eje Y: ");
		scanf(" %lf", &t);
		do{
			printf("\n\nx: ");
			scanf(" %lf",&x);
			printf(" Pulso rectangular: %.2f\n",pulso_rectangular(x,p,h,a,e,t));
			printf("\nOtro valor de x (S/N)?");
			c=toupper(getch());
		}while(c!='N');
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

double pulso_rectangular(double x,double p,double h,double a,double e,double t){
	double y;

	x=x-t;
	if(x<0)
		x=-x;
	x=x-p*floor(x/p);
	if(x<=a/2)
		y=h;
	else
		if(x<=a/2+e)
			y=h/e*(a/2+e-x);
		else
			if(x<=p-a/2-e)
				y=0;
			else
				if(x<=p-a/2)
					y=h/e*(x-p+a/2+e);
				else
					y=h;
	return(y);
}
