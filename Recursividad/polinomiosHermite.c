/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06


 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

void leer_entero_no_negativo(int *n);
double hermite(int n,double x);

int main(){
	char c;
	int i,n;
	double x;
	FILE *f;

	f=fopen("xx.dat","w");
	do{ 	      system("cls||clear");
			printf("POLINOMIOS DE HERMITE\n");
			printf("=====================\n\n");
			printf("Introduzca valor de x: ");
			scanf(" %lf", &x);
			printf("Introduzca nº de polinomios:\n");
			leer_entero_no_negativo(&n);
			for(i=0;i<=n;++i){
				printf("\nPolinomio nº %3d (%.2lf) = %.2lf",i,x,hermite(i,x));
				fprintf(f,"\nPolinomio nº %3d (%.2lf) = %.2lf",i,x,hermite(i,x));
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	fclose(f);
	return 0;
}

void leer_entero_no_negativo(int *n){
	do{	printf("\tIntroduzca entero no negativo: ");
			scanf(" %d",n);
	}while(*n<0);
}

double hermite(int n,double x){
	if(n==0)
		return(1);
	else 	if(n==1)
				return(x);
			else	return(2*x*hermite(n-1,x)-2*(n-1)*hermite(n-2,x));
}
