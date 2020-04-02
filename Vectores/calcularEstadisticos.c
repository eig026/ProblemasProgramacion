#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 10

/* Nuevos tipos de datos */
typedef double tipo_vector[N];
/* prototipos de funciones */
void inicializar_vector(tipo_vector v,int n);
void copiar_vector(tipo_vector v, tipo_vector v2, int n);
void ordenar_vector(tipo_vector v, int n);
double calcular_media(tipo_vector v, int n);
double calcular_mediana(tipo_vector v, int n);
void escribir_vector(tipo_vector v, int n);

int main(){
	char c;
	tipo_vector v,v2;
	int n;

	randomize();
	do{ 	clrscr();
			printf("CALCULO DE MEDIA ARITMETICA Y MEDIANA\n");
			printf("=====================================\n\n");
			do{	printf("\tIntroduzca nº de datos a introducir: ");
					scanf(" %d", &n);
			}while((n<=0)||(n>N));
			inicializar_vector(v,n);
			printf("\nVector original:      ");
			escribir_vector(v,n);
			copiar_vector(v,v2,n);
			ordenar_vector(v2,n);
			printf("\nVector ordenado:      ");
			escribir_vector(v2,n);
			printf("\n\tMedia aritmetica: %.2f",calcular_media(v,n));
			printf("\n\tMediana: %.2f",calcular_mediana(v2,n));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void inicializar_vector(tipo_vector v,int n){
	int i;

	for(i=0;i<n;++i){
		//v[i]=1.0*rand()/RAND_MAX*100.0;
		printf("\tv[%d]: ",i+1);
      scanf(" %lf",&v[i]);
	}
}

void copiar_vector(tipo_vector v, tipo_vector v2,int n){
	int i;
	for(i=0;i<n;++i)
		v2[i]=v[i];
}

void ordenar_vector(tipo_vector v,int n){
	int i,j,k;
	double x;

	for(i=0;i<n-1;++i){
		k=i;
		for(j=i+1;j<n;++j)
			if(v[j]<v[k])
				k=j;
		x=v[i];
		v[i]=v[k];
		v[k]=x;
	}
}

void escribir_vector(tipo_vector v,int n){
	int i;
	for(i=0;i<n;++i){
		printf("%.2f  ",v[i]);
	}
}

double calcular_media(tipo_vector v, int n){
	int i;
	double suma;

	suma=0;
	for(i=0;i<n;++i)
		suma+=v[i];
	return(suma/n);
}

double calcular_mediana(tipo_vector v, int n){
	if(n%2)
		return v[n/2];
	else return(v[n/2]+v[n/2-1])/2.0;
}
