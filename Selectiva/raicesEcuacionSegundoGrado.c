/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */
/* raicesEcuacionSegundoGrado                     */
/* programa que calcula e imprime en pantalla las */
/* soluciones de la ecuación: A*x*x+B*x+C=0       */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

int main(){
    char c1;
    float a,b,c;      /* coeficientes polinomio   */
    float d;		  /* discriminante: b*b-4*a*c */
    float x1,x2;      /* raices de la ecuacion    */

    do{ system("cls");
        printf("SOLUCIONES EC. SEGUNDO GRADO: A*x*x+B*x+C=0\n");
        printf("==========================================\n\n");
        printf("Introduzca coeficiente de x*x: ");
        scanf(" %f",&a);
        printf("Introduzca coeficiente de x: ");
        scanf(" %f",&b);
        printf("Introduzca termino independiente: ");
        scanf(" %f",&c);
        printf("\n\n");
        if(a==0)
            if(b==0)
                if(c==0)
                    printf("Igualdad 0=0");
                else printf("Imposible %f=0",c);
            else printf("Sol. ec. de primer grado: x=%f",-c/b);
        else{ d=b*b-4*a*c;
              if(d<0)
                  printf("Raices imaginarias");
              else{ x1=(-b+sqrt(d))/(2*a);
                    x2=(-b-sqrt(d))/(2*a);
                    printf("x1=%f\nx2=%f",x1,x2);
              }
        }
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c1=toupper(getch());
    }while (c1!='N');
    return 0;
}
