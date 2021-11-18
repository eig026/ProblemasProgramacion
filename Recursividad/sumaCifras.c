#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int suma1digitos(int n);
int suma2digitos(int n);

int main(){
	char c;
	int n;

	do{ 	      system("cls||clear");
			printf("SUMA DE DIGITOS NUMERO ENTERO\n");
			printf("=============================\n\n");
			do{	printf("Introduzca numero entero positivo: ");
					scanf(" %d", &n);
			}while(n<0);
			printf("\n\nSuma digitos (version recursiva):    %d",suma1digitos(n));
			printf("\n\nSuma digitos (version no recursiva): %d",suma2digitos(n));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

int suma1digitos(int n){
	if(n<10)
		return(n);
	else return(n%10+suma1digitos(n/10));
}

int suma2digitos(int n){
	int suma;

	suma=0;
	while(n>0){
		suma+=n%10;
		n=n/10;
	}
   return(suma);
}
