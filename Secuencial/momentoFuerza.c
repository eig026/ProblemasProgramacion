/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float ox,oy,oz,ax,ay,az,fx,fy,fz;
	float rx,ry,rz,mx,my,mz;
	float m;

	do{	system("cls");
		printf("MOMENTO DE UNA FUERZA\n");
		printf("=====================\n\n");
		printf("Introduzca componentes de la fuerza:\n");
		printf("\tFx: ");
		scanf(" %f",&fx);
		printf("\tFy: ");
		scanf(" %f",&fy);
		printf("\tFz: ");
		scanf(" %f",&fz);
		printf("Introduzca coordenadas del punto de aplicacion de la fuerza:\n");
		printf("\tAx: ");
		scanf(" %f",&ax);
		printf("\tAy: ");
		scanf(" %f",&ay);
		printf("\tAz: ");
		scanf(" %f",&az);
		printf("Introduzca coordenadas del punto respecto del cual se calcula el momento:\n");
		printf("\tOx: ");
		scanf(" %f",&ox);
		printf("\tOy: ");
		scanf(" %f",&oy);
		printf("\tOz: ");
		scanf(" %f",&oz);
		rx=ax-ox;
		ry=ay-oy;
		rz=az-oz;
		mx=ry*fz-rz*fy;
		my=rz*fx-rx*fz;
		mz=rx*fy-ry*fx;
		printf("\nEl momento vale: (%.0f,%.0f,%.0f)",mx,my,mz);
		m=sqrt(mx*mx+my*my+mz*mz);
		printf("\n\tModulo: %.2f",m);
		if(m)
			printf("\n\tVectorunitario: (%.2f,%.2f,%.2f)",mx/m,my/m,mz/m);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
