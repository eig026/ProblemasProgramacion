






/// se queda colgado arreglar

#include <stdio.h>

int primo(int num);
void leer_intervalo(int *inf,int *sup);
void buscar_primos(int a, int b);
void tipo_primo(int p1, int p2);

main()
{
  int a,b;
  leer_intervalo(&a,&b);
  buscar_primos(a,b);
  return 0;
}
int primo(int num){
int i,a;
a=0; 
for(i=1;i<=num;i++)
{ 
    if(num % i==0) // si num1 modulo de i es 0, incrementamos a en 1.
    a++;
}
return (a==2);
}

void buscar_primos(int a, int b){
int i,j;
i=a;
while (i<=b)
{
if (primo(i)) {
	 j=i+1;
	 while (j<=b & j!=i){
	   if (primo(j)) {
	   	tipo_primo(i,j);
	   	i=j;
	   }
		else j++;
	   }
      }
   else i++;
 }
}
void leer_intervalo(int *inf,int *sup){

    do{ printf("\nIntroduzca numero en para limite inferior: ");
           scanf(" %i",inf);
           printf("\nIntroduzca numero en para limite superior: ");
           scanf(" %i",sup);
          }while(*inf>=*sup);
}

void tipo_primo(int p1, int p2){
switch ( p2-p1 )
{
	case 2 : printf(" %i y %i son primos gemelos \n", p1, p2);    break; 
	case 4: printf(" %i y %i son primos primos \n",  p1, p2);     break; 
	case 6 :printf(" %i y %i son primos sexis\n",  p1, p2);       break; 
	default : printf(" %i y %i son primos sin una relacion especial \n", p1, p2);
	}
}
