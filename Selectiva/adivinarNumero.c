/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int n,r;

	do{	system("cls");
		printf("ADIVINAR NUMERO DE UN DIGITO\n");
		printf("============================\n\n");
		do{	printf("Introduzca P (par) o I (impar): ");
			c=toupper(getche());
			printf("\n");
		}while((c!='P')&&(c!='I'));
		do{	printf("Introduzca resto de division entre 5: ");
			scanf(" %d", &r);
		}while((r<0)||(r>=5));
		if(c=='P')
			if(r%2)
				n=r+5;
			else
				n=r;
		else
			if(r%2)
				n=r;
			else
				n=r+5;
		printf("\nEl numero es: %d", n);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
   return 0;
}
