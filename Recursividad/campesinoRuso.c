#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int prod_camp_ruso(int a,int b){
	if (a==1){
		printf(" %5d  %5d  %5d\n",a,b,b);
		return (b);
	}else{	if(a%2){	printf(" %5d  %5d  %5d\n",a,b,b);
							return(b+prod_camp_ruso(a/2, 2*b));
				}else{	printf(" %5d  %5d \n",a,b);
							return(prod_camp_ruso(a/2, 2*b));
				}
	}
}

int prod_camp_ruso2(int a,int b){
	int suma;

	suma=0;
	while(a>=1){
		if(a%2)
			suma+=b;
		a=a/2;
		b=b*2;
	}
	return suma;
}

int main(){
	char c;
	int a,b;

	do{
			printf("METODO DE MULTIPLICACION DE NATURALES DEL CAMPESINO RUSO\n");
			printf("======================================================\n\n");
			do{	printf("Introduzca un numero: ");
					scanf(" %d", &a);
			}while(a<=0);
			do{	printf("Introduzca otro numero: ");
					scanf(" %d", &b);
			}while(b<=0);
			printf("    A      B      Sumandos\n");
			printf("Resultado:      %d",prod_camp_ruso(a,b));
			printf("\nEl producto vale: %d",prod_camp_ruso2(a,b));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}
