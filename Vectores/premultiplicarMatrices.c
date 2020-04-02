#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define N 3

/* Nuevos tipos de datos */
typedef float tipo_matriz[N][N];

/* prototipos de funciones */
void leer_matriz(tipo_matriz v);
void pre_multiplicar_matrices(tipo_matriz a, tipo_matriz b);
void copiar_matriz(tipo_matriz a, tipo_matriz b);
void escribir_operacion(tipo_matriz a, tipo_matriz b, tipo_matriz c);

int main(){
	char cc;
	tipo_matriz a,b,c;

	do{ 	clrscr();
			printf("PRE-MULTIPLICACION DE MATRICES\n");
			printf("==============================\n\n");
			printf("Introduzca primera matriz: \n");
			leer_matriz(a);
			copiar_matriz(a,c);
			printf("Introduzca segunda matriz: \n");
			leer_matriz(b);
			pre_multiplicar_matrices(a,b);
			printf("\nProducto de matrices:\n");
			escribir_operacion(c,b,a);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			cc=toupper(getch());
	}while (cc!='N');
	return 0;
}

void leer_matriz(tipo_matriz v){
	int i,j;
	for(i=0;i<N;++i)
		for(j=0;j<N;++j){
			printf("\t\tv[%d,%d]: ",i+1,j+1);
			scanf(" %f", &v[i][j]);
		}
}

void copiar_matriz(tipo_matriz a, tipo_matriz b){
	int i,j;
	for(i=0;i<N;++i)
		for(j=0;j<N;++j){
			b[i][j]=a[i][j];
		}
}

void pre_multiplicar_matrices(tipo_matriz a, tipo_matriz b){
	tipo_matriz c;
	int i,j,k;

	for(i=0;i<N;++i)
		for(j=0;j<N;++j){
			c[i][j]=0;
			for(k=0;k<N;++k)
				c[i][j]+=a[i][k]*b[k][j];
		}
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			a[i][j]=c[i][j];
}

void escribir_operacion(tipo_matriz a, tipo_matriz b, tipo_matriz c){
	int i,j;

	i=0;
	while(i<N){
		for(j=0;j<N;++j)
			printf("%6.2f", a[i][j]);
		if(i==N/2)
			printf("   * ");
		else printf("     ");
		for(j=0;j<N;++j)
			printf("%6.2f", b[i][j]);
		if(i==N/2)
			printf("   = ");
		else printf("     ");
		for(j=0;j<N;++j)
			printf("%6.2f", c[i][j]);
		printf("\n");
      ++i;
	}
}
