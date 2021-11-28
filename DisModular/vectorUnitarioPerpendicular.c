/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <ctype.h>
#include <math.h>

void leer_vector(float *x, float *y);
void normalizar(float *x, float *y);
float modulo(float x,float y);
void obtener_vector_perpendicular(float vx,float vy,float *ux,float *uy);
void escribir_resultados(float vx,float vy,float ux,float uy);
void escribir_vector(float x,float y);
float calcular_angulo(float vx,float vy,float ux,float uy);
float prod_escalar(float vx,float vy,float ux,float uy);

int main(){
	char c;
	float vx,vy,ux,uy;

	do{ 	      system("cls||clear");
			printf("VECTOR UNITARIO PERPENDICULAR\n");
			printf("=============================\n\n");
			printf("Introduzca vector:\n");
			leer_vector(&vx,&vy);
         printf("\nModulo: %.2f",modulo(vx,vy));
			normalizar(&vx,&vy);
			obtener_vector_perpendicular(vx,vy,&ux,&uy);
			escribir_resultados(vx,vy,ux,uy);
			getch();
			      system("cls||clear");
			printf("CALCULO DEL ANGULO ENTRE DOS VECTORES\n");
			printf("=====================================\n\n");
			printf("Introduzca primer vector:\n");
			leer_vector(&vx,&vy);
			printf("Introduzca segundo vector:\n");
			leer_vector(&ux,&uy);
			printf("\nEl angulo que forman es: %.2f",calcular_angulo(vx,vy,ux,uy));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_vector(float *x, float *y){
	do{ 	printf("\tx: ");
			scanf(" %f",x);
			printf("\ty: ");
			scanf(" %f",y);
	}while((*x==0)&&(*y==0));
}

void normalizar(float *x, float *y){
	float m;
	m=modulo(*x,*y);
	*x/=m;
	*y/=m;
}

void obtener_vector_perpendicular(float vx,float vy,float *ux,float *uy){
	*ux=-vy;
	*uy=vx;
}

float modulo(float x,float y){
	return(sqrt(x*x+y*y));
}

void escribir_resultados(float vx,float vy,float ux,float uy){
	printf("\nVector unitario misma direccion: ");
	escribir_vector(vx,vy);
	printf("\nVector unitario direccion perpendicular: ");
	escribir_vector(ux,uy);
}

void escribir_vector(float x,float y){
	printf("(%.2f,%.2f)",x,y);
}

float calcular_angulo(float vx,float vy,float ux,float uy){
	return(180*acos(prod_escalar(vx,vy,ux,uy)/(modulo(vx,vy)*modulo(ux,uy)))/M_PI);
}

float prod_escalar(float vx,float vy,float ux,float uy){
	return(vx*ux+vy*uy);
}
