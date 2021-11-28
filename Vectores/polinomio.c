/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 10

/* Nuevos tipos de datos */
typedef double tipo_polinomio[MAX+1];

/* prototipos de funciones */
void leer_polinomio(tipo_polinomio p, int *n);
void derivar_polinomio(tipo_polinomio p,int n,tipo_polinomio pd, int *nd);
void escribir_polinomio(tipo_polinomio p,int n);

/* Definiciones de funciones */
int main(){
	char c;
	int n,nd;
	tipo_polinomio p,pd;

	do{ 	system("cls");
			printf("DERIVACION DE POLINOMIOS\n");
			printf("========================\n\n");
			leer_polinomio(p,&n);
			derivar_polinomio(p,n,pd,&nd);
			printf("\nPolinomio original: ");
			escribir_polinomio(p,n);
			printf("\nPolinomio derivado: ");
			escribir_polinomio(pd,nd);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_polinomio(tipo_polinomio p,int *n){
	int i;

	printf("Introduzca polinomio:\n");
	do{	printf("\tGrado (0-%d): ",MAX);
		scanf(" %d",n);
	}while((*n<0)||(*n>MAX));
	i=0;
	while(i<=*n){
		printf("Termino de grado %d: ",i);
		scanf(" %lf",&p[i]);
		i++;
	}
	if((*n)&&(!p[*n])){
		do{
			printf("Termino de grado %d: ",*n);
			scanf(" %lf",&p[*n]);
		}while(p[*n]==0);
	}
}

void derivar_polinomio(tipo_polinomio p,int n,tipo_polinomio pd,int *nd){
	int i;

	for(i=1;i<=n;++i){
		pd[i-1]=p[i]*i;
	}
	if(n){
		*nd=n-1;
	}else{
		*nd=0;
		pd[0]=0;
	}
}

void escribir_polinomio(tipo_polinomio p,int n){
	int i;

	for(i=n;i>0;--i){
		if(p[i]){
			if(p[i]>0)
				printf(" + ");
			else printf(" - ");
			printf("%.2lf * x**%d ",fabs(p[i]),i);
		}
	}
	if(p[0]){
		if(p[0]>0)
			printf(" + ");
		else printf(" - ");
			printf("%.2lf",fabs(p[i]));
	}else{
		if(n==0){
			printf("0");
		}
	}
}
