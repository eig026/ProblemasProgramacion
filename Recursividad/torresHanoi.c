#include <stdio.h>
#include <ctype.h>
#include <math.h>

void leer_entero_positivo(int *n);
void mover_discos(int n,char ori,char des, char aux);
void mover_un_disco(int n, char ori, char des);
void escribir_pivote(char c);

int main(){
	char c;
	int n;

	do{ 	      system("cls||clear");
			printf("TORRES DE HANOI\n");
			printf("===============\n\n");
			printf("Numero de discos:\n");
			leer_entero_positivo(&n);
			mover_discos(n,'i','d','c');
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_entero_positivo(int *n){
	do{	printf("\tIntroduzca entero positivo: ");
			scanf(" %d",n);
	}while(*n<=0);
}

void mover_discos(int n,char ori,char des, char aux){
	if(n==1)
		mover_un_disco(1, ori, des);
	else{	mover_discos(n-1,ori,aux,des);
			mover_un_disco(n,ori,des);
			mover_discos(n-1,aux,des,ori);
	}
}

void mover_un_disco(int n, char ori, char des){
	printf("\nMover disco nº %3d del pivote ",n);
	escribir_pivote(ori);
	printf(" al pivote ");
	escribir_pivote(des);
}

void escribir_pivote(char c){
	switch(c){
	case 'i':	printf("%10s","izquierdo");
					break;
	case 'd':	printf("%10s","derecho");
					break;
	case 'c':	printf("%10s","centro");
					break;
	}
}
