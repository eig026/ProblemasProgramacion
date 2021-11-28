/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */
/*  * Ejemplo : Calculo moda y media. Si son mas de diez, se cuentan en 10*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 25
typedef int tipo_vector[MAX];

void leer_vector(tipo_vector v, int *n);
void obtener_frecuencia(tipo_vector v1, tipo_vector v2, int tam);
void escribir_vector(tipo_vector v, int tam);
float calcular_media(tipo_vector v,int n);
int calcular_moda(tipo_vector v,int n);
void leer_entero_rango(int a,int b,int *m);

int main()
{
    tipo_vector jornada;
    int n = 0, moda;
    float media;
    char c;
    do{ system("cls");
        printf("Estadisticos sobre partidos\n");
        printf("===================================\n\n");
        leer_vector(jornada,&n);
        media=calcular_media(jornada,n);
        moda=calcular_moda(jornada,n);
        //escribir_vector(jornada,n);
        printf("\n\n la media es: %f y la moda es %d: ", media, moda);

        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while(c!='N');
    return 0;
}
void leer_vector(tipo_vector v,int *n){
    int i;
    printf("Introduzca num. de datos:\n");
    leer_entero_rango(1,MAX,n);
    printf("Introduzca numero de goles: \n");
    for(i=0;i<*n;++i){
        printf("\t goles [%d]: ",i+1);
        leer_entero_rango(0,10,&v[i]);
        //scanf(" %d",&v[i]);
    }}

void leer_entero_rango(int a,int b,int *m){
    int aux;
    if(a>b){
        aux=a;
        a=b;
        b=aux;
    }
    do{    printf("\tIntroduzca entero [%d,%d]: ",a,b);
            scanf(" %d",m);
    }while((*m<a)||(*m>b));
}

float calcular_media(tipo_vector v,int n){
    int i;
    int suma;
    suma=0;
    for(i=0;i<n;++i)
        suma+=v[i];
    return(suma/n);
}



int calcular_moda(tipo_vector v,int n)
{
    int i, maximo, moda=0;
    int  frecuencia[ ] = {0,0,0,0,0,0,0,0,0,0};
    obtener_frecuencia(v, frecuencia, n);
    moda=v[0];
    maximo=0;

    for (i=0; i < 10; i++) {
        if (frecuencia[i] > maximo) {
           moda=i;
           maximo=frecuencia[i];
        }
    }
  return moda;
}

void obtener_frecuencia(tipo_vector v1, tipo_vector v2,int n)
{
    int i;
    for (i=0; i < n; i++) {
         v2[v1[i]]++;
    }
}

