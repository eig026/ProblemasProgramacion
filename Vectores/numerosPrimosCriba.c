#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define N 1000

/* Dise�o preliminar */
/* Nuevos tipos de datos */
typedef int tipo_vector[N];

/* prototipos de funciones */
void inicializar_vector(tipo_vector v, int n);
void criba_erastotenes(tipo_vector v, int n);
void escribir_primos(tipo_vector v, int n);

/* Dise�o Detallado */
/* Definiciones de funciones */
int main(){
	char c;
	int n;
	tipo_vector v;

	do{ 	system("cls");
			printf("CRIBA DE ERASTOTENES\n");
			printf("====================\n\n");
			do{	printf("Introduzca n� entero (1-%d): ",N);
					scanf(" %d", &n);
			}while(n<=0);
			inicializar_vector(v,n);
			criba_erastotenes(v,n);
			escribir_primos(v,n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void inicializar_vector(tipo_vector v, int n){
	int i;
	for(i=0;i<n;++i)
		v[i]=i+1;
}

void criba_erastotenes(tipo_vector v, int n){
	int i,j;
	i=1;
	while(i<floor(sqrt(n))+1){
		if(v[i])
			for(j=i+v[i];j<n;j+=v[i])
				v[j]=0;
		++i;
	}
}

void escribir_primos(tipo_vector v, int n){
	int i,cont;

	cont=0;
	printf("\nNumeros primos entre 1 y %d: \n",n);
	for(i=0;i<n;++i)
		if(v[i]){	printf("%10d", v[i]);
                  cont++;
		}
}
