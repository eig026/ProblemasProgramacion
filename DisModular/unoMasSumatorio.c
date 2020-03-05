/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  * Programa que calcula la suma de 1+Sumatoria(x**i/i!)
 */
     

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Prototipos de funciones */
void leer_datos(float *x, int *n);
void leer_real(float *x);
void leer_num_sumandos(int *n);
double calcular_suma(float x, int n);
double potencia(float x, int n);
double factorial(int n);
void escribir_resultados(float x, int n, double suma);

/* Definiciones de funciones */
int main(){
    char c;
    int n;        /* Numero de sumandos  */
    float x;      /* Numero real         */
    double suma;

    do{ system("cls");
        printf("CALCULO DE LA SUMA DE x**i/i!\n");
        printf("=============================\n\n");
        leer_datos(&x, &n);
        suma=calcular_suma(x,n);
        escribir_resultados(x,n,suma);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leer_datos(float *x, int *n){
    leer_real(x);
    leer_num_sumandos(n);
}

void leer_real(float *x){
    printf("Introduzca un numero real: ");
    scanf(" %f", x);
}

void leer_num_sumandos(int *n){
    do{ printf("Introduzca numero de sumandos: ");
        scanf(" %d", n);
    }while(*n<=0);
}

double calcular_suma(float x, int n){
    int i;
    double suma;

    suma=1;
    i=1;
    while(i<=n){
        suma=suma+potencia(x,i)/factorial(i);
        i=i+1;
    }
    return suma;
}

double potencia(float x, int n){
/* el exponente n debe ser mayor que cero */
    if(n==1)
         return x;
    else return(x*potencia(x,n-1));
}

double factorial(int n){
/* n mayor o igual a cero */
    if(n==0)
         return(1);
    else return(n*factorial(n-1));
}

void escribir_resultados(float x, int n, double suma){
    printf("\n\n");
    printf("Suma de %d terminos de %.1f**i/i! = %.10lf", n,x,suma);
}
