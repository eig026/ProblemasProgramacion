/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 20

void main()
{  char c;
	int i,j;

	do{ clrscr();
		 printf("DIVISORES DE LOS PRIMEROS 20 NUMEROS ENTEROS\n");
		 printf("============================================\n\n");
		 i=1;
		 while (i<=MAX){
			printf("\nDivisores de %-5d: ",i);
			j=1;
			while(j<=i){
				if(!(i%j))
					printf("%5d ",j);
				j++;
			}
			i++;
		 }
		 printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
       c=toupper(getch());
   }while (c!='N');
}
