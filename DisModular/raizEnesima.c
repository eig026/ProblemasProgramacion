/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  
 
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define 	MAX 10 	/* Número máximo de cifras decimales	*/

void leer_entero_positivo(int *n);
void leer_entero_rango(int a,int b,int *m);
double potencia(double b,int e);
double calcular_raiz_n(double x,int n, int d);
void escribir_real(double x, int n);

int main(){
	char c;
	double x;
	int n,d;

	do{ 	      system("cls||clear");
			printf("RAIZ n-esima DE UN NUMERO REAL\n");
			printf("==============================\n\n");
			do{ 	printf("Introduzca un numero real positivo: ");
					scanf(" %lf", &x);
			}while(x<0);
			printf("Introduzca raiz a calcular (n):\n");
			leer_entero_positivo(&n);
			printf("Introduzca numero de decimales:\n");
			leer_entero_rango(0,MAX,&d);
			printf("\Raiz: %.10lf\n\n",calcular_raiz_n(x,n,d+1));
			escribir_real(calcular_raiz_n(x,n,d+1),d);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_entero_positivo(int *n){
	do{	printf("\tIntroduzca entero positivo: ");
			scanf(" %d",n);
	}while(*n<=0);
}

void leer_entero_rango(int a,int b,int *m){
	int aux;

	if(a>b){
		aux=a;
		a=b;
		b=aux;
	}
	do{	printf("\tIntroduzca entero [%d,%d]: ",a,b);
			scanf(" %d",m);
	}while((*m<a)||(*m>b));
}

double calcular_raiz_n(double x,int n, int d){
	double raiz;	/* raíz cuarta							*/
	double inc;		/* incremento del número			*/
	int i;			/* contador de iteraciones			*/

	raiz=0;
	i=0;
	inc=1;
	while(i<=d){
		 while(potencia(raiz,n)<x)
			raiz=raiz+inc;
		 if(potencia(raiz,n)>x)
			raiz=raiz-inc;
		 inc=inc/10;
		 ++i;
	}
	return(raiz);
}

double potencia(double b,int e){
	int i;
	double pot;

	if (b==0)
		if(e==0)
			pot=0;
		else 	if(e>0)
					pot=0;
				else pot=1e37;
	else{	pot=1;
			if(e<0){
				b=1/b;
				e=-e;
			}
			i=1;
			while(i<=e){
				pot=pot*b;
				i++;
			}
	}
	return pot;
}

void escribir_real(double x, int n){
	int i;
	double x2;

	if(n==0)
	  x+=0.5;
	x2=floor(x);
	printf("%.0lf",x2);
	if(n){
		printf(".");
		for(i=1;i<=n;++i){
			x=x-x2;
			x=x*10;
			if(i==n)
         	x+=0.5;
			x2=floor(x);
			printf("%.0lf",x2);
		}
	}
}