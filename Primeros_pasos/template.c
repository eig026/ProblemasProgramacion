#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;

	do{  system("cls");
			printf("\n");
			printf("======\n\n");


			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			fflush(stdin);
			c=toupper(getchar());
	}while (c!='N');
	return 0;
}
