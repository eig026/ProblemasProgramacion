








#include <stdio.h>

int cubo(int base);
void cubopro(int base,int *resultado);

main()
{
  int numero;
  int resultado;
  
  // Utilizamos la funcion
  for(numero=1; numero<=5; numero++){
     printf("El cubo del numero %d es %d\n", numero, cubo(numero));
   }

   // Utilizamos el procedimiento
  for(numero=1; numero<=5; numero++){
     cubopro(numero,&resultado);
     printf("El cubo del numero %d es %d\n", numero, resultado);  
      
  }
return 0;
}

int cubo(int base)
{
    int potencia;
    potencia = base * base * base;
    return potencia;
}
void cubopro(int base,int *resultado)
{
    *resultado = base * base * base;
}
