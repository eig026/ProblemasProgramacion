#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//#define

/* Diseño preliminar     */
/* Nuevos tipos de datos */

/* prototipos de funciones */
void leer_opcion_menu(char *c);
void opcion1(void);
void opcion2(void);
void opcion3(void);
void opcion4(void);

/* Diseño detallado          */
/* Definiciones de funciones */
int main(){
    char op;  /* opcion del menu */

    do{ system("cls");
        leer_opcion_menu(&op);
        switch(op){
        case '1': opcion1();
                  break;
        case '2': opcion2();
                  break;
        case '3': opcion3();
                  break;
        case '4': opcion4();
                  break;
        case '0': printf("FIN DE EJECUCION");;
                  getch();
        break;
        default:  printf("\a");
        }
    }while(op!='0');
    return 0;
}

void leer_opcion_menu(char *c){
    printf("MENU DE OPCIONES:\n");
    printf("=================\n\n");
    printf("\t1.- Opcion 1\n");
    printf("\t2.- Opcion 2\n");
    printf("\t3.- Opcion 3\n");
    printf("\t4.- Opcion 4\n");
    printf("\t0.- Fin de ejecucion\n");
    printf("\n\t\tIntroduzca opcion: ");
    *c=getch();
}

void opcion1(void){
}

void opcion2(void){
}

void opcion3(void){
}

void opcion4(void){
}
