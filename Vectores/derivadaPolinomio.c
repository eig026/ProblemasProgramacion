#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 10

/* Nuevos tipos de datos */
typedef double tipo_polinomio[N];
/* prototipos de funciones */
void leer_polinomio(tipo_polinomio p, int *n);
void derivar_polinomio(tipo_polinomio p,int *n,tipo_polinomio dp);
void escribir_polinomio(tipo_polinomio p,int n);

int main(){
	char c;
	int n;
   tipo_polinomio p,dp;

	do{ 	      system("cls||clear");
			printf("DERIVACION DE POLINOMIOS\n");
			printf("========================\n\n");
			leer_polinomio(p,&n);
			derivar_polinomio(p,&n,dp);
			printf("\nPolinomio original: ");
			escribir_polinomio(p,n+1);
			printf("\nPolinomio derivado: ");
			escribir_polinomio(dp,n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_polinomio(tipo_polinomio p,int *n){
	int i;
	char c;

	printf("Introduzca polinomio:");
	i=0;
	c='S';
	while((i<N)&&(c!='N')){
		printf("\nTermino de grado %d: ",i);
		scanf(" %lf",&p[i]);
		printf("Mas terminos (S/N): ");
		c=toupper(getche());
		i++;
	}
	*n=i-1;
}

void derivar_polinomio(tipo_polinomio p,int *n,tipo_polinomio dp){
	int i;

	for(i=1;i<=*n;++i)
		dp[i-1]=p[i]*i;
	dp[*n]=0;
	*n=(*n)-1;
}

void escribir_polinomio(tipo_polinomio p,int n){
	int i;
	char c;

	for(i=n;i>=0;--i)
		if(p[i]){
			if(p[i]>0)
				c='+';
			else c='-';
			printf("%c %.2lf x%d ",c,fabs(p[i]),i);
		}
}
