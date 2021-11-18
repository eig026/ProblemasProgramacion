#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 10

/* Nuevos tipos de datos */
typedef double tipo_vector[N];

/* prototipos de funciones */
void leer_vectores(tipo_vector vx,tipo_vector vy,int *n);
double interpolacion(tipo_vector vx,tipo_vector vy,int n,double x);
void construir_polinomio(tipo_vector vx,int n,double x,tipo_vector fi);
int encontrado(tipo_vector vx,int n,double x,int *pos);

int main(){
	char c;
	tipo_vector vx,vy;
	int n;
	double x,y;

	do{ 	      system("cls||clear");
			printf("INTERPOLACION LINEAL - FORMULA DE LAGRANGE\n");
			printf("==========================================\n\n");
			leer_vectores(vx,vy,&n);
			do{	do{   printf("Introduzca valor de x: ");
							scanf(" %lf",&x);
					}while((x<vx[0])||(x>vx[n-1]));
					y=interpolacion(vx,vy,n,x);
					printf("\nValor interpolado: %.10lf\n",y);
					printf("\n\nDesea interpolar un nuevo valor (s/n)? ");
					c=toupper(getch());
			}while (c!='N');
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_vectores(tipo_vector vx,tipo_vector vy,int *n){
	char c;
	double x,y;
	int i,pos;

	c='S';
	*n=0;
	while((*n<N)&&(c=='S')){
		do{ 	printf("\nIntroduzca valor de x: ");
				scanf(" %lf", &x);
		}while(encontrado(vx,*n,x,&pos));
		printf("Introduzca valor de y: ");
		scanf(" %lf", &y);
		for(i=*n;i>pos;--i){
			vx[i]=vx[i-1];
			vy[i]=vx[i-1];
		}
		vx[*n]=x;
		vy[*n]=y;
		(*n)++;
		if(*n<N){	printf("\nDesea introducir un nuevo punto (S/N): ");
						c=toupper(getch());
						printf("\n");
		}
	}
}

double interpolacion(tipo_vector vx,tipo_vector vy,int n,double x){
	tipo_vector fi;
	int i;
	double suma;

	construir_polinomio(vx,n,x,fi);
	suma=0;
	for(i=0;i<n;++i)
		suma+=fi[i]*vy[i];
	return suma;
}

void construir_polinomio(tipo_vector vx,int n,double x,tipo_vector fi){
	int i,j;

	for(i=0;i<n;++i){
		fi[i]=1;
		for(j=0;j<i;++j)
			fi[i]*=(x-vx[j])/(vx[i]-vx[j]);
		for(j=i+1;j<n;++j)
			fi[i]*=(x-vx[j])/(vx[i]-vx[j]);
	}
}

int encontrado(tipo_vector vx,int n,double x,int *pos){

	*pos=0;
	while((*pos<n)&&(vx[*pos]<x))
		++(*pos);
	return(*pos<n)&&(vx[*pos]==x);
}

