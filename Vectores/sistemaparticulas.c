/* Programa que gestiona un sistema de particulas: */
/* inserta, elimina, lista y escribe masa y        */
/* centro de masas                                 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAX 10      /* Numero maximo de particulas */

/* Nuevos tipos de datos */
typedef float tipo_vector[MAX];

/* Prototipos de funciones */
void leer_opcion_menu(char *c);
void insertar_particula(tipo_vector m, tipo_vector x,
        tipo_vector y,tipo_vector z, int *n);
void leer_masa(float *m);
void leer_posicion(float *x, float *y, float *z);
int posicion_ocupada(tipo_vector x, tipo_vector y,
        tipo_vector z, int n, float nx, float ny, float nz);
int buscar_posicion_insercion(tipo_vector m, int n, float nm);
void eliminar_particula(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int *n);
void listar_particulas(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int n);
void escribir_centro_masas(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int n);

int main(){
    char c;            /* Seleccion opcion de menu      */
    tipo_vector m;     /* masas de las particulas       */
    tipo_vector x,y,z; /* coordenadas de sus posiciones */
    int n;             /* Numero de particulas          */

    n=0;
    do{ system("cls");
        leer_opcion_menu(&c);
        switch(c){
        case '1': insertar_particula(m,x,y,z,&n);
                  break;
        case '2': eliminar_particula(m,x,y,z,&n);
                  break;
        case '3': listar_particulas(m,x,y,z,n);
                  break;
        case '4': escribir_centro_masas(m,x,y,z,n);
                  break;
        case '5': printf("\n\nFIN EJECUCION\n");
                  getch();
                  break;
        default:  printf("\a");
                  break;
        }
    }while(c!='5');
    return 0;
}

void leer_opcion_menu(char *c){
	system("cls");
	printf("SISTEMA DE PARTICULAS\n");
	printf("=====================\n\n");
	printf("\t1.- Insertar nueva particula\n");
	printf("\t2.- Eliminar particula\n");
	printf("\t3.- Listar particulas\n");
	printf("\t4.- Calcular centro de masas\n");
	printf("\t5.- Terminar ejecucion\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void insertar_particula(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int *n){
/* Módulo para insertar partículas; tras insertar una partícula  */
/* pregunta si se desean introducir mas partículas.              */
/* Las particulas se insertan en orden de masa, de mayor a menor */
    int i;                           /* posición de inserción    */
    int j;                           /* contador de bucle        */
    float nm, nx, ny, nz;            /* datos de nueva partícula */
    char c;                          /* respuesta a pregunta     */

    do{ if(*n==MAX){
               printf("\n\nVector lleno");
               c='N';
               getch();
        }else{ printf("\n\nIntroduzca datos particula:");
               leer_masa(&nm);
               do{ leer_posicion(&nx,&ny,&nz);
               }while(posicion_ocupada(x,y,z,*n,nx,ny,nz));
               i=buscar_posicion_insercion(m,*n,nm);
               for(j=*n;j>i;--j){
                   m[j]=m[j-1];
                   x[j]=x[j-1];
                   y[j]=y[j-1];
                   z[j]=z[j-1];
               }
               m[i]=nm;
               x[i]=nx;
               y[i]=ny;
               z[i]=nz;
               (*n)++;
               printf("\nDesea introducir nueva particula (S/N): ");
               c=toupper(getch());
        }
    }while((c=='S')&&(*n<MAX));
}

void leer_masa(float *m){
    do{ printf("\n\tMasa: ");
        scanf(" %f", m);
    }while(*m<=0);
}

void leer_posicion(float *x, float *y, float *z){
	printf("\tPosicion:\n");
	printf("\t\tx: ");
	scanf(" %f", x);
	printf("\t\ty: ");
	scanf(" %f", y);
	printf("\t\tz: ");
	scanf(" %f", z);
}

int posicion_ocupada(tipo_vector x, tipo_vector y,
        tipo_vector z,int n, float nx, float ny, float nz){
/* Devuelve verdadero si en la nueva posición  ya hay  una partícula */
    int res;        /* resultado de la comprobación */
    int i;          /* contador de bucle            */

    res=0;
    i=0;
    while((i<n)&&(!res)){
        if((x[i]==nx)&&(y[i]==ny)&&(z[i]==nz))
             res=1;
        else i++;
    }
    return(res);
}

int buscar_posicion_insercion(tipo_vector m, int n, float nm){
/* Devuelve la posición del primer elemento de masa menor a nm	*/
    int i;          /* contador de bucle   */
    int enc;        /* indicador de suceso */

    i=0;
    enc=0;
    while((i<n)&&(!enc)){
        if(m[i]<nm)
             enc=1;
        else ++i;
    }
    return(i);
}

void eliminar_particula(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int *n){
    int num;        /* posicion de la particula a borrar */
    int i;          /* contador de bucle                 */
    char c;         /* respuesta a pregunta              */

    do{ if(*n==0){
               printf("\n\nNo hay ninguna particula");
               c='N';
               getch();
        }else{ do{ printf("\n\nIntrod. num. particula(1-%d): ",*n);
                   scanf(" %d", &num);
               }while((num<0)||(num>*n));
               for(i=num;i<*n;++i){
                   m[i-1]=m[i];
                   x[i-1]=x[i];
                   y[i-1]=y[i];
                   z[i-1]=z[i];
               }
               (*n)--;
               printf("Desea eliminar otra particula (S/N): ");
               c=toupper(getch());
        }
    }while((c=='S')&&(*n>0));
}

void listar_particulas(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int n){
    int i;           /* contador de bucle */

    system("cls");
    printf("LISTADO DE PARTICULAS\n");
    printf("=====================\n\n");
    printf("Numero       masa          x          y          z\n");
    for(i=0;i<n;++i)
        printf("   %3d %10.2f %10.2f %10.2f %10.2f\n",
             i+1,m[i],x[i],y[i],z[i]);
    getch();
}

void escribir_centro_masas(tipo_vector m, tipo_vector x,
        tipo_vector y, tipo_vector z, int n){
    int i;          /* contador de bucle                */
    float cx,cy,cz; /* coordenadas del centro de masas  */
    float masa;     /* masa total sistema de particulas */

    cx=0;
    cy=0;
    cz=0;
    masa=0;
    if(n==0){
           printf("\n\nNinguna particula introducida");
           getch();
    }else{ for(i=0;i<n;++i){
               cx+=m[i]*x[i];
               cy+=m[i]*y[i];
               cz+=m[i]*z[i];
               masa+=m[i];
           }
           cx=cx/masa;
           cy=cy/masa;
           cz=cz/masa;
           printf("\n\nCentro de masas: (%10.2f,%10.2f,%10.2f)",
               cx,cy,cz);
           printf("\nMasa: %10.2f",masa);
           getch();
    }
}
