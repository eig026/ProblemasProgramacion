/*
 * @authors Equipo docente Programación
 * @project Creación de Materiales Didácticos en la Univer. de Almería (2021-2022)
 * Grados en Ingeniería Elécctrica, Electrónica Industrial, Mecénica y Química industrial
 * @date 2021-02-06

  Este programa saludara al usuario incorporando su nombre y apellidos al saludo formal
 */

#include <stdio.h>

int main()
{
    char nombre[30], apellidos[30];

    printf("Por favor, introduzca su nombre: ");
    scanf(" %[^\n]s", nombre);
    printf("Por favor, introduzca sus apellidos: ");
    scanf(" %[^\n]s", apellidos);
    printf("\n\nSaludos D. %s", nombre);
    printf(" %s", apellidos);
    printf("\n\nPulse una tecla para finalizar");
    getchar();
    return 0;
}
