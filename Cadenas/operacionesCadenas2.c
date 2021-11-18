#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 10		/* longitud maxima de las cadenas de entrada 	*/

/* Nuevos tipos de datos */
typedef char cadena[N+1];

/* Prototipos de funciones */
void leer_cadena(char *c, int n);
void leer_opcion_menu(char *c);
void ejecutar_opcion(char c);
void opcion1(void);
void opcion2(void);
void opcion3(void);
void opcion4(void);
void opcion5(void);
void subcadena(char *c, int pos, int l, char *s);
int busqueda_subcadena(char *c, char *s);
void insertar(char *c,int pos, char *s);
void borrar(char *c,int pos, int l);
void sustituir(char *c, char *s1, char *s2);

int main(){
	char c;

	do{ leer_opcion_menu(&c);
		 ejecutar_opcion(c);
	}while(c!='0');
	return 0;
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

void leer_opcion_menu(char *c){
	      system("cls||clear");
	printf("OPERACIONES CON CADENAS DE CARACTERES\n");
	printf("=====================================\n\n");
	printf("\t1.- Extraccion de una subcadena\n");
	printf("\t2.- Busqueda de una subcadena\n");
	printf("\t3.- Insercion de una cadena en medio de otra\n");
	printf("\t4.- Borrado de una parte de una cadena\n");
	printf("\t5.- Sustitucion de una parte de una cadena\n");
	printf("\t0.- Finalizar\n\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void ejecutar_opcion(char c){
	switch(c){
	case '1': opcion1();
				 break;
	case '2': opcion2();
				 break;
	case '3': opcion3();
				 break;
	case '4': opcion4();
				 break;
	case '5': opcion5();
				 break;
	case '0': printf("FIN DE EJECUCION");
				 getch();
				 break;
	default: printf("\a");
	}
}

void opcion1(void){
	cadena cad,cad2;
	int i,pos;
	char c;

	do{	      system("cls||clear");
			printf("EXTRACCION DE SUBCADENAS\n");
			printf("========================\n\n");
			printf("Introduzca cadena original: ");
			leer_cadena(cad,N);
			printf("Introduzca posicion inicial: ");
			scanf(" %d", &pos);
			printf("Introduzca numero de caracteres a extraer: ");
			scanf(" %d", &i);
			subcadena(cad,pos,i,cad2);
			printf("\nLa subcadena extraida es %s",cad2);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
}

void opcion2(void){
	cadena cad,cad2;
	int pos;
	char c;

	do{	      system("cls||clear");
			printf("BUSQUEDA DE CADENA DENTRO DE OTRA\n");
			printf("=================================\n\n");
			printf("Introduzca cadena original: ");
			leer_cadena(cad,N);
			printf("Introduzca cadena a buscar: ");
			leer_cadena(cad2,N);
         pos=busqueda_subcadena(cad,cad2);
			if(pos)
				printf("\n\nPrimera ocurrencia: posicion=%d",pos);
			else printf("\n\nNo se encuentra la subcadena");
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
}

void opcion3(void){
	cadena cad,cad2;
	int pos;
	char c;

	do{	      system("cls||clear");
			printf("INSERCION DE UNA CADENA DENTRO DE OTRA\n");
			printf("======================================\n\n");
			printf("Introduzca cadena original: ");
			leer_cadena(cad,N);
			printf("Introduzca cadena a insertar: ");
			leer_cadena(cad2,N);
			printf("Introduzca posicion de insercion: ");
			scanf(" %d", &pos);
			insertar(cad,pos,cad2);
			printf("\nLa cadena resultante es %s",cad);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
}

void opcion4(void){
	cadena cad;
	int i,pos;
	char c;

	do{	      system("cls||clear");
			printf("BORRADO DE PARTE DE UNA CADENA\n");
			printf("==============================\n\n");
			printf("Introduzca cadena original: ");
			leer_cadena(cad,N);
			printf("Introduzca posicion inicial: ");
			scanf(" %d", &pos);
			printf("Introduzca numero de caracteres a borrar: ");
			scanf(" %d", &i);
			borrar(cad,pos,i);
			printf("\nLa cadena resultante es %s",cad);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
}

void opcion5(void){
	cadena cad,cad2,cad3;
	char c;

	do{	      system("cls||clear");
			printf("SUSTITUCION DE TODAS LAS OCURRENCIAS DE UNA SUBCADENA\n");
			printf("=====================================================\n\n");
			printf("Introduzca cadena original: ");
			leer_cadena(cad,N);
			printf("Sustituir subcadena: ");
			leer_cadena(cad2,N);
			printf("\tPor subcadena: ");
			leer_cadena(cad3,N);
			sustituir(cad,cad2,cad3);
			printf("\nLa cadena resultante es %s",cad);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
}

void subcadena(char *c, int pos, int l, char *s){
	int lon,i,j;

	lon=strlen(c);
	if((pos<=0)||(pos>lon))
		s[0]='\0';
	else{ i=pos-1;
			j=0;
			while((i<lon)&&(j<l)){
				s[j]=c[i];
				i++;
				j++;
			}
			s[j]='\0';
	}
}

int busqueda_subcadena(char *c, char *s){
	int i,j;
	int l1,l2;
	int enc;

	i=0;
	enc=0;
	l1=strlen(c);
	l2=strlen(s);
	while((i<l1)&&(!enc)){
		if(c[i]==s[0]){
			j=1;
			enc=1;
			while((j<l2)&&(i+j<l1)&&(enc))
				if(c[i+j]==s[j])
					j++;
				else enc=0;
			if(j!=l2){
				enc=0;
				++i;
			}
		}
		else ++i;
	}
	if(enc)
		return i+1;
	else return 0;
}

void insertar(char *c,int pos, char *s){
	int j,k;
	int l1,l2;

	l1=strlen(c);
	l2=strlen(s);
	if(pos<1)
		pos=1;
	else if (pos>l1)
				pos=l1+1;
	/* hacer hueco en cadena inicial */
	pos--;
	if(l1+l2>N)
		k=N;
	else k=l1+l2;
	for(j=k-1;j>=pos+l2;j--)
		c[j]=c[j-l2];
	c[k]='\0';
	for(j=0;(j<l2)&&(j+pos<N);++j)
		c[j+pos]=s[j];
}

void borrar(char *c,int pos, int l){
	int i,lc;

	lc=strlen(c);
	if((pos>=1)&&(pos<=lc)&&(l>0)){
		if(pos+l>=lc)
			c[pos-1]='\0';
		else{ for(i=pos-1;i<=pos+lc-l;++i)
					c[i]=c[i+l];
				c[pos+lc-l+1]='\0';
		}
	}
}

void sustituir(char *c, char *s1, char *s2){
	int i,l1;

	l1=strlen(s1);
	i=busqueda_subcadena(c,s1);
	while(i){
		borrar(c,i,l1);
		insertar(c,i,s2);
		i=busqueda_subcadena(c,s1);
	}
}