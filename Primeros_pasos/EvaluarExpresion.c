/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

  Calcular una expresion aritmetica sencilla

 */

#include <stdio.h>

int main(void){
    float resultado,x,y;

    //se escriben dos valores separados por la barra espaciadora
    printf("Introduzca los valores de x e y separados por un espacio en blanco \n");
    //se leen o capturan dos valores escritos en las variables x e y.
    scanf(" %f %f",&x,&y);
    //Se evalua la expresion y el resultado es asignado a la variable resultado.
    resultado=(x+y)/(2*y);
    //se imprime el valor de la variable resultado.
    printf("Resultado expresion: %f",resultado);
    return 0;
}