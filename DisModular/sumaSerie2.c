/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
    
 */


#include <stdio.h>
#include <ctype.h>
#include <math.h>

void leer_numero(double *x);
void leer_precision(double *error);
double calcular_suma(double x,double error);
void escrbir_resultado(double suma);

FILE *f;
int main(){
	char c;
	double x,suma,error;

	do{ 	      system("cls||clear");
			printf("SUMA SERIE x-x**2/2+x**3/3-x**4/4...\n");
			printf("====================================\n\n");
			leer_numero(&x);
			leer_precision(&error);
			suma=calcular_suma(x,error);
			escrbir_resultado(suma);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_numero(double *x){
	do{	printf("Introduzca valor de x (-1..+1): ");
			scanf(" %lf", x);
	}while((*x<=-1)||(*x>=1));
}

void leer_precision(double *error){
	do{	printf("Introduzca error: ");
			scanf(" %lf", error);
	}while(*error<=0);
}

double calcular_suma(double x,double error){
	double suma,p,term;
	int i;

	suma=0;
	p=x;
	i=1;
	term=p/i;
	while(fabs(term)>=error){
		suma+=term;
		p*=(-x);
		++i;
		term=p/i;
	}
	printf("\nSuma= %.15lf\n", suma);
	printf("(para n= %d)\n",i-1);
				f=fopen("zz.dat","a");
				fprintf(f,"x=%.1f   E=%f    S(x)=%.15f    n=%d\n",x,error,suma,i-1);
				fclose(f);
	return(suma);
}

void escrbir_resultado(double suma){
	printf("\nSuma= %.15f\n", suma);
}
