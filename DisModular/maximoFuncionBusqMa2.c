/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 
 */
/* Programa de prueba del modulo que calcula el maximo 	*/
/* de una funcion	en un intervalo especificado 				*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define  A 0
#define  B 3.141593
#define  PREC 0.0001

double calcular_maximo(double (*f)(double x), double a, double b, double prec);
double f(double x);

int main(){
	double xmax;	/* Maximo de la funcion				*/
	double ymax;	/* valor de la funcion en xmax	*/

	printf("Maximo de la funcion seno de x\n");
	printf("==============================\n");
	xmax=calcular_maximo(sin,A,B,PREC);
	ymax=sin(xmax);
	printf("xmax=%10.5lf   ymax=%10.5lf\n\n",xmax,ymax);
	/*printf("Maximo de la funcion x*cos(x)\n");
	printf("=============================\n");
	xmax=calcular_maximo(f,A,B,PREC);
	ymax=f(xmax);
	printf("xmax=%10.5lf   ymax=%10.5lf",xmax,ymax);*/
	printf("Maximo de la funcion x*x en [-1,1]\n");
	printf("==================================\n");
	xmax=calcular_maximo(f,-1.,1.,PREC);
	ymax=f(xmax);
	printf("xmax=%10.5lf   ymax=%10.5lf",xmax,ymax);
	return 0;
}

void leer_extremos_intervalo(double *a, double *b){
	printf("\nIntroduzca extremo izquierdo intervalo: ");
	scanf(" %lf",a);
	do{ 	printf("Introduzca extremo derecho intervalo: ");
			scanf(" %lf",b);
	}while(*b<=*a);
}

double calcular_maximo(double (*f)(double x), double a, double b, double prec){
/* funcion que calcula el maximo de una funcion f(x)	*/
/* en un intervalo [a,b]										*/
	double xi,xd,yi,yd;

	do{ 	xi=a+0.5*(b-a-prec);
			xd=xi+prec;
			yi=f(xi);
			yd=f(xd);
			if(yi>yd)
				b=xd;
			else if(yi<yd)
						a=xi;
	}while((yi!=yd)&&((b-a)>3*prec));
   return(0.5*(xi+xd));
}

double f(double x){
	//return(x*cos(x));
   return (x*x);
}
