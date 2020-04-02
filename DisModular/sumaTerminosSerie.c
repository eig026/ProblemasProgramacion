#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void leer_entero_positivo(int *n);
double calcular_suma(int n,int p);
double potencia(double x, int n);

int main(){
	char c;
	int n,p;
	double suma;
	int i;
	FILE *f;

	f=fopen("xx.dat","w");
	do{ 	clrscr();
			printf("SUMA DE n TERMINOS SERIES: i**e\n");
			printf("===============================\n\n");
			printf("Numero de terminos:\n");
			leer_entero_positivo(&n);
			printf("\nExponente de la potencia a sumar:\n");
			leer_entero_positivo(&p);
			//for(i=1;i<=n;++i){
				//suma=calcular_suma(i,p);
				//printf("\nSuma(%d) de i**%d = %.0lf",i,p,suma);
				//fprintf(f,"%.0lf\n",calcular_suma(n,p));
				printf("%.0lf\n",calcular_suma(n,p));
			//}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
   fclose(f);
	return 0;
}

void leer_entero_positivo(int *n){
	do{	printf("\tIntroduzca entero positivo: ");
			scanf(" %d",n);
	}while(*n<=0);
}

double calcular_suma(int n,int p){
	if (n==1)
		return 1;
	else return(calcular_suma(n-1,p)+potencia(n,p));
}

double potencia(double x, int n){
	if(n==1)
		return x;
	else return(x*potencia(x,n-1));
}
