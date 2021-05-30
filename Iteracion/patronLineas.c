#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAXF  25
#define MAXC  80

/* Diseño Detallado */
int main(){
	char c;
	int nf,nc,d;
  int i,j,inc;

	do{ 	system("cls");
			printf("PATRON DE RAYAS DIAGONALES\n");
			printf("==========================\n\n");
			do{  printf("Introduzca nº de filas: ");
				  scanf(" %d", &nf);
			}while((nf<=0)||(nf>MAXF));
			do{  printf("Introduzca nº de columnas: ");
				  scanf(" %d", &nc);
			}while((nc<=0)||(nc>MAXC));
			do{  printf("Introduzca separacion lineas: ");
				  scanf(" %d", &d);
			}while(d<0);

            system("cls");
            if(d<0)
                d=0;
            i=1;
            inc=0;
            while(i<=nf){
                j=1;
                while(j<=nc){
                    if((j-inc-1)%(d+1))
                        printf(" ");
                    else printf("*");
                    ++j;
                }
                ++i;
                inc++;
                if(inc==d+1)  inc=0;
                printf("\n");
            }
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
