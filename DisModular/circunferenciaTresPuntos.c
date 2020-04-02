#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* Prototipos de funciones */
void leer_punto(double *x,double *y);
int puntos_iguales(double x1,double y1,double x2,double y2);
int puntos_colineales(double x1,double y1,double x2,double y2,double x3,double y3);
void prod_vectorial(double ax,double ay,double az,double bx,double by,double bz,
						double *cx,double *cy,double *cz);
void calcular_centro(double x1,double y1,double x2,double y2,
							double x3,double y3,double *xc,double *yc);
double calcular_radio(double xc, double yc, double x, double y);
void Escribir_resultados(double xc,double yc,double r);

int main(){
	char c;
	double x1,y1,x2,y2,x3,y3;		/* 3 puntos en el plano  */
	double xc,yc,r;					/* centro y radio de la circunferencia */

	do{ 	clrscr();
			printf("Radio y centro de una circunferencia que pasa por 3 puntos\n");
			printf("========================================================\n\n");
			do{	printf("Introduzca coordenadas del primer punto: \n");
					leer_punto(&x1,&y1);
					do{	printf("Introduzca coordenadas del segundo punto: \n");
							leer_punto(&x2,&y2);
					}while (puntos_iguales(x1,y1,x2,y2));
					do{	printf("Introduzca coordenadas del tercer punto: \n");
							leer_punto(&x3,&y3);
					}while (puntos_iguales(x1,y1,x3,y3)||puntos_iguales(x2,y2,x3,y3));
			}while (puntos_colineales(x1,y1,x2,y2,x3,y3));
			calcular_centro(x1,y1,x2,y2,x3,y3,&xc,&yc);
			r=calcular_radio(x1,y1,xc,yc);
			Escribir_resultados(xc,yc,r);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void leer_punto(double *x,double *y){
	printf("\tx: ");
	scanf(" %lf", x);
	printf("\ty: ");
	scanf(" %lf", y);
}

int puntos_iguales(double x1,double y1,double x2,double y2){
	if((x1==x2)&&(y1==y2))
		return 1;
	else return 0;
}

int puntos_colineales(double x1,double y1,double x2,double y2,double x3,double y3){
	double vx,vy,vz;

	prod_vectorial(x2-x1,y2-y1,0,x3-x1,y3-y1,0,&vx,&vy,&vz);
	if(vx||vy||vz)
		return 0;
	else return 1;
}

void prod_vectorial(double ax,double ay,double az,double bx,double by,double bz,
						double *cx,double *cy,double *cz){
	*cx=ay*bz-az*by;
	*cy=az*bx-ax*bz;
	*cz=ax*by-ay*bx;
}

void calcular_centro(double x1,double y1,double x2,double y2,
							double x3,double y3,double *xc,double *yc){
	*yc=((x1-x3)*(x1-x2)*(x2-x3)+(x1-x3)*(y1*y1-y2*y2)-(x1-x2)*(y1*y1-y3*y3))/
			(2*(x1-x3)*(y1-y2)-2*(x1-x2)*(y1-y3));
	*xc=((y1-y3)*(y1-y2)*(y2-y3)+(y1-y3)*(x1*x1-x2*x2)-(y1-y2)*(x1*x1-x3*x3))/
						(2*(y1-y3)*(x1-x2)-2*(y1-y2)*(x1-x3));
}

double calcular_radio(double xc, double yc, double x, double y){
	return(sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc)));
}

void Escribir_resultados(double xc,double yc,double r){
	printf("\n\nCircunferencia que pasa por esos tres puntos: \n");
	printf("\tCentro: (%.2f,%.2f)\n",xc,yc);
	printf("\tRadio: %.2f",r);
}

