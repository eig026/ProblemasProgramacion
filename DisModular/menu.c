/*
 * @authors Equipo docente programacion grado de ingenieria 
 * @university  UAL
 * @date 2019-02-06
  
   */



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Prototipos de funciones */
void leer_opcion_menu(char *c);
void ejecutar_opcion(char c);
void ej_1_TEC_2(void);
void ej_2_TEC_2(void);
void ej_2_TEC_3(void);
void pausa(void);

/* Definiciones de funciones */
int main(){
	char c;

    do{ system("cls");
        leer_opcion_menu(&c);
        ejecutar_opcion(c);
    }while (c!='4');
    return 0;
}

void ejecutar_opcion(char c){
    switch(c){
    case '1': ej_1_TEC_2();
              pausa();
              break;
    case '2': ej_2_TEC_2();
              pausa();
              break;
    case '3': ej_2_TEC_3();
              pausa();
              break;
    case '4': printf("\n\nFIN DE EJECUCION");
              pausa();
              break;
    default:  printf("\a");
              break;
    }
}

void leer_opcion_menu(char *c){
	printf("      MENU DE OPCIONES\n");
	printf("      ================\n\n");
	printf("\t1.- Calcular aceleracion normal\n");
	printf("\t2.- Convertir grados centigrados a Fahrenheit\n");
	printf("\t3.- Calcular temperatura a partir de voltaje del sensor\n");
	printf("\t4.- Finalizar ejecucion\n\n");
	printf("\t\tIntroduzca opcion: ");
	*c=getch();
}

void ej_1_TEC_2(void){
	float an,va,r;

	system("cls");
	printf("ACELERACION NORMAL (O CENTRIPETA)\n");
	printf("=================================\n\n");
	printf("Introduzca velocidad angular (rad/sg): ");
	scanf(" %f",&va);
	printf("Introduzca radio de la trayectoria (m): ");
	scanf(" %f",&r);
	an=va*va*r;
	printf("\nLa aceleracion normal vale: %.2f m/sg2",an);
}

void ej_2_TEC_2(void){
  /* Insertar declaraciones e instrucciones del programa 2 de TEC_2 */
}

void ej_2_TEC_3(void){
  /* Insertar declaraciones e instrucciones del programa 2 de TEC_3 */
}

void pausa(void){
	printf("\nPulse cualquier tecla para continuar ");
	getch();
}
