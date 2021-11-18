#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

void leer_opcion(char *c);
void analisis(void);
void comparacion(void);
void subrogacion();
void leer_datos(double *c, int *na, char *tc,double *ia);
void leer_capital(double *c);
void leer_annos(int *na);
void leer_tipo_cuota(char *c);
void leer_interes(double *ia);
double cuota_plazo(double c, double i, int n);
int num_plazos_anno(char tc);
void tabla_amortizacion(double c,int na,char tc,double ia);
void cabecera(FILE *f,double c,double ia,int na,int n);
void resumen_anual(FILE *f,int j,double sumac,double sumai,double totalc,double totali);

int main(){
	char c;

	do{ 	      system("cls||clear");
			printf("ASESORAMIENTO PRESTAMOS HIPOTECARIOS\n");
			printf("====================================\n\n");
			leer_opcion(&c);
			switch(c){
			case '1':   analisis();
							break;
			case '2':   comparacion();
							break;
			case '3':   subrogacion();
							break;
			case '4':   printf("\n\nFIN EJECUCION");
							getch();
							break;
			default:    printf("\a");;
							break;
			}
	}while (c!='4');
	return 0;
}

void leer_opcion(char *c){
	printf("\t1.- Analisis y estudio prestamo\n");
	printf("\t2.- Estudio comparativo de dos ofertas de prestamos\n");
	printf("\t3.- Rentabilidad subrogacion de acreedor\n");
	printf("\t4.- Fin de ejecucion\n\n");
	printf("\t\t\tOpcion: ");
	*c=getch();
	printf("%c\n\n",*c);
}

void analisis(void){
	double c,ia;
	int na;
	char tc;

	      system("cls||clear");
	printf("Datos del prestamo:\n");
	printf("===================\n\n");
	leer_datos(&c,&na,&tc,&ia);
	tabla_amortizacion(c,na,tc,ia);
}

void comparacion(void){
}

void subrogacion(){
}

void leer_datos(double *c, int *na, char *tc,double *ia){
	leer_capital(c);
	leer_annos(na);
	leer_tipo_cuota(tc);
	leer_interes(ia);
}

void leer_capital(double *c){
	do{	printf("\tCapital: ");
			scanf(" %lf", c);
	}while(*c<=0);
}

void leer_annos(int *na){
	do{	printf("\tNumero de a�os: ");
			scanf(" %d", na);
	}while((*na<1)||(*na>50));
}

void leer_tipo_cuota(char *c){
	do{	printf("\tTipo de cuota: (A)nual, (S)emestral, (C)uatrimestral,\n");
			printf("\t              (T)rimestral, (M)ensual: ");
			scanf(" %c", c);
			*c=toupper(*c);
	}while((*c!='A')&&(*c!='S')&&(*c!='C')&&(*c!='T')&&(*c!='M'));
}

void leer_interes(double *ia){
	do{	printf("Tipo de interes anual (0-25%): ");
			scanf(" %lf",ia);
	}while((*ia<0)||(*ia>25));
}

double cuota_plazo(double c, double i, int n){
	double x;

	x=pow(1+i,n);
	return(c*i*x/(x-1));
}

int num_plazos_anno(char tc){
	int npa;

	switch(tc){
	case 'A':	npa=1;
					break;
	case 'S':	npa=2;
					break;
	case 'C':	npa=3;
					break;
	case 'T':	npa=4;
					break;
	case 'M':	npa=12;
					break;
	}
	return npa;
}

void tabla_amortizacion(double c,int na,char tc,double ia){
	double cuota,i;
	int npa,n;
	double cap_pen,cap_amo,int_amo;
	double sumac,sumai,totalc,totali;
	int j;
	FILE *f;

	f=fopen("xx.dat","a");
	if(f==NULL) exit(0);
	npa=num_plazos_anno(tc);
	i=ia/npa;
	i=i/100;
	n=na*npa;
	cuota=cuota_plazo(c,i,n);
	cabecera(f,c,ia,na,n);
	cap_pen=c;
	sumac=sumai=totalc=totali=0;
	for(j=1;j<=n;++j){
		int_amo=cap_pen*i;
		cap_amo=cuota-int_amo;
		cap_pen=cap_pen-cap_amo;
		sumac+=cap_amo;
		sumai+=int_amo;
		printf("%8d %10.2f %10.2f %10.2f %13.2f\n",j,cuota,cap_amo,int_amo,cap_pen);
		fprintf(f,"%8d %10.2f %10.2f %10.2f %13.2f\n",j,cuota,cap_amo,int_amo,cap_pen);
		if(j%npa==0){  totalc+=sumac;
							totali+=sumai;
							resumen_anual(f,j/npa,sumac,sumai,totalc,totali);
							sumac=sumai=0;
							getch();
							if(j!=n)
								cabecera(f,c,ia,na,n);
		}
	}
	getch();
	fclose(f);
}

void cabecera(FILE *f,double c,double ia,int na,int n){
	      system("cls||clear");
	printf("\t\tCapital:         %10.2f\n",c);
	printf("\t\tInteres anual:   %10.2f %%\n",ia);
	printf("\t\tNumero a�os:     %7d\n",na);
	printf("\t\tNumero plazos:   %7d\n\n",n);
	printf("N� plazo      Cuota  Cap_amort  Intereses Cap_pendiente\n");
	fprintf(f,"\t\tCapital:         %10.2f\n",c);
	fprintf(f,"\t\tInteres anual:   %10.2f %%\n",ia);
	fprintf(f,"\t\tNumero a�os:     %7d\n",na);
	fprintf(f,"\t\tNumero plazos:   %7d\n\n",n);
	fprintf(f,"N� plazo      Cuota  Cap_amort  Intereses Cap_pendiente\n");
}

void resumen_anual(FILE *f,int j,double sumac,double sumai,double totalc,double totali){
	printf("\n\tA�o n�: %d\n",j);
	printf("\t\tCapital amortizado: %10.2f\n",sumac);
	printf("\t\tintereses pagados:  %10.2f\n",sumai);
	printf("\tCapital total amortizado:   %10.2f\n",totalc);
	printf("\tIntereses totales pagados:  %10.2f\n",totali);
	fprintf(f,"\n\tA�o n�: %d\n",j);
	fprintf(f,"\t\tCapital amortizado: %10.2f\n",sumac);
	fprintf(f,"\t\tintereses pagados:  %10.2f\n",sumai);
	fprintf(f,"\tCapital total amortizado:   %10.2f\n",totalc);
	fprintf(f,"\tIntereses totales pagados:  %10.2f\n",totali);
}

