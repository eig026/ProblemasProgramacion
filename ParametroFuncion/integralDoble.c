#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* prototipos de funciones */
double f(double x,double y);
double integral_doble(double (*f)(double x,double y),double xmin,double xmax,
							 double ymin,double ymax,int m,int n);

int main(){
	char c;
	double xmin,xmax,ymin,ymax;
	int m,n;

	do{ 	clrscr();
			printf("INTEGRAL DOBLE\n");
			printf("==============\n\n");
			printf("Introduzca limites del rectangulo:\n");
			printf("\txmin: ");
			scanf(" %lf",&xmin);
			do{	printf("\txmax: ");
					scanf(" %lf",&xmax);
			}while(xmax<=xmin);
			printf("\tymin: ");
			scanf(" %lf",&ymin);
			do{	printf("\tymax: ");
					scanf(" %lf",&ymax);
			}while(ymax<=ymin);
			do{	printf("Nº de filas: ");
					scanf(" %d", &m);
			}while(m<=0);
			do{	printf("Nº de columnas: ");
					scanf(" %d", &n);
			}while(n<=0);
			printf("\nVolumen encerrado: %.15f",integral_doble(f,xmin,xmax,ymin,ymax,m,n));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

double integral_doble(double (*f)(double x,double y),double xmin,double xmax,
							 double ymin,double ymax,int m,int n){
	double vol;
	int i, j;
	double hx,hy;

	hx=(xmax-xmin)/m;
	hy=(ymax-ymin)/n;
	vol=0;
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			//vol+=f(xmin+(i+0.5)*hx,ymin+(j+0.5)*hy)*hx*hy;
         vol+=f(xmin+(i+0.5)*hx,ymin+(j+0.5)*hy);
			//vol+=f(xmin+i*hx,ymin+j*hy)*hx*hy;
	//return vol;
	return vol*hx*hy;
}

double f(double x,double y){
	return(log(x+2*y));
	//return 1;
	//return (x+y);
	//return (x*x+y*y);
}

