/* Programa que resuelve un sistema lineal */
/* de 3 ecuaciones con 3 incognitas por    */
/* medio de la regla de Cramer  		   */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define n 3

/* Nuevos tipos de datos */
typedef float tipo_vector[n];
typedef float tipo_matriz[n][n];

/* Prototipos de funciones */
void leer_coeficientes(tipo_matriz a);
void leer_terminos(tipo_vector c);
int resolver_sistema(tipo_matriz a,tipo_vector c,tipo_vector x);
void sustituir_columna(tipo_matriz a,tipo_vector c,int i,
        tipo_matriz aux);
float determinante(tipo_matriz a);
void escribir_solucion(tipo_vector x);

int main(){
    char ca;
    tipo_vector c;      /* vector de terminos independientes */
    tipo_vector x;      /* vector de incognitas              */
    tipo_matriz a;      /* matriz de coeficientes            */
    int i;              /* 1: sistema compatible determinado */
                        /* 0: sistema compatible indetermi-	 */
                        /*    nado o incompatible            */

    do{ system("cls");
        printf("SISTEMA DE 3 ECUACIONES CON 3 INCOGNITAS\n");
        printf("========================================\n\n");
        printf("\ta[1,1]*x[1]+a[1,2]*x[2]+a[1,3]*x[3]=c[1]\n");
        printf("\ta[2,1]*x[1]+a[2,2]*x[2]+a[2,3]*x[3]=c[2]\n");
        printf("\ta[3,1]*x[1]+a[3,2]*x[2]+a[3,3]*x[3]=c[3]\n\n");
        printf("Introduzca coeficientes de variables: \n");
        leer_coeficientes(a);
        printf("\nIntroduzca terminos independientes:\n");
        leer_terminos(c);
        i=resolver_sistema(a,c,x);
        if(i)
             escribir_solucion(x);
        else printf("\nSistema indeterminado o incompatible");
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        ca=toupper(getch());
    }while (ca!='N');
    return 0;
}

void leer_coeficientes(tipo_matriz a){
    int i,j;

    for(i=0;i<n;++i)
        for(j=0;j<n;++j){
            printf("\ta[%d,%d]: ",i+1,j+1);
            scanf(" %f",&a[i][j]);
        }
}

void leer_terminos(tipo_vector c){
    int i;

    for(i=0;i<n;++i){
        printf("\tc[%d]: ",i+1);
        scanf(" %f", &c[i]);
    }
}

int resolver_sistema(tipo_matriz a,tipo_vector c,tipo_vector x){
/* Devuelve: 0 (sistema compatible indeterminado o incompatible)*/
/*           1 (sistema compatible determinado)                 */
    float d;             /* determinante matriz de coeficientes */
    int i;
    tipo_matriz aux;

    d=determinante(a);
    if(d==0)
          return 0;
    else{ for(i=0;i<n;++i){
              sustituir_columna(a,c,i,aux);
              x[i]=determinante(aux)/d;
          }
          return 1;
    }
}

void sustituir_columna(tipo_matriz a,tipo_vector c,int i,
        tipo_matriz aux){
    int j,k;

    for(j=0;j<n;++j)
        for(k=0;k<n;++k)
            if(k==i)
                 aux[j][k]=c[j];
            else aux[j][k]=a[j][k];
}

float determinante(tipo_matriz a){
    return(a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+
        a[0][2]*a[1][0]*a[2][1]- a[0][2]*a[1][1]*a[2][0]-
        a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[1][2]*a[2][1]);
}

void escribir_solucion(tipo_vector x){
    int i;

    printf("\nSoluciones:\n");
    for(i=0;i<n;++i)
        printf("\tx[%d] = %.2f\n",i+1,x[i]);
}
