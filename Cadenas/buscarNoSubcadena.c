#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 100

/* Nuevos tipos de datos */
typedef char cadena[N+1];

/* prototipos de funciones */
void leer_cadena(char *cad, int n);
void escribir_palabras(cadena cad1,cadena cad2);
int busqueda_subcadena(char *c, char *s);

int main(){
	char c;
	cadena cad1,cad2;

	do{ 	clrscr();
			printf("PALABRAS DE UNA CADENA QUE NO ESTAN EN OTRA\n");
			printf("===========================================\n\n");
			printf("Introduzca primera cadena: ");
			leer_cadena(cad1,N);
			printf("Introduzca segunda cadena: ");
			leer_cadena(cad2,N);
			escribir_palabras(cad1,cad2);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
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
	printf("\n");
}

void escribir_palabras(cadena cad1,cadena cad2){
	cadena cad;
	int i,j,l1;

	l1=strlen(cad1);
	j=0;
	printf("\nPalabras de la primera cadena que no estan en la segunda:\n");
	for(i=0;i<l1;++i)
		if(isalpha(cad1[i])){
			cad[j]=cad1[i];
			j++;
		}else if (j){
					cad[j]='\0';
					j=0;
					if(!busqueda_subcadena(cad2,cad))
						printf("\t%s\n",cad);
				}
	if(j){
		cad[j]='\0';
		if(!busqueda_subcadena(cad2,cad))
			printf("\t%s\n",cad);
	}
	getch();
}

int busqueda_subcadena(char *c, char *s){
	int i,j;
	int l1,l2;
	int enc;

	i=0;
	enc=0;
	l1=strlen(c);
	l2=strlen(s);
	while((i<l1)&&(!enc)){
		if(c[i]==s[0]){
			j=1;
			enc=1;
			while((j<l2)&&(i+j<l1)&&(enc))
				if(c[i+j]==s[j])
					j++;
				else enc=0;
			if(j!=l2){
				enc=0;
				++i;
			}
		}
		else ++i;
	}
	if(enc)
		return i+1;
	else return 0;
}
