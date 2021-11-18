#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void leer_vector(float *x,float *y,float *z);
float producto_escalar(float ax,float ay,float az,float bx,float by,float bz);
void cte_por_vector(float c, float ax, float ay, float az,
							float *bx, float *by, float *bz);
void sumar_vectores(float ax,float ay,float az,float bx,float by,float bz,
							float *cx,float *cy,float *cz);
void escribir_vector(float x, float y, float z);

int main(){
	char c;
	float ax,ay,az,bx,by,bz,cx,cy,cz,dx,dy,dz;
	float c1,c2;

	do{ 	      system("cls||clear");
			printf("CALCULO D=B*(A.C)-C*(A.B)\n");
			printf("=========================\n\n");
			printf("Introduzca vector A:\n");
			leer_vector(&ax,&ay,&az);
			printf("Introduzca vector B:\n");
			leer_vector(&bx,&by,&bz);
			printf("Introduzca vector C:\n");
			leer_vector(&cx,&cy,&cz);
			c1=producto_escalar(ax,ay,az,cx,cy,cz);
			c2=producto_escalar(ax,ay,az,bx,by,bz);
			cte_por_vector(c1,bx,by,bz,&bx,&by,&bz);
			cte_por_vector(-c2,cx,cy,cz,&cx,&cy,&cz);
			sumar_vectores(bx,by,bz,cx,cy,cz,&dx,&dy,&dz);
			printf("\n\nD = ");
         escribir_vector(dx,dy,dz);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
           scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_vector(float *x,float *y,float *z){
	printf("\tx: ");
	scanf(" %f", x);
	printf("\ty: ");
	scanf(" %f", y);
	printf("\tz: ");
	scanf(" %f", z);
}

float producto_escalar(float ax,float ay,float az,float bx,float by,float bz){
	return(ax*bx+ay*by+az*bz);
}

void cte_por_vector(float c, float ax, float ay, float az,
							float *bx, float *by, float *bz){
	*bx=c*ax;
	*by=c*ay;
	*bz=c*az;
}

void sumar_vectores(float ax,float ay,float az,float bx,float by,float bz,
							float *cx,float *cy,float *cz){
	*cx=ax+bx;
	*cy=ay+by;
	*cz=az+bz;
}

void escribir_vector(float x, float y, float z){
	printf("(%.2f,%.2f,%.2f)",x,y,z);
}
