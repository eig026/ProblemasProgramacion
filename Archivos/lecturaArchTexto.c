/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */
/* Programa que graba datos sobre temperaturas registradas   */
/* a determinadas horas del dia en un archivo de texto y que */
/* permite leerlas del archivo y escribirlas en pantalla     */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define archivo "temperat.txt"

void grabar_datos_archivo_texto();
void leer_datos_archivo_texto();

int main(){
    char c;

    do{ system("cls");
        printf("\n       Menu de opciones:");
        printf("\n       =================\n");
        printf("\n1.- Grabar datos en archivo");
        printf("\n2.- Leer datos del archivo");
        printf("\n3.- Terminar");
        printf("\n\n\tIntroduzca opcion: ");
        c=getch();
        switch(c){
        case '1': grabar_datos_archivo_texto();
                  break;
        case '2': leer_datos_archivo_texto();
                  break;
        case '3': break;
        default:  printf("\a");
                  break;
        }
    }while(c!='3');
    return 0;
}

void grabar_datos_archivo_texto(){
    FILE *f;
    int hora, minuto;
    float temp;
    char c='C';

    system("cls");
    printf("     Grabacion de datos en archivo de texto\n");
    printf("     ======================================\n\n");
    if((f=fopen(archivo,"r"))!=NULL){
          printf("Ya existe el archivo: %s\n\n",archivo);
          printf("Seleccione opcion:\n\n");
          printf("\tC.- borrarlo y (C)rearlo de nuevo\n");
          printf("\tA.- (A)nadir informacion\n");
          printf("\tcualquier otra tecla para salir\n\n");
          printf("\t\tOpcion: ");
          c=toupper(getch());
          fclose(f);
          switch (c){
          case 'C': f=fopen(archivo,"w");
                    break;
          case 'A': f=fopen(archivo,"a");
                    break;
          default:  c='F';
                    break;
          }
    }else f=fopen(archivo,"w");
    if(c!='F'){
          printf("\nIntroduccion de datos:");
          do{ do{ printf("\n\n\tIntroduzca la hora: ");
                  scanf(" %d", &hora);
              }while((hora<0)||(hora>23));
              do{ printf("\tIntroduzca los minutos: ");
                  scanf(" %d", &minuto);
              }while((minuto<0)||(minuto>59));
              do{ printf("\tIntroduzca la temperatura: ");
                  scanf(" %f", &temp);
              }while((temp<-100)||(temp>100));
              fprintf(f,"%5d %5d %15.2f\n",hora,minuto,temp);
              printf("\nDesea introducir mas datos (S/N): ");
              c=toupper(getch());
          }while (c=='S');
          fclose(f);
    }
}

void leer_datos_archivo_texto(){
    FILE *f;
    int hora, minuto, i;
    float temp;
    char c;

    system("cls");
    printf("Lectura de datos del archivo de texto\n");
    printf("=====================================\n\n");
    printf("Hora  Minuto     Temperatura\n");
    printf("----  ------     -----------\n");
    if((f=fopen(archivo,"r"))==NULL){
           printf("No se encuentra el archivo: %s",archivo);
    }else{ i=0;
           fscanf(f,"%d %d %f",&hora,&minuto,&temp);
           while(!feof(f)){
               ++i;
               printf("%4d %7d %15.2f\n",hora,minuto,temp);
               if(i%15==0){
                   printf("\nPulse cualquier tecla\n");
                   c=getch();
                   system("cls");
                   i=0;
               }
               fscanf(f,"%d %d %f",&hora,&minuto,&temp);
           }
           fclose(f);
    }
    printf("\nPulse cualquier tecla para continuar");
    c=getch();
}
