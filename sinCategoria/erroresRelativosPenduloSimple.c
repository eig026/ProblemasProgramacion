/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06


 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define PI (4*atan(1))

double calcular_suma(double a, long int n);
double elongacion_maxima(double prec, double er);

FILE *f;

int main(){
	char c;
	double prec,er;

	f=fopen("zz.txt","w");
	do{ 	      system("cls||clear");
			printf("ERRORES RELATIVOS PERIODO OSCILACION PENDULO SIMPLE\n");
			printf("===================================================\n\n");
			do{  printf("Error relativo maximo: ");
					scanf(" %lf", &er);
			}while(er<=0);
			do{ 	printf("Precision: ");
					scanf(" %lf",&prec);
			}while(prec<=0);
			printf("\n\nLa maxima elongacion es: %.3f   Error relativo: %.5f", elongacion_maxima(prec,er),er);
			fprintf(f,"\n\nLa maxima elongacion es: %.3f   Error relativo: %.5f", elongacion_maxima(prec,er),er);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	fclose(f);
	return 0;
}

double elongacion_maxima(double prec, double er){
	long int i,j;
	double elo,error;

	printf("%4s"," ");
	fprintf(f,"%4s"," ");
	for(i=1;i<10000;i*=10){
		printf("%20d",i);
		fprintf(f,"%20d",i);
		}
	printf("\n");
   fprintf(f,"\n");
	elo=0;
	error=0;
	while(error<er){
		printf("%5.3f",elo);
		fprintf(f,"%5.3f",elo);
		for(j=1;j<10000;j*=10){
			printf("%20.15f",calcular_suma(elo*PI/180,j));
			fprintf(f,"%20.15f",calcular_suma(elo*PI/180,j));
		}
		printf("\n");
		fprintf(f,"\n");
		elo+=prec;
		error=calcular_suma(elo*PI/180,1000);
	}
	elo-=prec;
   return(elo);
}

double calcular_suma(double a, long int n){
	double suma;
	double x,y;
	long int i;

	suma=0;
	x=1;
	y=sin(a/2)*sin(a/2);
	for(i=1;i<=n;++i){
		x=x*(2.0*i-1)*(2.0*i-1)/(4.0*i*i)*y;
      suma+=x;
	}
   return(suma);
}

