#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define N 20

/* Nuevos tipos de datos */
typedef struct{
	double x,y;
}tipo_punto2d;
typedef tipo_punto2d tipo_lista_vertices[N];
typedef struct{
	int n;
	tipo_lista_vertices v;
}tipo_poligono;

/* prototipos de funciones */
void leer_poligono(tipo_poligono *pol);
void leer_vertice(tipo_punto2d *p);
int poligono_regular(tipo_poligono pol);
int vertices_distintos(tipo_poligono pol);
int interseccion_lineas(tipo_punto2d p1, tipo_punto2d p2,
								tipo_punto2d p3, tipo_punto2d p4,tipo_punto2d *p);
int poligono_convexo(tipo_poligono pol);
double superficie(tipo_poligono pol);
double area_triangulo(double l1, double l2, double l3);
double distancia(tipo_punto2d p1,tipo_punto2d p2);
double area(tipo_poligono pol);

int main(){
	char c;
	tipo_poligono pol;

	do{ 	clrscr();
			printf("SUPERFICIE PIEZA PLANA POLIGONAL CONVEXA\n");
			printf("========================================\n\n");
			leer_poligono(&pol);
			if(pol.n<3)
				printf("\nNo es un poligono (menos de 3 lados)");
			else 	if(!vertices_distintos(pol))
						printf("\nNo es un poligono (dos vertices seguidos iguales)");
					else{	if (poligono_regular(pol)){
								printf("\nPoligono regular\n");
								if(poligono_convexo(pol)){
									printf("\nPoligono convexo\n");
									printf("\nSuperficie (triangulacion): %.2lf",superficie(pol));
									printf("\nSuperficie: %.2lf",area(pol));
								}else{	printf("\nPoligono concavo\n");
											printf("\nSuperficie: %.2lf",area(pol));
								}
							}else	printf("\nPoligono irregular (tiene aristas que intersectan)");
					}
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			c=toupper(getch());
	}while (c!='N');
	return 0;
}

void leer_poligono(tipo_poligono *pol){
	char c;

	pol->n=0;
	c='S';
	printf("Introduzca vertices del poligono:\n");
	while((pol->n<N)&&(c!='N')){
		printf("\tVertice num. %d:\n",pol->n+1);
		leer_vertice(&pol->v[pol->n]);
		printf("Mas vertices (S/N): ");
		c=toupper(getche());
		printf("\n");
		++(pol->n);
	}
}

void leer_vertice(tipo_punto2d *p){
	printf("\t\tx: ");
	scanf(" %lf",&p->x);
	printf("\t\ty: ");
	scanf(" %lf",&p->y);
}

double superficie(tipo_poligono pol){
	int i;
	double sup;

	sup=0;
	for(i=1;i<pol.n-1;++i)
		sup+=area_triangulo(distancia(pol.v[0],pol.v[i]),
								  distancia(pol.v[0],pol.v[i+1]),
								  distancia(pol.v[i+1],pol.v[i]));
	return sup;
}

double area_triangulo(double l1, double l2, double l3){
	double s;

	s=(l1+l2+l3)/2;
	return(sqrt(s*(s-l1)*(s-l2)*(s-l3)));
}

double distancia(tipo_punto2d p1,tipo_punto2d p2){
	return(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

int poligono_regular(tipo_poligono pol){
	int regular;
	int i,j;
	tipo_punto2d p;

	i=0;
	regular=1;
	while((i<pol.n-1)&&(regular)){
		 j=i+1;
		 while((j<pol.n)&&(regular)){
			if(interseccion_lineas(pol.v[i],pol.v[i+1],pol.v[j],pol.v[(j+1)%pol.n],&p)==2)
				regular=0;
			else j++;
		 }
		 i++;
	}
	return regular;
}

int vertices_distintos(tipo_poligono pol){
	int dis;
	int i;

	dis=1;
	i=0;
	while((i<pol.n)&&(dis)){
		if((pol.v[i].x==pol.v[(i+1)%pol.n].x)&&(pol.v[i].y==pol.v[(i+1)%pol.n].y)){
			dis=0;
         printf("\nVertices iguales: %d y %d\n",i+1, i+2);
		}else ++i;
	}
	return(dis);

}

int poligono_convexo(tipo_poligono pol){
	tipo_poligono ari;
	double z[N];
	int i;
	int cvx;

	ari.n=pol.n;
	for(i=0;i<pol.n;++i){
		ari.v[i].x=pol.v[(i+1)%pol.n].x-pol.v[i%pol.n].x;
		ari.v[i].y=pol.v[(i+1)%pol.n].y-pol.v[i%pol.n].y;
	}
	for(i=0;i<ari.n;++i)
		z[i]=ari.v[i].x*ari.v[(i+1)%ari.n].y-ari.v[i].y*ari.v[(i+1)%ari.n].x;
		//z[i]=ari.v[i].x*ari.v[i+1].y-ari.v[i].y*ari.v[i+1].x;
	cvx=1;
	i=0;
	while((i<=ari.n)&&cvx)
		if(z[i]>=0)
			++i;
		else cvx=0;
	if(!cvx){
		cvx=1;
		i=0;
		while((i<=ari.n)&&cvx)
			if(z[i]<=0)
				++i;
			else cvx=0;
	}
	return cvx;
}

double area(tipo_poligono pol){
	int i;
	double suma;

	suma=0;
	i=1;
	while(i<pol.n){
		suma+=(pol.v[i-1].x*pol.v[i].y-pol.v[i].x*pol.v[i-1].y);
		++i;
	}
	suma+=(pol.v[pol.n-1].x*pol.v[0].y-pol.v[0].x*pol.v[pol.n-1].y);
	return(fabs(suma/2));
}

int interseccion_lineas(tipo_punto2d p1, tipo_punto2d p2,
								tipo_punto2d p3, tipo_punto2d p4,tipo_punto2d *p){
/* Devuelve 0: lineas iguales o paralelas
				1: lineas que interesectan pero no los segmentos
				2: segmentos de linea que intersectan */
	double a1,b1,c1,a2,b2,c2;	  //Ecuaciones linea: a*x+b*y+c=0
	double u1,u2;				// Ec. parametricas: x=x1+u*(x2-x1)  y=y1+u*(y2-y1)

	a1=p2.y-p1.y;
	b1=p1.x-p2.x;
	c1=p1.y*(p2.x-p1.x)-p1.x*(p2.y-p1.y);
	a2=p4.y-p3.y;
	b2=p3.x-p4.x;
	c2=p3.y*(p4.x-p3.x)-p3.x*(p4.y-p3.y);
	if(a1*b2==b1*a2){
		if((a1*c2==a2*c1)&&(b1*c2==b2*c1)){
			if(p2.x-p1.x)
				u1=(p3.x-p1.x)/(p2.x-p1.x);
			else u1=(p3.y-p1.y)/(p2.y-p1.y);
			if(p2.x-p1.x)
				u2=(p4.x-p1.x)/(p2.x-p1.x);
			else u1=(p4.y-p1.y)/(p2.y-p1.y);
			if(((0<u1)&&(u1<1))||((0<u2)&&(u2<1))||((u1<=0)&&(u2>=1))||((u1>=1)&&(u2<=0)))
				return 2;
			else return 0;		//printf("\nLas dos rectas son iguales");
		}else
			return 0; 		//printf("\nLas dos rectas son paralelas");
	}else{ 	p->y=(a1*c2-c1*a2)/(a2*b1-a1*b2);
				p->x=(b1*c2-c1*b2)/(a1*b2-a2*b1);
				//printf("\nRectas secantes: ");
				//printf("Punto de interseccion: (%.2f,%.2f)",x,y);
				if(p2.x-p1.x)
					u1=(p->x-p1.x)/(p2.x-p1.x);
				else u1=(p->y-p1.y)/(p2.y-p1.y);
				if(p4.x-p3.x)
					u2=(p->x-p3.x)/(p4.x-p3.x);
				else u2=(p->y-p3.y)/(p4.y-p3.y);
				if((0<u1)&&(u1<1)&&(0<u2)&&(u2<1))
					return 2; 		//printf("\nLos segmentos de linea se cortan");
				else return 1; 	//printf("\nLos segmentos de linea no se cortan");
	}
}

