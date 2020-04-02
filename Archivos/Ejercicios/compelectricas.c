#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#define CLIENTES "clientes.dat"
#define LECTURAS "lecturas.dat"
#define CONSUMOS "consumos.txt"
#define ERRORES  "errores.txt"

/* Nuevos tipos de datos */
typedef char cadena12[12];
typedef struct{
	cadena12 nif;
	int num;
	float lectura;
}tipo_cliente;
typedef struct{
	int num;
	float lectura;
}tipo_lectura;

/* Prototipos de funciones */
void leer_cliente_archivo(FILE *f,tipo_cliente *cli);
void leer_lectura_archivo(FILE *f,tipo_lectura *lec);

/* Definiciones de funciones */

int main(){
	char c;
	FILE *f1,*f2,*f3,*f4;
	tipo_cliente cli;
	tipo_lectura lec;

	if((f1=fopen(CLIENTES,"rb"))==NULL){
		printf("Error al abrir archivo: %s",CLIENTES);
		getch();
		exit(1);
	}
	if((f2=fopen(LECTURAS,"rb"))==NULL){
		printf("Error al abrir archivo: %s",LECTURAS);
		getch();
		exit(1);
	}
	if((f3=fopen(CONSUMOS,"w"))==NULL){
		printf("Error al abrir archivo: %s",CONSUMOS);
		getch();
		exit(1);
	}
	if((f4=fopen(ERRORES,"w"))==NULL){
		printf("Error al abrir archivo: %s",ERRORES);
		getch();
		exit(1);
	}
	//fread(&cli,sizeof(cli),1,f1);
	leer_cliente_archivo(f1,&cli);
	//fread(&lec,sizeof(lec),1,f2);
	leer_lectura_archivo(f2,&lec);
	while((!feof(f1))&&(!feof(f2))){
		if(cli.num==lec.num){
			fprintf(f3,"%-12s  %10.0f kWh\n",cli.nif,lec.lectura-cli.lectura);
			//fread(&cli,sizeof(cli),1,f1);
			leer_cliente_archivo(f1,&cli);
			//fread(&lec,sizeof(lec),1,f2);
			leer_lectura_archivo(f2,&lec);
		}else{ if(cli.num<lec.num){
					fprintf(f3,"%-12s  %10.0f kWh\n",cli.nif,0.0);
					//fread(&cli,sizeof(cli),1,f1);
					leer_cliente_archivo(f1,&cli);
				 }else{ fprintf(f4,"%4ld\n",lec.num);
						 //fread(&lec,sizeof(lec),1,f2);
						 leer_lectura_archivo(f2,&lec);
				 }
		}
	}
	while(!feof(f1)){
		fprintf(f3,"%-12s  %10.0f kWh\n",cli.nif,0.0);
		//fread(&cli,sizeof(cli),1,f1);
		leer_cliente_archivo(f1,&cli);
	}
	while(!feof(f2)){
		fprintf(f4,"%4ld\n",lec.num);
		//fread(&lec,sizeof(lec),1,f2);
		leer_lectura_archivo(f2,&lec);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}

void leer_cliente_archivo(FILE *f,tipo_cliente *cli){
	fread(&cli->nif,sizeof(cli->nif),1,f);
	fread(&cli->num,sizeof(cli->num),1,f);
	fread(&cli->lectura,sizeof(cli->lectura),1,f);
}

void leer_lectura_archivo(FILE *f,tipo_lectura *lec){
	fread(&lec->num,sizeof(lec->num),1,f);
	fread(&lec->lectura,sizeof(lec->lectura),1,f);
}
