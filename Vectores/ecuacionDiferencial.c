#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define N 10

/* Nuevos tipos de datos */
typedef double tipo_vector[N];

/* Prototipos de funciones */
void metodo_euler(double a,double b,double y0,int n,tipo_vector y);
void metodo_runge_kutta(double a,double b,double y0,int n,tipo_vector y);
void escribir_resultados(double a, double b,tipo_vector eul,tipo_vector rk,int n);
double f(double x, double y);

int main(){
	char c;
	tipo_vector eul,rk;
	double a,b,y0;
	int n;

	do{ 	clrscr();
			printf("ECUACIONES DIFERENCIALES ORDINARIAS\n");
			printf("===================================\n\n");
			printf("Introduzca intervalo[a,b]:\n");
			printf("\ta: ");
			scanf(" %lf", &a);
			do{	printf("\tb: ");
					scanf(" %lf",&b);
			}while(b<=a);
			printf("Introduzca condicion inicial y(%.2lf): ",a);
			scanf(" %lf", &y0);
			do{	printf("Introduzca nº de intervalos (1-%d): ",N);
					scanf(" %d", &n);
			}while ((n<=0)&&(n>N));
			metodo_euler(a,b,y0,n,eul);
			metodo_runge_kutta(a,b,y0,n,rk);
			escribir_resultados(a,b,eul,rk,n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void metodo_euler(double a,double b,double y0,int n,tipo_vector y){
	int i;
	double h,x;

	h=(b-a)/n;
	x=a;
	y[0]=y0;
	for(i=0;i<n;++i){
		y[i+1]=y[i]+f(x,y[i])*h;
		x=x+h;
	}
}

void metodo_runge_kutta(double a,double b,double y0,int n,tipo_vector y){
	int i;
	double h,x,k1,k2,k3,k4;

	h=(b-a)/n;
	x=a;
	y[0]=y0;
	for(i=0;i<n;++i){
		k1=h*f(x,y[i]);
		k2=h*f(x+h/2,y[i]+k1/2);
		k3=h*f(x+h/2,y[i]+k2/2);
		k4=h*f(x+h,y[i]+k3);
		y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
		x=x+h;
	}
}

void escribir_resultados(double a,double b,tipo_vector eul,tipo_vector rk,int n){
	int i;
	double h;
	FILE *f;

	f=fopen("xx.dat","w");
	h=(b-a)/n;
	clrscr();
	printf("%-10s %-10s %-10s\n","x","y(Euler)","y(Runge-Kutta)");
	fprintf(f,"%-10s %-10s %-10s\n","x","y(Euler)","y(Runge-Kutta)");
	for(i=0;i<=n;++i){
		printf("%10.2lf %10.6lf %10.6lf\n",a,eul[i],rk[i]);
		fprintf(f,"%10.2lf %10.6lf %10.6lf\n",a,eul[i],rk[i]);
		a+=h;
	}
   fclose(f);
}

double f(double x, double y){
	return((1+x)*y*y/2);
}

