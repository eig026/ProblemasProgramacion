#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define NF 3
#define NC 3

/* Nuevos tipos de datos */
typedef double tipo_imagen[NF][NC];

/* prototipos de funciones */
void leer_imagen(tipo_imagen imagen);
double polucion_media(tipo_imagen imagen);
void escribir_pixeles(tipo_imagen imagen, double media);

FILE *f;

int main(){
	char c;
	tipo_imagen imagen;
	double media;
	time_t t;

	f=fopen("zz.dat","w");
	srand((unsigned) time(&t));
	do{ 	system("cls");
			printf("PROCESAMIENTO DE IMAGEN: POLUCION\n");
			printf("=================================\n\n");
			leer_imagen(imagen);
			media=polucion_media(imagen);
			escribir_pixeles(imagen,media);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	fclose(f);
	return 0;
}

void leer_imagen(tipo_imagen imagen){
	int i,j;

	for(i=0;i<NF;++i)
		for(j=0;j<NC;++j)
			imagen[i][j]= 1.0*rand()/RAND_MAX;
}

double polucion_media(tipo_imagen imagen){
	int i,j;
	double suma;

	suma=0;
	for(i=0;i<NF;++i)
		for(j=0;j<NC;++j)
			suma+=imagen[i][j];
	return(suma/NF/NC);
}

void escribir_pixeles(tipo_imagen imagen, double media){
	int i,j;

	printf("   ");
	fprintf(f,"   ");
	for(i=0;i<NC;++i){
		printf(" %5d",i+1);
		fprintf(f," %5d",i+1);
	}
	printf("\n");
   fprintf(f,"\n");
	for(i=0;i<NF;++i){
		printf("%3d",i+1);
		fprintf(f,"%3d",i+1);
		for(j=0;j<NC;++j){
			printf(" %5.3lf",imagen[i][j]);
			fprintf(f," %5.3lf",imagen[i][j]);
		}
		printf("\n");
		fprintf(f,"\n");
	}
	printf("\nPolucion media: %.3lf",media);
	printf("\nPixles con polucion superior al 25%% de la media (%.3lf):\n",1.25*media);
	fprintf(f,"\nPolucion media: %.3lf",media);
	fprintf(f,"\nPixles con polucion superior al 25%% de la media (%.3lf):\n",1.25*media);
	for(i=0;i<NF;++i)
		for(j=0;j<NC;++j)
			if(imagen[i][j]>1.25*media){
				printf(" (%d,%d)",i+1,j+1);
				fprintf(f," (%d,%d)",i+1,j+1);
			}
}
