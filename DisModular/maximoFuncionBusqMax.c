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

void leer_extremos_intervalo(double *a, double *b);
double calcular_maximo(double (*f)(double x), double a, double b, double prec);
double f(double x);

int main(){
	char c;
	double a,b,xmax,ymax;

	do{ 	      system("cls||clear");
			printf("BUSQUEDA DEL MAXINO DE UNA FUNCION EN UN INTERVALO\n");
			printf("==================================================\n\n");
			leer_extremos_intervalo(&a,&b);
			xmax=calcular_maximo(f,a,b,0.0001);
			ymax=f(xmax);
			printf("\nxmax=%10.5lf   ymax==%10.5lf",xmax,ymax);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
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
	return(x*cos(x));
}
