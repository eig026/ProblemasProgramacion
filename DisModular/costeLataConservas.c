/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Eléctrica, Electrónica Industrial, Mecánica y Química Industrial
 * @date 2021-02-06
 */



#include <stdio.h>
#include <ctype.h>
#include <math.h>

void leer_datos(double *h,double *d,double *phoj,double *ppro);
void leer_real_positivo(double *r);
void calcular_costes(double sup,double vol,double phoj,double ppro,double *crep,double *cpro);
double calcular_coste_recipiente(double sup,double phoj);
double superficie_cilindro(double h,double r);
double area_lateral(double h,double r);
double area_circulo(double r);
double calcular_coste_producto(double vol, double ppro);
double volumen_cilindro(double h,double r);
void escribir_resultados(double h,double d,double phoj,double ppro,
								 double sup,double vol,double crep,double cpro);
void escribir_dimensiones(double h,double d);
void escribir_costes_unitarios(double phoj,double ppro);
void escribir_coste_total(double sup, double vol,double crec,double cpro);

int main(){
	char c;
	double h,d,phoj,ppro,crep,cpro,sup,vol;

	do{ 	      system("cls||clear");
			printf("COSTE LATA DE CONSERVAS\n");
			printf("=======================\n\n");
			leer_datos(&h,&d,&phoj,&ppro);
			sup=superficie_cilindro(h,d/2);
			vol= volumen_cilindro(h,d/2);
			calcular_costes(sup,vol,phoj,ppro,&crep,&cpro);
			escribir_resultados(h,d,phoj,ppro,sup,vol,crep,cpro);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(double *h,double *d,double *phoj,double *ppro){
	printf("Altura de la lata (cm):\n");
	leer_real_positivo(h);
	printf("Diametro de la lata (cm):\n");
	leer_real_positivo(d);
	printf("Precio por cm2 de la hojalata:\n");
	leer_real_positivo(phoj);
	printf("Precio por cm3 del producto a envasar:\n");
	leer_real_positivo(ppro);
}

void leer_real_positivo(double *r){
	do{ 	printf("\tIntroduzca real positivo: ");
			scanf(" %lf", r);
	}while(*r<=0);
}

void calcular_costes(double sup,double vol,double phoj,double ppro,double *crep,double *cpro){
	*crep=calcular_coste_recipiente(sup,phoj);
	*cpro=calcular_coste_producto(vol,ppro);
}

double calcular_coste_recipiente(double sup,double phoj){
	return(sup*phoj);
}

double superficie_cilindro(double h,double r){
	return(area_lateral(h,r)+2*area_circulo(r));
}

double area_lateral(double h,double r){
	return(2*M_PI*r*h);
}

double area_circulo(double r){
	return(M_PI*r*r);
}

double calcular_coste_producto(double vol, double ppro){
	return(vol*ppro);
}

double volumen_cilindro(double h,double r){
	return(M_PI*r*r*h);
}

void escribir_resultados(double h,double d,double phoj,double ppro,
                         double sup,double vol,double crep,double cpro){
	escribir_dimensiones(h,d);
	escribir_costes_unitarios(phoj,ppro);
	escribir_coste_total(sup,vol,crep,cpro);
}

void escribir_dimensiones(double h,double d){
	printf("\nDimensiones lata:  Altura:   %10.2lf cm",h);
	printf("\n                   Diametro: %10.2lf cm",d);
}

void escribir_costes_unitarios(double phoj,double ppro){
	printf("\nCostes unitarios:  Hojalata: %10.3lf eu/cm2",phoj);
	printf("\n                   Producto: %10.3lf eu/cm3",ppro);
}

void escribir_coste_total(double sup,double vol,double crep,double cpro){
	printf("\nCoste Total:       Hojalata: %10.2lf cm2  %10.2lf eu",sup,crep);
	printf("\n                   Producto: %10.2lf cm3  %10.2lf eu",vol,cpro);
	printf("\n                                 Total:  %10.2f",crep+cpro);
}
