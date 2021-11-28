/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */
// Contar elementos duplicados de un  Arrays


#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef int tipo_vector[MAX];

int contar_duplicados(tipo_vector v,int n);
void leer_vector(tipo_vector v, int *n);

int main()
{
    tipo_vector arr1;
    int n, total=0;
       printf("\n\nContar el n�mero total de elementos duplicados en un array:\n");
       printf("---------------------------------------------------------\n");
       leer_vector(arr1,&n);
       total=contar_duplicados(arr1,n);
      printf("El numero total de elementos duplicados en el array es: %d \n", total);

}
void leer_vector(tipo_vector v,int *n){
    int i;
    printf("Introduzca num. de datos:\n");
    scanf(" %d",n);
    printf("Introduzca los datos de cada elemento del vector \n");
    for(i=0;i<*n;++i){
        printf("\t valor [%d]: ",i+1);
        scanf(" %d",&v[i]);
    }
}


void copiar_vector(tipo_vector v,tipo_vector vc, int n) {
    int i;
        for(i=0;i<n; i++)
            vc[i]=v[i];
}

contar_duplicados (tipo_vector v, int n)
{
    int i,j,mm,ctr;
    tipo_vector arr2,arr3;
    copiar_vector(v,arr2,n);

   for(i=0; i<n; i++)
      arr3[i]=0;

    for(i=0;i<n; i++)  {
        for(j=0;j<n;j++)  {
if(v[i]==arr2[j]) {
                arr3[j]=mm;
                mm++;
                }
            }
        mm=1;
    }
   ctr=0;
   for(i=0; i<n; i++)
      if(arr3[i]==2){ctr++;}
   return ctr;
}
