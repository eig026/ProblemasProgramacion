/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06


 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 5

/* ********************* */
/* DISEÑO PRELIMINAR     */
/* ********************* */

/* Nuevos tipos de datos */
typedef char cadena10[11];
typedef struct{
	float largo,ancho;
	cadena10 color;
} tipo_pieza;
typedef tipo_pieza tipo_vector[MAX];
typedef struct{
	int n;
	tipo_vector v;
}tipo_conjunto_piezas;

/* prototipos de funciones */
void leer_piezas(tipo_conjunto_piezas *cp);
void leer_cadena(char *cad, int n);
void escribir_piezas(tipo_conjunto_piezas *cp);
void eliminar_piezas(tipo_conjunto_piezas *cp);
void listar_color(tipo_conjunto_piezas *cp);
void buscar_pieza(tipo_conjunto_piezas *cp);
void clasificar_area(tipo_vector v,int n);
void clasificar_long(tipo_vector v,int n);
int es_anterior(tipo_pieza a, tipo_pieza b);

/* ********************* */
/* DISEÑO DETALLADO      */
/* ********************* */

/* Definiciones de funciones */
int main(){
	char c;
	tipo_conjunto_piezas cp;

	cp.n=0;
	do{ system("cls");
		printf("GESTION DE PIEZAS RECTANGULARES\n");
		printf("===============================\n\n");
		printf("\t1.- Insertar nueva pieza\n");
		printf("\t2.- Listar piezas registradas\n");
		printf("\t3.- Eliminar piezas no cuadradas de area menor\n");
		printf("\t4.- Listar num de piezas por color\n");
		printf("\t5.- Buscar pieza a medida\n");
		printf("\t6.- Listar piezas por tamaño area\n");
		printf("\t7.- Listar piezas por longitud lado mayor\n");
		printf("\t8.- Terminar programa\n");
		printf("\n\t\tIntroduzca opcion: ");
		c=getch();
		switch(c){
		case '1': 	leer_piezas(&cp);
					break;
		case '2': 	escribir_piezas(&cp);
					break;
		case '3': 	eliminar_piezas(&cp);
					break;
		case '4': 	listar_color(&cp);
					break;
		case '5': 	buscar_pieza(&cp);
					break;
		case '6': 	clasificar_area(cp.v,cp.n);
					escribir_piezas(&cp);
					break;
		case '7': 	clasificar_long(cp.v,cp.n);
					escribir_piezas(&cp);
					break;
		case '8':	printf("\n\nFIN PROGRAMA");
					break;
		default:	printf("\a");
					break;
		}
	}while (c!='8');
	return 0;
}

void leer_piezas(tipo_conjunto_piezas *cp){
	char c;

	do{	system("cls");
		printf("INSERCION DE PIEZAS PLANAS RECTANGULARES\n");
		printf("========================================\n\n");
		if(cp->n==MAX){
			printf("Conjunto de piezas completo\n");
			printf("Pulse una tecla para continuar");
            c=getch();
		}else{	do{	printf("\tLargo: ");
					scanf(" %f",&(cp->v[cp->n].largo));
				}while(cp->v[cp->n].largo<=0);
				do{ printf("\tAncho: ");
					scanf(" %f",&(cp->v[cp->n].ancho));
				}while(cp->v[cp->n].ancho<=0);
				printf("\tColor: ");
				leer_cadena(cp->v[cp->n].color,10);
				(cp->n)++;
				printf("\nDesea introducir una nueva pieza (S/N): ");
				c=toupper(getch());
		}
	}while((cp->n<MAX)&&(c=='S'));
}

void leer_cadena(char *cad, int n){
/* lee por teclado y devuelve una cadena de hasta n caracteres */
/* Nota: la cadena debe preveer una posicion adicional para la */
/* marca fin de cadena (\0) --> tamaño minimo n+1 caracteres   */
    int i,fin;
    char c;

    i=0;
    fin=0;
    while((i<n)&&(!fin)){
        c=getch();
        switch(c){
        case '\r': fin=1;
                   printf("\n");
                   break;
        case '\b': if (i>0){
                     --i;
                     printf("\b \b");
                   }
                   break;
        default:   cad[i]=c;
                   ++i;
                   printf("%c",c);
                   break;
        }
    }
    cad[i]='\0';
    if (i==n) printf("\n");
}

void escribir_piezas(tipo_conjunto_piezas *cp){
	int i;
	float area,total;

	system("cls");
	total=0;
	printf("LISTADO DE PIEZAS DEL CONJUNTO\n");
	printf("==============================\n\n");
	printf("\n\n");
	printf("Color          Largo     Ancho      Area\n");
	printf("=====          =====     =====      ====\n");
	for(i=0;i<cp->n;++i){
		printf("%-10s",cp->v[i].color);
		printf("%10.2f",cp->v[i].largo);
		printf("%10.2f",cp->v[i].ancho);
		area=cp->v[i].largo*cp->v[i].ancho;
		printf("%10.2f\n",area);
		total+=area;
	}
	printf("========================================\n");
	printf("Num. de piezas: %d\n",cp->n);
	printf("Area total: %.2f\n",total);
	printf("\n\nPulse una tecla para continuar");
	getch();
}

void eliminar_piezas(tipo_conjunto_piezas *cp){
	int i,j;
	float area;

	system("cls");
	printf("ELIMINACION DE PIEZAS NO CUADRADAS PEQUEÑAS\n");
	printf("===========================================\n\n");
	do{	printf("Introduzca area minima: ");
		scanf(" %f",&area);
	}while(area<=0);
	j=0;
	i=0;
	while(i<cp->n){
		if((cp->v[i].largo==cp->v[i].ancho)||(cp->v[i].largo*cp->v[i].ancho>=area)){
			cp->v[j]=cp->v[i];
			++j;
		}
		++i;
	}
	cp->n=j;
	printf("\nTotal de piezas eliminadas: %d\n",i-j);
	printf("\n\nPulse una tecla para continuar");
	getch();
}

void listar_color(tipo_conjunto_piezas *cp){
	int i,j,n,enc,total;

	system("cls");
	printf("Color     Num. de piezas\n");
	printf("=====     ==============\n");
	total=0;
	for(i=0;i<cp->n;++i){
		enc=0;
		j=0;
		while((j<i)&&(!enc)){
			if(strcmpi(cp->v[i].color,cp->v[j].color))
				++j;
			else enc=1;
		}
		if(!enc){
			printf("%-10s",cp->v[i].color);
			n=1;
			j=i+1;
			while(j<cp->n){
				if(strcmpi(cp->v[i].color,cp->v[j].color)==0)
					++n;
				++j;
			}
			printf("%14d\n",n);
			total+=n;
		}
	}
	printf("-----     --------------\n");
	printf("%-10s%14d\n","Total",total);
	printf("\n\nPulse una tecla para continuar");
	getch();
}

void buscar_pieza(tipo_conjunto_piezas *cp){
	float ancho,largo,area,area2;
	int i,j,enc;

	system("cls");
	printf("BUSQUEDA DE PIEZAS DE MEDIDAS DADAS\n");
	printf("===================================\n\n");
	do{	printf("\tLargo: ");
		scanf(" %f",&largo);
	}while(largo<=0);
	do{ printf("\tAncho: ");
		scanf(" %f",&ancho);
	}while(ancho<=0);
	enc=0;
	for(i=0;i<cp->n;++i){
		if((cp->v[i].largo>=largo)&&(cp->v[i].ancho>=ancho)){
			area2=(cp->v[i].largo)*(cp->v[i].ancho);
			if(enc){
				if(area2<area){
					j=i;
					area=area2;
				}
			}else{
				enc=1;
				area=area2;
			}
		}
	}
	if(enc){
		printf("\nPieza encontrada:\n");
		printf("\nLargo: %10.2f\n",cp->v[j].largo);
		printf("Ancho: %10.2f\n",cp->v[j].ancho);
		printf("Area:  %10.2f\n",area);
		printf("Color: %s\n",cp->v[j].color);
	}else{
		printf("\nNo hay piezas de esas medidas");
	}
	printf("\n\nPulse una tecla para continuar");
	getch();
}



void clasificar_area(tipo_vector v,int n){
	int i,j;
  	tipo_pieza x;
  	int k;           /* posicion de insercion */
  	for(i=0;i<n-1;++i){
    	k=i;
    	for (j=i+1;j<n;++j)
        	if (v[j].largo*v[j].ancho > v[k].largo*v[k].ancho)
           		k=j;
     	x=v[k];
     	v[k]=v[i];
     	v[i]=x;
  	}
}

void clasificar_long(tipo_vector v,int n){
	int i,j;
  	tipo_pieza x;
  	int k;           /* posicion de insercion */
  	for(i=0;i<n-1;++i){
     	k=i;
     	for(j=i+1;j<n;++j)
        	if(es_anterior(v[j],v[k]))
           		k=j;
     	x=v[k];
     	v[k]=v[i];
     	v[i]=x;
  	}
}

int es_anterior(tipo_pieza a, tipo_pieza b){
	float amax,bmax;
	if(a.largo>=a.ancho)
		amax=a.largo;
	else amax=a.ancho;
	if(b.largo>=b.ancho)
		bmax=b.largo;
	else bmax=b.ancho;
	if(amax>bmax)
		return 1;
	else return 0;
}
