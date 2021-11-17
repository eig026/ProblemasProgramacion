/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
    char c;
    double x,suma,p;
    int n,i;

    do{ system("cls||clear");
        printf("SUMA SERIE x-x**2/2+x**3/3-x**4/4...\n");
        printf("====================================\n\n");
        do{ printf("Introduzca valor de x (-1..+1): ");
            scanf(" %lf", &x);
        }while((x<=-1)||(x>=1));
        do{ printf("\nIntroduzca nº de sumandos: ");
            scanf(" %d",&n);
        }while(n<=0);
        suma=0;
        p=-1;
        i=1;
        while(i<=n){
                p*=(-x);
                suma+=p/i;
                ++i;
        }
        printf("\nSuma= %.15f\n", suma);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}
