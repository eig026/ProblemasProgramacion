#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 10

/* Nuevos tipos de datos */
typedef char cadena30[31];
typedef struct{
	cadena30 mat;
	cadena30 fab;
	float den;
	int dur;
	float rt;
	float me;
}tipo_prueba;
typedef tipo_prueba tipo_vector[MAX];
/* prototipos de funciones */
void introducir_prueba(tipo_vector v,int *n);
void listar_pruebas(tipo_vector v,int n);
void listar_fabricantes(tipo_vector v, int n);

int main(){
	char c;
	int n;
	tipo_vector v;

	n=0;
	do{ 	      system("cls||clear");
			printf("PRUEBAS DE MATERIALES\n");
			printf("=====================\n\n");
			printf("\t1.- Introducir nueva prueba\n");
			printf("\t2.- Listar las pruebas realizadas\n");
			printf("\t3.- Listado por fabricante\n");
			printf("\t4.- Terminar programa\n");
			printf("\t\tIntroduzca opcion: ");
			c=getch();
			switch(c){
			case '1':	introducir_prueba(v,&n);
							break;
			case '2':	listar_pruebas(v,n);
							break;
			case '3':	listar_fabricantes(v,n);
							break;
			case '4':	printf("\n\nFIN DE EJECUCION\n");
							getch();
							break;
			default:		printf("\a");
							break;
			}
	}while (c!='4');
	return 0;
}

void introducir_prueba(tipo_vector v,int *n){
	      system("cls||clear");
	printf("ALTA DE NUEVAS PRUEBAS\n");
	printf("======================\n\n");
	if(*n<MAX){
		printf("Prueba n� %d\n",*n+1);
		printf("\tIntroduzca nombre de material: ");
		scanf(" %s", v[*n].mat);
		printf("\tIntroduzca nombre de fabricante: ");
		scanf(" %s", v[*n].fab);
		do{	printf("\tIntroduzca densidad (kg/m3): ");
				scanf(" %f", &v[*n].den);
		}while(v[*n].den<=0);
		do{	printf("\tIntroduzca dureza (1-10): ");
				scanf(" %d", &v[*n].dur);
		}while((v[*n].dur<1)||(v[*n].dur>10));
		do{	printf("\tIntroduzca resistencia a la traccion (MPa): ");
				scanf(" %f", &v[*n].rt);
		}while(v[*n].rt<=0);
		do{	printf("\tIntroduzca modulo de elasticidad (MPa): ");
				scanf(" %f", &v[*n].me);
		}while(v[*n].me<=0);
		(*n)=*n+1;
	}else{	printf("Vector lleno\n");
				getch();
	}
}

void listar_pruebas(tipo_vector v,int n){
	int i;

	      system("cls||clear");
	printf("LISTADO DE TODAS LAS PRUEBAS:\n");
	printf("============================\n\n");
	printf("%-10s %-10s %10s %10s %10s %10s\n","Material","Fabricante","Densidad","Dureza","Res.Tracc.","Mod.Elast.");
	printf("%-10s %-10s %10s %10s %10s %10s\n","========","==========","========","======","==========","==========");
  for(i=0;i<n;++i)
		printf("%-10s %-10s %10.2f %10d %10.2f %10.2f\n",v[i].mat,v[i].fab,
																		v[i].den,v[i].dur,
																		v[i].rt,v[i].me);
  getch();
}

void listar_fabricantes(tipo_vector v, int n){
	int i,j,enc;
	int cont,total;

	      system("cls||clear");
	total=0;
	printf("LISTADO DE FABRICANTES:\n");
	printf("=======================\n\n");
	printf("%-10s %10s\n","Fabricante","N� pruebas");
	printf("%-10s %10s\n","----------","----------");
	for(i=0;i<n;++i){
		enc=0;
		j=0;
		while((j<i)&&(!enc)){
			if(strcmpi(v[i].fab,v[j].fab))
				j++;
			else	enc=1;
		}
		if(!enc){
			printf("%-10s ",v[i].fab);
			cont=0;
			j=i;
			while(j<n){
				if(strcmpi(v[i].fab,v[j].fab)==0)
					if(v[j].dur>=1)
						++cont;
				++j;
			}
			printf("%10d\n",cont);
			total+=cont;
		}
	}
   printf("\n%10s %10d\n","Total:",total);
  getch();
}
