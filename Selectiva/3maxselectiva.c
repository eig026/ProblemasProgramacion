/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

*/
/* temperaturaMaxima                                  */
/* programa que calcula la mayor de tres temperaturas */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c;
    float t1, t2, t3; /* temperaturas leídas */
    float tmax;       /* temperatura máxima  */

    do
    {
        system("cls||clear");
        printf("MAXIMA DE TRES TEMPERATURAS\n");
        printf("===========================\n\n");
        printf("Introduzca tres temperaturas:\n");
        printf("\tt1: ");
        scanf(" %f", &t1);
        printf("\tt2: ");
        scanf(" %f", &t2);
        printf("\tt3: ");
        scanf(" %f", &t3);
        if (t1 >= t2)
            if (t1 >= t3)
                tmax = t1;
            else
                tmax = t3;
        else if (t2 >= t3)
            tmax = t2;
        else
            tmax = t3;
        printf("\nTemperatura maxima: %.1f", tmax);
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        scanf(" %c", &c);
    } while ((c != 'N') && (c != 'n'));
    return 0;
}
