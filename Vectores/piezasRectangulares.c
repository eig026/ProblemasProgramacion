#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

/* Nuevos tipos de datos */
typedef struct{
	float largo,ancho;
} tipo_pieza;
typedef tipo_pieza tipo_vector[MAX];
typedef struct{
	int n;
	tipo_vector v;
}tipo_conjunto_piezas;

/* prototipos de funciones */
void leer_pieza(tipo_conjunto_piezas *cp);
void leer_piezas(tipo_conjunto_piezas *cp);
void escribir_piezas(tipo_conjunto_piezas cp);
void eliminar_piezas(tipo_conjunto_piezas *cp);

int main(){
	char c;
	tipo_conjunto_piezas cp;

	randomize();
	do{ 	      system("cls||clear");
			printf("GESTION DE PIEZAS RECTANGULARES\n");
			printf("===============================\n\n");
			printf("\t1.- Insertar nueva pieza\n");
			printf("\t2.- Listar piezas registradas\n");
			printf("\t3.- Eliminar piezas no cuadradas de area menor\n");
			printf("\t4.- Terminar programa\n");
			printf("\n\t\tIntroduzca opcion: ");
			c=getch();
			switch(c){
			case '1': 	leer_pieza(&cp);
							//leer_piezas(&cp);
							break;
			case '2': 	escribir_piezas(cp);
							break;
			case '3': 	eliminar_piezas(&cp);
							break;
			case '4':	printf("\n\nFIN PROGRAMA");
							break;
			default:		printf("\a");
							break;
			}
	}while (c!='4');
	return 0;
}

void leer_pieza(tipo_conjunto_piezas *cp){
	char c;

	do{	      system("cls||clear");
			printf("INSERCION DE PIEZAS PLANAS RECTANGULARES\n");
			printf("========================================\n\n");
			if(cp->n==MAX){
				printf("Conjunto de piezas completo\n");
				printf("Pulse una tecla para continuar");
            c=getch();
			}else{	printf("\tLargo: ");
						scanf(" %f",&(cp->v[cp->n].largo));
						printf("\tAncho: ");
						scanf(" %f",&(cp->v[cp->n].ancho));
						(cp->n)++;
						printf("\nDesea introducir una nueva pieza (S/N): ");
						c=toupper(getch());
			}
	}while((cp->n<MAX)&&(c=='S'));
}

void leer_piezas(tipo_conjunto_piezas *cp){
	int i;

	cp->n=5;//rand()%25;
	for(i=0;i<cp->n;++i){
		cp->v[i].ancho=1.0+20.0*rand()/RAND_MAX;
		cp->v[i].largo=1.0+20.0*rand()/RAND_MAX;
	}
}

void escribir_piezas(tipo_conjunto_piezas cp){
	int i;

	      system("cls||clear");
	printf("LISTADO DE PIEZAS DEL CONJUNTO\n");
   printf("==============================\n\n");
	printf("\n\n");
	printf("     Largo     Ancho    Area");
	printf("\n");
	for(i=0;i<cp.n;++i){
		printf("%10.2f",cp.v[i].largo);
		printf("%10.2f",cp.v[i].ancho);
		printf("%10.2f\n",cp.v[i].largo*cp.v[i].ancho);
	}
	printf("\n\nPulse una tecla para continuar");
   getch();
}

void eliminar_piezas(tipo_conjunto_piezas *cp){
	int i,j;
	float area;

	j=0;
	i=0;
	      system("cls||clear");
	printf("ELIMINACION DE PIEZAS NO CUADRADAS PEQUE�AS\n");
	printf("===========================================\n\n");
	printf("Introduzca area minima: ");
	scanf(" %f",&area);
	while(i<cp->n){
		if((cp->v[i].largo!=cp->v[i].ancho)&&(cp->v[i].largo*cp->v[i].ancho<area))
			++i;
		else{	cp->v[j]=cp->v[i];
				++i;
				++j;
		}
	}
	cp->n=j;
}

