/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int i,j,n,max;

	do{
            system("cls");
			printf("TRIANGULO DE NUMEROS\n");
			printf("====================\n\n");
			do{  printf("Introduzca nº de filas: ");
				  scanf(" %d", &n);
			}while((n<=0)||(n>25));
			max=n*(n+1)/2;
			for(i=1;i<=n;++i){
				for(j=1;j<=i;++j){
					printf("%5d",max);
					max--;
				}
            printf("\n");
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}
