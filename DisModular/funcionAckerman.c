#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void leer_entero_no_negativo(int *n);
int ackermann(int m, int n);

int main(){
	char c;
	int n,m;

	do{ 	      system("cls||clear");
			printf("FUNCION DE ACKERMANN A(m,n)\n");
			printf("=========================\n\n");
			printf("Introduzca valor de m:\n");
			leer_entero_no_negativo(&m);
			printf("\nIntroduzca valor de n:\n");
			leer_entero_no_negativo(&n);
			printf("\n\nAckermann(%d,%d) = %d",m,n,ackermann(m,n));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_entero_no_negativo(int *n){
	do{	printf("\tIntroduzca entero positivo: ");
			scanf(" %d",n);
	}while(*n<0);
}

int ackermann(int m, int n){
	if(m==0)
		return (n+1);
	else 	if (n==0)
				return(ackermann(m-1,1));
			else	return(ackermann(m-1,ackermann(m,n-1)));
}

