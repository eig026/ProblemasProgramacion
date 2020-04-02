/* Gestion de materiales industriales           */
/* Programa para añadir, consultar y actualizar */
/* datos de nuevos materiales industriales      */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 50
/* Diseño Preliminar */
/* Nuevos tipos de datos */
typedef char cadena50[N+1];
typedef struct{
    cadena50 nom;              /* Nombre del material            */
    double den;                /* Densidad: g/cm3                */
    double rt;                 /* Resistencia a la traccion: MPa */
    double me;                 /* Modulo de elasticidad: MPa     */
    double rrp; /* Resistencia relativa al peso (acero=1)        */
    double cetl;/* Coeficiente de expansion termica lineal: 1/ºK */
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
void escribir_material(tipo_material mat);
void actualizacion(cadena50 nombre);
void leer_opcion_modificacion(char *c);
void modificar_material(tipo_material *mat);
void leer_archivo_material(FILE *f, tipo_material *mat);
void grabar_archivo_material(FILE *f, tipo_material mat);

/* Diseño detallado */
/* Definiciones de funciones */
int main(){
    char c;          /* Opcion del menu            */
    cadena50 nombre; /* Nombre del archivo maestro */

    system("cls");
    printf("PROGRAMA DE GESTION DE NUEVOS MATERIALES DE INGENIERIA:\n");
    printf("=======================================================\n\n");
    printf("Introduzca nombre del archivo maestro: ");
    leer_cadena(nombre,N);
    do{ leer_opcion_menu(&c);
        switch(c){
        case '1': creacion(nombre);
                  break;
        case '2': anadir(nombre);
                  break;
        case '3': consulta(nombre);
                  break;
        case '4': actualizacion(nombre);
                  break;
        case '5': printf("\n\nFIN DE EJECUCION\n");
                  getch();
                  break;
        default:  printf("\a");
                  break;
        }
    }while(c!='5');
    return 0;
}

void leer_opcion_menu(char *c){
/* Lee por teclado opcion del menu principal */
    system("cls");
    printf("GESTION DE NUEVOS MATERIALES INDUSTRIALES\n");
    printf("=========================================\n\n");
    printf("\t1.- Creacion del archivo\n");
    printf("\t2.- Anadir nuevos materiales\n");
    printf("\t3.- Consulta de materiales\n");
    printf("\t4.- Actualizacion de archivo de materiales\n");
    printf("\t5.- Finalizar ejecucion\n");
    printf("\n\t\tIntroduzca opcion: ");
    *c=getch();
}

void leer_cadena(char *cad, int n){
/* lee por teclado y devuelve una cadena de hasta n caracteres */
/* Nota: la cadena debe preveer una posicion adicional para la */
/* marca fin de cadena (\0) --> tamaño minimo n+1 caracteres   */
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

void pausa(void){
    printf("\nPulse cualquier tecla para continuar");
    getch();
}

void creacion(cadena50 nombre){
/* Crea un nuevo archivo con el nombre dado y realiza una minima */
/* comprobacion de errores (si existe o no el archivo,...)       */
    FILE *f;
    char c;

    system("cls");
    printf("CREACION DEL ARCHIVO MAESTRO\n");
    printf("============================\n\n");
    if((f=fopen(nombre,"rb"))!=NULL){
           printf("Ya existe el archivo: %s\n\n",nombre);
           printf("Desea borrarlo y crearlo de nuevo (S/N): ");
           c=toupper(getch());
           fclose(f);
           if(c=='S'){
               f=fopen(nombre,"wb");
               printf("\nArchivo borrado y creado de nuevo: %s",nombre);
               pausa();
  		       fclose(f);
           }
    }else{ if((f=fopen(nombre,"wb"))!=NULL){
                  printf("Se ha creado el archivo: %s\n",nombre);
                  pausa();
                  fclose(f);
           }else{ printf("Error en creacion del archivo: %s",nombre);
                  pausa();
           }
    }
}

void anadir(cadena50 nombre){
/* Añade datos de nuevos materiales leidos por */
/* teclado al final del archivo                */
    FILE *f;
    tipo_material mat;
    char c;

    printf("ANADIR NUEVOS MATERIALES AL ARCHIVO\n");
    printf("===================================\n\n");
    if((f=fopen(nombre,"ab"))!=NULL){
           do{ leer_material(&mat);
               grabar_archivo_material(f,mat);
               printf("\nDesea introducir mas materiales (S/N): ");
               c=toupper(getch());
           }while(c=='S');
           fclose(f);
    }else{ printf("ERROR EN APERTURA DEL ARCHIVO: %s",nombre);
           pausa();
    }
}

void leer_material(tipo_material *mat){
/* Lee por teclado datos de un material */
    system("cls");
    printf("Introduzca datos del nuevo material:\n\n");
    leer_nombre(mat->nom);
    leer_real_positivo("\tDensidad: ",&mat->den);
    leer_real_positivo("\tResistencia a la traccion (MPa): ",&mat->rt);
    leer_real_positivo("\tModulo de elasticidad (MPa): ",&mat->me);
    leer_real_positivo("\tResistencia relativa al peso(acero=1): ",&mat->rrp);
    leer_real_positivo("\tCoef. expansion termica lineal(10**-6/K): ",&mat->cetl);
}

void leer_nombre(cadena50 nom){
/* Lee por teclado el nombre de un nuevo material */
    printf("\tNombre: ");
    leer_cadena(nom,N);
}

void leer_real_positivo(char *cad,double *r){
/* Lee por teclado un numero real positivo, presentando en */
/* pantalla el mensaje contenido en el parametro cad       */
    do{ printf(cad);
        scanf(" %lf",r);
    }while(r<=0);
}

void escribir_material(tipo_material mat){
/* Escribe en pantalla los datos de un material */
    printf("\tNombre: %s\n",mat.nom);
    printf("\tDensidad (g/cm3): %.2lf\n",mat.den);
    printf("\tResistencia a la traccion (MPa): %.2lf\n",mat.rt);
    printf("\tModulo de elasticidad (MPa): %.2lf\n",mat.me);
    printf("\tResistencia relativa al peso (acero=1): %.2lf\n",mat.rrp);
    printf("\tCoeficiente expansion termica lineal (10**-6/K): %.2lf\n",mat.cetl);
}

void consulta(cadena50 nombre){
/* Presenta un menu con las opciones de consulta,    */
/* lee la opcion y ejecuta la accion correspondiente */
    char c;

    do{ system("cls");
        printf("CONSULTA DE NUEVOS MATERIALES\n");
        printf("=============================\n\n");
        printf("\t1.- De un material individual\n");
        printf("\t2.- Listado de todos los materiales\n");
        printf("\t3.- Salir del menu de consultas\n");
        printf("\n\t\tIntroduzca opcion: ");
        c=getch();
        switch(c){
        case '1': c_individual(nombre);
                  break;
        case '2': c_secuencial(nombre);
                  break;
        case '3': break;
        default:  printf("\a");;
                  break;
        }
    }while(c!='3');
}

void c_individual(cadena50 nombre){
/* Consulta individual de materiales: lee por teclado el nombre      */
/* del material, lo busca en el archivo y presenta en pantalla todas */
/* las ocurrencias del mismo (si asi se solicita)                    */
    FILE *f;
    tipo_material mat;
    cadena50 nom;       /* Nombre del material a buscar         */
    int enc;            /* Verdadero: se encuentra el material  */
    int enc1;           /* Verdadero: hay al menos 1 ocurrencia */
    char c;

    do{ system("cls");
        printf("CONSULTA INDIVIDUAL DE MATERIALES\n");
        printf("=================================\n\n");
        if((f=fopen(nombre,"rb"))==NULL){
               printf("No se puede abrir el archivo: %s",nombre);
               c='N';
               pausa();
        }else{ printf("Introduzca el nombre del material: ");
               leer_cadena(nom,N);
               enc1=0;
               do{ buscar_material(f,nom,&enc,&mat);
                   if(enc){ escribir_material(mat);
                          enc1=1;
                          printf("Desea buscar mas ocurrencias (S/N): ");
                          c=toupper(getch());
                   }else{ c='N';
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
/* Busca en el archivo f, a partir de la posicion actual, el primer */
/* registro con nombre de material igual al parametro nom           */
    *enc=0;
    leer_archivo_material(f,mat);
    while((!feof(f))&&(!(*enc)))
        if(strcmp(mat->nom,nom)==0)
             *enc=1;
        else leer_archivo_material(f,mat);
}

void c_secuencial(cadena50 nombre){
/* Listado en pantalla de todos los materiales del archivo,    */
/* presentandolos de 1 en 1, con opcion de terminar el listado */
    FILE *f;
    tipo_material mat;
    char c;
    int n;

    system("cls");
    printf("LISTADO DE MATERIALES\n");
    printf("=====================\n");
    if((f=fopen(nombre,"rb"))==NULL){
           printf("No se puede abrir el archivo: %s",nombre);
           pausa();
    }else{ c='S';
           n=1;
           leer_archivo_material(f,&mat);
           while((!feof(f))&&(c!='F')){
               system("cls");
               printf("Material num. %d\n\n",n);
               escribir_material(mat);
               leer_archivo_material(f,&mat);
               printf("\nPulse cualquier tecla (F=Finalizar)\n");
               c=toupper(getch());
               n++;
           }
           fclose(f);
    }
}

void actualizacion(cadena50 nombre){
/* Crea un  uevo archivosecuencial donde se almacenan los         */
/* registros modificados y no se almacenan los registros a borrar */
    FILE *f,*g;
    cadena50 nom_hist;    /* Nombre archivo historico */
    tipo_material mat;
    char c;

    system("cls");
    printf("ACTUALIZACION DEL ARCHIVO DE MATERIALES\n");
    printf("=======================================\n\n");
    do{ printf("Introduzca nombre maestro historico: ");
        leer_cadena(nom_hist,N);
        if((f=fopen(nom_hist,"rb"))!=NULL){
            printf("Ya existe un archivo con ese nombre\n");
            printf("Desea eliminarlo (S/N): ");
            c=toupper(getch());
            fclose(f);
            if(c=='S')
                 remove(nom_hist);
        }else c='S';
    }while(c!='S');
    if(rename(nombre,nom_hist)!=0){
           printf("Error al renombrar archivo maestro");
           pausa();
    }else{ f=fopen(nombre,"wb");
           g=fopen(nom_hist,"rb");
           leer_archivo_material(g,&mat);
           while(!feof(g)){
               system("cls");
               escribir_material(mat);
               leer_opcion_modificacion(&c);
               if(c!='3'){
                   if(c=='2')
                       modificar_material(&mat);
                   grabar_archivo_material(f,mat);
               }
               leer_archivo_material(g,&mat);
           }
           fclose(f);
           fclose(g);
    }
}

void leer_opcion_modificacion(char *c){
/* Lee por teclado opcion del menu de modificacion del material */
    do{ printf("\nIntroduzca opcion: \n");
        printf("\t1.- Grabar sin modificar\n"),
        printf("\t2.- Modificar\n");
        printf("\t3.- Eliminar\n");
        printf("\t\topcion: ");
        *c=getch();
    }while((*c<'1')||(*c>'3'));
}

void modificar_material(tipo_material *mat){
/* Presenta en pantalla los datos del material, permitiendo */
/* la modificacion de cualquier dato  */
char c;

    do{ system("cls");
        printf("Modificacion de datos del material:\n");
        printf("==================================\n\n");
        escribir_material(*mat);
        printf("\nIntroduzca dato a modificar (N,D,R,M,P,C) o T para terminar: ");
        c=toupper(getch());
        printf("\n");
        switch(c){
        case 'N': leer_nombre(mat->nom);
                  break;
        case 'D': leer_real_positivo("\tDensidad: ",&mat->den);
                  break;
        case 'R': leer_real_positivo("\tResist. traccion (MPa): ",&mat->rt);
                  break;
        case 'M': leer_real_positivo("\tModulo elasticidad (MPa): ",&mat->me);
                  break;
        case 'P': leer_real_positivo("\tRes. rel. peso(acero=1): ",&mat->rrp);
                  break;
        case 'C': leer_real_positivo("\tCoef. exp. term(10**-6/K):",&mat->cetl);
                  break;
        }
    }while(c!='T');
}

void leer_archivo_material(FILE *f, tipo_material *mat){
    fread(mat->nom,sizeof(cadena50),1,f);
    fread(&mat->den,sizeof(double),1,f);
    fread(&mat->rt,sizeof(double),1,f);
    fread(&mat->me,sizeof(double),1,f);
    fread(&mat->rrp,sizeof(double),1,f);
    fread(&mat->cetl,sizeof(double),1,f);
}

void grabar_archivo_material(FILE *f, tipo_material mat){
    fwrite(mat.nom,sizeof(cadena50),1,f);
    fwrite(&mat.den,sizeof(double),1,f);
    fwrite(&mat.rt,sizeof(double),1,f);
    fwrite(&mat.me,sizeof(double),1,f);
    fwrite(&mat.rrp,sizeof(double),1,f);
    fwrite(&mat.cetl,sizeof(double),1,f);
}
