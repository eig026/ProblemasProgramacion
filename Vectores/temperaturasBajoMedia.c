#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define N 5

/* Nuevos tipos de datos */
typedef float tipo_vector[N];

/* prototipos de funciones */
void leer_vector(tipo_vector v);
float calcular_media(tipo_vector v);
void escribir_inferior_media(float media, tipo_vector v);

int main(){
	char c;
	float media;
   tipo_vector v;

	do{ 	      system("cls||clear");
			printf("TEMPERATURAS POR DEBAJO DE LA MEDIA\n");
			printf("===================================\n\n");
			leer_vector(v);
			media=calcular_media(v);
			escribir_inferior_media(media,v);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_vector(tipo_vector v){
	int i;
	printf("Introduzca temperaturas: \n");
	for(i=0;i<N;++i){
		printf("\ttemperatura[%d]: ",i+1);
		scanf(" %f",&v[i]);
	}
}

float calcular_media(tipo_vector v){
	int i;
	float suma;
	suma=0;
	for(i=0;i<N;++i)
		suma+=v[i];
	return(suma/N);
}

void escribir_inferior_media(float media, tipo_vector v){
	int i;
	printf("\nListado de temperaturas inferiores a la media (%.2f)\n",media);
	for(i=0;i<N;++i)
		if(v[i]<media)
			printf("\tv[%d] = %10.2f\n",i+1,v[i]);
}
