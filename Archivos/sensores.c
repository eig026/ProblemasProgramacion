#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 10
#define archivo "sensor.dat"

/* Nuevos tipos de datos */
typedef struct{
	short int dia, mes, anno;
}tipo_fecha;
typedef struct{
	short int hora, mn,sg;
}tipo_tiempo;
typedef float tipo_sensores[N];
typedef struct{
	tipo_fecha f;
	tipo_tiempo t;
	tipo_sensores s;
} tipo_reg;

/* prototipos de funciones */
void procesar_archivo(void);
void coeficiente_correlacion(void);
void recta_regresion(void);
void leer_registro(FILE *f,tipo_reg *reg);

int main(){
	char c;

	do{ 	system("cls");
			printf("MEDIDAS REGISTRADAS POR SENSORES\n");
			printf("================================\n\n");
			printf("1.- Obtener datos de sensor\n");
			printf("2.- Calcular coeficiente de correlacion\n");
			printf("3.- Calcular recta de regresion\n");
			printf("0.- Fin de ejecucion\n");
			printf("\t\tIntroduzca opcion: ");
			c=getch();
			printf("\n");
			switch(c){
			case '1': procesar_archivo();
						 break;
			case '2': coeficiente_correlacion();
						 break;
			case '3': recta_regresion();
						 break;
			case '0': printf("FIN DE EJECUCION");
						 getch();
						 break;
			default:	printf("\a");
						break;
			}
	}while (c!='0');
	return 0;
}

void procesar_archivo(void){
	tipo_reg reg;
	int i;
	long n;
	float suma,suma2,maximo,minimo;
	FILE *f;

	if ((f=fopen(archivo,"rb"))==NULL){
		printf("Error al abrir archivo: %s\n",archivo);
		getch();
	}else{	do{ printf("\nNum. de sensor a analizar: ");
					 scanf(" %d",&i);
				}while((i<1)||(i>N));
				i--;
				n=0;
				suma=0;
				suma2=0;
				/* Recorrido secuencial del archivo */
				//fread(&reg,sizeof(tipo_reg),1,f);
				leer_registro(f,&reg);
				minimo=1e30;
				maximo=-1e30;
				while (!feof(f)){
					n++;
					suma+=reg.s[i];
					suma2+=reg.s[i]*reg.s[i];
					if(reg.s[i]>maximo)
						maximo=reg.s[i];
					if(reg.s[i]<minimo)
						minimo=reg.s[i];
					//fread(&reg,sizeof(tipo_reg),1,f);
					leer_registro(f,&reg);
				}
				printf("\nSensor num. %d",i+1);
				printf("\nValor maximo: %10.1f",maximo);
				printf("\nValor minimo: %10.1f",minimo);
				printf("\nMedia aritmetica: %.1f", suma/n);
				printf("\nDesv. estandar:   %.1f", sqrt((suma2-suma*suma/n)/n));
				getch();
				fclose(f);
	}
}

void coeficiente_correlacion(void){
	tipo_reg reg;
	int i,j;
	long n;
	float sumax,sumax2,sumay,sumay2,sumaxy,r;
	FILE *f;

	if ((f=fopen(archivo,"rb"))==NULL){
		printf("Error al abrir archivo: %s\n",archivo);
		getch();
	}else{	do{ printf("\nNum. del primer sensor: ");
					 scanf(" %d",&i);
				}while((i<1)||(i>N));
				do{ printf("\nNum. del segundo sensor: ");
					 scanf(" %d",&j);
				}while((j<1)||(j>N)||(i==j));
				i--;
				j--;
				n=0;
				sumax=0;
				sumax2=0;
				sumay=0;
				sumay2=0;
				sumaxy=0;
				/* Recorrido secuencial del archivo */
				//fread(&reg,sizeof(tipo_reg),1,f);
				leer_registro(f,&reg);
				while (!feof(f)){
					n++;
					sumax+=reg.s[i];
					sumax2+=reg.s[i]*reg.s[i];
					sumay+=reg.s[j];
					sumay2+=reg.s[j]*reg.s[j];
					sumaxy+=reg.s[i]*reg.s[j];
					//fread(&reg,sizeof(tipo_reg),1,f);
					leer_registro(f,&reg);
				}
				r=(n*sumax2-sumax*sumax)*(n*sumay2-sumay*sumay);
				if(r)
					r=(n*sumaxy-sumax*sumay)/sqrt(r);
				else r=1;
				printf("\nCoeficiente de correlacion entre sensores %d y %d",i+1,j+1);
				printf("\nr:   %.4f", r);
				getch();
				fclose(f);
	}
}

void recta_regresion(void){
	tipo_reg reg;
	int i,j;
	long n;
	float sumax,sumax2,sumay,sumay2,sumaxy,a,b,xmed,ymed;
	FILE *f;

	if ((f=fopen(archivo,"rb"))==NULL){
		printf("Error al abrir archivo: %s\n",archivo);
		getch();
	}else{	do{ printf("\nNum. del primer sensor (y): ");
					 scanf(" %d",&i);
				}while((i<1)||(i>N));
				do{ printf("\nNum. del segundo sensor (x): ");
					 scanf(" %d",&j);
				}while((j<1)||(j>N)||(i==j));
				i--;
				j--;
				n=0;
				sumax=0;
				sumax2=0;
				sumay=0;
				sumay2=0;
				sumaxy=0;
				/* Recorrido secuencial del archivo */
				//fread(&reg,sizeof(tipo_reg),1,f);
				leer_registro(f,&reg);
				while (!feof(f)){
					n++;
					sumax+=reg.s[i];
					sumax2+=reg.s[i]*reg.s[i];
					sumay+=reg.s[j];
					sumay2+=reg.s[j]*reg.s[j];
					sumaxy+=reg.s[i]*reg.s[j];
					//fread(&reg,sizeof(tipo_reg),1,f);
					leer_registro(f,&reg);
				}
				if(n==0){
					printf("\nNingun dato registrado\n");
				}else{
					xmed=sumax/n;
					ymed=sumay/n;
					b=n*sumax2-sumax*sumax;
					if(b==0){
						printf("\nrecta de regresion entre sensores %d y %d",i+1,j+1);
						printf("\n\t x = %.2f\n",xmed);
					}else{
						b=(n*sumaxy-sumax*sumay)/b;
						a=ymed-b*xmed;
						printf("\nrecta de regresion entre sensores %d y %d",i+1,j+1);
						printf("\n\ty = %.2f ", a);
						if(b>0)
							printf("+ %.2f * x\n",b);
						else if (b<0)
								printf("- %.2f * x\n",-b);
					}
				}
				getch();
				fclose(f);
	}
}

void leer_registro(FILE *f,tipo_reg *reg){
	int i;
	fread(&reg->f.dia,2,1,f);
	fread(&reg->f.mes,2,1,f);
	fread(&reg->f.anno,2,1,f);
	fread(&reg->t.hora,2,1,f);
	fread(&reg->t.mn,2,1,f);
	fread(&reg->t.sg,2,1,f);
	for(i=0;i<N;++i){
		fread(&reg->s[i],4,1,f);
	}
}
