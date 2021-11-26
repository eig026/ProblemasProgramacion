/* Programa que invierte una cadena de caracteres */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 50		/* longitud maxima de las cadenas */

/* Nuevos tipos de datos */
typedef char cadena50[N+1];

/* Prototipos de funciones */
void invertir_cadena(cadena50 cad1);
void leer_cadena(char *c, int n);

int main(){
	cadena50 cad;
	char c;

	do{ 	      system("cls||clear");
			printf("INVERSION DE CADENAS DE CARACTERES\n");
			printf("==================================\n\n");
			printf("Introduzca cadena: ");
			leer_cadena(cad,N);
			invertir_cadena(cad);
			printf("\nCadena resultante: %s",cad);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void invertir_cadena(cadena50 cad){
	int i,n;
	char c;

	i=0;
	n=strlen(cad);
	while(i<n/2){
	  c=cad[i];
	  cad[i]=cad[n-1-i];
	  cad[n-1-i]=c;
	  i=i+1;
	}
}

void leer_cadena(char *cad, int n){
/* lee por teclado y devuelve una cadena de hasta n caracteres */
	int i,fin;
	char c;

	i=0;
	fin=0;
	while((i<n)&&(!fin)){
		c=getche();
		if(c!='\r'){
			cad[i]=c;
			++i;
		}else fin=1;
	}
	cad[i]='\0';
}