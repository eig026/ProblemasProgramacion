#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 100		/* longitud maxima de las cadenas de entrada 	*/

/* Nuevos tipos de datos */
typedef char cadena[N+1];
typedef cadena tipo_vector[N/4];

/* Prototipos de funciones */
void leer_cadena(char *c, int n);
void leer_opcion_menu(char *c);
void ejecutar_opcion(char c,cadena cad);
void opcion1(cadena cad);
void opcion2(cadena cad);
void opcion3(cadena cad);
int buscar(tipo_vector v,int cont,cadena cad2);
void opcion4(cadena cad);
int isvocal(char c);
int isconsonant(char c);

int main(){
	char c;
	cadena cad;

	do {	printf("Introduzca una cadena: ");
			leer_cadena(cad,N);
			do{   leer_opcion_menu(&c);
					ejecutar_opcion(c,cad);
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
	printf("\t1.- Escribir cadena en mayusculas\n");
	printf("\t2.- Contar vocales, consonantes, puntuacion y otros caracteres\n");
	printf("\t3.- Contar y escribir palabras diferentes\n");
	printf("\t4.- Indicar si es un palindromo\n");
	printf("\t0.- Finalizar\n\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void ejecutar_opcion(char c,cadena cad){
	switch(c){
	case '1': opcion1(cad);
				 break;
	case '2': opcion2(cad);
				 break;
	case '3': opcion3(cad);
				 break;
	case '4': opcion4(cad);
				 break;
	case '0': printf("FIN DE EJECUCION");
				 getch();
				 break;
	default: printf("\a");
	}
}

void opcion1(cadena cad){
	cadena cad2;

	printf("\nCadena original: %s\n",cad);
	strcpy(cad2,cad);
	strupr(cad2);
	printf("\nCadena en mayusculas: %s\n",cad2);
	getch();
}

void opcion2(cadena cad){
	int v,c,p,o;
	int i,l;

	l=strlen(cad);
	v=c=o=p=0;
	for(i=0;i<l;++i)
		if (isvocal(cad[i]))
			v++;
		else 	if (isconsonant(cad[i]))
					c++;
				else	if(ispunct(cad[i]))
							p++;
						else 	o++;
	printf("\n\nRecuento de letras:\n");
	printf("\tVocales:          %5d\n",v);
	printf("\tConsonantes:      %5d\n",c);
	printf("\tPuntuacion:       %5d\n",p);
	printf("\tOtros caracteres: %5d\n",o);
	getch();
}

void opcion3(cadena cad){
	cadena cad2;
	tipo_vector v;
	int i,j,l,cont;

	l=strlen(cad);
	j=0;
	cont=0;
	printf("\nCadena original: %s\n",cad);
	printf("Palabras diferentes:\n");
	for(i=0;i<l;++i)
		if(isalpha(cad[i])){
			cad2[j]=cad[i];
			j++;
		}else if (j){
					cad2[j]='\0';
					if(buscar(v,cont,cad2)){
						strcpy(v[cont],cad2);
						cont++;
					}
					j=0;
					//printf("\t%s\n",cad2);
				}
	if(j){
		cad2[j]='\0';
		if(buscar(v,cont,cad2)){
			strcpy(v[cont],cad2);
			cont++;
		}
		//printf("\t%s\n",cad2);
	}
	for(i=0;i<cont;++i)
		printf("\t%s\n",v[i]);
	printf("\nNumero de palabras encontradas: %d\n",cont);
	getch();
}

int buscar(tipo_vector v,int cont,cadena cad2){
	int i;

	i=0;
	while((i<cont)&&(strcmp(v[i],cad2)))
		i++;
	if(i<cont)
		return 0;
	else return 1;
}

void opcion4(cadena cad){
	int i,l;

	l=strlen(cad);
	i=0;
	while((i<l/2-1)&&(cad[i]==cad[l-1-i]))
		++i;
	printf("\nCadena original: %s\n",cad);
	if(i<l/2-1)
		printf("No es un palindromo\n");
	else	printf("Es un palindromo\n");
	getch();
}

int isvocal(char c){
	switch(toupper(c)){
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': return 1;
	default: return 0;
	}
}

int isconsonant(char c){
	if((!isvocal(c))&&(c>='A')&&(c<='z'))
		return 1;
	else return 0;
}