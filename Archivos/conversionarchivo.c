/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */




#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#define	archivo "notas"

/*** DISEÑO PRELIMINAR ***/
/* Nuevos tipos de datos */
typedef char cadena50[51];
typedef struct{
	cadena50 asig;
	float nota;
}tipo_calificacion;
typedef struct{
	cadena50 nombre;
	tipo_calificacion cali;
}tipo_alumno;

/* prototipos de funciones */
void anadir_binario(void);
void escribir_binario(void);
void bin_texto(void);
void leer_registro_archivo(FILE *f, tipo_alumno *a);
void escribir_registro_archivo(FILE *f, tipo_alumno *a);
void leer_cadena(char *cad, int n);

/*** DISEÑO DETALLADO ***/
/* Definiciones de funciones */
int main(){
	char c;

	/* Establecemos que vamos a usar caracteres locales */
	setlocale(LC_CTYPE,"Spanish");
	/* Para m�quinas Windows tambi�n hay que cambiar  */
	/* la p�gina de c�digos de la consola a la p�gina */
	/* de c�digos ANSI (1252), ya que por defecto se  */
	/* utiliza la p�gina de c�digos 437               */
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	do{ system("cls");
		printf("ARCHIVO BINARIO --> TEXTO\n");
		printf("=========================\n\n");
		printf("\t1.- A�adir registros al archivo binario\n");
		printf("\t2.- Leer registros archivo binario\n");
		printf("\t3.- Convertir binario en texto\n");
		printf("\t4.- Fin programa\n");
		printf("\n\t\tIntroduzca opcion: ");
        c=getch();
		switch(c){
		case '1': 	anadir_binario();
						break;
		case '2': 	escribir_binario();
						break;
		case '3': 	bin_texto();
						break;
		case '4': 	printf("\n\nFIN EJECUCION");
						break;
		default: 	printf("\a");
						break;
		}
	}while (c!='4');
	return 0;
}

void anadir_binario(void){
/* Funci�n para a�adir registros al archivo notas.bin */
	char c;
	FILE *f;
	tipo_alumno alu;
	cadena50 nombre;

	system("cls");
	printf("GRABACION DE REGISTROS\n");
	printf("======================\n");
	strcpy(nombre,archivo);
	strcat(nombre,".bin");
	if((f=fopen(nombre,"ab"))==NULL){
		printf("Error al abrir el archivo %s\n",nombre);
		exit(1);
	}else{	do{	printf("\nNombre: ");
				//scanf(" %[^\n]s",alu.nombre);
				leer_cadena(alu.nombre,50);
				printf("Asignatura: ");
				//scanf(" %[^\n]s",alu.cali.asig);
				leer_cadena(alu.cali.asig,50);
				printf("Nota: ");
				scanf(" %f",&alu.cali.nota);
				//fwrite(&alu,sizeof(tipo_alumno),1,f);
				escribir_registro_archivo(f,&alu);
				printf("\nMas registros (S/N)? ");
				c=toupper(getch());
			}while(c!='N');
			fclose(f);
	}
}

void escribir_binario(void){
/* Funci�n que lee el archivo binario notas.bin */
/* y lo imprime en pantalla registro a registro */
	FILE *f;
	tipo_alumno alu;
	cadena50 nombre;

	system("cls");
	printf("LECTURA DE REGISTROS\n");
	printf("======================\n\n");
	strcpy(nombre,archivo);
	strcat(nombre,".bin");
	if((f=fopen(nombre,"rb"))==NULL){
		printf("Error al abrir el archivo %s\n",nombre);
		exit(1);
	}else{  /* Recorrido secuencial del archivo */
			//fread(&alu,sizeof(tipo_alumno),1,f);
	        leer_registro_archivo(f,&alu);
			while(!feof(f)){
				printf("%-30.30s ",alu.nombre);
				printf("%-30.30s",alu.cali.asig);
				printf("%10.2f\n",alu.cali.nota);
				//fread(&alu,sizeof(tipo_alumno),1,f);
				leer_registro_archivo(f,&alu);
			}
			fclose(f);
	}
   getch();
}

void leer_registro_archivo(FILE *f, tipo_alumno *a){
     fread(a->nombre,sizeof(a->nombre),1,f);
     fread(a->cali.asig,sizeof(a->cali.asig),1,f);
     fread(&a->cali.nota,sizeof(float),1,f);
}

void escribir_registro_archivo(FILE *f, tipo_alumno *a){
     fwrite(a->nombre,sizeof(a->nombre),1,f);
     fwrite(a->cali.asig,sizeof(a->cali.asig),1,f);
     fwrite(&a->cali.nota,sizeof(float),1,f);
}

void bin_texto(void){
/* Funci�n que convierte el archivo binario notas.bin */
/* en un archivo de texto de nombre notas.txt         */
	FILE *f,*g;
	tipo_alumno alu;
	cadena50 nombre;

	system("cls");
	printf("LECTURA DE REGISTROS\n");
	printf("======================\n\n");
	strcpy(nombre,archivo);
	strcat(nombre,".bin");
	if((f=fopen(nombre,"rb"))==NULL){
		printf("Error al abrir el archivo %s\n",nombre);
		exit(1);
	}else{  strcpy(nombre,archivo);
			strcat(nombre,".txt");
			if((g=fopen(nombre,"w"))==NULL){
				printf("Error al abrir el archivo %s\n",nombre);
				exit(1);
			}else{
				/* Recorrido secuencial del archivo */
				//fread(&alu,sizeof(tipo_alumno),1,f);
				leer_registro_archivo(f,&alu);
				while(!feof(f)){
					fprintf(g,"%-30.30s ",alu.nombre);
					fprintf(g,"%-30.30s",alu.cali.asig);
					fprintf(g,"%10.2f\n",alu.cali.nota);
					//fread(&alu,sizeof(tipo_alumno),1,f);
					leer_registro_archivo(f,&alu);
				}
				fclose(g);
			}
			fclose(f);
	}
}

void leer_cadena(char *cad, int n){
/* lee por teclado y devuelve una cadena de hasta n caracteres */
/* Nota: la cadena debe preveer una posicion adicional para la */
/* marca fin de cadena (\0) --> tama�o minimo n+1 caracteres   */
    int i,fin;
    char c;

    i=0;
    fin=0;
    while((i<n)&&(!fin)){
        c=getch();
        switch(c){
        case '\r': fin=1;
                   printf("\n");
                   break;
        case '\b': if (i>0){
                     --i;
                     printf("\b \b");
                   }
                   break;
        default:   cad[i]=c;
                   ++i;
                   printf("%c",c);
                   break;
        }
    }
    cad[i]='\0';
    if (i==n) printf("\n");
}
