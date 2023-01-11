/* Programa que graba datos sobre temperaturas registradas   */
/* a determinadas horas del dia en un archivo binario y que  */
/* permite leerlas del archivo y escribirlas en pantalla     */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define archivo "temperat.bin"

/* Definicion de nuevas tipologias */
typedef struct{
    short int hora;
    short int minuto;
    float temp;
}tipo_reg;

/* Prototipos de funciones */
void grabar_archivo_binario();
void leer_archivo_binario();
void grabar_registro_archivo(FILE *f, tipo_reg reg);
void leer_registro_archivo(FILE *f,tipo_reg *reg);

/* Definiciones de funciones */
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
        case '1': grabar_archivo_binario();
                  break;
        case '2': leer_archivo_binario();
                  break;
        case '3': break;
        default:  printf("\a");
                  break;
        }
    }while(c!='3');
    return 0;
}

void grabar_archivo_binario(){
    FILE *f;
    tipo_reg reg;
    char c='C';

    system("cls");
    printf("     Grabacion de datos en archivo de texto\n");
    printf("     ======================================\n\n");
    if((f=fopen(archivo,"rb"))!=NULL){
          printf("Ya existe el archivo: %s\n\n",archivo);
          printf("Seleccione opcion:\n\n");
          printf("\tC.- borrarlo y (C)rearlo de nuevo\n");
          printf("\tA.- (A)nadir informacion\n");
          printf("\tcualquier otra tecla para salir\n\n");
          printf("\t\tOpcion: ");
          c=toupper(getch());
          fclose(f);
          switch (c){
          case 'C': f=fopen(archivo,"wb");
                    break;
          case 'A': f=fopen(archivo,"ab");
                    break;
          default:  c='F';
                    break;
          }
    }else f=fopen(archivo,"wb");
    if(c!='F'){
          printf("\nIntroduccion de datos:");
          do{ do{ printf("\n\n\tIntroduzca la hora: ");
                  scanf(" %d", &reg.hora);
              }while((reg.hora<0)||(reg.hora>23));
              do{ printf("\tIntroduzca los minutos: ");
                  scanf(" %d", &reg.minuto);
              }while((reg.minuto<0)||(reg.minuto>59));
              do{ printf("\tIntroduzca la temperatura: ");
                  scanf(" %f", &reg.temp);
              }while((reg.temp<-100)||(reg.temp>100));
              grabar_registro_archivo(f,reg);
              printf("\nDesea introducir mas datos (S/N): ");
              c=toupper(getch());
          }while (c=='S');
          fclose(f);
    }
}

void leer_archivo_binario(){
    FILE *f;
    int i;
    tipo_reg reg;
    char c;

    system("cls");
    printf("Lectura de datos del archivo de texto\n");
    printf("=====================================\n\n");
    printf("Hora  Minuto     Temperatura\n");
    printf("----  ------     -----------\n");
    if((f=fopen(archivo,"rb"))==NULL){
           printf("No se encuentra el archivo: %s",archivo);
    }else{ i=0;
           leer_registro_archivo(f,&reg);
           while(!feof(f)){
               ++i;
               printf("%4d %7d %15.2f\n",reg.hora,reg.minuto,reg.temp);
               if(i%15==0){
                   printf("\nPulse cualquier tecla\n");
                   c=getch();
                   system("cls");
                   i=0;
               }
               leer_registro_archivo(f,&reg);
           }
           fclose(f);
    }
    printf("\nPulse cualquier tecla para continuar");
    c=getch();
}

void grabar_registro_archivo(FILE *f, tipo_reg reg){
    fwrite(&reg.hora,sizeof(short int),1,f);
    fwrite(&reg.minuto,sizeof(short int),1,f);
    fwrite(&reg.temp,sizeof(float),1,f);
}

void leer_registro_archivo(FILE *f,tipo_reg *reg){
    fread(&reg->hora,sizeof(short int),1,f);
    fread(&reg->minuto,sizeof(short int),1,f);
    fread(&reg->temp,sizeof(float),1,f);
}
