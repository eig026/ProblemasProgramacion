/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
   
   
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

void cartesianas_esfericas(float x,float y,float z,
					float *r,float *fi,float *zeta);

int main(){
	char c;
	float x,y,z;
	float r, zeta, fi;

	do{ 	      system("cls||clear");
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
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void cartesianas_esfericas(float x,float y,float z,
					float *r,float *fi,float *zeta){
	float rxy;

	*r=sqrt(x*x+y*y+z*z);
	if(*r==0){
		*zeta=0;
		*fi=0;
	}else if((x==0)&&(y==0)){
				*zeta=acos(z/(*r));
				*fi=0;
			}else{
				if(z>=0)
					*zeta=acos(z/(*r));
				else *zeta=M_PI-acos(-z/(*r));
				rxy=sqrt(x*x+y*y);
				if(x>=0)
					*fi=asin(y/rxy);
				else *fi=M_PI-asin(y/rxy);
				if (*fi<0)
					*fi=2*M_PI+*fi;
			}
	*zeta=180*(*zeta)/M_PI;
	*fi=180*(*fi)/M_PI;
}