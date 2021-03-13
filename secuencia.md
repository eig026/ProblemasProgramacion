# Programación estructurada. Secuencia

Las fases que se definen para resolver un problema utilizando programacióne estructurada son:

- Análisis
- Diseño
    - Diseño detallado
- Codificación
- Prueba

## **Análisis**
Representa el **QUE**. Conlleva la definición concreta del problema, la especificación de los datos de entrada y salida, la identificación de las tareas a realizar, así como la definición de los criterios de validación indicando cuales son los casos para los que la solución debe resolver el problema.

## **Diseño**
Supone la elaboración de la solución, es decir el **COMO**. Conlleva la definición completa de los algoritmos y datos que se van a utilizar. Habitualmente se comienza con un diseño global o arquitectónico, donde se estudia la estructura y pasos a seguir sin utilizar ningún tipo de notación o preAlgoritmo  para refinar el resultado mediante el **diseño detallado** de los algoritmos, utilizando una notación propia de la programación estructurada como puede ser el pseudocódigo o los diagramas de flujo de datos.


## **Codificación**
Es la traducción a un lenguaje de programación de los algoritmos y conlleva la ejecución de todas las pruebas necesarias para comprobar los criterios de validez fijados en el análisis.

## **Prueba**
También llamada validación consiste en la ejecución del código escrito para comprobar que las salidas generadas se corresponden con la solución al problema según las entradas definidas para cada caso.

*******************************************

# Problemas de solución secuencial

### Calculo de la masa de una bola de hierro

> :triangular_flag_on_post:
> Construir un programa que calcule e imprima en pantalla la masa en kilogramos de una bola de hierro dado por teclado su diámetro en centímetros. Conocidos el valor de la densidad del hierro, densidad(Fe)=7.86 g/cm3

> #### Entrada
> - Diámetro de la masa
> - Debe ser un valor positivo
> - masa >0
> #### Fórmulas de cálculo:
> - masa=densidad*volumen
> - densidad(Fe)=7.86 g/cm3
> - volumen(esfera)=4*PI*radio3/3
> - PI=3.141593
> - radio=diámetro/2

&ensp;&ensp;&ensp;[:paw_prints: Ver aqui  CalculoMasaBolaHierro.psc](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Secuencial/CalcularMasaBolaHierro.psc)
&ensp;&ensp;&ensp;[:arrow_down_small: Ver aqui  CalculoMasaBolaHierro.c](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Secuencial/CalcularMasaBolaHierro.c)


### Calculo vectorial básico

> :triangular_flag_on_post:
> Construir un programa que lea por teclado los componentes espaciales de dos vectores y que calcule e imprima en pantalla la suma de los dos vectores, su producto escalar y  vectorial.

&ensp;&ensp;&ensp;[:paw_prints: Ver aqui  calculoVectorial.psc](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Secuencial/calculoVectorial.psc)
&ensp;&ensp;&ensp;[:arrow_down_small: Ver aqui  calculoVectorial.c](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Secuencial/calculoVectorial.c)


### Distribución de los envases

> :triangular_flag_on_post: Una empresa de envasado automático de aceite dispone de diversos tipos de envases con capacidades de 50, 20, 10, 5, 2 y 1 litro, respectivamente. Construir un programa que dado por teclado un número entero de litros a envasar, determine el menor número de envases completos necesarios e indique el número de envases de cada tipo, presentándolos en pantalla

********************************

[Capitulo siguiente](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/selectiva.md)
