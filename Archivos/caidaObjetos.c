#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define g 9.81

int main(){
	char c;
	float inte,t,v,h,y;
	FILE *f;

	f=fopen("zz.z","w");
	do{ 	clrscr();
			printf("POSICION Y VELOCIDAD - CAIDA DE OBJETOS\n");
			printf("=======================================\n\n");
			do{	printf("Introduzca altura de caida (m): ");
					scanf(" %f",&h);
			}while(h<=0);
			do{	printf("Introduzca intervalo de tiempo (sg): ");
					scanf(" %f",&inte);
			}while(inte<=0);
			printf("\n");
			printf("%s %s %s\n","Tiempo(sg)","Posicion(y)","velocidad(m/s)");
			printf("%s %s %s\n","==========","===========","==============");
			fprintf(f,"\n");
			fprintf(f,"%s %s %s\n","Tiempo(sg)","Posicion(y)","velocidad(m/s)");
			fprintf(f,"%s %s %s\n","==========","===========","==============");
			t=0;
			y=h-g*t*t/2;
			v=g*t;
			while(y>=0){
				printf("%10.2f %11.2f %14.2f\n",t,y,v);
				fprintf(f,"%10.2f %11.2f %14.2f\n",t,y,v);
				t+=inte;
				y=h-g*t*t/2;
				v=g*t;
			}
			printf("\n");
			fprintf(f,"\n");
			t=sqrt(2*h/g);
			v=g*t;
			y=0;
			printf("%10.2f %11.2f %14.2f\n",t,y,v);
         fprintf(f,"%10.2f %11.2f %14.2f\n",t,y,v);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
   fclose(f);
	return 0;
}
