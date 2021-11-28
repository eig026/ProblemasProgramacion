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
#include <math.h>
#include <locale.h>
#include <windows.h>
#define N 4       // Datos de prueba
//#define N 100
#define NOTAS 2   // Datos de prueba
//#define NOTAS 5
#define ARCHIVO "alumnos.bin"
#define BAK "alumnos.bak"

/* Nuevos tipos de datos */
typedef char cadena20[21];
typedef float tipo_notas[NOTAS];
typedef struct{
	cadena20 nom;
	cadena20 ape1;
	cadena20 ape2;
}tipo_identificacion;
typedef struct{
	tipo_identificacion id;
	tipo_notas notas;
}tipo_alumno;
typedef tipo_alumno tipo_vector[N];
/* prototipos de funciones */
void insertar_alumno(tipo_vector v,int *n,int np);
void leer_cadena(char *cad, int n);
int buscar_alumno(tipo_vector v,int n,tipo_identificacion id);
void insertar_calificaciones(tipo_vector v,int n,int *np);
void consulta(tipo_vector v,int n,int np);
void listado(tipo_vector v,int n,int np);
void calificacion_final(tipo_vector v,int n,int np);
void clasificar_nota_media(tipo_vector v,int n,int np);
float nota_media(tipo_notas v,int np);
void clasificar_nombre(tipo_vector v,int n);
int es_anterior(tipo_identificacion a, tipo_identificacion b);
void inicializar_vector(tipo_vector v, int *n, int *np);
void grabar_archivo(tipo_vector v, int n, int np);
void leer_registro_archivo(FILE *f, tipo_alumno *a);
void escribir_registro_archivo(FILE *f, tipo_alumno *a);

int main(){
	char c;
	tipo_vector v;
	int n,np;

	/* Establecemos que vamos a usar caracteres locales */
	setlocale(LC_CTYPE,"Spanish");
	/* Para m�quinas Windows tambi�n hay que cambiar  */
	/* la p�gina de c�digos de la consola a la p�gina */
	/* de c�digos ANSI (1252), ya que por defecto se  */
	/* utiliza la p�gina de c�digos 437               */
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	// n=0;
	// np=0;
	inicializar_vector(v,&n,&np);
	do{	system("cls");
		printf("GESTION DE NOTAS DE ALUMNOS\n");
		printf("===========================\n\n");
		printf("\t1.- Insertar nuevo alumno\n");
		printf("\t2.- Introducir calificaciones examen parcial\n");
		printf("\t3.- Consulta calificaciones alumno\n");
		printf("\t4.- Listado calificaciones\n");
		printf("\t5.- Calificacion final\n");
		printf("\t6.- Listado clasificado orden alfabetico\n");
		printf("\t7.- Listado clasificado por calificacion media\n");
		printf("\t0.- Terminar programa\n");
		printf("\t\tIntroduzca opcion: ");
		c=getch();
		switch(c){
		case '1': insertar_alumno(v,&n,np);
				  break;
		case '2': insertar_calificaciones(v,n,&np);
				  break;
		case '3': consulta(v,n,np);
				  break;
		case '4': listado(v,n,np);
				  break;
		case '5': if(np==NOTAS)
		          	calificacion_final(v,n,np);
		          else{
		          	printf("\n\nFaltan parciales por calificar\n");
		          	getch();
				  }
				  break;
		case '6': clasificar_nombre(v,n);
		          listado(v,n,np);
				  break;
		case '7': clasificar_nota_media(v,n,np);
		          listado(v,n,np);
				  break;
		case '0': printf("\n\n\tF I N   D E   E J E C U C I O N");
				  break;
		default:  printf("\a");
				  break;
		}
	}while (c!='0');
	grabar_archivo(v,n,np);
	return 0;
}

void insertar_alumno(tipo_vector v,int *n,int np){
	char c;
	int i;
	float r;
	tipo_identificacion id;

	c='S';
	if(*n==N){
		printf("\n\nNo se pueden registrar mas alumnos");
		getch();
	}
	while((*n<N)&&(c=='S')){
		system("cls");
		printf("Insercion de nuevos alumnos\n");
		printf("===========================\n\n");
		do{ printf("\tNombre: ");
			 leer_cadena(id.nom,20);
			 printf("\tApellido1: ");
			 leer_cadena(id.ape1,20);
			 printf("\tApellido2: ");
			 leer_cadena(id.ape2,20);
			 i=buscar_alumno(v,*n,id);
			 if(i!=-1){
				printf("\tYa esta registrado ese alumno\n");
				getch();
			 }
		}while(i!=-1);
		v[*n].id=id;
		if(np){ printf("Notas:\n");
				for(i=0;i<np;++i){
					do{ printf("\tExamen %d ((0-10 o -1): ",i+1);
						scanf(" %f",&r);
					}while(((r<0)||(r>10))&&(r!=-1));
					v[*n].notas[i]=r;
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

int buscar_alumno(tipo_vector v,int n,tipo_identificacion id){
	/* Devuelve la posici�n del alumno en el vector */
	/* � -1 si no se encuentra registrado           */
	int i;

	i=0;
	while((i<n)&&(strcmpi(v[i].id.nom,id.nom)||
	      strcmpi(v[i].id.ape1,id.ape1)
		  ||strcmpi(v[i].id.ape2,id.ape2)))
	  ++i;
	if (i<n)
		return i;
	else return -1;
}

void insertar_calificaciones(tipo_vector v,int n,int *np){
	int i;
	float r;

	if(*np<NOTAS){ system("cls");
				 printf("Introducir calificaciones examen n� %d\n",*np+1);
				 printf("=====================================\n\n");
				 for(i=0; i<n; ++i){
					 printf("Alumno: %s %s, %s\n",v[i].id.ape1,
					        v[i].id.ape2,v[i].id.nom);
					 do{ printf("\tNota (0-10 o -1): ");
						 scanf(" %f",&r);
					 }while(((r<0)||(r>10))&&(r!=-1));
					 v[i].notas[*np]=r;
				}
				(*np)++;
	}else{ 		printf("\n\nAlumnos ya calificados totalmente");
			 	getch();
	}
}

void consulta(tipo_vector v,int n, int np){
	tipo_identificacion id;
	int i,k;
	char c;

	do{	system("cls");
		printf("Consulta de alumnos\n");
		printf("===================\n\n");
		printf("Nombre: ");
		leer_cadena(id.nom,20);
		printf("Apellido 1: ");
		leer_cadena(id.ape1,20);
		printf("Apellido 2: ");
		leer_cadena(id.ape2,20);
		k=buscar_alumno(v,n,id);
		if(k!=-1){
			printf("\nAlumno registrado\n");
			 if(np){
			 	for (i=0;i<np;++i)
					if(v[k].notas[i]!=-1)
						printf("\tNota(%d)= %5.2f\n",i+1,v[k].notas[i]);
					else printf("\n");
			}else printf("\nNo hay notas registradas\n");
		}else printf("\n Sin datos de ese alumno\n");
		printf("\nDesea consultar otro alumno (S/N): ");
		c=toupper(getch());
	} while(c!='N');
}

void listado(tipo_vector v,int n,int np){
	int i,j;
	int espacios;

	system("cls");
	printf("Listado de alumnos y notas parciales\n");
	printf("====================================\n\n");
	printf("%-63s", "Apellidos y nombre");
	for(i=0;i<np; ++i)
		printf("Nota %d ",i+1);
	printf("\n\n");
	for(i=0;i<n;++i){
		printf("%s %s, %s",v[i].id.ape1,v[i].id.ape2,v[i].id.nom);
		espacios=60-strlen(v[i].id.nom)-strlen(v[i].id.ape1)-strlen(v[i].id.ape2);
		for(j=0;j<espacios;++j)
			printf(" ");
		for(j=0;j<np;++j)
			if(v[i].notas[j]!=-1.0)
				printf("%6.2f ",v[i].notas[j]);
			else printf("%7s"," ");
		printf("\n");
	}
	getch();
}

void calificacion_final(tipo_vector v,int n,int np){
	int i,j,cal,espacios;
	float media;

	system("cls");
	printf("Listado de calificacion final\n");
	printf("=============================\n\n");
	printf("%-63s %-10s\n","Apellidos y nombre","Nota final");
	printf("==============================");
	printf("=================================");
	printf(" ==========\n\n");
	for(i=0;i<n;++i){
		media=nota_media(v[i].notas,np);
		if(media>=0.0){
			printf("%s %s,%s",v[i].id.ape1,v[i].id.ape2,v[i].id.nom);
			espacios=60-strlen(v[i].id.nom)-strlen(v[i].id.ape1)-strlen(v[i].id.ape2);
			for(j=0;j<espacios;++j)
				printf(" ");
			printf(" %5.2f\n",media);
		}
	}
	getch();
}

void clasificar_nota_media(tipo_vector v,int n,int np){
	int i,j;
  	tipo_alumno x;
  	int k;           /* posicion de insercion */
  	for (i=0;i<n-1;++i){
     	k=i;
     	for (j=i+1;j<n;++j)
        	if (nota_media(v[j].notas,np)>nota_media(v[k].notas,np))
           		k=j;
     	x=v[k];
     	v[k]=v[i];
     	v[i]=x;
  	}
}

float nota_media(tipo_notas v,int np){
	float suma;
	int i,cal;
	if(np==0){
		return 0.0;
	}else{
		suma=0;
		i=0;
		cal=1;
		while((i<np)&&(cal!=-1)){
			if(v[i]!=-1){
				suma+=v[i];
				++i;
			}else cal=-1;
		}
		if(cal!=-1)
			return(suma/np);
		else return -1.0;
	}
}

void clasificar_nombre(tipo_vector v,int n){
	int i,j;
  	tipo_alumno x;
  	int k;           /* posicion de insercion */
  	for (i=0;i<n-1;++i){
     	k=i;
     	for (j=i+1;j<n;++j)
        	if (es_anterior(v[j].id,v[k].id))
           		k=j;
     	x=v[k];
     	v[k]=v[i];
     	v[i]=x;
  	}
}

int es_anterior(tipo_identificacion a, tipo_identificacion b){
	int res;
	res=0;
	if(strcmpi(a.ape1,b.ape1)<0)
	    res=1;
	else if(strcmpi(a.ape1,b.ape1)==0)
	        if(strcmpi(a.ape2,b.ape2)<0)
	            res=1;
	        else if(strcmpi(a.ape2,b.ape2)==0)
	        		if(strcmpi(a.nom,b.nom)<0)
	            		res=1;
	return res;
}

void inicializar_vector(tipo_vector v, int *n, int *np){
    FILE *f;
	int i,j;
	tipo_alumno a;

	f=fopen(ARCHIVO,"rb");
	if(f==NULL){
		*n=0;
		*np=0;
		/* Inicializamos las notas de los parciales */
		/* no evaluados a -2                        */
		for(i=0;i<N;++i){
			for(j=0;j<NOTAS;++j){
				v[i].notas[j]=-2.0;
			}
		}
	}else{
		*n=0;
		*np=0;
		/* Recorrido secuencial del archivo */
		leer_registro_archivo(f,&a);
		while((*n<N)&&(!feof(f))){
			v[*n]=a;
			(*n)++;
			/* Calcular el n� de parciales evaluados */
			for(j=0;j<NOTAS;++j){
				if(a.notas[j]!=-2.0){
					if(j==(*np))
						(*np)++;
				}
			}
			leer_registro_archivo(f,&a);
		}
		fclose(f);
	}
}

void grabar_archivo(tipo_vector v, int n, int np){
	FILE *f;
	int i;
	if((f=fopen(ARCHIVO,"rb"))!=NULL){
        fclose(f);
        if((f=fopen(BAK,"rb"))!=NULL){
        	fclose(f);
        	remove(BAK);
		}
        rename(ARCHIVO,BAK);
	}
	f=fopen(ARCHIVO,"wb");
	if(f==NULL){
		printf("Error al crear el archivo: %s",ARCHIVO);
		getch();
		exit(0);
	}else{
		for(i=0;i<n;++i){
			escribir_registro_archivo(f,&v[i]);
		}
		fclose(f);
	}
}

void leer_registro_archivo(FILE *f, tipo_alumno *a){
	int i;
    fread(a->id.nom,sizeof(a->id.nom),1,f);
    fread(a->id.ape1,sizeof(a->id.ape1),1,f);
    fread(a->id.ape2,sizeof(a->id.ape2),1,f);
    for(i=0;i<NOTAS;++i)
    	fread(&a->notas[i],sizeof(float),1,f);
}

void escribir_registro_archivo(FILE *f, tipo_alumno *a){
	int i;
    fwrite(a->id.nom,sizeof(a->id.nom),1,f);
    fwrite(a->id.ape1,sizeof(a->id.ape1),1,f);
    fwrite(a->id.ape2,sizeof(a->id.ape2),1,f);
    for(i=0;i<NOTAS;++i)
    	fwrite(&a->notas[i],sizeof(float),1,f);
}
