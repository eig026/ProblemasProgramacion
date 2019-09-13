#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	float ang;

	do{ 	clrscr();
			printf("ANGULO ENTRE 0 y 360 grados\n");
			printf("===========================\n\n");
			printf("Introduzca un angulo (grados): ");
			scanf(" %f",&ang);
			if(ang>=360)
				ang-=360*(int)(ang/360);
			else if(ang<0)
					ang+=360*(int)(fabs(ang)/360)+360;
			printf("\nAngulo (0-360): %.2f",ang);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
   return 0;
}