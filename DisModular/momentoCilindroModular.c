/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
   
 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

float momento_inercia(float m, float a, float b, float h, char eje);

int main(){
	char c;
	float m,a,b,h;

	do{ 	      system("cls||clear");
			printf("MOMENTO DE INERCIA DE UN CILINDRO HUECO\n");
			printf("=======================================\n\n");
			do{ printf("Introduzca masa (kg): ");
					scanf(" %f",&m);
			}while(m<=0);
			do{ printf("Introduzca radio exterior (m): ");
					scanf(" %f",&a);
			}while(a<=0);
			do{ printf("Introduzca radio interior (m): ");
					scanf(" %f",&b);
			}while(b<=0);
			do{ printf("Introduzca altura (m): ");
					scanf(" %f",&h);
			}while(h<=0);
			do{ 	printf("Introduzca Eje de rotacion:\n");
					printf("\tC  Eje principal del cilindro\n");
					printf("\tP  Eje perpendicular que atraviesa el centro de masas\n");
					printf("\tD  Eje que coincide con el diametro en un extremo\n");
					printf("\t\tIntroduzca opcion: ");
					c=toupper(getch());
			}while((c!='C')&&(c!='P')&&(c!='D'));
			printf("\n\nMomento de inercia= %.4f kg/m2",momento_inercia(m,a,b,h,c));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

float momento_inercia(float m, float a, float b, float h, char eje){
	float mom;

	switch(eje){
	case 'c':
	case 'C': 	mom=m*(a*a+b*b)/2;
					break;
	case 'p':
	case 'P': 	mom=m*(3*a*a+3*b*b+h*h)/12;
					break;
	case 'd':
	case 'D': 	mom=m*(3*a*a+3*b*b+4*h*h)/12;
					break;
	default: 	mom=0;
					break;
	}
   return mom;
}

