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
#define FIN 2015

void leer_datos(int *d1,int *m1,int *a1,int *d2,int *m2,int *a2);
void leer_fecha(int *d,int *m,int *a);
int dias_mes(int a,int m);
int es_bisiesto(int a);
long calcular_dias_entre_fechas(int d1,int m1,int a1,int d2,int m2,int a2);
long calcular_dias(int d,int m,int a);
void escribir_resultados(int d1,int m1,int a1,int d2,int m2,int a2,long n);
void escribir_fecha(int d,int m,int a);
void escribir_mes(int m);

int main(){
	char c;
	int d1,m1,a1;
	int d2,m2,a2;
	long n;

	do{ 	system("cls");
			printf("Nº DE DIAS ENTRE DOS FECHAS\n");
			printf("===========================\n\n");
			leer_datos(&d1,&m1,&a1,&d2,&m2,&a2);
			n=calcular_dias_entre_fechas(d1,m1,a1,d2,m2,a2);
			escribir_resultados(d1,m1,a1,d2,m2,a2,n);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(int *d1,int *m1,int *a1,int *d2,int *m2,int *a2){
	printf("Introduzca primera fecha:\n");
	leer_fecha(d1,m1,a1);
	printf("Introduzca segunda fecha:\n");
	leer_fecha(d2,m2,a2);
}

void leer_fecha(int *d,int *m,int *a){
	int n;
	do{ printf("\tIntroduzca dia: ");
		 scanf(" %d", d);
	}while((*d<1)||(*d>31));
	do{ printf("\tIntroduzca mes: ");
		 scanf(" %d",m);
	}while((*m<1)||(*m>12));
	do{  printf("\tIntroduzca año: ");
		  scanf(" %d", a);
	}while((*a<1)||(*a>FIN));
	n=dias_mes(*a,*m);
	while(*d>n){
		printf("Introduzca de nuevo el dia [1-%d]: ",n);
		scanf(" %d", d);
	}
}

int dias_mes(int a,int m){
	int n;
	switch(m){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: n=31;
				break;
	case 2:  if(es_bisiesto(a))
					n=29;
				else n=28;
            break;
	default: n=30;
				break;
	}
	return (n);
}

int es_bisiesto(int a) {
	int n;

	n=0;
	if((a%4)==0){
		if((a%100)==0){
			if((a%400)==0){
			  n=1;
			}
		}else n=1;
	}
	return (n);
}

long calcular_dias_entre_fechas(int d1,int m1,int a1,int d2,int m2,int a2){
	long n1,n2;

	n1=calcular_dias(d1,m1,a1);
	n2=calcular_dias(d2,m2,a2);
	return(n2-n1);
}

long calcular_dias(int d,int m,int a){
	int coc,resto;
	long n;
	int i;

	coc=(a-1)/4;
	resto=(a-1)%4;
	n=coc*(3l*365+366l)+resto*365l;
	n-=(a-1)/100;
   n+=(a-1)/400;
	for(i=1;i<m;++i)
		n+=dias_mes(a,i);
	n+=d;
	return n;
}

void escribir_resultados(int d1,int m1,int a1,int d2,int m2,int a2,long n){
	printf("\nFecha inicial: ");
	escribir_fecha(d1,m1,a1);
	printf("\nFecha final:   ");
	escribir_fecha(d2,m2,a2);
	printf("\nDias transcurridos: %ld\n",n);
}

void escribir_fecha(int d,int m,int a){
	printf("%d-",d);
	escribir_mes(m);
	printf("-%d",a);
}

void escribir_mes(int m){
	switch(m){
	case 1: printf("Enero");
			  break;
	case 2: printf("Febrero");
			  break;
	case 3: printf("Marzo");
			  break;
	case 4: printf("Abril");
			  break;
	case 5: printf("Mayo");
			  break;
	case 6: printf("Junio");
			  break;
	case 7: printf("Julio");
			  break;
	case 8: printf("Agosto");
			  break;
	case 9: printf("Septiembre");
			  break;
	case 10: printf("Octubre");
			  break;
	case 11: printf("Noviembre");
			  break;
	case 12: printf("Diciembre");
			  break;
	}
}
