/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06


 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void metodo_newton(double (*f)(double x),double x0,double h,int n);
double derivada(double (*f)(double x), double x0, double h);
double f(double x);

FILE *g;

int main(){
	char c;
	double x0,h;
	int n;

	g=fopen("zz.dat","w");
	do{ 	      system("cls||clear");
			printf("METODO DE NEWTON PARA SOLUCION f(x)=0\n");
			printf("=====================================\n\n");
			printf("Introduzca valor inicial (x0): ");
			scanf(" %lf", &x0);
			do{ printf("Introduzca precision: ");
					scanf(" %lf",&h);
			}while(h<=0);
			do{	printf("Introduzca num maximo de iteraciones: ");
					scanf(" %d",&n);
			}while(n<=0);
			metodo_newton(f,x0,h,n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	fclose(g);
	return 0;
}

void metodo_newton(double (*f)(double x),double x0,double h,int n){
	double x,xsig;
	double d;
	int i;
	int sal;

	fprintf(g,"x0=%.4f   E=%f   n=%3d\n",x0,h,n);
	sal=0;
	i=1;
	x=x0;
	printf("\nSoluciones aproximadas; \n");
	printf("\%d: %10.10lf\n",i-1,x0);
	d=derivada(f,x,h);
	if (d)
		xsig=x-f(x)/d;
	else sal=1;
	while((!sal)&&(fabs(x-xsig)>=h)&&(i<=n)){
		printf("\%d: %.10lf\n",i,xsig);
		x=xsig;
		d=derivada(f,x,h);
		if (d){
			xsig=x-f(x)/d;
			++i;
		}else sal=1;
	}
	if(sal){
		printf("Encontrada derivada nula en iteracion num: %d\n",i);
		printf("Ultima aproximacion encontrada: %.6lf\n",x);
		fprintf(g,"Encontrada derivada nula en iteracion num: %d\n",i);
		fprintf(g,"Ultima aproximacion encontrada: %.6lf\n",x);
	}else if (i>n){
				printf("Excedido num maximo de iteraciones: %d\n",n);
				printf("Ultima aproximacion encontrada: %.6lf\n",x);
				fprintf(g,"Excedido num maximo de iteraciones: %d\n",n);
				fprintf(g,"Ultima aproximacion encontrada: %.6lf\n",x);
			}else{	printf("Solucion aproximada: %.6lf",xsig);
						fprintf(g,"Solucion aproximada: %.6lf",xsig);
			}

}

double derivada(double (*f)(double x), double x0, double h){
	return((8*(f(x0+h)-f(x0-h))-(f(x0+2*h)-f(x0-2*h)))/(12*h));
}

double f(double x){
	return (x*x*x-3*x*x+5);
	//return (exp(-x*x));
	//return(sin(x)*exp(-x));
}