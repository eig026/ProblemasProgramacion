/* Ejemplo de registro con parte variante:  */
/* Coordenadas bidimensionales de un punto: */
/* Cartesianas: (x,y)                       */
/* Polares: (modulo,angulo)                 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define PI atan(1.0)*4.0

/* Nuevos tipos de datos */
typedef struct{        /* Registro con parte variante         */
    int cartesianas;   /* Discriminante: 1-cartes 0-polares   */
    union{   /* sus campos comparten mismas posiciones de M.C.*/
        struct{        /* variante 1 */
            float x,y;
        };
        struct{        /* variante 2 */
            float modulo,angulo;
        };
    };
}tipo_coordenadas;

/* prototipos de funciones */
void leer_coordenadas(tipo_coordenadas *punto);
void c_p_c(tipo_coordenadas *punto);
void escribir_coordenadas(tipo_coordenadas punto);

int main(){
    char c;
    tipo_coordenadas punto;

    do{ system("cls");
        printf("EJEMPLO DE REGISTRO VARIANTE\n");
        printf("============================\n\n");
        printf("Introducir coordenadas 2D de un punto:\n");
        leer_coordenadas(&punto);
        printf("Punto introducido por teclado:\n");
        escribir_coordenadas(punto);
        c_p_c(&punto);
        printf("Punto en coordenadas cartesianas:\n");
        escribir_coordenadas(punto);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leer_coordenadas(tipo_coordenadas *punto){
    do{ printf("\tTipo de coordenadas (1: cartesianas, 0: polares): ");
        scanf(" %d", &punto->cartesianas);
    }while((punto->cartesianas<0)||(punto->cartesianas>1));
    if(punto->cartesianas){
           printf("\t\tx: ");
           scanf(" %f",&punto->x);
           printf("\t\ty: ");
           scanf(" %f",&punto->y);
    }else{ do{ printf("\t\tr: ");
               scanf(" %f",&punto->modulo);
           }while(punto->modulo<0);
           printf("\t\tAngulo (grados): ");
           scanf(" %f",&punto->angulo);
    }
}

void c_p_c(tipo_coordenadas *punto){
/* Convierte coordenadas polares a cartesinas  */
    float x,y;
    if(!(punto->cartesianas)){
        x=punto->modulo*cos(punto->angulo*PI/180.0);
        y=punto->modulo*sin(punto->angulo*PI/180.0);
        punto->cartesianas=1;
        punto->x=x;
        punto->y=y;
    }
}

void escribir_coordenadas(tipo_coordenadas punto){
    if(punto.cartesianas){
           printf("\tx = %.2f\n",punto.x);
           printf("\ty = %.2f\n",punto.y);
    }else{ printf("\tr = %.2f\n",punto.modulo);
           printf("\tang (grados) = %.2f\n",punto.angulo);
    }
}
