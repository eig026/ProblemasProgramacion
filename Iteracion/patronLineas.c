/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXF 25
#define MAXC 80

/* Dis. Detallado */
int main()
{
    char c;
    int nf, nc, d;
    int i, j, inc;

    do
    {
        system("cls||clear");
        printf("PATRON DE RAYAS DIAGONALES\n");
        printf("==========================\n\n");
        do
        {
            printf("Introduzca num de filas: ");
            scanf(" %d", &nf);
        } while ((nf <= 0) || (nf > MAXF));
        do
        {
            printf("Introduzca num de columnas: ");
            scanf(" %d", &nc);
        } while ((nc <= 0) || (nc > MAXC));
        do
        {
            printf("Introduzca separacion lineas: ");
            scanf(" %d", &d);
        } while (d < 0);

        system("cls||clear");
        if (d < 0)
            d = 0;
        i = 1;
        inc = 0;
        while (i <= nf)
        {
            j = 1;
            while (j <= nc)
            {
                if ((j - inc - 1) % (d + 1))
                    printf(" ");
                else
                    printf("*");
                ++j;
            }
            ++i;
            inc++;
            if (inc == d + 1)
                inc = 0;
            printf("\n");
        }
        printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
        scanf(" %c", &c);
    } while ((c != 'N') && (c != 'n'));
    return 0;
}
