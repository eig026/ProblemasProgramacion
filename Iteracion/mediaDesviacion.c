/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define FIN -99

int main(){
	char c;
	double t,suma,suma2,media,de;
	int n;

	do{	system("cls");
		printf("MEDIA Y DESVIACION ESTANDAR DE TEMPERATURAS\n");
		printf("===========================================\n\n");
		suma=0;
		suma2=0;
		n=0;
		do{	printf("Introduza temperatura [-50,+50](FIN=-99): ");
			scanf(" %lf", &t);
		}while (((t<-50)||(t>50))&&(t!=FIN));
		while(t!=FIN){
			n++;
			suma+=t;
			suma2+=t*t;
			do{	printf("Introduza temperatura [-50,+50](FIN=-99): ");
				scanf(" %lf", &t);
			}while (((t<-50)||(t>50))&&(t!=FIN));
		}
		if (n){
			media=suma/n;
			de=sqrt((suma2-n*media*media)/n);
			printf("\nTemperatura media:    %10.2f",media);
			printf("\nDesviacion estandar:  %10.2f",de);
			printf("\nNumero de datos:      %10d",n);
		}else
			printf("\nNingun dato valido");
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
