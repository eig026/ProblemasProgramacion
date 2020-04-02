#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAXF  25
#define MAXC  60

/* Prototipos de funciones */
void dibujar_patron_rayas_diagonales(int nf,int nc,int d);

/* definiciones de funciones */
int main(){
	char c;
	int nf,nc,d;

	do{
			printf("PATRON DE RAYAS DIAGONALES\n");
			printf("==========================\n\n");
			do{  printf("Introduzca nº de filas: ");
				  scanf(" %d", &nf);
			}while((nf<=0)||(nf>MAXF));
			do{  printf("Introduzca nº de columnas: ");
				  scanf(" %d", &nc);
			}while((nf<=0)||(nf>MAXC));
			do{  printf("Introduzca separacion lineas: ");
				  scanf(" %d", &d);
			}while(d<0);
			dibujar_patron_rayas_diagonales(nf,nc,d);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void dibujar_patron_rayas_diagonales(int nf,int nc,int d){
	int i,j;
	int inc;


	if(d<0)
      d=0;
	i=1;
	inc=d+1;
	while(i<=nf){
		j=1;
		while(j<=nc){
			if((j+inc-1)%(d+1))
				printf(" ");
			else printf("*");
			++j;
		}
		++i;
		inc--;
		if(inc==0)  inc=d+1;
		printf("\n");
	}
}
