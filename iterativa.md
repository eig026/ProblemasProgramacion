<link rel="stylesheet" type="text/css" href="estilo.css" media="screen" />

# Programación estructurada. Iterativa

A menudo en la resolución de un problema es necesario ejecutar  una instrucción o un bloque de instrucciones más de una vez. Por  ejemplo **Implementar un programa que calcule  la suma de N números leídos desde teclado**.

 Se podría escribir un programa en el que  que apareciese repetido el código que deseamos, pero tenemos varios inconvenientes. El primero es que el programa resultante sería muy largo, el segundo  que tendríamos mucho código duplicado lo que dificulta los futuros cambios en el código y el más importante que una vez escrito el programa para un número determinado de repeticiones (p.ej. sumar matrices 3x3), el mismo programa no podríamos reutilizarlo si necesitásemos realizar un número distinto de operaciones (p.ej. matrices 4x4).

 Las estructuras  de  control  repetitivas  o  iterativas,  también conocidas   como   **bucles**,   nos   permiten   resolver   este tipo de problemas. Algunas se pueden usar cuando   el   número   de   veces   que   deben   repetirse   las operaciones es conocido y     otras       permiten    repetir    un    conjunto    de operaciones mientras se cumpla una condición.



<img src="iconos/bucle.png"  width="500"/>

## Problemas donde se necesita utilizar bucles


### Mayor temperatura
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima la mayor de un conjunto de datos de temperaturas introducidas por teclado. El número de datos es conocido a priori (se lee porteclado).

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  Mayor Temperatura.psc](./Iteracion/temperatura.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/temperatura.psc)

### Mayor temperatura con centinela
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima la mayor de un conjunto de datos de temperaturas introducidas por teclado. El número de datos no es conocido a priori, finalizándose la introducción de datos con el valor –999.

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  Mayor Temperatura.psc](./Iteracion/temperaturaCentinela.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/temperaturaCentinela.psc)



### Fuerzas concurrentes
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima la resultante de un conjunto de fuerzas concurrentes. Las componentes espaciales de cada fuerza son introducidas por
teclado de una en una, finalizándose la entrada de datos con una fuerza nula

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  fuerzasConcurrentes.psc](./Iteracion/fuerzasConcurrentes.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/fuerzasConcurrentes.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ fuerzasConcurrentes.c](./Iteracion/fuerzasConcurrentes.c)


### Adivinar un número
>  <img src="iconos/prob.png">
Construir un programa que sea capaz de adivinar un número menor que 100, definido al azar en n intentos.

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  AdivinaNumero.psc](./Iteracion/AdivinaNumero.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/AdivinaNumero.psc)





### Sucesión de Fibonacci
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima en pantalla el término n-ésimo
de la serie de Fibonacci, dado por teclado el número del término a calcular

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  fibonacci.psc](./Iteracion/fibonacci.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/fibonacci.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ fibonacci.c](./Iteracion/fibonacci.c)

### Producto de Wallis
>  <img src="iconos/prob.png">
Construir un programa que calcule el producto de Wallis (expresión utilizada
en matemáticas para representar el valor de PI/2), hasta un factor tal que la diferencia en
valor absoluto entre dicho término y el número 1 sea inferior a un valor dado (precisión). El
programa leerá por teclado dicho valor de precisión, calculará el producto de Wallis hasta el
término correspondiente (sin incluirlo) utilizando la siguiente fórmula y presentará el resultado
en la pantalla

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  fibonacci.psc](./Iteracion/fibonacci.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/fibonacci.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ fibonacci.c](./Iteracion/fibonacci.c)

### Sumatoria
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima en pantalla la sumatoria de n terminos de (i/2^i)
donde el número de sumandos se introduce por teclado.

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[calculoSumatoria.psc](./Iteracion/3maxcalculoSumatoria.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/3maccalculoSumatoria.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ calculoSumatoria.c](./Iteracion/calculoSumatoria.c)


### Máximo Comun Divisor
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima en pantalla el máximo común
divisor de dos números enteros positivos introducidos por teclado

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[maximoComunDivisor.psc](./Iteracion/maximoComunDivisor.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/maximoComunDivisor.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ maximoComunDivisor.c](./Iteracion/maximoComunDivisor.c)


## Problemas donde se necesita utilizar bucles anidados

###  Tabla de multiplicar
>  <img src="iconos/prob.png">  Construir un programa que imprima en pantalla la tabla de multiplicar de los 9
primeros números naturales

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[tablaMultiplicarFinal.psc](./Iteracion/tablaMultiplicarFinal.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/maximoComunDivisor.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ tablaMultiplicarFinal.c](./Iteracion/tablaMultiplicarFinal.c)



###  Rectángulo con asteriscos
>  <img src="iconos/prob.png">    Construir un programa que imprima en pantalla mediante asteriscos las aristas
de un rectángulo, dados por teclado las dimensiones del mismo, donde la base debe estar
comprendida entre 3 y 40, y la altura entre 3 y 20

    * * * * * * * * * * * * * * *
    *                           *
    *                           *
    *                           *
    *                           *
    * * * * * * * * * * * * * * *

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[rectanguloAsteriscos.psc](./Iteracion/rectanguloAsteriscos.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/rectanguloAsteriscos.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ rectanguloAsteriscos.c](./Iteracion/rectanguloAsteriscos.c)







********************************
[Capítulo anterior. Selectiva](selectiva.md)
|
[Capítulo siguiente. Modulos](modulos.md)
