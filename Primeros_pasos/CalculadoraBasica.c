/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06

  Este programa realiza cálculos aritméticos sencillos con operandos enteros

 */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b;
	char operacion, c;

	do{ 
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
		scanf(" %c",&c);   
	
	}while ((c!='N') && (c!='n'));
    return 0;
}
