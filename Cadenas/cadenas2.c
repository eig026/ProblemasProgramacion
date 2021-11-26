#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 50		/* longitud maxima de la cadena de entrada 	*/

/* Nuevos tipos de datos */
typedef char cadena50[N+1];

/* Prototipos de funciones */
void leer_cadena(char *c, int n);
void leer_opcion_menu(char *c);
void invertir_cadena(char *cad);
void eliminar_no_alfabeticos(char *cad);
void listar_palabras(char *cad);

int main(){
	char c;
	cadena50 cad,cad2;

	do{ 	      system("cls||clear");
			printf("EJERCICIOS DE CADENAS DE CARACTERES\n");
			printf("===================================\n\n");
			printf("Introduzca una cadena de caracteres: ");
			leer_cadena(cad,N);
			do{ 	leer_opcion_menu(&c);
					printf("\n\nCadena original:  %s\n",cad);
					strcpy(cad2,cad);
					switch(c){
					case '1': invertir_cadena(cad2);
								 printf("Cadena invertida: %s\n",cad2);
								 getch();
								 break;
					case '2': eliminar_no_alfabeticos(cad2);
								 printf("Cadena modificada: %s\n",cad2);
								 getch();
								 break;
					case '3': listar_palabras(cad);
								 break;
					case '0': printf("FIN DE EJECUCION");
								 getch();
								 break;
					default: printf("\a");
					}
			}while(c!='0');
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
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

void leer_opcion_menu(char *c){
	      system("cls||clear");
	printf("OPERACIONES CON CADENAS DE CARACTERES\n");
	printf("=====================================\n\n");
	printf("\t1.- Invertir cadena\n");
	printf("\t2.- Eliminar caracteres no alfabeticos de cadena\n");
	printf("\t3.- Listar palabras de una cadena\n");
	printf("\t0.- Finalizar\n\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void invertir_cadena(char *cad){
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

void eliminar_no_alfabeticos(char *cad){
	int i,j,n;

	n=strlen(cad);
	j=0;
	for(i=0;i<n;++i){
		if(isalpha(cad[i])){
			cad[j]=cad[i];
			++j;
		}
	}
	cad[j]='\0';
}

void listar_palabras(char *cad){
	int i,n,z;

	n=strlen(cad);
	z=0;
	printf("\n\nListado de palabras:\n\t");
	for(i=0;i<n;++i){
		if(isalpha(cad[i])){
			z=0;
			printf("%c",cad[i]);
		}else{	if(!z){
						z=1;
						printf("\n\t");
					}
		}
	}
	getch();
}
