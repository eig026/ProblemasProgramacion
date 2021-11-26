/* Programa para añadir, consultar y actualizar 	*/
/* datos de nuevos materiales industriales			*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 50

/* Nuevos tipos de datos */
typedef char cadena50[N+1];
typedef struct{
		cadena50 nom;	/* Nombre del material										*/
		double den;		/* Densidad: g/cm3											*/
		double rt;		/* Resistencia a la traccion: MPa						*/
		double me;		/* Modulo de elasticidad: MPa								*/
		double rrp;		/* Resistencia relativa al peso (acero=1)				*/
		double cetl;	/* Coeficiente de expansion termica lineal: 1/K	*/
}tipo_material;

/* prototipos de funciones */
void leer_cadena(char *cad, int n);
void leer_opcion_menu(char *c);
void pausa(void);
void creacion(cadena50 nombre);
void anadir(cadena50 nombre);
void leer_material(tipo_material *mat);
void leer_nombre(cadena50 nom);
void leer_real_positivo(char *cad,double *r);
void consulta(cadena50 nombre);
void c_individual(cadena50 nombre);
void buscar_material(FILE *f,cadena50 nom,int *enc,tipo_material *mat);
void c_secuencial(cadena50 nombre);
void c_secuencial_clasificado(cadena50 nombre);
void listado_selectivo(cadena50 nombre);
void escribir_material(tipo_material mat);
void actualizacion(cadena50 nombre);
void leer_opcion_modificacion(char *c);
void modificar_material(tipo_material *mat);
void Clasificacion_MD(char *nombre);
void Particion_tramos(char *nombre,char *nombre1,char *nombre2,int n);
void Fusion_tramos(char *nombre,char *nombre1,char *nombre2,int n);
long Tamano_archivo(char *nombre);
void realizar_copia(char *nombre, char *copia);

int main(){
	char c;        		/* Opcion del menu			 	*/
	cadena50 nombre;		/* Nombre del archivo maestro	*/

	      system("cls||clear");
	printf("PROGRAMA DE GESTION DE NUEVOS MATERIALES DE INGENIERIA:\n");
	printf("=======================================================\n\n");
	printf("Introduzca nombre del archivo maestro: ");
	leer_cadena(nombre,N);
	do{ 	leer_opcion_menu(&c);
			switch(c){
			case '1': 	creacion(nombre);
							break;
			case '2': 	anadir(nombre);
							break;
			case '3': 	consulta(nombre);
							break;
			case '4': 	actualizacion(nombre);
							break;
			case '5': 	printf("\n\nFIN DE EJECUCION\n");
							getch();
							break;
			default: 	printf("\a");
							break;
			}
	}while (c!='5');
	return 0;
}

void leer_opcion_menu(char *c){
/* Lee por teclado opcion del menu principal */
	      system("cls||clear");
	printf("GESTION DE NUEVOS MATERIALES INDUSTRIALES\n");
	printf("=========================================\n\n");
	printf("\t1.- Creacion del archivo\n");
	printf("\t2.- Incluir nuevos materiales\n");
	printf("\t3.- Consulta de materiales\n");
	printf("\t4.- Actualizacion de archivo de materiales\n");
	printf("\t5.- Finalizar ejecucion\n");
	printf("\n\t\tIntroduzca opcion: ");
	*c=getch();
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

void pausa(void){
	printf("\nPulse cualquier tecla para continuar");
	getch();
}

void creacion(cadena50 nombre){
/* Crea un nuevo archivo con el nombre dado y realiza una minima */
/* comprobacion de errores (si existe o no el archivo,...)       */
	FILE *f;
	char c;

	      system("cls||clear");
	printf("CREACION DEL ARCHIVO MAESTRO\n");
	printf("============================\n\n");
	if((f=fopen(nombre,"rb"))!=NULL){
		 printf("Ya existe el archivo: %s\n\n",nombre);
		 printf("Desea borrarlo y crearlo de nuevo (S/N): ");
		 c=toupper(getch());
		 fclose(f);
		 if (c=='S'){
			f=fopen(nombre,"wb");
			printf("\nArchivo borrado y creado de nuevo: %s",nombre);
			pausa();
         fclose(f);
		 }
	}else{ if((f=fopen(nombre,"wb"))!=NULL){
				printf("Se ha creado el archivo: %s\n",nombre);
				pausa();
				fclose(f);
			 }else{	printf("Error en creacion del archivo: %s",nombre);
						pausa();
			 }
	}
}

void anadir(cadena50 nombre){
/* Añade datos de nuevos materiales leidos por  */
/* teclado al final del archivo                 */
	FILE *f;
	tipo_material mat;
	char c;

	printf("ANADIR NUEVOS MATERIALES AL ARCHIVO\n");
	printf("===================================\n\n");
	if((f=fopen(nombre,"ab"))!=NULL){
		do{ leer_material(&mat);
			 fwrite(&mat,sizeof(mat),1,f);
			 printf("\nDesea introducir mas materiales (S/N): ");
			 c=toupper(getch());
		}while (c=='S');
		fclose(f);
	}else{ printf("ERROR EN APERTURA DEL ARCHIVO: %s",nombre);
			 pausa();
	}
}

void leer_material(tipo_material *mat){
/* Lee por teclado datos de un material  */
	      system("cls||clear");
	printf("Introduzca datos del nuevo material:\n\n");
	leer_nombre(mat->nom);
	leer_real_positivo("\tDensidad: ",&mat->den);
	leer_real_positivo("\tResistencia a la traccion (MPa): ",&mat->rt);
	leer_real_positivo("\tModulo de elasticidad (MPa): ",&mat->me);
	leer_real_positivo("\tResistencia relativa al peso (acero=1): ",&mat->rrp);
	leer_real_positivo("\tCoeficiente de expansion termica lineal (1/�K): ",&mat->cetl);
}

void leer_nombre(cadena50 nom){
/* Lee por teclado el nombre de un nuevo material */
	printf("\tNombre: ");
	leer_cadena(nom,N);
}

void leer_real_positivo(char *cad,double *r){
/* Lee por teclado un numero real positivo, presentando en */
/* pantalla el mensaje contenido en el parametro cad       */
	do{	printf(cad);
			scanf(" %lf",r);
	}while(r<=0);
}

void escribir_material(tipo_material mat){
/* Escribe en pantalla los datos de un material  */
	FILE *f;

	f=fopen("zz.dat","a");
	printf("\tNombre: %s\n",mat.nom);
	printf("\tDensidad (g/cm3): %.2lf\n",mat.den);
	printf("\tResistencia a la traccion (MPa): %.2lf\n",mat.rt);
	printf("\tModulo de elasticidad (MPa): %.2lf\n",mat.me);
	printf("\tResistencia relativa al peso (acero=1): %.2lf\n",mat.rrp);
	printf("\tCoeficiente de expansion termica lineal (10**-6/�K): %.2lf\n",mat.cetl*1e6);
	fprintf(f,"\tNombre: %s\n",mat.nom);
	fprintf(f,"\tDensidad (g/cm3): %.2lf\n",mat.den);
	fprintf(f,"\tResistencia a la traccion (MPa): %.2lf\n",mat.rt);
	fprintf(f,"\tModulo de elasticidad (MPa): %.2lf\n",mat.me);
	fprintf(f,"\tResistencia relativa al peso (acero=1): %.2lf\n",mat.rrp);
	fprintf(f,"\tCoeficiente de expansion termica lineal (10**-6/�K): %.2lf\n",mat.cetl*1e6);
   fclose(f);
}

void consulta(cadena50 nombre){
/* Presenta un menu con las opciones de consulta,    */
/* lee la opcion y ejecuta la accion correspondiente */
	char c;

	do{ 	      system("cls||clear");
			printf("CONSULTA DE NUEVOS MATERIALES\n");
			printf("=============================\n\n");
			printf("\t1.- De un material individual\n");
			printf("\t2.- Listado de todos los materiales\n");
			printf("\t3.- Listado clasificado de todos los materiales\n");
			printf("\t4.- Listado selectivo de materiales\n");
			printf("\t5.- Salir del menu de consultas\n");
			printf("\n\t\tIntroduzca opcion: ");
			c=getch();
			switch(c){
			case '1': 	c_individual(nombre);
							break;
			case '2': 	c_secuencial(nombre);
							break;
			case '3': 	c_secuencial_clasificado(nombre);
							break;
			case '4': 	listado_selectivo(nombre);
							break;
			case '5': 	break;
			default: 	printf("\a");;
							break;
			}
	}while(c!='5');
}

void c_individual(cadena50 nombre){
/* Consulta individual de materiales: lee por teclado el nombre      */
/* del material, lo busca en el archivo y presenta en pantalla todas */
/* las ocurrencias del mismo (si asi se solicita)                    */
	FILE *f;
	tipo_material mat;
	cadena50 nom;			/* Nombre del material a buscar	       */
	int enc;					/* Verdadero: se encuentra el material  */
	int enc1;				/* Verdadero: hay al menos 1 ocurrencia */
	char c;

	do{	      system("cls||clear");
			printf("CONSULTA INDIVIDUAL DE MATERIALES\n");
			printf("=================================\n\n");
			if ((f=fopen(nombre,"rb"))==NULL){
				printf("No se puede abrir el archivo: %s",nombre);
				c='N';
				pausa();
			}else{
				printf("Introduzca el nombre del material: ");
				leer_cadena(nom,N);
				enc1=0;
				do{	buscar_material(f,nom,&enc,&mat);
						if(enc){ escribir_material(mat);
									enc1=1;
									printf("Desea buscar mas ocurrencias (S/N): ");
									c=toupper(getch());
						}else{   c='N';
									if(enc1)
										printf("\nNo hay mas ocurrencias");
									else printf("\nMaterial no encontrado");
									pausa();
						}
				}while(c=='S');
				fclose(f);
				printf("\nDesea consultar otro material (S/N): ");
				c=toupper(getch());
			}
	}while(c!='N');
}

void buscar_material(FILE *f,cadena50 nom,int *enc,tipo_material *mat){
/* Busca en el archivo f, a partir de la posicion actual, el primer  */
/* registro con nombre de material igual al parametro nom            */
	*enc=0;
	fread(mat,sizeof(*mat),1,f);
	while((!feof(f))&&(!(*enc)))
		if (strcmp(mat->nom,nom)==0)
			*enc=1;
		else	fread(mat,sizeof(*mat),1,f);
}

void c_secuencial(cadena50 nombre){
/* Listado en pantalla de todos los materiales del archivo,    */
/* presentandolos de 1 en 1, con opcion de terminar el listado */
	FILE *f;
	tipo_material mat;
	char c;
	int n;

	      system("cls||clear");
	printf("LISTADO DE MATERIALES\n");
	printf("=====================\n");
	if ((f=fopen(nombre,"rb"))==NULL){
		printf("No se puede abrir el archivo: %s",nombre);
		pausa();
	}else{   c='S';
				n=1;
				fread(&mat,sizeof(mat),1,f);
				while((!feof(f))&&(c!='F')){
					       system("cls||clear");
					 printf("Material num. %d\n\n",n);
					 escribir_material(mat);
					 fread(&mat,sizeof(mat),1,f);
					 printf("\nPulse cualquier tecla para continuar (F=Finalizar)\n");
					 c=toupper(getch());
					 n++;
				}
				fclose(f);
	}
}

void c_secuencial_clasificado(cadena50 nombre){
	cadena50 cad;

	strcpy(cad,"copia.dat");
	realizar_copia(nombre,cad);
	Clasificacion_MD(cad);
   c_secuencial(cad);
}

void listado_selectivo(cadena50 nombre){
	float den;
   int n;
	FILE *f;
	tipo_material mat;

	      system("cls||clear");
	printf("LISTADO SELECTIVO DE MATERIALES\n");
	printf("===============================\n\nn");
	if((f=fopen(nombre,"rb"))==NULL){
		printf("No se puede abrir el archivo %s",nombre);
		getch();
	}else{	do{	printf("Introduzca valor minimo densidad: ");
						scanf(" %f", &den);
				}while(den<=0);
				printf("Materiales con densidad mayor que %.2f y\n",den);
				printf("resistencia relativa al peso mayor que 1:\n\n");
				fread(&mat,sizeof(mat),1,f);
				n=0;
				while(!feof(f)){
					if((mat.den>=den)&&(mat.rrp>1.0)){
						printf("%s\n",mat.nom);
						n=1;
					}
					fread(&mat,sizeof(mat),1,f);
				}
				fclose(f);
				if (n==0)
					printf("No hay ningun material");
				getch();
	}
}

void actualizacion(cadena50 nombre){
/* Crea un  uevo archivosecuencial donde se almacenan los         */
/* registros modificados y no se almacenan los registros a borrar */
	FILE *f, *g;
	cadena50 nom_hist;		/* Nombre archivo historico */
	tipo_material mat;
	char c;

	      system("cls||clear");
	printf("ACTUALIZACION DEL ARCHIVO DE MATERIALES\n");
	printf("=======================================\n\n");
	do{	printf("Introduzca nombre maestro historico: ");
			leer_cadena(nom_hist,N);
			if((f=fopen(nom_hist,"rb"))!=NULL){
				printf("Ya existe un archivo con ese nombre\n");
				printf("Desea eliminarlo (S/N): ");
				c=toupper(getch());
				fclose(f);
				if (c=='S')
					remove(nom_hist);
			}else c='S';
	}while(c!='S');
	if (rename(nombre,nom_hist)!=0){
		printf("Error al renombrar archivo maestro");
		pausa();
	}else{	f=fopen(nombre,"wb");
				g=fopen(nom_hist,"rb");
				fread(&mat,sizeof(mat),1,g);
				while(!feof(g)){
					      system("cls||clear");
					escribir_material(mat);
					leer_opcion_modificacion(&c);
					if(c!='3'){
						if(c=='2')
							modificar_material(&mat);
						fwrite(&mat,sizeof(mat),1,f);
					}
					fread(&mat,sizeof(mat),1,g);
				}
				fclose(f);
				fclose(g);
	}
}

void leer_opcion_modificacion(char *c){
/* Lee por teclado opcion del menu de modificacion del material */
	do{	printf("\nIntroduzca opcion: \n");
			printf("\t1.- Grabar sin modificar\n"),
			printf("\t2.- Modificar\n");
			printf("\t3.- Eliminar\n");
			printf("\t\topcion: ");
			*c=getch();
	}while((*c<'1')||(*c>'3'));
}

void modificar_material(tipo_material *mat){
/* Presenta en pantalla los datos del material, permitiendo  */
/* la modificacion de cualquier dato  */
	char c;

	do{	      system("cls||clear");
			printf("Modificacion de datos del material:\n");
			printf("==================================\n\n");
			escribir_material(*mat);
			printf("\nIntroduzca dato a modificar (N,D,R,M,P,C) o T para terminar: ");
			c=toupper(getch());
			printf("\n");
			switch(c){
			case 'N':	leer_nombre(mat->nom);
							break;
			case 'D':	leer_real_positivo("\tDensidad: ",&mat->den);
							break;
			case 'R':	leer_real_positivo("\tResistencia a la traccion (MPa): ",&mat->rt);
							break;
			case 'M':	leer_real_positivo("\tModulo de elasticidad (MPa): ",&mat->me);
							break;
			case 'P':	leer_real_positivo("\tResistencia relativa al peso (acero=1): ",&mat->rrp);
							break;
			case 'C':	leer_real_positivo("\tCoeficiente de expansion termica lineal (mm/�K): ",&mat->cetl);
							break;
			}
	}while(c!='T');
}

void Clasificacion_MD(char *nombre){
		cadena50 nombre1,nombre2;
		int tamano;
		int n;
		tamano=Tamano_archivo(nombre);
		strcpy(nombre1,"tempo1");
		strcpy(nombre2,"tempo2");
		n=1;
		while (n<tamano){
			Particion_tramos(nombre,nombre1,nombre2,n);
			remove(nombre);
			Fusion_tramos(nombre,nombre1,nombre2,n);
			remove(nombre1);
			remove(nombre2);
			n=n*2;
		}
}

void realizar_copia(char *nombre, char *copia){
	FILE *f,*g;
	tipo_material p;

	f=fopen(nombre,"rb");
	g=fopen(copia,"wb");
	fread(&p,sizeof(tipo_material),1,f);
	while(!feof(f)){
		fwrite(&p,sizeof(tipo_material),1,g);
		fread(&p,sizeof(tipo_material),1,f);
	}
	fclose(f);
	fclose(g);
}

void Particion_tramos(char *nombre,char *nombre1,char *nombre2,int n){
		FILE *f,*f1,*f2;
		tipo_material vent;
		int cont;
		int conmutador;

		f=fopen(nombre,"rb");
		f1=fopen(nombre1,"wb");
		f2=fopen(nombre2,"wb");
		cont=0;
		conmutador=1;
		fread(&vent,sizeof(vent),1,f);
		while(!feof(f)){
			if(conmutador)
					fwrite(&vent,sizeof(vent),1,f1);
			else fwrite(&vent,sizeof(vent),1,f2);
			cont=cont+1;
			if(cont==n){
				conmutador=!conmutador;
				cont=0;
			}
			fread(&vent,sizeof(vent),1,f);
		}
		fclose(f);
		fclose(f1);
		fclose(f2);
}

void Fusion_tramos(char *nombre,char *nombre1,char *nombre2,int n){
		FILE *f,*f1,*f2;
		tipo_material vent1,vent2;
		int cont1,cont2;

		f1=fopen(nombre1,"rb");
		f2=fopen(nombre2,"rb");
		f=fopen(nombre,"wb");
		cont1=0;
		cont2=0;
		fread(&vent1,sizeof(vent1),1,f1);
		fread(&vent2,sizeof(vent2),1,f2);
		while((!feof(f1))&&(!feof(f2))){
			if (strcmp(vent1.nom,vent2.nom)<=0){
					fwrite(&vent1,sizeof(vent1),1,f);
					cont1=cont1+1;
					if(cont1==n){
						cont1=0;
						while((!feof(f2))&&(cont2<n)){
							fwrite(&vent2,sizeof(vent2),1,f);
							cont2=cont2+1;
							fread(&vent2,sizeof(vent2),1,f2);
						}
						cont2=0;
					}
					fread(&vent1,sizeof(vent1),1,f1);
			}else{fwrite(&vent2,sizeof(vent2),1,f);
					cont2=cont2+1;
					if(cont2==n){
						cont2=0;
						while((!feof(f1))&&(cont1<n)){
								fwrite(&vent1,sizeof(vent1),1,f);
								cont1=cont1+1;
								fread(&vent1,sizeof(vent1),1,f1);
						}
						cont1=0;
					}
					fread(&vent2,sizeof(vent2),1,f2);
			}
		}
		while(!feof(f1)){
			fwrite(&vent1,sizeof(vent1),1,f);
			fread(&vent1,sizeof(vent1),1,f1);
		}
		while(!feof(f2)){
			fwrite(&vent2,sizeof(vent2),1,f);
			fread(&vent2,sizeof(vent2),1,f2);
		}
		fclose(f);
		fclose(f1);
		fclose(f2);
}


long Tamano_archivo(char *nombre){
		long cont;
		FILE *f;
		tipo_material vent;

		cont=0;
		f=fopen(nombre,"rb");
		fread(&vent,sizeof(vent),1,f);
		while(!feof(f)){
			cont=cont+1;
			fread(&vent,sizeof(vent),1,f);
		}
		fclose(f);
		return (cont);
}