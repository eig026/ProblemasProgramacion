#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void leer_entero_positivo(int *n);
double legendre(int n,double x);

int main(){
	char c;
	int i,n;
	double x;
	FILE *f;

	f=fopen("xx.dat","w");
	do{ 	clrscr();
			printf("POLINOMIOS DE LEGENDRE\n");
			printf("======================\n\n");
			printf("Introduzca valor de x: ");
			scanf(" %lf", &x);
			printf("Introduzca nº de polinomios:\n");
			leer_entero_positivo(&n);
			for(i=0;i<=n;++i){
				printf("\nPolinomio nº %3d (%.2lf) = %.2lf",i,x,legendre(i,x));
				fprintf(f,"\nPolinomio nº %3d (%.2lf) = %.2lf",i,x,legendre(i,x));
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
   fclose(f);
	return 0;
}

void leer_entero_positivo(int *n){
	do{	printf("\tIntroduzca entero positivo: ");
			scanf(" %d",n);
	}while(*n<0);
}

double legendre(int n,double x){
	if(n==0)
		return(1);
	else 	if(n==1)
				return(x);
			else	return((2*n-1.0)/n*x*legendre(n-1,x)-(n-1.0)/n*legendre(n-2,x));
}
