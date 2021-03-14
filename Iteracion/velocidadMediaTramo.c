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

int main(){
	char c;
	float d,t,vm,vmax;
	int n,imax;
	float dtotal,ttotal,v;
	int i;

	do{	system("cls");
		printf("VELOCIDAD MEDIA POR TRAMO\n");
		printf("=========================\n\n");
		do{	printf("Introduzca num. tramos trayectoria: ");
			scanf(" %d", &n);
		}while(n<=0);
		vmax=-1e38;
		i=1;
		dtotal=0;
		ttotal=0;
		while(i<=n){
			printf("Tramo %d:\n",i);
			do{	printf("\tDistancia recorrida (m): ");
				scanf(" %f",&d);
			}while(d<=0);
			do{	printf("\tTiempo empleado (sg): ");
				scanf(" %f",&t);
			}while(t<=0);
			v=d/t;
			if(v>vmax){
				vmax=v;
				imax=i;
			}
			dtotal+=d;
			ttotal+=t;
			i++;
		}
		vm=dtotal/ttotal;
		printf("\nVelocidad media trayectoria: %10.2f m/s\n",vm);
		printf("Tramo %d, velocidad maxima por tramo= %10.2f m/s",imax,vmax);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
