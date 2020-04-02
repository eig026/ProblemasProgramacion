#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Nuevos tipos de datos */
/* prototipos de funciones */
double curvatura(double (*f)(double x0), double x,double h);
double derivada(double (*f)(double x0), double x,double h);
double derivada2(double (*f)(double x0), double x,double h);
double f1(double x);
double f2(double x);
void escribir_tabla(double (*f)(double x),double xizq, double xder, double paso, double h);

int main(){
	char c;

	do{ 	clrscr();
			printf("CURVATURAS EN INTERVALO\n");
			printf("=======================\n\n");
			escribir_tabla(f1,0,10,1,1e-6);
			getch();
			escribir_tabla(f2,-10,10,2,1e-6);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

double curvatura(double (*f)(double x0), double x, double h){
	double d1;

	d1=derivada(f,x,h);
	d1=1+d1*d1;
	d1=d1*sqrt(d1);
	return(derivada2(f,x,h)/d1);
}

double derivada(double (*f)(double x0), double x, double h){
	return ((f(x-2*h)-8*f(x-h)+8*f(x+h)-f(x+2*h))/(12*h));
}

double derivada2(double (*f)(double x0), double x, double h){
	return ((-f(x-2*h)+16*f(x-h)-30*f(x)+16*f(x+h)-f(x+2*h))/(12*h*h));
	//return((f(x+h)-2*f(x)+f(x-h))/(h*h));
}

double derivada22(double (*f)(double x0), double x, double h){
	//return ((-f(x-2*h)+16*f(x-h)-30*f(x)+16*f(x+h)-f(x+2*h))/(12*h*h));
	return((f(x+h)-2*f(x)+f(x-h))/(h*h));
}

double f1(double x){
	return(cos(x)*exp(-x));
	//return(sqrt(1.0-x*x));
}

double f2(double x){
	return(x*x*x*x*x-4*x*x*x*x+3*x*x-8);
}

void escribir_tabla(double (*f)(double x),double xizq, double xder, double paso, double h){
	double x1;
	FILE *archivo;

	archivo=fopen("zz.dat","a");
	clrscr();
	printf("CURVATURAS:\n");
	printf("==========\n\n");
	printf("%15s %15s %15s %15s\n","x","curvatura","derivada1","derivada2");
	x1=xizq;
	while(x1<=xder){
		printf("%15.6f %15.6f %15.6f %15.6f\n",x1,curvatura(f,x1,h),derivada(f,x1,h),derivada2(f,x1,h));
		fprintf(archivo,"%15.6f %15.6f\n",x1,curvatura(f,x1,h));
		//printf("%15.6f %15.6f %15.6f %15.6f\n",x1,derivada(f,x1,1e-3),derivada(f,x1,1e-6),derivada(f,x1,1e-9));
		//printf("%15.6f %15.6f %15.6f %15.6f\n",x1,derivada2(f,x1,1e-3),derivada22(f,x1,1e-3),derivada2(f,x1,1e-6));
		x1+=paso;
	}
   fclose(archivo);
	getch();
}

