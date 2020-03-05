/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa saludara al usuario incorporando su nombre y apellidos al saludo
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Prototipos de funciones */
void leer_datos(int *n, int *m);
void leer_entero_positivo(int *n);
void leer_entero_rango(int a,int b,int *m);
double calcular_combinaciones(int n,int m);
double factorial(int n);
void escribir_resultados(int n, int m, double c);

/* Definiciones de funciones */
int main(){
    char c;
    int n,m;
    double comb;
    do{ system("cls");
        printf("COMBINACIONES DE n OBJETOS TOMADOS DE m EN m\n");
        printf("============================================\n\n");
        leer_datos(&n,&m);
        comb=calcular_combinaciones(n,m);
        escribir_resultados(n,m,comb);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while(c!='N');
    return 0;
}

void leer_datos(int *n, int *m){
	printf("Introduzca numero de objetos:\n");
	leer_entero_positivo(n);
	printf("Introduzca m:\n");
	leer_entero_rango(1,*n,m);
}

void leer_entero_positivo(int *n){
    do{ printf("\tIntroduzca entero positivo: ");
        scanf(" %d",n);
    }while(*n<=0);
}

void leer_entero_rango(int a,int b,int *m){
    int aux;

    if(a>b){
        aux=a;
        a=b;
        b=aux;
    }
    do{ printf("\tIntroduzca entero [%d,%d]: ",a,b);
        scanf(" %d",m);
    }while((*m<a)||(*m>b));
}

double calcular_combinaciones(int n,int m){
	return(factorial(n)/(factorial(m)*factorial(n-m)));
}

double factorial(int n){
    int i;
    double fac;

    fac=1;
    i=1;
    while(i<=n){
        fac=fac*i;
        i++;
    }
    return fac;
}

void escribir_resultados(int n, int m, double c){
	printf("\nCombinaciones de %d elementos tomados de %d en %d= %.0lf",n,m,m,c);
}
