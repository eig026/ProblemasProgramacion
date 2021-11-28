/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define PREC 0.1	// Precisión del cálculo (cm)
#define AMIN 5.0	// Extremos a,b en tabla
#define AMAX 50.0
#define BMIN 5.0
#define BMAX 50.0
#define INC 5.0		// Incremento valores a, b en tabla

/* Diseño Preliminar */
/* Diseño de Datos */
/* Nuevos tipos de datos */

/* Interfaces entre módulos */
/* Prototipos de funciones */
double triangulo(double a,double b,double *x);

/* Diseño Detallado */
/* Definiciones de funciones */
int main(){
    char c;
    double a,b,x,area;

    do{  system("cls||clear");
        printf("TRIANGULO DE AREA MAXIMA\n");
        printf("========================\n");
        /* Pruebas ejercicio 2.1 */
      //  do{	//do{ printf("\nLongitud lado 1: ");
			//	scanf(" %lf",&a);
			//}while(a<=0);
			//do{ printf("Longitud lado 2: ");
			//	scanf(" %lf",&b);
			//}while(b<=0);
		//	area=triangulo(a,b,&x);
		//	printf("\nLongitud 3: %.2f\n",x);
//			printf("Area maxima:  %.2f\n",area);
	//		printf("\n\nDesea efectuar otra prueba (s/n)? ");
	//	    c=toupper(getch());
	//	}while (c!='N');
		/* Ejercicio 2.2 */
		system("cls");
		printf("TABLA DE VALORES\n");
		printf("================\n\n");
		printf("%5s","");
		for(a=AMIN;a<=AMAX;a+=INC){
			printf("%5.0f",a);
		}
		printf("\n");
		printf("%5s","");
		for(a=AMIN;a<=AMAX;a+=INC){
			printf("-----");
		}
		printf("\n");
		for(b=BMIN;b<=BMAX;b+=INC){
			printf("%4.0f|",b);
			for(a=AMIN;a<=AMAX;a+=INC){
				area=triangulo(a,b,&x);
				printf("%5.1f",x);
			}
			printf("\n");
		}
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
   return 0;
}

double triangulo(double a,double b,double *x){
/* y=area/perimetro */
	double y,ymax;
	double c;
	double s;

	ymax=0;
	c=fabs(b-a);
	while(c<=(b+a)){
		s=(a+b+c)/2.0;
		y=sqrt(s*(s-a)*(s-b)*(s-c))/(2*s);
		//printf("%.2f\n",y);
		if(y>ymax){
			ymax=y;
			*x=c;
		}
		c+=PREC;
	}
	return(ymax);
}
