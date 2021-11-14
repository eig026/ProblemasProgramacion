/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
/* calcularNumeroEnvases                           */
/* programa que calcula el numero mñinimo de        */
/* envases completos necesarios para n litros.     */
/* Envases disponibles: 50, 20, 10, 5, 2 y 1 litro */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char c;
    int n;      /* numero de litros a envasar    */
    int n50;    /* num. de envases de 50 litros  */
    int n20;    /* num. de envases de 20 litros  */
    int n10;    /* num. de envases de 10 litros  */
    int n5;     /* num. de envases de 5 litros   */
    int n2;     /* num. de envases de 2 litros   */
    int n1;     /* num. de envases de 1 litros   */
    int resto;  /* resto de divisiones sucesivas */

    do{ 
        printf("CALCULO DEL NUMERO MINIMO DE ENVASES\n");
        printf("====================================\n\n");
        printf("Introduzca num. de litros a envasar: ");
        scanf(" %d", &n);
        n50=n/50;
        resto=n%50;
        n20=resto/20;
        resto=resto%20;
        n10=resto/10;
        resto=resto%10;
        n5=resto/5;
        resto=resto%5;
        n2=resto/2;
        n1=resto%2;
        printf("\nNumero de envases necesarios:\n");
        printf("\tEnvases de 50 litros: %4d\n",n50);
        printf("\tEnvases de 20 litros: %4d\n",n20);
        printf("\tEnvases de 10 litros: %4d\n",n10);
        printf("\tEnvases de  5 litros: %4d\n",n5);
        printf("\tEnvases de  2 litros: %4d\n",n2);
        printf("\tEnvases de  1 litro:  %4d\n",n1);
	    printf("\nDesea efectuar una nueva operacion (S/N)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
    return 0;
}