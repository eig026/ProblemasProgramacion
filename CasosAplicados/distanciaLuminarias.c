#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#define fm 0.70  	// Factor de mantenimiento
#define EMMIN 10.0	// Valores extremos Em (lux)
#define EMMAX 20.0
#define AMIN 2.0	// Valores extremos a (m)
#define AMAX 15.0
#define HMIN 6.0	// Valores extremos h (m)
#define HMAX 15.0

int main(){
    char c;
    double em;		// Iluminancia media en calzada (lux)
    double fu;		// factor de utilización de la instalación
    double fl;		// flujo luminoso de la lámpara (lm)
    double flmin,flmax;	// Valores extremos en función de h
    double a;		// anchura a iluminar de la calzada (m)
    double d;		// sepàración entre luminarias (m)
    double h; 		// altura de montaje (m)
    int valido;
    double x;		// auxiliar (a/h,d/h)

    do{ system("cls");
        printf("DISTANCIA ENTRE LUMINARIAS ALUMBRADO PUBLICO\n");
        printf("============================================\n\n");
		/* Lectura de datos de entrada (I) */
		do{	printf("Iluminancia media sobre calzada [%.0f,%.0f]lux: ",EMMIN,EMMAX);
			scanf(" %lf", &em);
		}while((em<EMMIN)||(em>EMMAX));
		do{	printf("Anchura de la calzada [%.0f,%.0f]m: ",AMIN,AMAX);
			scanf(" %lf", &a);
		}while((a<AMIN)||(a>AMAX));
		do{	printf("Altura de montaje prevista [%.0f,%.0f]m: ",HMIN,HMAX);
			scanf(" %lf", &h);
		}while((h<HMIN)||(h>HMAX));
		/* Límites de fl en función de h (lm*1000)*/
		if(h<8){
			flmin=3;
			flmax=10;
		}else{
			if(h<10){
				flmin=10;
				flmax=20;
			}else{
				if(h<12){
					flmin=20;
					flmax=40;
				}else{
					flmin=40;
					flmax=100;
				}
			}
		}
		/* Determinación de d mediante pruebas con valores de fl */
		valido=0;
		while(!valido){
			system("cls");
			printf("Em=%.0f lux\n",em);
			printf("fm=%.2f\n",fm);
			printf("a=%.2f m\n",a);
			printf("h=%.2f\n\n",h);
			do{	printf("Flujo luminoso lampara [%.0f,%.0f)klm: ",flmin,flmax);
				scanf(" %lf",&fl);
			}while((fl<flmin)||(fl>=flmax));
			fl*=1000;
			/* Calculo factor de utilización */
			x=a/h;
			if(x<=1){
				fu=x*0.4;
			}else{
				if(x<=2){
					fu=0.4+(x-1)*0.1;
				}else{
					fu=0.5;
				}
			}
			/* Calculo distancia de separación */
			d=fu*fm*fl/(em*a);
			printf("Distancia calculada: %.2f\n",d);
			/* Comprobación resultado */
			x=d/h;
			printf("d/h= %.2f\n",x);
			if(em<2){
				/* No tratado */
			}else{
				if(em<7){
					if((x>=4)&&(x<5)){
						valido=1;
						printf("Cumple 4<=d/h<5\n");
					}else{
						printf("No cumple 4<=d/h<5\n");
					}
				}else{
					if(em<15){
						if((x>=3.5)&&(x<4)){
							valido=1;
							printf("Cumple 3.5<=d/h<4\n");
						}else{
							printf("No cumple 3.5<=d/h<4\n");
						}
					}else{
						if(em<30){
							if((x>=2)&&(x<3.5)){
								valido=1;
								printf("Cumple 2<=d/h<3.5\n");
							}else{
								printf("No cumple 2<=d/h<3.5\n");
							}
						}else{
							/* No tratado */
						}
					}
				}
			}
			if(!valido){
				printf("Probar con otro valor de Flujo luminoso (S/N? ");
				c=toupper(getch());
				if(c!='S'){
					valido=1;
				}
			}
		}
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
   }while (c!='N');
   return 0;
}
