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





### Tabla de senos
>  <img src="iconos/prob.png">   Construir un programa que imprima en pantalla las tablas de la función
sin(n*x) para valores de n desde 1 hasta 10, y para valores de x de 0 a 90º con incrementos
del ángulo de 0.1º.


&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[tablaSenos.psc](./Iteracion/tablaSenos.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/tablaSenos.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ tablaSenos.c](./Iteracion/tablaSenos.c)



### Raiz cuarta
>  <img src="iconos/prob.png"> Construir un programa que calcule e imprima en pantalla la raíz cuarta de un
número real positivo introducido por teclado. El número de decimales del cálculo se introducirá
también por teclado y deberá ser inferior o igual a 10.


&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[raizCuarta.psc](./Iteracion/raizCuarta.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/raizCuarta.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ raizCuarta.c](./Iteracion/raizCuarta.c)


### Triangulo de Pascal
>  <img src="iconos/prob.png"> Construir un programa que imprima en pantalla el triángulo de Tartaglia
(también llamado triángulo de Pascal) dado por teclado el número de la última fila del mismo
(con un máximo de 20 filas)



&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[trianPascal.psc](./Iteracion/trianPascal.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/trianPascal.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ trianPascal.c](./Iteracion/trianPascal.c)




### Convexidad de polígonos
>  <img src="iconos/prob.png">  Construir un programa para identificar si un polígono es convexo (todos sus
ángulos interiores son menores de 180º) o no (cóncavo), estudiando el cambio de signo de la
componente z del producto vectorial de dos vectores de arista consecutivos. El programa solicitará
por teclado el nº de vértices del polígono (mayor o igual a 3), así como las coordenadas bidimensionales (x,y) de cada uno de los vértices vi, identificando la concavidad/convexidad  e imprimiendo en pantalla el mensaje correspondiente.

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[analizarConvexos.psc](./Iteracion/analizarConvexos.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/analizarConvexos.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ analizarConvexos.c](./Iteracion/analizarConvexos.c)



### Cuadrados de Lagrange
>  <img src="iconos/prob.png"> Construir un programa que dado un número entero positivo por teclado,
imprima en pantalla todas las formas diferentes en que puede expresarse dicho número como la suma de cuatro cuadrados de enteros no negativos (teorema de los cuatro cuadrados de Lagrange). Por ejemplo

 10 = 02 + 02 + 12 + 32 = 0 + 0 + 1 + 9
 10 = 12 + 12 + 22 + 22 = 1 + 1 + 4 + 4

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[cuatroCuadrado.psc](./Iteracion/cuatroCuadrado.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Iteracion/cuatroCuadrado.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ cuatroCuadrado.c](./Iteracion/cuatroCuadrado.c)




Diseñar un programa que calcule e imprima en pantalla la suma de todos los
números impares múltiplos de 3 comprendidos entre 0 y n, dado un número entero positivo n
por teclado



Diseñar un programa que calcule e imprima en pantalla la potencia de un número, dados
por teclado el número base (real) y el exponente (entero).




Diseñar un programa que calcule e imprima en pantalla el factorial de un
número entero no negativo dado por teclado.




Diseñar un programa que dado por teclado un valor x mayor que –1 y menor
que +1, calcule y presente en pantalla la siguiente suma: (Solución A.16)
S(x) = x􀀀(x2=2)+(x3=3)􀀀(x4=4)+::::(xn=n) 1) Para un valor n dado introducido por
teclado.
2) Hasta un sumando n (no incluido) tal que abs(xn=n)  E, donde el valor de E también se
introduce por teclado.



Diseñar un programa que lea por teclado un conjunto de datos de temperatura
en el intervalo [-50,+50], y que calcule su media aritmética y su desviación estándar. El
tamaño del conjunto de datos no se especifica a priori, finalizándose la entrada de datos con
el valor –99.



Diseñar un programa que calcule la resistencia equivalente de un conjunto
de hasta un máximo de 100 resistencias en paralelo. El programa deberá leer por teclado las
resistencias individuales en ohmios, de una en una y adecuadamente validadas, finalizando
la entrada de datos bien cuando se introduzca un valor 0 para la resistencia o bien cuando
se haya introducido el nº máximo de resistencias, presentando en pantalla la resistencia
equivalente en ohmios.


Diseñar un programa que calcule e imprima en pantalla el centroide de
un objeto con forma poligonal (centroide: posición del centro de masas para un objeto con
densidad uniforme). El número de lados del polígono (n) será leído previamente por teclado,
comprobándose que es mayor o igual a 3, introduciéndose a continuación en orden la abscisa
(x) y la ordenada (y) de cada uno de los n vértices del polígono


Diseñar un programa que integre la función f(x) = x3 􀀀 3x2 + 5 en un
intervalo, esto es que calcule el área bajo la curva, mediante un proceso de muestreo en
pasos discretos.




Construir un programa que calcule una raíz (cero) de la función f(x) =
x5 􀀀 x4 + x3 􀀀 3, mediante el método de bisección. Dicho método se basa
en el teorema de Bolzano que dice que si una función f(x) es continua y toma en los extremos
de un intervalo [a; b] valores de signo opuesto, entonces la función admite al menos una raíz
en dicho intervalo. Para el cálculo de la raíz, se parte del intervalo inicial [xizq; xder], se calcula
el punto medio xm y se evalúa el signo del producto f(xizq)  f(xm)

Si f(xizq)  f(xm) < 0 se debe redefinir límite izquierdo del intervalo: xder   xm
Si f(xizq)  f(xm) > 0 se debe redefinir límite izquierdo del intervalo: xizq   xm
Si f(xizq)  f(xm) = 0 hay una raiz en xm
El proceso anterior de reducción del intervalo a la mitad se repite hasta encontrar una
raíz o bien hasta que el tamaño del intervalo sea menor que un valor de precisión E dado. En
este último caso la raíz se aproxima por el valor central de dicho intervalo.
El programa deberá leer por teclado dos valores a y b que cumplan la condición del teorema
de Bolzano, así como un valor positivo para la precisión (exactitud o error) E deseada,
escribiendo en pantalla la raíz (x) y el valor correspondiente de la función (f(x)). Si los valores
dados no cumplen la condición de Bolzano se volverán a leer por teclado solo en el
caso de que sean distintos y ninguno de ellos sea una raíz. El programa se ejecutará de
forma reiterada para un nuevo conjunto de datos de entrada, finalizando su ejecución cuando
coincidan los límites izquierdo y derecho del intervalo.


Diseñar un programa que lea por teclado las distancias recorridas por un
coche y los tiempos empleados en los diferentes tramos de su trayectoria, y que calcule
e imprima la velocidad media empleada en toda la trayectoria, así como el primer tramo
donde se alcanzó la máxima velocidad media por tramo, presentando la misma en la pantalla.


Diseñar un programa que lea por teclado un número natural menor de 20,
y que imprima en pantalla bien un rombo de asteriscos si el número es impar, o bien un
triángulo rectángulo si el número es par.


¿Qué es el invariante de un bucle?. Determinar el invariante del bucle(s)
del siguiente problema y a partir del mismo diseñar el bucle(s), explicando brevemente los
pasos realizados: dado un número natural menor de 20 presentar en pantalla un triángulo
rectángulo con base y altura igual al número introducido y formado por los primeros números
naturales en orden inverso.


Construir un programa que dibuje en pantalla mediante asteriscos las aristas
visibles de un paralelepípedo, dados por teclado las dimensiones del mismo adecuadamente
validadas: ancho (entre 3 y 20 asteriscos), alto (entre 3 y 10) y profundidad (entre 3 y 10). En
la impresión en pantalla se intentará simular una proyección paralela axonométrica de las caras
visibles del paralelepípedo, según el formato indicado en los datos de prueba.










********************************
[Capítulo anterior. Selectiva](selectiva.md)
|
[Capítulo siguiente. Modulos](modulos.md)
