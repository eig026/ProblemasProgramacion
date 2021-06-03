#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
    char cc;
	double A,B,C,D; 	// Coeficientes ecuacion cubica
	double a,b,c;		// Coeficientes ecuacion forma normal
	double p,q;			// Coeficientes ecuación forma reducida
	double disc;		
	double z0,z1,z2;	// Raices ecuación reducida
	int n;				// Número de raices reales
	
    do{ system("cls");
        printf("ECUACION CUBICA: A*x3+B*x2+C*x+D=0\n");
        printf("==================================\n\n");
        /* Lectura de coeficientes de ecuación cúbica */
        printf("Introduzca coeficientes:\n");
        do{	printf("\tA: ");
        	scanf(" %lf",&A);
		}while(!A);
		printf("\tB: ");
		scanf(" %lf",&B);
		printf("\tC: ");
		scanf(" %lf",&C);
		printf("\tD: ");
		scanf(" %lf",&D);
		/* Conversion a forma normal: x3+a*x2+b*x+c=0 */
		a=B/A;
		b=C/A;
		c=D/A;
		/* Conversion a forma reducida: z3+p*z+q=0 */
		p=b-a*a/3;
		q=2*a*a*a/27-a*b/3+c;
		/* Resolución por el método de Cardano */
		disc=q*q+4*p*p*p/27;
		if(disc>0){
			n=1;
			if((-q+sqrt(disc))>=0){
				z0=pow((-q+sqrt(disc))/2,1.0/3.0);
			}else{
				z0=-pow((q-sqrt(disc))/2,1.0/3.0);
			}
			if((-q-sqrt(disc))>=0){
				z0+=pow((-q-sqrt(disc))/2,1.0/3.0);
			}else{
				z0-=pow((q+sqrt(disc))/2,1.0/3.0);
			}
		}else{
			if(disc==0){
				n=2;
				z0=3*q/p;
				z1=-3*q/(2*p);
			}else{
				n=3;
				z0=2*sqrt(-p/3)*cos((acos(-q/2*sqrt(-27/(p*p*p)))+
				                    2*0*M_PI)/3);
				z1=2*sqrt(-p/3)*cos((acos(-q/2*sqrt(-27/(p*p*p)))+
				                    2*1*M_PI)/3);
				z2=2*sqrt(-p/3)*cos((acos(-q/2*sqrt(-27/(p*p*p)))+
				                    2*2*M_PI)/3);
			}
		}
		/* Soluciones: x=z-a/3 */
		printf("\nSoluciones reales:\n");
		switch(n){
		case 1: printf("Una solucion real:\n");
				printf("\tx0=%.3f\n",z0-a/3);
				break;
		case 2: printf("Dos soluciones reales (una doble):\n");
				printf("\tx0=%.3f\n",z0-a/3);
				printf("\tx1=x2=%.3f\n",z1-a/3);
				break;
		case 3: printf("Tres soluciones reales:\n");
				printf("\tx0=%.3f\n",z0-a/3);
				printf("\tx1=%.3f\n",z1-a/3);
				printf("\tx2=%.3f\n",z2-a/3);
				break;
		}
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        cc=toupper(getch());
   }while (cc!='N');
   return 0;
}

