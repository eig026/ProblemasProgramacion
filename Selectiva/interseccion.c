/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	double x1,y1,x2,y2,x3,y3,x4,y4;	// extremos de cada linea
	double u1,u2;				    // Ec. parametricas: x=x1+u*(x2-x1)  y=y1+u*(y2-y1)
	double a1,b1,c1,a2,b2,c2;	    //Coeficientes del sistema ecuaciones 2x2: a*x+b*y=c
	double aux;					    // Auxiliar para intercambiar dos valores


	do{ system("cls||clear");
		printf("INTERSECCION DE DOS SEGMENTOS RECTOS EN EL PLANO XY\n");
		printf("===================================================\n\n");
		printf("Introduzca extremos del primer segmento:\n");
		printf("\tPrimer extremo:\n");
		printf("\t\tx: ");
		scanf(" %lf",&x1);
		printf("\t\ty: ");
		scanf(" %lf",&y1);
		printf("\tSegundo extremo:\n");
		printf("\t\tx: ");
		scanf(" %lf",&x2);
		printf("\t\ty: ");
		scanf(" %lf",&y2);
		if((x1==x2)&&(y1==y2)){
			printf("Error: los extremos deben de ser diferentes\n");
		}else{
			printf("Introduzca extremos del segundo segmento:\n");
			printf("\tPrimer extremo:\n");
			printf("\t\tx: ");
			scanf(" %lf",&x3);
			printf("\t\ty: ");
			scanf(" %lf",&y3);
			printf("\tSegundo extremo:\n");
			printf("\t\tx: ");
			scanf(" %lf",&x4);
			printf("\t\ty: ");
			scanf(" %lf",&y4);
			if((x3==x4)&&(y3==y4)){
				printf("Error: los extremos deben de ser diferentes\n");
			}else{
				/* x=x1+(x2-x1)*u1=x1+a1*u1
				   y=y1+(y2-y1)*u1=y1+a2*u1
				   x=x3+(x4-x3)*u2=x3+b1*u2
				   y=y3+(y4-y3)*u2=y3+b2*u2 */
				a1=x2-x1;
				a2=y2-y1;
				b1=x4-x3;
				b2=y4-y3;
				/* Interseccion: sistema lineal de ecuaciones 2x2:
				   a1*u1-b1*u2=x3-x1
				   a2*u1-b2*u2=y3-y1 */
				c1=x3-x1;
				c2=y3-y1;
				if(a1*b2==b1*a2){
					if((a1*c2==a2*c1)&&(b1*c2==b2*c1)){
						printf("\nLas dos rectas son coincidentes:\n");
						/* u1,u2: parametros en la segunda recta de (x1,y1) y (x2,y2)  */
						if(b1){
							u1=-c1/b1;
							u2=(x2-x3)/b1;
						}else{
							u1=-c2/b2;
							u2=(y2-y3)/b2;
						}
						/* Ordenamos u1 y u2 */
						if(u1>u2){
							aux=u1;
							u1=u2;
							u2=aux;
						}
						/* Evaluamos todas las alternativas entre (u1,u2) y (0,1) */
						if(u2<=0){
							printf("No intersectan");
						}else {
							if(u2<1){
								if(u1<=0){
									printf("Segmento de solapamiento:\n");
									printf("(%.3f,%.3f) a (%.3f,%.3f)\n",
									        x3,y3,x3+u2*b1,y3+u2*b2);
								}else{
									printf("Segmento de solapamiento:\n");
									printf("(%.3f,%.3f) a (%.3f,%.3f)\n",
									        x3+u1*b1,y3+u1*b1,x3+u2*b2,y3+u2*b2);
								}
							}else{
								if(u1<=0){
									printf("Segmento de solapamiento:\n");
									printf("(%.3f,%.3f) a (%.3f,%.3f)\n",
									        x3,y3,x4,y4);
								}else{
									if(u1<1){
										printf("Segmento de solapamiento:\n");
										printf("(%.3f,%.3f) a (%.3f,%.3f)\n",
									        x3+u1*b1,y3+u1*b2,x4,y4);
									}else{
										printf("No intersectan");
									}
								}
							}
						}
					}else{
						printf("\nLas dos rectas son paralelas\n");
						printf("No hay punto de interseccion\n");
					}
				}else{ 	u1=(-c1*b2+c2*b1)/(-a1*b2+a2*b1);
						u2=(a1*c2-c1*a2)/(-a1*b2+a2*b1);
						printf("\nRectas secantes: ");
						if((0<u1)&&(u1<1)&&(0<u2)&&(u2<1)){
							printf("\nLos segmentos de linea se cortan:\n");
							printf("Punto de interseccion Segmento 1: (%.2f,%.2f)\n",x1+u1*a1,y1+u1*a2);
							printf("Punto de interseccion Segmento 2: (%.2f,%.2f)\n",x3+u2*b1,y3+u2*b2);
						}else{
							printf("\nLos segmentos de linea no se cortan");
						}
				}
			}
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
