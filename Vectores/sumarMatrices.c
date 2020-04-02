#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define maxfila 5
#define maxcol  5

/* Nuevos tipos de datos */
typedef float tipo_matriz[maxfila][maxcol];

/* prototipos de funciones */
void leer_dimensiones(int *f, int *c);
void leer_matriz(tipo_matriz v, int f, int c);
void sumar_matrices(tipo_matriz a, tipo_matriz b, tipo_matriz c, int fil, int col);
void multiplicar_matrices(tipo_matriz a, tipo_matriz b, tipo_matriz c,
		int f1, int c1, int f2, int c2, int *f3, int *c3);
void escribir_operacion(tipo_matriz a, tipo_matriz b, tipo_matriz c,
		int f1, int c1, int f2, int c2, int f3, int c3, char cod);

int main(){
	char cc;
	tipo_matriz a,b,c;
	int f1,c1,f2,c2,f3,c3;

	do{ 	clrscr();
			printf("SUMA Y PRODUCTO DE MATRICES\n");
			printf("===========================\n\n");
			printf("Introduzca primera matriz: \n");
			leer_dimensiones(&f1,&c1);
			leer_matriz(a,f1,c1);
			printf("Introduzca segunda matriz: \n");
			leer_dimensiones(&f2,&c2);
			leer_matriz(b,f2,c2);
			if((f1==f2)&&(c1==c2)){
				sumar_matrices(a,b,c,f1,c1);
				printf("\nSuma de matrices:\n");
				escribir_operacion(a,b,c,f1,c1,f1,c1,f1,c1,'+');
			}else printf("\nNo se puede sumar dos matrices de dimensiones distintas\n");
			if(c1==f2){
				multiplicar_matrices(a,b,c,f1,c1,f2,c2,&f3,&c3);
            printf("\nProducto de matrices:\n");
				escribir_operacion(a,b,c,f1,c1,f2,c2,f3,c3,'*');
			}else printf("\nNo se puede multiplicar las dos matrices (cols1<>fil2\n");
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			cc=toupper(getch());
	}while (cc!='N');
	return 0;
}

void leer_dimensiones(int *f, int *c){
	do{	printf("\tNumero de filas (1-%d): ",maxfila);
			scanf(" %d", f);
	}while((*f<1)||(*f>maxfila));
	do{	printf("\tNumero de columnas (1-%d): ",maxcol);
			scanf(" %d", c);
	}while((*c<1)||(*c>maxcol));
}

void leer_matriz(tipo_matriz v, int f, int c){
	int i,j;
	for(i=0;i<f;++i)
		for(j=0;j<c;++j){
			printf("\t\tv[%d,%d]: ",i+1,j+1);
			scanf(" %f", &v[i][j]);
		}
}

void sumar_matrices(tipo_matriz a, tipo_matriz b, tipo_matriz c, int fil, int col){
	int i,j;
	for(i=0;i<fil;++i)
		for(j=0;j<col;++j)
			c[i][j]=a[i][j]+b[i][j];
}

void multiplicar_matrices(tipo_matriz a, tipo_matriz b, tipo_matriz c,
		int f1, int c1, int f2, int c2, int *f3, int *c3){
	int i,j,k;
	float suma;
	for(i=0;i<f1;++i)
		for(j=0;j<c2;++j){
			suma=0;
			for(k=0;k<c1;++k)
				suma+=a[i][k]*b[k][j];
			c[i][j]=suma;
		}
	*f3=f1;
	*c3=c2;
}

void escribir_operacion(tipo_matriz a, tipo_matriz b, tipo_matriz c,
		int f1, int c1, int f2, int c2, int f3, int c3, char cod){
	int i,j;
	FILE *f;

	f=fopen("xx.dat","w");
	i=0;
	while((i<f1)||(i<f2)){
		if(i<f1)
			for(j=0;j<c1;++j){
				printf("%5.0f",a[i][j]);
				fprintf(f,"%5.0f",a[i][j]);
			}
		else for(j=0;j<c1;++j){
				printf("     ");
				fprintf(f,"     ");
			  }
		if(i==f1/2){
			printf("  %c  ",cod);
			fprintf(f,"  %c  ",cod);
		}else{ printf("     ");
				 fprintf(f,"     ");
		}
		if(i<f2)
			for(j=0;j<c2;++j){
				printf("%5.0f",b[i][j]);
				fprintf(f,"%5.0f",b[i][j]);
			}
		else for(j=0;j<c2;++j){
				printf("     ");
				fprintf(f,"     ");
			  }
		if(i==f1/2){
			printf("  =  ");
			fprintf(f,"  =  ");
		}else{ printf("     ");
				 fprintf(f,"     ");
		}
		if(i<f3)
			for(j=0;j<c3;++j){
				printf("%5.0f",c[i][j]);
				fprintf(f,"%5.0f",c[i][j]);
			}
		printf("\n");
      fprintf(f,"\n");
		++i;
	}
	fclose(f);
}
