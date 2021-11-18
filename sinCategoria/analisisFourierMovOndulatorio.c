// Ejemplo sin catalogar

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define BASE 1E-6

void leer_datos(double *a,double *h,double *p,double *t);
double pulso_rectangular(double a, double h, double p, double t, double x);
double seno_iw(int i, double w, double x);
double coseno_iw(int i, double w, double x);
double integral(double (*f)(double a, double h, double p, double t, double x),
					 double (*g)(int i,double w,double x),
					 double ancho,double h,double p,double t,
					 int i,double w,double a,double b,double base);

int main(){
	char c;
	int i;
	double a,h,p,t,w,x;

	do{ 	//      system("cls||clear");
			printf("ANALISIS DE FOURIER MOVIMIENTO ONDULATORIO\n");
			printf("==========================================\n\n");
			leer_datos(&a,&h,&p,&t);
			w=2*M_PI/p;
			printf("Orden          a          b\n");
			printf("%6d %14.8f\n",0,(4/p)*integral(pulso_rectangular,coseno_iw,a,h,p,t,0,w,-p/2,p/2,BASE));
			for(i=1;i<=10;++i){
				printf("%6d %14.8f %14.8f\n",i,
					(2/p)*integral(pulso_rectangular,coseno_iw,a,h,p,t,i,w,-p/2,p/2,BASE),
					(2/p)*integral(pulso_rectangular,seno_iw,a,h,p,t,i,w,-p/2,p/2,BASE));
			}
			/*do{  printf("x: ");
				  scanf(" %lf",&x);
				  printf(" Pulso rectangular: %.0f\n",pulso_rectangular(a,h,p,t,x));
			}while(x);*/
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(double *a,double *h,double *p,double *t){
	printf("Parametros pulso rectangular:\n");
	do{	printf("\tAncho: ");
			scanf(" %lf", a);
	}while(*a<=0);
	do{	printf("\tAltura: ");
			scanf(" %lf", h);
	}while(*h<=0);
	do{	printf("\tPeriodo: ");
			scanf(" %lf", p);
	}while(*p<=(*a));
	do{	printf("\tDesfase centro pulso-eje Y: ");
			scanf(" %lf", t);
	}while((*t<0)||(*t>=((*p)-(*a)/2)));
}

double pulso_rectangular(double a, double h, double p, double t, double x){
	double aux,coc,resto;

	aux=x-t;
	if(aux<0)
		aux=-aux;
	coc=(int)(aux/p);
	resto=aux-p*coc;
	if((resto<=a/2)||(resto>=p-a/2))
		return(h);
	else return(0);
}

double seno_iw(int i, double w, double x){
	return(sin(i*w*x));
}

double coseno_iw(int i, double w, double x){
	return(cos(i*w*x));
}

double integral(double (*f)(double a, double h, double p, double t, double x),
					 double (*g)(int i,double w,double x),
					 double ancho,double h,double p,double t,
					 int i,double w,double a,double b,double base){
	double x,suma,area;

	suma=0;
	x=a;
	while(x+base<b){
		area=base*(f(ancho,h,p,t,x)*g(i,w,x)+f(ancho,h,p,t,x+base)*g(i,w,x+base))/2;
		suma+=area;
		x+=base;
	}
	area=(b-x)*(f(ancho,h,p,t,x)*g(i,w,x)+f(ancho,h,p,t,b)*g(i,w,b))/2;
	suma+=area;
	return suma;
}


