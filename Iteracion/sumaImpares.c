/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

*  */



#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int i,n;
	float suma;

	do{ 	//clrscr();
			printf("SUMA DE NUMEROS IMPARES ENTRE 0 y 1000\n");
			printf("======================================\n\n");
			do{	printf("Introduzca limite superior: ");
					scanf(" %d", &n);
			}while(n<0);
			i=1;
			suma=0;
			while(i<=n){
				if (!(i%3))
					suma+=i;
				i+=2;
			}
         printf("\nLa suma vale: %.0f",suma);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
   return 0;
}
