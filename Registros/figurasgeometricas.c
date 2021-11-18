#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Nuevos tipos de datos */
typedef struct{
	char tipo;
	union{
		double radio;
		struct{
			double base;
			double altura;
		};
		struct{
			double lado1;
			double lado2;
			double lado3;
		};
	};
}tipo_figura;
/* prototipos de funciones */
void leer_figura(tipo_figura *fig);
double calcular_area(tipo_figura fig);
void leer_real_positivo(double *d);

int main(){
	char c;
	tipo_figura fig;

	do{ 	system("cls");
			printf("FIGURAS GEOMETRICAS\n");
			printf("===================\n\n");
			leer_figura(&fig);
			printf("\nEl area vale: %.2lf",calcular_area(fig));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_figura(tipo_figura *fig){
	char c;
	double l1,l2,l3;

	do{ printf("Seleccione figura: \n");
		 printf("\tC: circulo\n");
		 printf("\tR: rectangulo\n");
		 printf("\tT: triangulo\n");
		 printf("\t\tIntroduzca opcion: ");
		 c=toupper(getche());
       printf("\n");
	}while((c!='T')&&(c!='R')&&(c!='C'));
	fig->tipo=c;
	switch(c){
	case 'C': printf("Introduzca radio:\n");
				 leer_real_positivo(&fig->radio);
				 break;
	case 'R': printf("Introduzca base: \n");
				 leer_real_positivo(&fig->base);
				 printf("Introduzca altura:\n");
				 leer_real_positivo(&fig->altura);
				 break;
	case 'T': do{ 	 printf("Introduzca lado 1 :\n");
						 leer_real_positivo(&fig->lado1);
						 l1=fig->lado1;
						 printf("Introduzca lado 2 :\n");
						 leer_real_positivo(&fig->lado2);
						 l2=fig->lado2;
						 printf("Introduzca lado 3 :\n");
						 leer_real_positivo(&fig->lado3);
						 l3=fig->lado3;
				 }while((l1>=l2+l3)||(l2>=l1+l3)||(l3>=l1+l2));
				 break;
	}
}

void leer_real_positivo(double *d){
	do{ printf("\tIntroduzca real positivo: ");
		 scanf(" %lf", d);
	}while(*d<=0);
}

double calcular_area(tipo_figura fig){
	double s;

	switch(fig.tipo){
	case 'C': return(M_PI*fig.radio*fig.radio);
	case 'R': return(fig.base*fig.altura);
	case 'T': s=(fig.lado1+fig.lado2+fig.lado3)/2;
				 return sqrt(s*(s-fig.lado1)*(s-fig.lado2)*
								 (s-fig.lado3));
	default: return 0;
	}
}
