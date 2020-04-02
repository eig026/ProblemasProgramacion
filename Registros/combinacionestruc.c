/* Programa ejemplo de combinacion de estructuras de datos:                */
/* Definición de nuevos tipos de datos (array de registros jerárquicos)    */
/* Lectura por teclado de los datos individuales de un array  de registros */
/* Escritura en pantalla de los datos individuales del array de registros  */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define  Max_alumnos  50
#define  Max_notas 6

/* Nuevos tipos de datos */
typedef char cadena15[16];
typedef char cadena20[21];
typedef char cadena40[41];
typedef struct{
	int dia;
	int mes;
	int anno;
}tipo_fecha;
typedef float tipo_notas[Max_notas];
typedef struct{
	cadena20 calle;
	cadena15 ciudad;
	int cp;
	int tfno;
	cadena40 e_mail;
}tipo_direccion;
typedef struct{
	cadena20 nombre;
	cadena20 apellidos;
	int dni;
	tipo_fecha fecha_nacimiento;
	int numero_convocatorias;
	tipo_notas notas;
	tipo_direccion direccion;
}tipo_ficha;
typedef tipo_ficha tipo_tabla[Max_alumnos];

/* Prototipos de funciones */
void leerFichasAlumnos(tipo_tabla tabla,int *n);
void escribirFichasAlumnos(tipo_tabla tabla,int n);
void leer_cadena(char *cad, int n);

/* Definiciones de funciones */
int main(){
    int n;
    tipo_tabla tabla;
    int i;
    /* Introduccion de datos en la ED */
    n=0;
    leerFichasAlumnos(tabla,&n);
    /* Listado en pantalla de todas las fichas */
    escribirFichasAlumnos(tabla,n);
    printf("\n\nPulse una tecla para terminar");
    getch();
    return(0);
}

void leerFichasAlumnos(tipo_tabla tabla,int *n){
    int j;
    char c;
    printf("Introduccion de datos de fichas de alumnos\n");
    printf("==========================================\n");
    c='S';
    while((*n<Max_alumnos)&&(c=='S')){
        printf("Alumno num. %d\n",*n+1);
        printf("\tNombre: ");
        leer_cadena(tabla[*n].nombre,20);
        printf("\tApellidos: ");
        leer_cadena(tabla[*n].apellidos,20);
        printf("\tDNI: ");
        scanf(" %d",&tabla[*n].dni);
        printf("\tFecha de nacimiento:\n");
        do{ printf("\t\tDia: ");
            scanf(" %d",&tabla[*n].fecha_nacimiento.dia);
        }while((tabla[*n].fecha_nacimiento.dia<1)||(tabla[*n].fecha_nacimiento.dia>31));
        do{ printf("\t\tMes: ");
            scanf(" %d",&tabla[*n].fecha_nacimiento.mes);
        }while((tabla[*n].fecha_nacimiento.mes<1)||(tabla[*n].fecha_nacimiento.mes>12));
        printf("\t\tAño: ");
        scanf(" %d",&tabla[*n].fecha_nacimiento.anno);
        do{ printf("\tNumero de convocatorias: ");
            scanf(" %d",&tabla[*n].numero_convocatorias);
        }while(tabla[*n].numero_convocatorias<0 ||tabla[*n].numero_convocatorias>Max_notas);
        for(j=0;j<tabla[*n].numero_convocatorias;++j){
            printf("\tNota[%d]: ",j+1);
            scanf(" %f",&tabla[*n].notas[j]);
        }
        printf("\tDireccion:\n");
        printf("\t\tCalle: ");
        leer_cadena(tabla[*n].direccion.calle,20);
        printf("\t\tCiudad: ");
        leer_cadena(tabla[*n].direccion.ciudad,15);
        printf("\t\tC.P.: ");
        scanf(" %d",&tabla[*n].direccion.cp);
        printf("\t\tTelefono: ");
        scanf(" %d",&tabla[*n].direccion.tfno);
        printf("\t\tE-mail: ");
        leer_cadena(tabla[*n].direccion.e_mail,40);
        (*n)++;
        printf("\nDesea añadir otra ficha (S/N)? ");
        c=toupper(getch());
        printf("\n\n");
    }
}

void escribirFichasAlumnos(tipo_tabla tabla,int n){
    int i,j;
    char c;
    c='S';
    i=0;
    while((i<n)&&(c=='S')){
        system("cls");
        printf("Alumno num. %d\n",i+1);
        printf("\tNombre: %s\n",tabla[i].nombre);
        printf("\tApellidos: %s\n ",tabla[i].apellidos);
        printf("\tDNI: %d\n",tabla[i].dni);
        printf("\tFecha de nacimiento:\n");
        printf("\t\tDia: %d\n",tabla[i].fecha_nacimiento.dia);
        printf("\t\tMes: %d\n",tabla[i].fecha_nacimiento.mes);
        printf("\t\tAño: %d\n",tabla[i].fecha_nacimiento.anno);
        printf("\tNumero de convocatorias: %d\n",tabla[i].numero_convocatorias);
        for(j=0;j<tabla[i].numero_convocatorias;++j){
            printf("\tNota[%d]: %.2f\n",j+1,tabla[i].notas[j]);
        }
        printf("\tDireccion:\n");
        printf("\t\tCalle: %s\n",tabla[i].direccion.calle);
        printf("\t\tCiudad: %s\n",tabla[i].direccion.ciudad);
        printf("\t\tC.P.: %d\n",tabla[i].direccion.cp);
        printf("\t\tTelefono: %d\n",tabla[i].direccion.tfno);
        printf("\t\tE-mail: %s\n",tabla[i].direccion.e_mail);
        i++;
        printf("\nDesea ver otra ficha (S/N)? ");
        c=toupper(getch());
    }
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
