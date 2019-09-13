/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Genera el llll
 
 */

#include<stdio.h>
main(void)
{
    float resultado,x,w;
  
    //se escriben dos valores separados por la barra espaciadora
    printf("ingrese el valor de x , tambien de w \n");
  
    //se leen o capturan dos valores escritos en las variables x y w.
    scanf("%f;%f",&x,&w);
  
    //Se evalua la expresion y el resultado es asignado a la variable resultado.
    resultado=(x+w)/(2*w);
  
    //se imprime el valor de la variable resultado.
    printf("%f",resultado);
}
