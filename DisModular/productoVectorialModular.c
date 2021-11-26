/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  * Programa que calcula: D=A^(B^C)
 */
  

#include <stdio.h>
#include <ctype.h>
#include <math.h>

void leer_datos(float *ax, float *ay, float *az,
					 float *bx, float *by, float *bz,
					 float *cx, float *cy, float *cz);
void leer_vector(float *vx, float *vy, float *vz);
void calcular_expresion(float ax, float ay, float az,
								float bx, float by, float bz,
								float cx, float cy, float cz,
								float *dx, float *dy, float *dz);
void prod_vectorial(float ax, float ay, float az,
						  float bx, float by, float bz,
						  float *cx, float *cy, float *cz);
void escribir_resultados(float vx, float vy, float vz);

int main(){
	char c;
	float ax,ay,az;
	float bx,by,bz;
	float cx,cy,cz;
	float dx,dy,dz;

	do{ 	      system("cls||clear");
			printf("CALCULO EXPRESION D=A^(B^C)\n");
			printf("===========================\n\n");
			leer_datos(&ax,&ay,&az,&bx,&by,&bz,&cx,&cy,&cz);
			calcular_expresion(ax,ay,az,bx,by,bz,cx,cy,cz,&dx,&dy,&dz);
			escribir_resultados(dx,dy,dz);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(float *ax, float *ay, float *az,
					 float *bx, float *by, float *bz,
					 float *cx, float *cy, float *cz){
	printf("\nIntroduzca vector A:\n");
	leer_vector(ax,ay,az);
	printf("\nIntroduzca vector B:\n");
	leer_vector(bx,by,bz);
	printf("\nIntroduzca vector C:\n");
	leer_vector(cx,cy,cz);
}

void leer_vector(float *vx, float *vy, float *vz){
	printf("\tx: ");
	scanf(" %f", vx);
	printf("\ty: ");
	scanf(" %f", vy);
	printf("\tz: ");
	scanf(" %f", vz);
}

void calcular_expresion(float ax, float ay, float az,
								float bx, float by, float bz,
								float cx, float cy, float cz,
								float *dx, float *dy, float *dz){
	float ex,ey,ez;

	prod_vectorial(bx,by,bz,cx,cy,cz,&ex,&ey,&ez);
	prod_vectorial(ax,ay,az,ex,ey,ez,dx,dy,dz);
}

void prod_vectorial(float ax, float ay, float az,
						  float bx, float by, float bz,
						  float *cx, float *cy, float *cz){
	*cx=ay*bz-az*by;
	*cy=az*bx-ax*bz;
	*cz=ax*by-ay*bx;
}

void escribir_resultados(float vx, float vy, float vz){
	printf("\nComponentes del vector D:\n");
	printf("\tx= %.1f\n",vx);
	printf("\ty= %.1f\n",vy);
	printf("\tz= %.1f\n",vz);
}
