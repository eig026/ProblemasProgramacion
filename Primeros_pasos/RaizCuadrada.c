/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
 
  Este programa muestra el resultado de la ecuacion 3x^2 + 4y^2
 
 */

#include<stdio.h>
#include<math.h>

main(void)
{
  int x,y;
  float resultado;
  printf("ingrese el valor de x, tambien y \n");
  scanf("%d %d",&x,&y);
  resultado=sqrt(3*x*x+4*y*y);
  printf("%f",resultado);
}
