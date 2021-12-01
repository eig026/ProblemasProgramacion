/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06


 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 3

/* Nuevos tipos de datos */
typedef struct{
	char tipo;
	union{
		struct{
			double tx,ty;
		};
		double zeta;
		struct{
			double sx;
			double sy;
		};
	};
}tipo_transformacion;
typedef double tipo_matriz[N][N];

/* prototipos de funciones */
void leer_transformacion(tipo_transformacion *t);
void leer_traslacion(double *tx,double *ty);
void leer_rotacion(double *zeta);
void leer_escalado(double *sx,double *sy);
void construir_matriz_transformacion(tipo_transformacion t,tipo_matriz m);
void construir_traslacion(double tx,double ty,tipo_matriz m);
void construir_rotacion(double zeta,tipo_matriz m);
void construir_escalado(double sx,double sy,tipo_matriz m);
void escribir_matriz(tipo_matriz m);
void inicializar_matriz_identidad(tipo_matriz m);

int main(){
	char c;
	tipo_matriz m;
	tipo_transformacion t;

	do{ 	system("cls");
			printf("TRANSFORMACIONES GEOMETRICAS 2D BASICAS\n");
			printf("=======================================\n\n");
			leer_transformacion(&t);
			construir_matriz_transformacion(t,m);
			escribir_matriz(m);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_transformacion(tipo_transformacion *t){
	system("cls");
	do{	printf("Tipos de transformaciones geometricas basicas:\n");
			printf("\tT: Traslacion:\n");
			printf("\tR: Rotacion\n");
			printf("\tE: Escalado\n");
			printf("\t\tIntroduzca tipo de transformacion: ");
			t->tipo=toupper(getch());
	}while((t->tipo!='T')&&(t->tipo!='R')&&(t->tipo!='E'));
	switch(t->tipo){
	case 'T': 	leer_traslacion(&(t->tx),&(t->ty));
					break;
	case 'R': 	leer_rotacion(&(t->zeta));
					break;
	case 'E': 	leer_escalado(&(t->sx),&(t->sy));
					break;
	}
}

void leer_traslacion(double *tx,double *ty){
	printf("\n\tDistancia de traslacion horizontal (tx): ");
	scanf(" %lf",tx);
	printf("\n\tDistancia de traslacion vertical (ty): ");
	scanf(" %lf",ty);
}

void leer_rotacion(double *zeta){
	do{	printf("\n\tAngulo de rotacion (0-360 grados): ");
			scanf(" %lf",zeta);
	}while((*zeta<0)||(*zeta>360));
}

void leer_escalado(double *sx,double *sy){
	printf("\n\tFactor de escalado horizontal (sx): ");
	scanf(" %lf",sx);
	printf("\n\tDFactor de escalado vertical (sy): ");
	scanf(" %lf",sy);
}

void construir_matriz_transformacion(tipo_transformacion t,tipo_matriz m){
	switch(t.tipo){
	case 'T': 	construir_traslacion(t.tx,t.ty,m);
					break;
	case 'R': 	construir_rotacion(t.zeta,m);
					break;
	case 'E': 	construir_escalado(t.sx,t.sy,m);
					break;
	}
}

void construir_traslacion(double tx,double ty,tipo_matriz m){
	inicializar_matriz_identidad(m);
	m[0][2]=tx;
	m[1][2]=ty;
}

void construir_rotacion(double zeta,tipo_matriz m){
	inicializar_matriz_identidad(m);
	zeta=zeta*M_PI/180.0;
	m[0][0]=m[1][1]=cos(zeta);
	m[1][0]=sin(zeta);
	m[0][1]=-m[1][0];
}

void construir_escalado(double sx,double sy,tipo_matriz m){
	inicializar_matriz_identidad(m);
	m[0][0]=sx;
	m[1][1]=sy;
}

void escribir_matriz(tipo_matriz m){
	int i,j;
	system("cls");
	printf("Matriz de la transformacion:\n\n");
	for(i=0;i<N;++i){
		for(j=0;j<N;++j)
			printf("%10.2f",m[i][j]);
		printf("\n");
	}
}

void inicializar_matriz_identidad(tipo_matriz m){
	int i,j;
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			if(i==j)
				m[i][j]=1;
			else m[i][j]=0;
}
