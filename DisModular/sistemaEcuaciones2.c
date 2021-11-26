/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
 
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char sistema_lineal_2_ecuaciones(float a1, float b1, float c1,
									float a2, float b2, float c2,
									float *x,float *y);

int main(){
	char c;
	float a1,b1,c1;
	float a2,b2,c2;
	float x,y;

	do{	system("cls");
		printf("SISTEMA LINEAL DE 2 ECUACIONES CON 2 INCOGNITAS: \n");
		printf("       a1*x+b1*y+c1=0\n");
		printf("       a2*x+b2*y+c2=0\n");
		printf("================================================\n\n");
		printf("Introduzca coeficiente a1: ");
		scanf(" %f",&a1);
		printf("Introduzca coeficiente b1: ");
		scanf(" %f",&b1);
		printf("Introduzca termino independiente c1: ");
		scanf(" %f",&c1);
		printf("Introduzca coeficiente a2: ");
		scanf(" %f",&a2);
		printf("Introduzca coeficiente b2: ");
		scanf(" %f",&b2);
		printf("Introduzca termino independiente c2: ");
		scanf(" %f",&c2);
		printf("\n\n");
		c=sistema_lineal_2_ecuaciones(a1,b1,c1,a2,b2,c2,&x,&y);
		switch(c){
		case 'M':	printf("Sistema compatible indeterminado");
					break;
		case 'I': 	printf("Sistema incompatible");
					break;
		case 'C': 	printf("x=%f\ny=%f",x,y);
					break;
		case '0':	printf("Igualdades 0=0");
					break;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}

char sistema_lineal_2_ecuaciones(float a1, float b1, float c1,
									float a2, float b2, float c2,
									float *x,float *y){

	char c;
	float d;  /* determinante matriz de coeficientes: a1*b2-a2*b1 	*/

	d=a1*b2-a2*b1;
	if(d){
		*x=(-c1*b2+c2*b1)/d;
		*y=(-c2*a1+c1*a2)/d;
		c='C';
	}else{
		if(a1||b1||a2||b2){
			if((-a1*c2+a2*c1)||(-b1*c2+b2*c1)){
				c='I';
			}else{
				c='M';
			}
		}else{
			if(c1||c2){
				c='I';
			}else{
				c='0';
			}
		}
	}
	return c;
}
