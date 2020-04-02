#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define g 9.81

int main(){
	char c;
	float v,ang,h,x;
	FILE *f;

	f=fopen("zz.dat","w");
	do{ 	clrscr();
			printf("ALCANCE Y ALTURA DE UN PROYECTIL\n");
			printf("================================\n\n");
			do{	printf("Introduzca velocidad inicial: ");
					scanf(" %f", &v);
			}while(v<=0);
			printf("\n");
			printf("%6s %10s %10s\n","Angulo","hmax","xmax");
			printf("%6s %10s %10s\n","======","====","====");
			fprintf(f,"\n");
			fprintf(f,"%6s %10s %10s\n","Angulo","hmax","xmax");
			fprintf(f,"%6s %10s %10s\n","======","====","====");
			ang=0;
			while(ang<=90){
				h=v*v*sin(M_PI*ang/180)*sin(M_PI*ang/180)/(2*g);
				x=v*v*sin(M_PI*ang/90)/g;
				printf("%6.0f %10.2f %10.2f\n",ang,h,x);
				fprintf(f,"%6.0f %10.2f %10.2f\n",ang,h,x);
				ang+=10;
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
   fclose(f);
	return 0;
}
