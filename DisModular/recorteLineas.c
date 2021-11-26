#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* prototipos de funciones */
void leer_datos(float *xmin,float *xmax,float *ymin,float *ymax,
					 float *x1,float *y1, float *x2,float *y2);
void leer_ventana_recorte(float *xmin,float *xmax,float *ymin,float *ymax);
void leer_linea(float *x1,float *y1, float *x2,float *y2);
void leer_punto(float *x,float *y);
int recortar_lineas(float xmin,float xmax,float ymin,float ymax,
					 float *x1,float *y1, float *x2,float *y2);
int es_interior(float xmin,float xmax,float ymin,float ymax,float x,float y);
void intercambiar_puntos(float *x1,float *y1,float *x2,float *y2);
int misma_posicion(float xmin,float xmax,float ymin,float ymax,
						 float x1,float y1, float x2,float y2);
char posicion_relativa(float xmin,float xmax,float ymin,float ymax,
						 float x,float y);
void interseccion(char frontera,float xmin,float xmax,float ymin,float ymax,
						 float x1,float y1, float x2,float y2,float *x,float *y);
void escribir_linea(float x1,float y1, float x2,float y2);
void escribir_punto(float x,float y);

/* definiciones de funciones */
int main(){
	char c;
	int i;
	float xmin,xmax,ymin,ymax;
	float x1,y1,x2,y2;

	do{ 	      system("cls||clear");
			printf("RECORTE DE LINEAS DE COHEN-SUTHERLAND\n");
			printf("=====================================\n\n");
			leer_datos(&xmin,&xmax,&ymin,&ymax,&x1,&y1,&x2,&y2);
			i=recortar_lineas(xmin,xmax,ymin,ymax,&x1,&y1,&x2,&y2);
			if(i){
				printf("\tLinea recortada:\n");
				escribir_linea(x1,y1,x2,y2);
			}else{
				printf("\tLinea recortada completamente\n");
			}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_datos(float *xmin,float *xmax,float *ymin,float *ymax,
					 float *x1,float *y1, float *x2,float *y2){
	printf("Ventana de recorte:\n");
	leer_ventana_recorte(xmin,xmax,ymin,ymax);
	printf("Linea a recortar:\n");
	leer_linea(x1,y1,x2,y2);
}

void leer_ventana_recorte(float *xmin,float *xmax,float *ymin,float *ymax){
	float aux;

	do{	printf("\tPrimera esquina:\n");
			leer_punto(xmin,ymin);
			printf("\tEsquina opuesta:\n");
			leer_punto(xmax,ymax);
	}while((*xmin==*xmax)||(*ymin==*ymax));
	if(*xmin>*xmax){
		aux=*xmin;
		*xmin=*xmax;
		*xmax=aux;
	}
	if(*ymin>*ymax){
		aux=*ymin;
		*ymin=*ymax;
		*ymax=aux;
	}
}

void leer_linea(float *x1,float *y1, float *x2,float *y2){
	do{	printf("\tPrimer extremo:\n");
			leer_punto(x1,y1);
			printf("\tSegundo extremo:\n");
			leer_punto(x2,y2);
	}while((*x1==*x2)&&(*y1==*y2));
}

void leer_punto(float *x,float *y){
	printf("\t\tx: ");
	scanf(" %f", x);
	printf("\t\ty: ");
	scanf(" %f", y);
}

int recortar_lineas(float xmin,float xmax,float ymin,float ymax,
					 float *x1,float *y1, float *x2,float *y2){
	int i;
	char pos;
	float x,y;

	i=2;
	while(i==2){
		if(es_interior(xmin,xmax,ymin,ymax,*x1,*y1)&&
			es_interior(xmin,xmax,ymin,ymax,*x2,*y2))
			i=1;
		else	if(misma_posicion(xmin,xmax,ymin,ymax,*x1,*y1,*x2,*y2))
					i=0;
				else{ if(es_interior(xmin,xmax,ymin,ymax,*x1,*y1)){
							intercambiar_puntos(x1,y1,x2,y2);
						}
						pos=posicion_relativa(xmin,xmax,ymin,ymax,*x1,*y1);
						interseccion(pos,xmin,xmax,ymin,ymax,*x1,*y1,*x2,*y2,&x,&y);
						*x1=x;
						*y1=y;
				}
	}
	return(i);
}

int es_interior(float xmin,float xmax,float ymin,float ymax,float x,float y){
	if((x>=xmin)&&(x<=xmax)&&(y>=ymin)&&(y<=ymax))
		return(1);
	else return(0);
}

void intercambiar_puntos(float *x1,float *y1,float *x2,float *y2){
	float aux;

	aux=*x1;
	*x1=*x2;
	*x2=aux;
	aux=*y1;
	*y1=*y2;
	*y2=aux;
}

int misma_posicion(float xmin,float xmax,float ymin,float ymax,
						 float x1,float y1, float x2,float y2){
	int res;
	res=0;
	if((x1<xmin)&&(x2<xmin))
		res=1;
	else 	if((x1>xmax)&&(x2>xmax))
				res=1;
			else	if((y1<ymin)&&(y2<ymin))
						res=1;
					else	if((y1>ymax)&&(y2>ymax))
								res=1;
	return(res);
}

char posicion_relativa(float xmin,float xmax,float ymin,float ymax,
						 float x,float y){
	char pos;
	if(x<xmin)
		pos='i';
	else 	if(x>xmax)
				pos='d';
			else	if(y<ymin)
						pos='a';
					else	if(y>ymax)
								pos='s';
							else pos=' ';
	return(pos);
}

void interseccion(char frontera,float xmin,float xmax,float ymin,float ymax,
						 float x1,float y1, float x2,float y2,float *x,float *y){
	float m;
	switch(frontera){
	case 'i':	m=(y2-y1)/(x2-x1);
					*x=xmin;
					*y=y1+m*(xmin-x1);
					break;
	case 'd':	m=(y2-y1)/(x2-x1);
					*x=xmax;
					*y=y1+m*(xmax-x1);
					break;
	case 'a':	m=(x2-x1)/(y2-y1);
					*y=ymin;
					*x=x1+m*(ymin-y1);
					break;
	case 's':	m=(x2-x1)/(y2-y1);
					*y=ymax;
					*x=x1+m*(ymax-y1);
					break;
	}
}

void escribir_linea(float x1,float y1, float x2,float y2){
	printf("\t\tPrimer extremo: ");
	escribir_punto(x1,y1);
	printf("\n\t\tSegundo extremo: ");
	escribir_punto(x2,y2);
}

void escribir_punto(float x,float y){
	printf("(%.2f,%.2f)",x,y);
}