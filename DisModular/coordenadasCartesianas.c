/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa saludara al usuario incorporando su nombre y apellidos al saludo
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void cartesianas_esfericas(float x,float y,float z,
					float *r,float *fi,float *zeta);

int main(){
	char c;
	float x,y,z;
	float r, zeta, fi;

	do{	system("cls");
		printf("COORDENADAS CARTESIANAS --> ESFERICAS\n");
		printf("=====================================\n\n");
		printf("Introduzca coordenadas cartesianas:\n");
		printf("\tx: ");
		scanf(" %f", &x);
		printf("\ty: ");
		scanf(" %f", &y);
		printf("\tz: ");
		scanf(" %f", &z);
		cartesianas_esfericas(x,y,z,&r,&fi,&zeta);
		printf("\nCoordenadas esfericas:\n");
		printf("\tr=   %10.2f\n",r);
		printf("\tzeta=%10.2f\n",zeta);
		printf("\tfi=  %10.2f\n",fi);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

void cartesianas_esfericas(float x,float y,float z,
					float *r,float *fi,float *zeta){
	float rxy;

	*r=sqrt(x*x+y*y+z*z);
	if(*r==0){
		*zeta=0;
		*fi=0;
	}else{
		*zeta=acos(z/(*r));
		rxy=sqrt(x*x+y*y);
		if(rxy==0){
			*fi=0;
		}else{
			*fi=asin(y/rxy);
			if(x<0){
				*fi=M_PI-*fi;
			}
			if (*fi<0){
				*fi=2*M_PI+*fi;
			}
		}
		*zeta=180*(*zeta)/M_PI;
		*fi=180*(*fi)/M_PI;
	}
}
