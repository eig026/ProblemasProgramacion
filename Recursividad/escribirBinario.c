#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void escribir_binario(int n);

int main(){
	char c;
   int n;

	do{ 	clrscr();
			printf("CONVERSION DECIMAL --> BINARIO\n");
			printf("==============================\n\n");
			do{	printf("Introduzca entero positivo: ");
					scanf(" %d",&n);
			}while(n<0);
			escribir_binario(n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void escribir_binario(int n){
	if(n<2)
		printf("%d",n);
	else{	escribir_binario(n/2);
			printf("%d",n%2);
	}
}

