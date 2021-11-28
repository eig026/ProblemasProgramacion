/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Nuevos tipos de datos */
typedef long tipo_vector[3];
/* prototipos de funciones */
void inicializar_vector(tipo_vector v);
void simular_lanzamiento(tipo_vector v,long n);
void escribir_resultados(tipo_vector v,long n);


int main(){
	char c;
	long n;
	tipo_vector v;

	randomize();
	do{ 	      system("cls||clear");
			printf("LANZAMIENTO DE DOS MONEDAS\n");
			printf("==========================\n\n");
			do{ printf("Introduzca n� de lanzamientos de las dos monedas: ");
				 scanf(" %ld", &n);
			}while(n<=0);
			inicializar_vector(v);
			simular_lanzamiento(v,n);
			escribir_resultados(v,n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void inicializar_vector(tipo_vector v){
	int i;
	for(i=0;i<3;++i)
		v[i]=0;
}

void simular_lanzamiento(tipo_vector v,long n){
	long i;
	int j;
	for(i=0;i<n;++i){
		j=rand()%2;
		j+=rand()%2;
		//printf("%5d",j+1);
		v[j]++;
	}
}

void escribir_resultados(tipo_vector v,long n){
	int i;

	printf("\n\nPorcentaje de veces que ha salido:\n");
	for (i=0;i<3;++i){
		printf("%d caras: %.2lf\n",i,100.0*v[i]/n);
	}
}
