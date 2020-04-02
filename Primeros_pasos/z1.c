#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;

	do{ 	clrscr();
			printf("\n");
			printf("======\n\n");

			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}