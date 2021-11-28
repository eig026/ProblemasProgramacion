/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */
/* Programa que lee por teclado un numero de datos      */
/* de temperatura (dado a priori) e imprime en pantalla */
/* las temperaturas inferiores a la media               */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAX 25

/* Nuevos tipos de datos */
typedef float tipo_vector[MAX];

/* Prototipos de funciones */
void leer_vector(tipo_vector v, int *n);
void leer_entero_rango(int a,int b,int *m);
float calcular_media(tipo_vector v, int n);
void escribir_inferior_media(float media, tipo_vector v, int n);

/* Definiciones de funciones */
int main(){
    char c;
    float media;
    tipo_vector v;
    int n;

    do{ system("cls");
        printf("TEMPERATURAS POR DEBAJO DE LA MEDIA\n");
        printf("===================================\n\n");
        leer_vector(v,&n);
        media=calcular_media(v,n);
        escribir_inferior_media(media,v,n);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while(c!='N');
    return 0;
}

void leer_vector(tipo_vector v,int *n){
	int i;
	printf("Introduzca num. de datos:\n");
	leer_entero_rango(1,MAX,n);
	printf("Introduzca temperaturas: \n");
	for(i=0;i<*n;++i){
		printf("\ttemperatura[%d]: ",i+1);
		scanf(" %f",&v[i]);
	}
}

void leer_entero_rango(int a,int b,int *m){
	int aux;
	if(a>b){
		aux=a;
		a=b;
		b=aux;
	}
	do{	printf("\tIntroduzca entero [%d,%d]: ",a,b);
			scanf(" %d",m);
	}while((*m<a)||(*m>b));
}

float calcular_media(tipo_vector v,int n){
	int i;
	float suma;
	suma=0;
	for(i=0;i<n;++i)
		suma+=v[i];
	return(suma/n);
}

void escribir_inferior_media(float media, tipo_vector v, int n){
	int i;
	int cont;
	printf("\nListado de temperaturas inferiores a la media (%.2f)\n",
         media);
	cont=0;
	for(i=0;i<n;++i)
		if(v[i]<media){
			printf("\tv[%d] = %10.2f\n",i+1,v[i]);
			cont++;
		}
	if(cont==0)
		printf("No hay ninguna");
}
