#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#define MAX_ICA 500    /* Valor superior del indice de calidad del aire */
#define MAX_EST 100    /* Numero maximo de estaciones de monitorizacion */
#define INTERVALOS 10  /* Numero de intervalos de clase para histograma */

/* Diseño Preliminar */
/* Nuevos tipos de datos */
typedef int tipo_ica[MAX_EST];      /* Indice de calidad del aire */
typedef int tipo_fa[INTERVALOS];    /* Frecuencias absolutas */
typedef float tipo_fr[INTERVALOS];  /* Frecuencias relativas */

/* Prototipos de funciones */
void leer_num_estaciones(int *n);
void leer_medidas(int n,tipo_ica v);
void calcular_frecuencias_absolutas(tipo_ica v,int n,int ni,tipo_fa vf);
void calcular_frecuencias_relativas(tipo_fa vf,int ni,int n,tipo_fr vr);
void imprimir_histograma(tipo_ica v,int n,int ni);
void imprimir_grafico(tipo_fa vf,tipo_fr vr,int ni);

/* Diseño Detallado */
int main(){
    char c;
    tipo_ica v;
    int n;

    do{ system("cls");
        printf("DISTRIBUCION DE FRECUENCIAS DE INDICES DE CALIDAD DEL AIRE\n");
        printf("==========================================================\n\n");
        leer_num_estaciones(&n);
        leer_medidas(n,v);
        imprimir_histograma(v,n,INTERVALOS);
        printf("\n\nDesea ejecutar de nuevo el programa (S/N)? ");
        c=toupper(getch());
    }while(c!='N');
    return 0;
}

void leer_num_estaciones(int *n){
     do{ printf("Numero de estaciones (1-%d): ",MAX_EST);
         scanf(" %d",n);
     }while((*n<1)||(*n>MAX_EST));
}

void leer_medidas(int n,tipo_ica v){
     int i;
     printf("Introduzca indices de calidad del aire [0-%d] para cada estacion:\n",MAX_ICA);
     i=0;
     while(i<n){
         do{ printf("\tEstacion %3d: ",i+1);
             //scanf(" %d",&v[i]);
             v[i]=rand()%MAX_ICA;
             printf("%d\n",v[i]);
         }while((v[i]<0)||(v[i]>MAX_ICA));
         ++i;
     }
     getch();
}

void calcular_frecuencias_absolutas(tipo_ica v,int n,int ni,tipo_fa vf){
     int i,j;

     i=0;
     while(i<ni){
        vf[i]=0;
        ++i;
     }
     i=0;
     while(i<n){
         j=v[i]*ni/MAX_ICA;
         if(j==ni){
            j--;
         }
         vf[j]++;
         ++i;
     }
}

void calcular_frecuencias_relativas(tipo_fa vf,int ni,int n,tipo_fr vr){
     int i;

     for(i=0;i<ni;++i)
         vr[i]=1.0*vf[i]/n;
}

void imprimir_histograma(tipo_ica v,int n,int ni){
    tipo_fa vf;
    tipo_fr vr;

    calcular_frecuencias_absolutas(v,n,ni,vf);
    calcular_frecuencias_relativas(vf,ni,n,vr);
    imprimir_grafico(vf,vr,ni);
}

void imprimir_grafico(tipo_fa vf,tipo_fr vr,int ni){
     int i,j;
     float acum;
     int na;      /* Nº de asteriscos de la linea */

     acum=0;
     system("cls");
     printf("HISTOGRAMA DE FRECUENCIAS RELATIVAS ACUMULATIVAS\n");
     printf("================================================\n\n");
     printf("Intervalo  FA     FR    FRA\n");
     for(i=0;i<ni;++i){
        acum+=vr[i];
        printf("[%3d-%3d) %3d %6.3f %6.3f ",i*MAX_ICA/ni,(i+1)*MAX_ICA/ni,
                                      vf[i],vr[i],acum);
        na=(int)(acum*40+0.5);  /* 1.0 --> 40* */
        for(j=0;j<na;++j){
           printf("*");
        }
        printf("\n");
     }
}
