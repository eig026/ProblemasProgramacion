/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

  Este programa realiza calculos aritmeticos sencillos con operandos enteros

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int a, b;
	char operacion, c;

	do{ system("cls");
		printf("Realizaremos una operacion aritmetica simple:\n\n");
		printf("Introduzca el primer valor con el que operar: ");
		scanf(" %d",&a);
		printf("Introduzca el segundo valor con el que operar: ");
		scanf(" %d",&b);
		printf("\n");
		printf("Introduzca + para sumar, - para restar o * para multiplicar: ");
		scanf(" %c",&operacion);
		switch(operacion){
        case '+':   printf("El resultado es: %d\n", a+b);
                    break;
        case '-':   printf("El resultado es: %d\n", a-b);
                    break;
        case '*':   printf("El resultado es: %d\n", a*b);
                    break;
        default:    printf("Operacion incorrecta\n");
                    break;
		}
	   	printf("\nDesea efectuar una nueva operacion (S/N)? ");
	   	c=toupper(getch());
	}while (c!='N');
    return 0;
}
