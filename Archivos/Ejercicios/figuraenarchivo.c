#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define MAX 20
#define NOMBRE "zz.txt"
int main(){
	char c;
	int n;
	int i,j;
	FILE *f;

	f=fopen(NOMBRE,"w");
	do{	system("cls");
		printf("FIGURAS: ROMBOS y TRIANGULOS\n");
		printf("============================\n\n");
		do{	printf("Introduzca numero positivo (0-%d): ",MAX);
			scanf(" %d",&n);
		}while((n<=0)||(n>=MAX));
		printf("\n\n");
		fprintf(f,"\n\n");
		if(n%2){
			for(i=1;i<=n;++i){
				for(j=1;j<=abs(n/2-i+1);++j){
					printf(" ");
					fprintf(f," ");
				}
				for(j=1;j<=(n/2+1-abs(n/2+1-i));++j){
					printf("* ");
					fprintf(f,"* ");
				}
				printf("\n");
				fprintf(f,"\n");
			}
		}else{
			for(i=1;i<=n;++i){
				for(j=1;j<=i;++j){
					printf("* ");
					fprintf(f,"* ");
				}
				printf("\n");
				fprintf(f,"\n");
			}
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	fclose(f);
	return 0;
}
