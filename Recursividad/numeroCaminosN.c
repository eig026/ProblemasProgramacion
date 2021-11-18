#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int caminos_NE(int x1, int y1, int x2, int y2);

int main(){
	char c;
	int x1,y1,x2,y2;

	do{ 	      system("cls||clear");
			printf("NUMERO DE CAMINOS NORDESTE\n");
			printf("==========================\n\n");
			printf("Introduzca A (x1,y1): ");
			scanf(" %d,%d",&x1,&y1);
			printf("Introduzca B (x2,y2): ");
			scanf(" %d,%d",&x2,&y2);
			printf("Numero de caminos nordeste: %d",caminos_NE(x1,y1,x2,y2));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

int caminos_NE(int x1, int y1, int x2, int y2){
	if((x2<x1)||(y2<y1))
		return (0);
	else	if((x1==x2)&&(y1==y2))
				return 0;
			else	if((x1==x2)||(y1==y2))
						return(1);
					else	return(caminos_NE(x1+1,y1,x2,y2)+caminos_NE(x1,y1+1,x2,y2));
}

