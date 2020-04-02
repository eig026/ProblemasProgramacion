/* Programa que lee por teclado 24 datos de          */
/* temperatura e imprime en pantalla las diferencias */
/* de cada dato con respecto a la media              */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define N 4				/* Numero de datos de temperatura */

/* Nuevos tipos de datos */
typedef float tipo_temp[N];

/* Prototipos de funciones */
void leer_temperaturas(tipo_temp t);
float calcular_media(tipo_temp t);
void escribir_diferencias(tipo_temp t, float media);

int main(){
	char c;
	tipo_temp temp;  	/* vector de temperaturas 	*/
	float media;		/* temperatura media		*/

	do{ system("cls");
		printf("DESVIACIONES RESPECTO A TEMPERATURA MEDIA\n");
		printf("=========================================\n\n");
		leer_temperaturas(temp);
		media=calcular_media(temp);
		escribir_diferencias(temp,media);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

void leer_temperaturas(tipo_temp t){
	int i;			/* contador para indice del vector 	*/

	system("cls");
	printf("Introduzca datos de temperatura: \n");
	for(i=0;i<N;++i){
		printf("\ttemperatura[%d]: ",i+1);
		scanf(" %f", &t[i]);
	}
}

float calcular_media(tipo_temp t){
	float suma;		/* acumulador de sumas			*/
	int i;			/* contador para indice del vector	*/

	suma=0;
	for(i=0;i<N;++i)
		suma+=t[i];
	return(suma/N);
}

void escribir_diferencias(tipo_temp t, float media){
	int i;			/* contador para indice del vector	*/

	printf("Desviaciones respecto a temp. media=%.2f\n\n" , media);
	for(i=0;i<N;++i){
		printf("\ttemperatura[%d]=%10.2f\tDesviacion: %10.2f\n",
                   i+1,t[i],t[i]-media);
	}
}
