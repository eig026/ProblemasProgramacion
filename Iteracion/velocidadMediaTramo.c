/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float d,t,vm,vmax;
	int n,imax;
	float dtotal,ttotal,v;
	int i;

	do{	system("cls||clear");
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
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
