/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa saludara al usuario incorporando su nombre y apellidos al saludo
 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

char ecuacion_segundo_grado(float a, float b, float c, float *x1,float *x2);

int main(){
	char c1;
	float a,b,c;	/* coeficientes polinomio		*/
	float x1,x2;	/* raices de la ecuacion		*/

	do{ 	      system("cls||clear");
			printf("SOLUCIONES ECUACION DE SEGUNDO GRADO: A*x*x+B*x+C=0\n");
			printf("===================================================\n\n");
			printf("Introduzca coeficiente de x*x: ");
			scanf(" %f",&a);
			printf("Introduzca coeficiente de x: ");
			scanf(" %f",&b);
			printf("Introduzca termino independiente: ");
			scanf(" %f",&c);
			printf("\n\n");
			c1=ecuacion_segundo_grado(a,b,c,&x1,&x2);
			switch(c1){
			case '-': 	printf("Imposible: %f=0",c);
							break;
			case '0': 	printf("Igualdad: 0=0",c);
							break;
			case '1': 	printf("Ecuacion primer grado: x=%f",x1);
							break;
			case 'I': 	printf("Raices imaginarias");
							break;
			case '2': 	printf("x1=%f\nx2=%f",x1,x2);
							break;
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c1=toupper(getch());
	}while (c1!='N');
	return 0;
}

char ecuacion_segundo_grado(float a, float b, float c, float *x1,float *x2){
	char c1;
	float d;			/* discriminante: b*b-4*a*c	*/

		 if(a==0)
			if(b==0)
				if(c==0)
					c1='0';
				else c1='-';
			else{ c1='1';
					*x1=*x2=-c/b;
			}
		 else{	d=b*b-4*a*c;
					if(d<0)
						c1='I';
					else{ *x1=(-b+sqrt(d))/(2*a);
							*x2=(-b-sqrt(d))/(2*a);
							c1='2';
					}
		 }
		 return c1;
}

