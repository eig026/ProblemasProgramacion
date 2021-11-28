/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define g 9.81

int main(){
	char c;
	float v,ang,h,x;
	FILE *f;

	f=fopen("zz.dat","w");
	do{ 	      system("cls||clear");
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
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
   fclose(f);
	return 0;
}
