#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 4
#define NOT 2

/* Nuevos tipos de datos */
typedef char cadena20[21];
typedef float tipo_notas[NOT];
typedef struct{
	cadena20 nom;
	tipo_notas not;
}tipo_reg;
typedef tipo_reg tipo_vector[N];
/* prototipos de funciones */
void insertar_alumno(tipo_vector v,int *n,int nc);
void leer_cadena(char *cad, int n);
int buscar(tipo_vector v,int n,cadena20 cad);
int buscar_alumno(tipo_vector v,int n,cadena20 cad);
void insertar_calificaciones(tipo_vector v,int n,int *nc);
void consulta(tipo_vector v,int n,int nc);
void listado(tipo_vector v,int n,int nc);
void calificacion_final(tipo_vector v,int n,int nc);

int main(){
	char c;
	tipo_vector v;
	int n,nc;

	n=0;
	nc=0;
	do{ 	      system("cls||clear");
			printf("GESTION DE NOTAS DE ALUMNOS\n");
			printf("===========================\n\n");
			printf("\t1.- Insertar nuevo alumno\n");
			printf("\t2.- Introducir calificaciones examen parcial\n");
			printf("\t3.- Consulta calificaciones alumno\n");
			printf("\t4.- Listado calificaciones\n");
			printf("\t5.- Calificacion final\n");
			printf("\t0.- Terminar programa\n");
			printf("\t\tIntroduzca opcion: ");
			c=getch();
			switch(c){
			case '1': insertar_alumno(v,&n,nc);
						 break;
			case '2': insertar_calificaciones(v,n,&nc);
						 break;
			case '3': consulta(v,n,nc);
						 break;
			case '4': listado(v,n,nc);
						 break;
			case '5': calificacion_final(v,n,nc);
						 break;
			case '0': printf("\n\n\tF I N   D E   E J E C U C I O N");
						 break;
			default:  printf("\a");
						 break;
			}
	}while (c!='0');
	return 0;
}

void insertar_alumno(tipo_vector v,int *n,int nc){
	char c;
	int i;
	float r;
	cadena20 cad;

	c='S';
	if(*n==N){
		printf("\n\nNo se pueden registrar mas alumnos");
		getch();
	}
	while((*n<N)&&(c=='S')){
		      system("cls||clear");
		printf("Insercion de nuevos alumnos\n");
		printf("===========================\n\n");
		do{ printf("\tNombre y apellidos: ");
			 leer_cadena(cad,20);
			 i=buscar(v,*n,cad);
			 if(i){
				printf("\tYa esta registrado ese alumno\n");
				getch();
			 }
		}while(i);
		strcpy(v[*n].nom,cad);
		if(nc){ printf("Notas:\n");
					for(i=0;i<nc;++i){
						do{ 	printf("\tExamen %d ((0-10 o -1): ",i+1);
								scanf(" %f",&v[*n].not[i]);
								r=v[*n].not[i];
						}while(((r<0)||(r>10))&&(r!=-1));
					}
		}
		(*n)++;
		printf("Desea insertar un nuevo alumno (S/N): ");
		c=toupper(getch());
		if(*n==N){
			printf("\n\nNo se pueden registrar mas alumnos");
			getch();
		}
	}
}

void leer_cadena(char *cad, int n){
/* lee por teclado y devuelve una cadena de hasta n caracteres */
	int i,fin;
	char c;

	i=0;
	fin=0;
	while((i<n)&&(!fin)){
		c=getche();
		if(c!='\r'){
			cad[i]=c;
			++i;
		}else fin=1;
	}
	cad[i]='\0';
	printf("\n");
}

int buscar(tipo_vector v,int n,cadena20 cad){
	int i;

	i=0;
	while((i<n)&&strcmpi(v[i].nom,cad))
	  ++i;
	if (i<n)
		return 1;
	else return 0;
}

void insertar_calificaciones(tipo_vector v,int n,int *nc){
	int i;
	float r;

	if(*nc<NOT){       system("cls||clear");
					 printf("Introducir calificaciones examen num %d\n",*nc+1);
					 printf("=====================================\n\n");
					 for(i=0; i<n; ++i){
						 printf("Alumno: %s\n",v[i].nom);
						 do{ 	printf("\tNota (0-10 o -1): ");
								scanf(" %f",&v[i].not[*nc]);
								r=v[i].not[*nc];
						 }while(((r<0)||(r>10))&&(r!=-1));
					 }
					 (*nc)++;
	}else{ printf("\n\nAlumnos ya calificados totalmente");
			 getch();
	}
}

void consulta(tipo_vector v,int n, int nc){
	cadena20 cad;
	int i,k;
	char c;

	do{	      system("cls||clear");
			printf("Consulta de alumnos\n");
			printf("===================\n\n");
			printf("Nombre y apellidos: ");
			leer_cadena(cad,20);
			k=buscar_alumno(v,n,cad);
			if(k!=-1){ printf("\nAlumno registrado");
					 if(nc){ for (i=0;i<nc;++i)
								printf("\n\tNota(%d)= %5.2f\n",i+1,v[k].not[i]);
					 }else printf("\nNo hay notas registradas\n");
			}else printf("\n Sin datos de ese alumno\n");
			printf("\nDesea consultar otro alumno (S/N): ");
			c=toupper(getch());
	} while(c!='N');
}

int buscar_alumno(tipo_vector v,int n,cadena20 cad){
	int i;

	i=0;
	while((i<n)&&strcmpi(v[i].nom,cad))
	  ++i;
	if (i<n)
		return i;
	else return -1;
}

void listado(tipo_vector v,int n,int nc){
	int i,j;

	      system("cls||clear");
	printf("Listado de alumnos y notas parciales\n");
	printf("====================================\n\n");
	printf(" %-20s", "Nombre y apellidos");
	for(i=0;i<nc; ++i)
		printf(" Nota %d",i+1);
	printf("\n\n");
	for(i=0;i<n;++i){
		printf(" %-20s",v[i].nom);
		for(j=0;j<nc;++j)
			printf(" %5.2f",v[i].not[j]);
		printf("\n");
	}
	getch();
}

void calificacion_final(tipo_vector v,int n,int nc){
	int i,j,cal;
	float suma;

	      system("cls||clear");
	printf("Listado de calificacion final\n");
	printf("=============================\n\n");
	printf(" %-20s %-10s\n", "Nombre y apellidos","Nota final");
	printf(" =================== ==========\n\n");
	for(i=0;i<n;++i){
		cal=1;
		j=0;
		suma=0;
		while((j<nc)&&cal)
			if (v[i].not[j]!=-1){
				suma+=v[i].not[j];
				++j;
			}else cal=0;
		if(cal)
			printf(" %-20s %5.2f\n",v[i].nom,suma/nc);
	}
	getch();
}
