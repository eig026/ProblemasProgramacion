#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 10       // Número máximo de materiales
#define MAX_CAD 30  // Longitud máxima de las cadenas de caracteres

/* ********************* */
/* DISEÑO PRELIMINAR     */
/* ********************* */

/* Nuevos tipos de datos */
typedef char cadena30[MAX_CAD];
typedef struct{
	float den;
	int dur;
	float rt;
	float me;
}tipo_pro;
typedef struct{
	cadena30 mat;
	cadena30 fab;
	tipo_pro pro;
}tipo_experimento;
typedef tipo_experimento tipo_vector[MAX];
/* prototipos de funciones */
void leer_opcion_menu(char *c);
void introducir_experimento(tipo_vector v,int *n);
void listar_experimentos(tipo_vector v,int n);
void modificar_nombre_material(tipo_vector v, int n);
void eliminar_experimento(tipo_vector v,int *n);
void listar_fabricantes(tipo_vector v, int n);
void clasificar_densidad(tipo_vector v,int n);
void clasificar_material_fabricante(tipo_vector v,int n);
int es_anterior(tipo_experimento a, tipo_experimento b);
void leer_cadena(char *c, int n);

/* ********************* */
/* DISEÑO DETALLADO      */
/* ********************* */

/* Definiciones de funciones */
int main(){
	char c;
	int n;
	tipo_vector v;

	n=0;
	do{ 	system("cls");
			leer_opcion_menu(&c);
			switch(c){
			case '1': 	introducir_experimento(v,&n);
						break;
			case '2':	listar_experimentos(v,n);
						break;
			case '3': 	modificar_nombre_material(v,n);
						break;
			case '4':	eliminar_experimento(v,&n);
						break;
			case '5':	listar_fabricantes(v,n);
						break;
			case '6': 	clasificar_densidad(v,n);
						break;
			case '7':	clasificar_material_fabricante(v,n);
						break;
			case '0':	printf("\n\nFIN DE EJECUCION\n");
						getch();
						break;
			default:	printf("\a");
						break;
			}
	}while (c!='0');
	return 0;
}

void leer_opcion_menu(char *c){
	printf("EXPERIMENTOS DE NUEVOS MATERIALES\n");
	printf("=================================\n\n");
	printf("\t1.- Introducir nuevo experimento\n");
	printf("\t2.- Listar los experimentos realizados\n");
	printf("\t3.- Modificar nombre de material\n");
	printf("\t4.- Eliminar experimento\n");
	printf("\t5.- Listado por fabricante\n");
	printf("\t6.- Clasificar por densidad del material\n");
	printf("\t7.- Clasificar por nombre de material y fabricante\n");
	printf("\t0.- Terminar programa\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void introducir_experimento(tipo_vector v,int *n){
	system("cls");
	printf("ALTA DE NUEVOS MATERIALES\n");
	printf("=========================\n\n");
	if(*n<MAX){
		printf("Prueba nº %d\n",*n+1);
		printf("\tIntroduzca nombre de material: ");
		leer_cadena(v[*n].mat,MAX_CAD);
		//scanf(" %s", v[*n].mat);
		printf("\tIntroduzca nombre de fabricante: ");
		leer_cadena(v[*n].fab,MAX_CAD);
		//scanf(" %s", v[*n].fab);
		do{	printf("\tIntroduzca densidad (kg/m3): ");
				scanf(" %f", &v[*n].pro.den);
		}while(v[*n].pro.den<=0);
		do{	printf("\tIntroduzca dureza (1-10): ");
				scanf(" %d", &v[*n].pro.dur);
		}while((v[*n].pro.dur<1)||(v[*n].pro.dur>10));
		do{	printf("\tIntroduzca resistencia a la traccion (MPa): ");
				scanf(" %f", &v[*n].pro.rt);
		}while(v[*n].pro.rt<=0);
		do{	printf("\tIntroduzca modulo de elasticidad (MPa): ");
				scanf(" %f", &v[*n].pro.me);
		}while(v[*n].pro.me<=0);
		(*n)=*n+1;
	}else{	printf("Vector lleno\n");
			getch();
	}
}

void listar_experimentos(tipo_vector v,int n){
	int i;
	char c;

	system("cls");
	printf("LISTADO DE TODAS LAS PRUEBAS:\n");
	printf("============================\n\n");
	printf("%-10s %-10s %10s %10s %10s %10s\n","Material","Fabricante","Densidad","Dureza","Res.Tracc.","Mod.Elast.");
	printf("%-10s %-10s %10s %10s %10s %10s\n","========","==========","========","======","==========","==========");
	i=0;
	c='S';
	while((i<n)&&(c!='N')){
		printf("%-10s %-10s %10.2f %10d %10.2f %10.2f\n",v[i].mat,v[i].fab,
				v[i].pro.den,v[i].pro.dur,v[i].pro.rt,v[i].pro.me);
  		if((i+1)%10==0){
		  	printf("Mas materiales (S/N):");
			c=toupper(getch());
		}
		++i;
	}
	getch();
}

void modificar_nombre_material(tipo_vector v, int n){
	cadena30 n1,n2;
	int i,cont;
	system("cls");
	printf("MODIFICACION NOMBRE DEL MATERIAL:\n");
	printf("================================\n\n");
	printf("Introduzca nombre material: ");
	leer_cadena(n1,MAX_CAD);
	//scanf(" %s", n1);
	printf("Introduzca nuevo nombre: ");
	scanf(" %s", n2);
	cont=0;
	for(i=0;i<n;++i){
		if(strcmpi(v[i].mat,n1)==0){
			strcpy(v[i].mat,n2);
			cont++;
		}
	}
	printf("\n\nNumero de reemplazamientos realizados: %d\n",cont);
	getch();
}

void eliminar_experimento(tipo_vector v,int *n){
	cadena30 nombre;
	int i,j;
	char c;
	system("cls");
	printf("ELIMINACION DE EXPERIMENTOS:\n");
	printf("===========================\n\n");
	printf("Introduzca nombre material: ");
	leer_cadena(nombre,MAX_CAD);
	//scanf(" %[^\n]s", nombre);
	i=0;
	c='S';
	while((i<*n)&&(c=='S')){
		if(strcmpi(v[i].mat,nombre)==0){
			printf("\n%-10s %-10s %10.2f %10d %10.2f %10.2f\n",v[i].mat,v[i].fab,
				v[i].pro.den,v[i].pro.dur,v[i].pro.rt,v[i].pro.me);
			printf("\n\nEliminar experimento (S/N): ");
			c=toupper(getche());
			if(c=='S'){ for(j=i+1;j<*n;++j)
							v[j-1]=v[j];
						(*n)--;
			}else ++i;
			if(i<*n){
				printf("\n\nEliminar otro experimento (S/N): ");
				c=toupper(getche());
			}
		}else ++i;
	}
}

void listar_fabricantes(tipo_vector v, int n){
	int i,j,enc;
	int cont,total;

	system("cls");
	total=0;
	printf("LISTADO DE FABRICANTES:\n");
	printf("=======================\n\n");
	printf("%-10s %10s\n","Fabricante","Nº experimentos");
	printf("%-10s %10s\n","----------","---------------");
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
					if(v[j].pro.dur>=1)
						++cont;
				++j;
			}
			printf("%10d\n",cont);
			total+=cont;
		}
	}
   printf("\n%10s %10d\n","Total:",total);
  getch();
}

void clasificar_densidad(tipo_vector v,int n){
	int i,j;
  	tipo_experimento x;
  	int k;           /* posicion de insercion */
  	for (i=0;i<n-1;++i){
     	k=i;
     	for (j=i+1;j<n;++j)
        	if (v[j].pro.den > v[k].pro.den)
           		k=j;
     	x=v[k];
     	v[k]=v[i];
     	v[i]=x;
  	}
}

void clasificar_material_fabricante(tipo_vector v,int n){
	int i,j;
  	tipo_experimento x;
  	int k;           /* posicion de insercion */
  	for (i=0;i<n-1;++i){
     	k=i;
     	for (j=i+1;j<n;++j)
        	if (es_anterior(v[j],v[k]))
           		k=j;
     	x=v[k];
     	v[k]=v[i];
     	v[i]=x;
  	}
}

int es_anterior(tipo_experimento a, tipo_experimento b){
	int res;
	res=0;
	if(strcmpi(a.mat,b.mat)<0)
	    res=1;
	else if(strcmpi(a.mat,b.mat)==0)
	        if(strcmpi(a.fab,b.fab)<0)
	            res=1;
	return res;
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
