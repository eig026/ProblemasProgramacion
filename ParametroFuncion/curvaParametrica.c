#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define N 1000

/* Prototipos de funciones */
double longCurva(void (*c)(double t, double *x, double *y,
                 double *z),double t1,double t2);
void circunferenciaUnitaria(double t,double *x,double *y,double *z);

/* Definiciones de funciones */
int main(){
	double t1,t2;
	char cc;

    do{ system("cls");
        printf("LONGITUDES DE CURVAS PARAMETRICAS\n");
        printf("=================================\n\n");
        printf("Parametro 1 (grados): ");
        scanf(" %lf", &t1);
        printf("Parametro 2 (grados): ");
        scanf(" %lf", &t2);
        t1*=M_PI/180;
        t2*=M_PI/180;
        printf("\nLongitud tramo: %.2f",longCurva(circunferenciaUnitaria,t1,t2));
        printf("\nDirectamente: %.2f",t2-t1);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        scanf(" %c",&cc);   
	}while ((cc!='N') && (cc!='n'));
   return 0;
}

double longCurva(void (*c)(double t, double *x, double *y,
                 double *z),double t1,double t2){
	int i;
	double t,inct;
	double lon;
	double x,y,z,x0,y0,z0;

	if(t1==t2){
		lon=0;
	}else{
		if(t1>t2){
			x=t1;
			t1=t2;
			t2=x;
		}
		inct=(t2-t1)/N;
		lon=0;
		t=t1;
		c(t,&x0,&y0,&z0);
		for(i=1;i<=N;++i){
			t+=inct;
			c(t,&x,&y,&z);
			lon+=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0)+(z-z0)*(z-z0));
			x0=x;
			y0=y;
			z0=z;
		}
	}
	return lon;
}

void circunferenciaUnitaria(double t,double *x,double *y,double *z){
	*x=cos(t);
	*y=sin(t);
	*z=0;
}

