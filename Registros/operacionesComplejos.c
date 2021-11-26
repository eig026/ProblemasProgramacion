/* Programa que realiza diversas operaciones */
/* con dos numeros complejos:                */
/* suma, resta, multiplicacion y division    */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* Nuevos tipos de datos */
typedef struct{
	float re;
	float im;
}tipo_complejo;

/* Prototipos de funciones */
void leer_datos(tipo_complejo *a, tipo_complejo *b);
void leer_complejo(tipo_complejo *a);
void leer_opcion_menu(char *c);
void realizar_operacion(tipo_complejo a, tipo_complejo b,
        char op, tipo_complejo *r);
void sumar_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r);
void restar_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r);
void multiplicar_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r);
void dividir_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r);
void escribir_resultados(tipo_complejo a, tipo_complejo b,
        char op, tipo_complejo r);
void escribir_complejo(tipo_complejo a);
int es_cero(tipo_complejo a);

int main(){
    char c;
    char op;           /* opcion del menu (codigo de la operacion) */
    tipo_complejo a,b; /* Numeros complejos de entrada             */
    tipo_complejo r;   /* Resultado de la operacion                */

    do{ system("cls");
        printf("ARITMETICA DE COMPLEJOS\n");
        printf("=======================\n\n");
        leer_datos(&a,&b);
        do{ leer_opcion_menu(&op);
            if (op!='0')
                  if((op=='/')&&(es_cero(b))){
                        printf("\nDivision por cero");
                        getch();
                  }else{ realizar_operacion(a,b,op,&r);
                         escribir_resultados(a,b,op,r);
                         getch();
                  }
        }while(op!='0');
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        c=toupper(getch());
    }while (c!='N');
    return 0;
}

void leer_datos(tipo_complejo *a, tipo_complejo *b){
    printf("Introduzca primer numero complejo:\n");
    leer_complejo(a);
    printf("Introduzca segundo numero complejo:\n");
    leer_complejo(b);
}

void leer_complejo(tipo_complejo *a){
    printf("\tIntroduzca parte real: ");
    scanf(" %f",&a->re);
    printf("\tIntroduzca parte imaginaria: ");
    scanf(" %f",&a->im);
}

void leer_opcion_menu(char *c){
    do{ system("cls");
        printf("MENU DE OPERACIONES:\n");
        printf("====================\n\n");
        printf("\t+  Suma de numeros complejos\n");
        printf("\t-  Resta de numeros complejos\n");
        printf("\t*  Multiplicacion de numeros complejos\n");
        printf("\t/  Division de numeros complejos\n");
        printf("\t0  Fin de operaciones\n");
        printf("\t\tIntroduzca operacion: ");
        *c=getch();
    }while((*c!='+')&&(*c!='-')&&(*c!='*')&&(*c!='/')&&(*c!='0'));
}

void realizar_operacion(tipo_complejo a, tipo_complejo b,
        char op, tipo_complejo *r){
    switch(op){
    case '+': sumar_complejos(a,b,r);
              break;
    case '-': restar_complejos(a,b,r);
              break;
    case '*': multiplicar_complejos(a,b,r);
              break;
    case '/': dividir_complejos(a,b,r);
              break;
    }
}

void sumar_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r){
    r->re=a.re+b.re;
    r->im=a.im+b.im;
}

void restar_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r){
    r->re=a.re-b.re;
    r->im=a.im-b.im;
}

void multiplicar_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r){
    r->re=a.re*b.re-a.im*b.im;
    r->im=a.re*b.im+a.im*b.re;
}

void dividir_complejos(tipo_complejo a, tipo_complejo b,
        tipo_complejo *r){
    float den;        /* denominador de la expresion */
    den=b.re*b.re+b.im*b.im;
    r->re=(a.re*b.re+a.im*b.im)/den;
    r->im=(a.im*b.re-a.re*b.im)/den;
}

void escribir_resultados(tipo_complejo a, tipo_complejo b,
        char op, tipo_complejo r){
    printf("\n\n");
    escribir_complejo(a);
    printf(" %c ",op);
    escribir_complejo(b);
    printf(" = ");
    escribir_complejo(r);
}

void escribir_complejo(tipo_complejo a){
    if(a.im==0)
          if(a.re)
              printf("(%.1f)",a.re);
         else printf("(0)");
    else if(a.im>0)
              if(a.re)
                   printf("(%.1f + i*%.1f)",a.re,a.im);
              else printf("(i*%.1f)",a.im);
         else if(a.re)
                   printf("(%.1f - i*%.1f)",a.re,-a.im);
              else printf("(-i*%.1f)",-a.im);
}

int es_cero(tipo_complejo a){
    if((a.re==0)&&(a.im==0))
         return 1;
    else return 0;
}
