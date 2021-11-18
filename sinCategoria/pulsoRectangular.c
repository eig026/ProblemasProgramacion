#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


void leer_datos(double *p,double *h,double *a,double *e,double *t);
double pulso_rectangular(double p,double h,double a,double e,double t, double x);
double integral_simpson(double (*f)(double p,double h,double a,double e,double t, double x),
					 double p,double h,double a,double e,double t,
					 double izq,double der,int n);

int main(){
	char c;
	int n;
	double p,h,a,e,t;
	double izq,der;
	double x;

	do{ 	      system("cls||clear");
			printf("ANALISIS PULSO RECTANGULAR\n");
			printf("==========================\n\n");
			leer_datos(&p,&h,&a,&e,&t);
			//leer_intervalo(&izq,&der);
			//do{	printf("
			do{  printf("x: ");
				  scanf(" %lf",&x);
				  printf(" Pulso rectangular: %.2f\n",pulso_rectangular(p,h,a,e,t,x));
			}while(x);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(double *p,double *h,double *a,double *e,double *t){
	printf("Parametros pulso rectangular:\n");
	do{	printf("\tPeriodo: ");
			scanf(" %lf", p);
	}while(*p<=0);
	do{	printf("\tAltura: ");
			scanf(" %lf", h);
	}while(*h<0);
	do{	printf("\tAncho: ");
			scanf(" %lf", a);
	}while((*a<0)||(*a>(*p)));
	do{	printf("\tEscalon: ");
			scanf(" %lf", e);
	}while((*e<0)||(2*(*e)>((*p)-(*a))));
	do{	printf("\tDesfase centro pulso-eje Y: ");
			scanf(" %lf", t);
	}while((*t<0)||(*t>((*p)-(*a)/2)));
}

double pulso_rectangular(double p,double h,double a,double e,double t, double x){
	double aux,coc,resto,y;

	aux=x-t;
	if(aux<0)
		aux=-aux;
	coc=(int)(aux/p);
	resto=aux-p*coc;
	if(resto<=a/2)
		y=h;
	else 	if(resto<=a/2+e)
				y=h/e*(a/2+e-resto);
			else 	if(resto<=p-a/2-e)
						y=0;
					else	if(resto<=p-a/2)
								y=h/e*(resto-p+a/2+e);
							else
								y=h;
	return(y);
}

double integral_simpson(double (*f)(double p,double h,double a,double e,double t, double x),
					 double p,double h,double a,double e,double t,
					 double izq,double der,int n){
	double inc,xi;
	long i;
	double aux,suma;

	if(n%2)
		n++;
	if(der<izq){
		aux=izq;
		izq=der;
		der=aux;
	}
	inc=(der-izq)/n;
	xi=izq;
	suma=f(p,h,a,e,t,izq)+f(p,h,a,e,t,der);
	for(i=1;i<n;++i){
		xi+=inc;
		if(i%2)
			suma+=4*f(p,h,a,e,t,xi);
		else suma+=2*f(p,h,a,e,t,xi);
	}
	return(inc*suma/3);
}

