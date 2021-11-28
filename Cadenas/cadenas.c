/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */

/* Programa que combina dos cadenas en una nueva cadena, insertando
	alternativamente los caracteres de ambas cadenas                  */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 5		/* longitud maxima de las cadenas de entrada 	*/

/* Nuevos tipos de datos */
typedef char cadena50[N+1];
typedef char cadena100[2*N+1];

/* Prototipos de funciones */
void intercalar_cadenas(cadena50 cad1, cadena50 cad2, cadena100 cad);
void leer_cadena(char *c, int n);

int main(){
	cadena50 cad1,cad2;	/* cadenas a intercalar	*/
	cadena100 cad;			/* cadena resultante		*/
	char c;

	do{ 	      system("cls||clear");
	        printf("INTERCALACION DE CADENAS DE CARACTERES\n");
			printf("======================================\n\n");
			printf("Introduzca primera cadena: ");
			leer_cadena(cad1,N);
			printf("\nIntroduzca segunda cadena: ");
			leer_cadena(cad2,N);
			intercalar_cadenas(cad1,cad2,cad);
			printf("\nCadena resultante: %s",cad);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void intercalar_cadenas(cadena50 cad1, cadena50 cad2, cadena100 cad){
	int i,j;		/* indices de vectores							*/
	int l1,l2;	/* longitudes de las cadenas cad1 y cad2	*/

	i=0;
	j=0;
	l1=strlen(cad1);
	l2=strlen(cad2);
	while((i<l1)&&(i<l2)){
	  cad[j]=cad1[i];
	  j=j+1;
	  cad[j]=cad2[i];
	  j=j+1;
	  i=i+1;
	}
	while(i<l1){
	  cad[j]=cad1[i];
	  i++;
	  j++;
	}
	while(i<l2){
	  cad[j]=cad2[i];
	  i++;
	  j++;
	}
	cad[j]='\0';
	return;
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
			if(c!='\b'){
				cad[i]=c;
				++i;
			}else{ if(i>0)
						--i;
			}
		}else fin=1;
	}
	cad[i]='\0';
}

