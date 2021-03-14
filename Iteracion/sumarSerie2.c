/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
    char c;
    double x,suma,p,term,error;
    int n,i;

    do{ system("cls");
        printf("SUMA SERIE x-x**2/2+x**3/3-x**4/4...\n");
        printf("====================================\n\n");
        do{ printf("Introduzca valor de x (-1..+1): ");
            scanf(" %lf", &x);
        }while((x<=-1)||(x>=1));
        do{ printf("Introduzca error: ");
            scanf(" %lf", &error);
        }while(error<=0);
        suma=0;
        p=x;
        i=1;
        term=p/i;
        while(fabs(term)>=error){
                suma+=term;
                p*=(-x);
                ++i;
                term=p/i;
        }
        printf("\nSuma= %.15f\n", suma);
        printf("(para n= %d)\n",i-1);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}
