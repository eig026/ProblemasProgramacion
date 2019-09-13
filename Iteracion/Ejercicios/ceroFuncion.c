/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

int main(){
	double a,b,xm;
	double xizq,xder,yizq,yder,ymed;
	double prec;
	int i;

	do{	system("cls");
		printf("DETERMINACION DE UN CERO DE UNA FUNCION\n");
		printf("=======================================\n\n");
		do{	printf("Introduzca limites del intervalo:\n");
			printf("\ta: ");
			scanf(" %lf",&a);
			do{	printf("\tb: ");
				scanf(" %lf",&b);
			}while(b<a);
			yizq=a*a*a*a*a-a*a*a*a+a*a*a-3;
			yder=b*b*b*b*b-b*b*b*b+b*b*b-3;
		}while((yizq*yder>0)&&(a!=b));
		if(a!=b){
			if(yizq&&yder){
				do{	printf("Introduzca precision: ");
					scanf(" %lf",&prec);
				}while(prec<=0);
				xizq=a;
				xder=b;
				xm=(xizq+xder)/2.;
				i=1;
				ymed=xm*xm*xm*xm*xm-xm*xm*xm*xm+xm*xm*xm-3;
				while(ymed&&((xder-xizq)>=prec)){
					++i;
					if(yizq*ymed<0){
						xder=xm;
						yder=ymed;
					}else{
						if(yizq*ymed>0){
							xizq=xm;
							yizq=ymed;
						}
					}
					xm=(xizq+xder)/2;
					ymed=xm*xm*xm*xm*xm-xm*xm*xm*xm+xm*xm*xm-3;
				}
				printf("Raiz: %.15f\n\tf(x)=%.15f\n\tnº iteraciones: %d",xm,ymed,i);
			}else{	if(!yizq)
						printf("Raiz: %.15f",a);
					if(!yder)
						printf("Raiz: %.15f",b);
			}
		}
		printf("\n\nPulse una tecla para continuar");
		getch();
	}while (a!=b);
	return 0;
}
