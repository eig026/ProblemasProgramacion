#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

double derivada(double (*f)(double x), double x0, double h);
double f1(double x);
double f2(double x);
double f3(double x);

int main(){
	char c;
	int i;
	double x0,h;
	FILE *ff;

	ff=fopen("xx.dat","w");
	do{ 	clrscr();
			printf("DERIVACION NUMERICA\n");
			printf("===================\n\n");
			printf("Prueba derivacion numerica de funcion: x**3-3*x**2+5\n");
			printf("Introduzca valor x0: ");
			scanf(" %lf",&x0);
			h=0.1;
			for (i=1;i<7;++i){
				printf("\ni=%2d h=%.6lf  derivada=%.6lf",i,h,derivada(f1,x0,h));
				fprintf(ff,"%.6lf\n",derivada(f1,x0,h));
				h=h/10;
			}
			printf("\n\nPrueba derivacion numerica de funcion: exp(-x**2)\n");
			printf("Introduzca valor x0: ");
			scanf(" %lf",&x0);
			h=0.1;
			for (i=1;i<7;++i){
				printf("\ni=%2d h=%.6lf  derivada=%.6lf",i,h,derivada(f2,x0,h));
				fprintf(ff,"%.6lf\n",derivada(f2,x0,h));
				h=h/10;
			}
			printf("\n\nPrueba derivacion numerica de funcion: seno(x)*exp(-x)\n");
			printf("Introduzca valor x0: ");
			scanf(" %lf",&x0);
			h=0.1;
			for (i=1;i<7;++i){
				printf("\ni=%2d h=%.6lf  derivada=%.6lf",i,h,derivada(f3,x0,h));
				fprintf(ff,"%.6lf\n",derivada(f3,x0,h));
				h=h/10;
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	fclose(ff);
	return 0;
}

double derivada(double (*f)(double x), double x0, double h){
	//return((f(x0+h)-f(x0))/h);
	//return((f(x0+h)-f(x0-h))/(2*h));
	return((8*(f(x0+h)-f(x0-h))-(f(x0+2*h)-f(x0-2*h)))/(12*h));
}

double f1(double x){
	return (x*x*x-3*x*x+5);
}

double f2(double x){
	return (exp(-x*x));
}

double f3(double x){
	return(sin(x)*exp(-x));
}