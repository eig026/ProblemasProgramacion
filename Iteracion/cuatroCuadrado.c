/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
*  */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	int n,a,b,c,d;
	int amax,bmax,cmax,dmax;
	char cc;

	do{	system("cls");
		printf("TEOREMA DE LOS CUATRO CUADRADOS\n");
		printf("===============================\n\n");
		do{	printf("Introduzca un num. natural: ");
			scanf(" %d",&n);
		}while(n<=0);
		a=0;
		amax=sqrt(n);
		while(a<=amax){
			b=a;
			bmax=sqrt(n-a*a);
			while(b<=bmax){
				c=b;
				cmax=sqrt(n-a*a-b*b);
				while(c<=cmax){
					d=c;
					dmax=sqrt(n-a*a-b*b-c*c);
					while(d<=dmax){
						if(n==a*a+b*b+c*c+d*d){
							printf("%d=%d+%d+%d+%d\n",n,a*a,b*b,c*c,d*d);
						}
						++d;
					}
					++c;
				}
				++b;
			}
			++a;
		}
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		cc=toupper(getch());
	}while (cc!='N');
	return 0;
}
