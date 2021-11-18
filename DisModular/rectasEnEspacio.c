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

/* Prototipos de funciones */
void leer_datos(double *x1,double *y1,double *z1,
					double *x2,double *y2,double *z2,
					double *x3,double *y3,double *z3,
					double *x4,double *y4,double *z4);
void leer_linea(double *x1,double *y1,double *z1,
					double *x2,double *y2,double *z2);
void leer_punto(double *x,double *y,double *z);
double calcular_distancia_minima(double x1,double y1,double z1,
						double x2,double y2,double z2,
						double x3,double y3,double z3,
						double x4,double y4,double z4,int *tipo);
void diferencia_vectores(double x2,double y2,double z2,
								double x1,double y1,double z1,
								double *ux,double *uy,double *uz);
void producto_vectorial(double ux,double uy,double uz,
								double vx,double vy,double vz,
								double *nx,double *ny,double *nz);
void constante_por_vector(double c,double *vx,double *vy,double *vz);
double producto_escalar(double x1,double y1,double z1,
								double x2,double y2,double z2);
double modulo(double x,double y,double z);
void escribir_resultados(double d,int tipo);
void escribir_tipo_rectas(int tipo);

int main(){
	char c;
	double x1,y1,z1;
	double x2,y2,z2;
	double x3,y3,z3;
	double x4,y4,z4;
   double d;
	int tipo;				/* 0: rectas coincidentes  1: rectas paralelas */
								/* 2: rectas secantes      3: rectas que se cruzan */

	do{ 	system("cls");
			printf("DISTANCIA MINIMA ENTRE DOS LINEAS RECTAS EN EL ESPACIO\n");
			printf("======================================================\n\n");
			leer_datos(&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4);
			d=calcular_distancia_minima(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,&tipo);
			escribir_resultados(d,tipo);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(double *x1,double *y1,double *z1,
					double *x2,double *y2,double *z2,
					double *x3,double *y3,double *z3,
					double *x4,double *y4,double *z4){
	printf("Introduzca extremos primera linea:\n");
	leer_linea(x1,y1,z1,x2,y2,z2);
	printf("Introduzca extremos segunda linea:\n");
	leer_linea(x3,y3,z3,x4,y4,z4);
}

void leer_linea(double *x1,double *y1,double *z1,
					double *x2,double *y2,double *z2){
	do{	printf("\tPrimer extremo:\n");
			leer_punto(x1,y1,z1);
			printf("\tSegundo extremo:\n");
			leer_punto(x2,y2,z2);
	}while((*x1==*x2)&&(*y1==*y2)&&(*z1==*z2));
}

void leer_punto(double *x,double *y,double *z){
	printf("\t\tx: ");
	scanf(" %lf", x);
	printf("\t\ty: ");
	scanf(" %lf", y);
	printf("\t\tz: ");
	scanf(" %lf", z);
}

double calcular_distancia_minima(double x1,double y1,double z1,
						double x2,double y2,double z2,
						double x3,double y3,double z3,
						double x4,double y4,double z4,int *tipo){
	double ux,uy,uz;
	double vx,vy,vz;
	double nx,ny,nz;		/* vector perpendicular a ambas rectas */
	double wx,wy,wz;
	double p,m,d;

	diferencia_vectores(x2,y2,z2,x1,y1,z1,&ux,&uy,&uz);
	diferencia_vectores(x4,y4,z4,x3,y3,z3,&vx,&vy,&vz);
	/* calcular vector perpendicular a ambas rectas */
	producto_vectorial(ux,uy,uz,vx,vy,vz,&nx,&ny,&nz);
	/* vector que une un punto de cada recta P1 y P3 */
	diferencia_vectores(x1,y1,z1,x3,y3,z3,&wx,&wy,&wz);
	/* Comprobacion rectas paralelas: el producto vectorial vale cero */
	if((nx==0)&&(ny==0)&&(nz==0)){
		p=producto_escalar(wx,wy,wz,vx,vy,vz);
		m=modulo(vx,vy,vz);
		constante_por_vector(p/(m*m),&vx,&vy,&vz);
		diferencia_vectores(wx,wy,wz,vx,vy,vz,&wx,&wy,&wz);
		d=modulo(wx,wy,wz);
		if(d>1e-15)	*tipo=1;
		else	*tipo=0;
	}else{	/* calcular distancia entre dos planos paralelos */
				d=fabs(producto_escalar(wx,wy,wz,nx,ny,nz)/modulo(nx,ny,nz));
				if(d>1e-15)	*tipo=3;
				else	*tipo=2;
	}
   return d;
}

void diferencia_vectores(double x2,double y2,double z2,
								double x1,double y1,double z1,
								double *ux,double *uy,double *uz){
	*ux=x2-x1;
	*uy=y2-y1;
	*uz=z2-z1;
}

void producto_vectorial(double ux,double uy,double uz,
								double vx,double vy,double vz,
								double *nx,double *ny,double *nz){
	*nx=uy*vz-uz*vy;
	*ny=uz*vx-ux*vz;
	*nz=ux*vy-uy*vx;
}

double producto_escalar(double x1,double y1,double z1,
								double x2,double y2,double z2){
	return(x1*x2+y1*y2+z1*z2);
}

void constante_por_vector(double c,double *vx,double *vy,double *vz){
	*vx=*vx*c;
	*vy=*vy*c;
	*vz=*vz*c;
}

double modulo(double x,double y,double z){
	return(sqrt(x*x+y*y+z*z));
}

void escribir_resultados(double d,int tipo){
	printf("\n\nDistancia minima: %.3f\n",d);
	escribir_tipo_rectas(tipo);
}

void escribir_tipo_rectas(int tipo){
	printf("Rectas ");
	switch (tipo){
	case 0:	printf("coincidentes");
				break;
	case 1:	printf("paralelas");
				break;
	case 2:	printf("secantes");
				break;
	case 3:	printf("que se cruzan");
				break;
	}
}
