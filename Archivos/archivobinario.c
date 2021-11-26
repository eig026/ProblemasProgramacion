#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define	archivo "poligono.bin"
#define MAX 20

/*** DISEÑO PRELIMINAR ***/
/* Nuevos tipos de datos */
typedef char cadena50[51];
typedef struct{
	float x,y;
}tipo_punto2d;
typedef tipo_punto2d tipo_v_p[MAX];
typedef struct{
	short int n;
	tipo_v_p v;
}tipo_poligono;

/* prototipos de funciones */
void leer_poligono_archivo(FILE *f,tipo_poligono *p);

/*** DISEÑO DETALLADO ***/
/* Definiciones de funciones */
int main(){
	FILE *f;
	tipo_poligono pol;
	int i,j;
	char c;
	cadena50 nombre;

	system("cls");
	printf("LECTURA DE REGISTROS\n");
	printf("======================\n\n");
	if((f=fopen(archivo,"rb"))==NULL){
		printf("Error al abrir el archivo %s\n",archivo);
		exit(1);
	}else{  //fread(&pol,sizeof(tipo_poligono),1,f);
	        /* Recorrido secuencial del archivo */
			leer_poligono_archivo(f,&pol);
			j=1;
			c='s';
			while((!feof(f))&&(c!='F')){
				printf("\nPoligono %d: Numero de vertices: %d\n",j,pol.n);
				j++;
				for(i=0;i<pol.n;++i){
					printf("\tVertice %d: (%.2f,%.2f)\n",i+1,pol.v[i].x,pol.v[i].y);
				}
				//fread(&pol,sizeof(tipo_poligono),1,f);
				leer_poligono_archivo(f,&pol);
				printf("Pulse una tecla para continuar (F: fin del listado)");
				c=toupper(getch());
			}
			fclose(f);
	}
	getch();
}

void leer_poligono_archivo(FILE *f,tipo_poligono *p){
/* Lectura de cada registro del archivo binario */
/* campo a campo para garantizar portabilidad   */
     int i;
     fread(&p->n,sizeof(short int),1,f);
     //fread(p->v,sizeof(tipo_v_p),1,f);
     for(i=0;i<MAX;++i){
       fread(&p->v[i].x,sizeof(float),1,f);
       fread(&p->v[i].y,sizeof(float),1,f);
     }
}
