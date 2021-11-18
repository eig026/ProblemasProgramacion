#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Nuevos tipos de datos */
/* prototipos de funciones */
double derivada_x(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h);
double derivada_y(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h);
double derivada_z(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h);
void gradiente(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h,
									double gx,double gy,double gz);
double f1(double x, double y, double z);
double f2(double x, double y, double z);

int main(){
	char c;

	do{ 	      system("cls||clear");
			printf("GRADIENTE\n");
			printf("=========\n\n");

			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

double derivada_x(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h){
	return ((f(x0-2*h,y0,z0)-8*f(x0-h,y0,z0)+8*f(x0+h,y0,z0)-f(x0+2*h,y0,z0))/(12*h));
}

double derivada_y(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h);
double derivada_z(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h);
void gradiente(double (*f)(double x,double y,double z),double x0,double y0,double z0,double h,
									double gx,double gy,double gz);
double f1(double x, double y, double z);
double f2(double x, double y, double z);

