/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*  */


#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(){
	char c;
	int i,j,n,max;

	do{
            system("cls||clear");
			printf("TRIANGULO DE NUMEROS\n");
			printf("====================\n\n");
			do{  printf("Introduzca nº de filas: ");
				  scanf(" %d", &n);
			}while((n<=0)||(n>25));
			max=n*(n+1)/2;
			for(i=1;i<=n;++i){
				for(j=1;j<=i;++j){
					printf("%5d",max);
					max--;
				}
            printf("\n");
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}
