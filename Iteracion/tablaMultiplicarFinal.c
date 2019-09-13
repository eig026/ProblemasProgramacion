#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	int i,j;
	char c;

	do{	system("cls");
		printf("TABLA DE MULTIPLICAR\n");
		printf("====================\n\n");
		printf("%-3c |",'*');
		i=1;
		while(i<=9){
			printf("%3d",i);
			++i;
		}
		printf("\n");
		i=1;
		while(i<=32){
			printf("-");
			++i;
		}
		printf("\n");
		i=1;
		while(i<=9){
			printf("%3d |",i);
			j=1;
			while(j<i){
				printf("%3c",' ');
				++j;
			}
			j=i;
			while(j<=9){
				printf("%3d",i*j);
				++j;
			}
			printf("\n");
			++i;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
