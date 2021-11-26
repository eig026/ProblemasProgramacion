/// FAlla buscar definie


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//#define

/* Nuevos tipos de datos */
typedef struct{
	int h;
	int mn;
	int sg;
	int cs;
}tipo_tiempo;

/* prototipos de funciones */
void leer_tiempo(tipo_tiempo *t);
void calcular_diferencia_tiempos(tipo_tiempo t1,tipo_tiempo t2,tipo_tiempo *t);
int es_anterior(tipo_tiempo tf,tipo_tiempo ti);
void escribir_tiempo(tipo_tiempo t);

int main(){
	char c;
	tipo_tiempo t1,t2,t;

	do{ 	      system("cls||clear");
			printf("DIFERENCIA DE DOS TIEMPOS\n");
			printf("=========================\n\n");
			printf("Introduzca instante de tiempo inicial:\n");
			leer_tiempo(&t1);
			printf("Introduzca instante de tiempo final:\n");
			leer_tiempo(&t2);
			if(es_anterior(t2,t1))
				printf("\nEl instante final es anterior al inicial");
			calcular_diferencia_tiempos(t1,t2,&t);
			printf("\nTiempo final:        ");
			escribir_tiempo(t2);
			printf("\nTiempo inicial:      ");
			escribir_tiempo(t1);
			printf("\nTiempo transcurrido: ");
			escribir_tiempo(t);
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

void leer_tiempo(tipo_tiempo *t){
	do{	printf("\tHora (0-23): ");
			scanf(" %d", &t->h);
	}while((t->h<0)||(t->h>23));
	do{	printf("\tMinutos (0-59): ");
			scanf(" %d", &t->mn);
	}while((t->mn<0)||(t->mn>59));
	do{	printf("\tSegundos (0-59): ");
			scanf(" %d", &t->sg);
	}while((t->sg<0)||(t->sg>59));
	do{	printf("\tCentesimas (0-99): ");
			scanf(" %d", &t->cs);
	}while((t->cs<0)||(t->cs>99));
}

void calcular_diferencia_tiempos(tipo_tiempo t1,tipo_tiempo t2,tipo_tiempo *t){
	if(t2.cs<t1.cs){
		t2.cs+=100;
		t2.sg--;
	}
	t->cs=t2.cs-t1.cs;
	if(t2.sg<t1.sg){
		t2.sg+=60;
		t2.mn--;
	}
	t->sg=t2.sg-t1.sg;
	if(t2.mn<t1.mn){
		t2.mn+=60;
		t2.h--;
	}
	t->mn=t2.mn-t1.mn;
	t->h=t2.h-t1.h;
	if (t->h<0)
		t->h=t->h+24;
}

void escribir_tiempo(tipo_tiempo t){
	/*printf("\tHora:       %2d\n",t.h);
	printf("\tMinutos:    %2d\n",t.mn);
	printf("\tSegundos:   %2d\n",t.sg);
	printf("\tCentesimas: %2d\n",t.cs);*/
	if(t.h<10)
		printf("0");
	printf("%d:",t.h);
	if(t.mn<10)
		printf("0");
	printf("%d:",t.mn);
	if(t.sg<10)
		printf("0");
	printf("%d.",t.sg);
	if(t.cs<10)
		printf("0");
	printf("%d",t.cs);
}

int es_anterior(tipo_tiempo tf,tipo_tiempo ti){
	int ant;

	ant=0;
	if(tf.h<ti.h)
		ant=1;
		else 	if(tf.h==ti.h)
					if(tf.mn<ti.mn)
						ant=1;
					else	if(tf.mn==ti.mn)
								if(tf.sg<ti.sg)
									ant=1;
								else	if(tf.sg==ti.sg)
											if(tf.cs<ti.cs)
												ant=1;
	return ant;
}

