/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Prototipos de funciones */
void leer_real_intervalo(float a, float b, float *x);

/* Definiciones de funciones */
int main(){
    char c;
    float a,b,x;

    do{ system("cls");
        printf("LECTURA DE UN NUMERO REAL EN UN INTERVALO DADO\n");
        printf("==============================================\n\n");
        printf("Introduzca limites del intervalo: \n");
        printf("\tIzquierdo: ");
        scanf(" %f",&a);
        printf("\tDerecho: ");
        scanf(" %f",&b);
        leer_real_intervalo(a,b,&x);
        printf("\nNumero leido: %.2f",x);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        scanf(" %c",&c);  
    }while (c!='N');
    return 0;
}

void leer_real_intervalo(float a, float b, float *x){
    if(a==b)
          *x=a;
    else{ if(a>b){
               *x=a;
               a=b;
               b=*x;
          }
          do{ printf("\nIntroduzca numero en [%.0f,%.0f]: ",a,b);
              scanf(" %f",x);
          }while((*x<a)||(*x>b));
    }
}
