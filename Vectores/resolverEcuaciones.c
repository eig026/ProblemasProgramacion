/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */
/* Programa que resuelve un sistema lineal de n ecuaciones con
	m incognitas por el metodo de eliminacion de Gauss-Jordan        */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAX 10

/* Nuevos tipos de datos */
typedef float tipo_vector[MAX];
typedef float tipo_matriz[MAX][MAX+1];

/* Prototipos de funciones */
void leer_coeficientes(tipo_matriz a, int n, int m);
void leer_terminos(tipo_matriz a, int n,int m);
int resolver_sistema(tipo_matriz a,int n, int m,tipo_vector x);
void escribir_solucion(tipo_vector x, int m);
void escribir_matriz(tipo_matriz a, int n, int m);

int main(){
	char ca;
	tipo_vector x;		/* vector de incognitas						*/
	tipo_matriz a;		/* matriz de coeficientes + terminos independientes	*/
	int i;				/* 1: sistema compatible determinado	*/
							/* 0: sistema compatible indeterminado o incompatible */
	int n;				/* n� de ecuaciones							*/
	int m;				/* n� de incognitas							*/

	do{ 	      system("cls||clear");
			printf("RESOLUCION SISTEMA DE n ECUACIONES CON m INCOGNITAS\n");
			printf("===================================================\n\n");
			printf("\ta[1,1] * x[1] + a[1,2] * x[2] + ... + a[1,m] *x[m] = c[1]\n");
			printf("\ta[2,1] * x[1] + a[2,2] * x[2] + ... + a[2,m] *x[m] = c[2]\n");
			printf("\t ....\n");
			printf("\ta[n,1] * x[1] + a[n,2] * x[2] + ... + a[n,m] *x[m] = c[n]\n\n");
			do{	printf("Introduzca n� de ecuaciones: ");
					scanf(" %d", &n);
			}while((n<=0)||(n>MAX));
			do{	printf("Introduzca n� de incognitas: ");
					scanf(" %d", &m);
			}while((m<=0)||(m>MAX));
			printf("Introduzca coeficientes de variables: \n");
			leer_coeficientes(a,n,m);
			printf("\nIntroduzca terminos independientes:\n");
			leer_terminos(a,n,m);
			printf("\n\nMatriz original:\n");
			escribir_matriz(a,n,m);
			i=resolver_sistema(a,n,m,x);
         printf("\n\nMatriz diagonalizada:\n");
			escribir_matriz(a,n,m);
			if(i==1)
				escribir_solucion(x,m);
			else 	if(i==0)	printf("\nSistema incompatible");
               else		printf("\nSistema compatible indeterminado");
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			ca=toupper(getch());
	}while (ca!='N');
	return 0;
}

void leer_coeficientes(tipo_matriz a,int n, int m){
	int i,j;

	for(i=0;i<n;++i)
		for(j=0;j<m;++j){
			printf("\ta[%d,%d]: ",i+1,j+1);
			scanf(" %f",&a[i][j]);
		}
}

void leer_terminos(tipo_matriz a,int n,int m){
	int i;

	for(i=0;i<n;++i){
		printf("\tc[%d]: ",i+1);
		scanf(" %f", &a[i][m]);
	}
}

int resolver_sistema(tipo_matriz a,int n,int m,tipo_vector x){
/* Devuelve: 0 (sistema incompatible)					*/
/*           1 (sistema compatible determinado)    */
/*           2 (sistema compatible indeterminado)	*/
	int i,j,k;
	int inc;
	int enc;
	float aux;

	i=0;
	while(i<m){
		enc=1;
		/* Si el coeficiente a[i][i]=0, buscar una fila con a[j][i]!=0 e intercambiar */
		if(!a[i][i]){
			enc=0;
			j=i+1;
			while((j<n)&&(!enc)){
				if(a[j][i])
					enc=1;
				else ++j;
			}
			if (enc){
				for (k=0;k<=m;++k){
					aux=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=aux;
				}
			}
		}
		if(enc){
			for(j=0;j<n;++j){
				if(i!=j){
					/* Multiplicar fila i por a[j][i] */
					/* Multiplicar fila j por a[i][i] */
					/* Restar fila j menos fila i y almacenar en fila j */
					aux=a[j][i];
					for(k=0;k<=m;++k)
						a[j][k]=a[j][k]*a[i][i]-a[i][k]*aux;
				}
			}
		}
		++i;
	}
	/* Comprobacion sistema incompatible */
	inc=0;
	i=0;
	while((i<n)&&(!inc)){
		if(i<m)
			if(!a[i][i]&&a[i][m])
				inc=1;
			else ++i;
		else if(a[i][m])
				inc=1;
				else ++i;
	}
	if (inc)
		return 0;
	else{ /* Comprobacion sistema compatible determinado */
			i=0;
			while((i<m)&&(!inc))
				if((!a[i][m])&&(!a[i][i]))
					inc=1;
				else ++i;
			if(inc)
				return(2);
			else{	for(i=0;i<m;++i)
						x[i]=a[i][m]/a[i][i];
					return 1;
			}
	}
}

void escribir_solucion(tipo_vector x,int m){
	int i;

	printf("\nSoluciones:\n");
	for(i=0;i<m;++i)
		printf("\tx[%d] = %.2f\n",i+1,x[i]);
}

void escribir_matriz(tipo_matriz a, int n, int m){
	int i, j;

	for(i=0;i<n;++i){
		for(j=0;j<=m;++j)
			printf("%5.0f",a[i][j]);
		printf("\n");
	}
}

