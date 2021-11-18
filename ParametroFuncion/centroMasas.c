#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

/* prototipos de funciones */
void realizar_calculos(double (*f)(double x,double y),double ancho,
				double alto,double *m,double *xcm,double *ycm,
				double *ix,double *iy);
void escribir_resultados(char *n,double ancho,double alto,double m,
				double xcm,double ycm,double ix,double iy);
double densidad1(double x,double y);
double f_1(double x, double y);
double f_x(double x, double y);
double f_y(double x, double y);
double f_x_2(double x, double y);
double f_y_2(double x, double y);
double integral_doble(double (*f)(double x,double y),
							double (*g)(double x,double y),
							double xmin,double xmax,
							double ymin,double ymax,int m,int n);
double calcular_masa(double (*f)(double x,double y),double ancho,double alto);
double calcular_xcm(double (*f)(double x,double y),double ancho,double alto);
double calcular_ycm(double (*f)(double x,double y),double ancho,double alto);
double calcular_Ix(double (*f)(double x,double y),double ancho,double alto);
double calcular_Iy(double (*f)(double x,double y),double ancho,double alto);

int main(){
	char c;
	double alto,ancho;
	double masa,xcm,ycm,ix,iy;
	int m,n;

	do{ 	      system("cls||clear");
			printf("CALCULOS DE MASA, CENTRO DE MASA Y MOMENTOS DE INERCIA\n");
			printf("======================================================\n\n");
			printf("Introduzca medidas del rectangulo:\n");
			do{	printf("\tancho: ");
					scanf(" %lf",&ancho);
			}while(ancho<=0);
			do{	printf("\talto: ");
					scanf(" %lf",&alto);
			}while(alto<=0);
			/*do{	printf("N� de filas: ");
					scanf(" %d", &m);
			}while(m<=0);
			do{	printf("N� de columnas: ");
					scanf(" %d", &n);
			}while(n<=0);*/
			realizar_calculos(densidad1,ancho,alto,&masa,&xcm,&ycm,&ix,&iy);
			printf("\nPieza Ancho(m)  Alto(m)  Masa (Kg) (xcm,ycm)   Ix		Iy\n");
			escribir_resultados("A",ancho,alto,masa,xcm,ycm,ix,iy);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void realizar_calculos(double (*f)(double x,double y),double ancho,
				double alto,double *m,double *xcm,double *ycm,
				double *ix,double *iy){
	*m=calcular_masa(f,ancho,alto);
	*xcm=calcular_xcm(f,ancho,alto);
	*ycm=calcular_ycm(f,ancho,alto);
	*ix=calcular_Ix(f,ancho,alto);
	*iy=calcular_Iy(f,ancho,alto);
}

void escribir_resultados(char *n,double ancho,double alto,double m,
				double xcm,double ycm,double ix,double iy){
	printf("%-5s %8.2f %8.2f %8.2f (%.2f,%.2f) %8.2f %8.2f\n",
				n,ancho,alto,m,xcm,ycm,ix,iy);
}

double integral_doble(double (*f)(double x,double y),
							double (*g)(double x,double y),
							double xmin,double xmax,
							double ymin,double ymax,int m,int n){
	double vol;
	int i, j;
	double hx,hy;

	hx=(xmax-xmin)/m;
	hy=(ymax-ymin)/n;
	vol=0;
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			//vol+=f(xmin+(i+0.5)*hx,ymin+(j+0.5)*hy)*hx*hy;
			vol+=f(xmin+(i+0.5)*hx,ymin+(j+0.5)*hy)*g(xmin+(i+0.5)*hx,ymin+(j+0.5)*hy);
			//vol+=f(xmin+i*hx,ymin+j*hy)*hx*hy;
	//return vol;
	return vol*hx*hy;
}

double calcular_masa(double (*f)(double x,double y),double ancho,double alto){
	return integral_doble(f,f_1,0,ancho,0,alto,100,100);
}

double calcular_xcm(double (*f)(double x,double y),double ancho,double alto){
	return integral_doble(f,f_x,0,ancho,0,alto,100,100)/calcular_masa(f,ancho,alto);
}

double calcular_ycm(double (*f)(double x,double y),double ancho,double alto){
	return integral_doble(f,f_y,0,ancho,0,alto,100,100)/calcular_masa(f,ancho,alto);
}

double calcular_Ix(double (*f)(double x,double y),double ancho,double alto){
	return integral_doble(f,f_y_2,0,ancho,0,alto,100,100);
}

double calcular_Iy(double (*f)(double x,double y),double ancho,double alto){
	return integral_doble(f,f_x_2,0,ancho,0,alto,100,100);
}

double f_1(double x, double y){
	return (1.0);
}

double f_x(double x, double y){
	return (x);
}

double f_y(double x, double y){
	return (y);
}

double f_x_2(double x, double y){
	return (x*x);
}

double f_y_2(double x, double y){
	return (y*y);
}

double densidad1(double x,double y){
	//return(log(x+2*y));
	//return 1;
	//return 2/(x+y+1);
	//return (x*y+0.5);
	return (sin(1/sqrt(x*y)));
}

