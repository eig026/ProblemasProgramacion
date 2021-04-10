# Programación estructurada. Selectiva


La estructura de secuencia se trató en el capítulo anterior. Por defecto,  las instrucciones de un programa se ejecutan secuencialmente.
Sin embargo, al describir la resolución de un problema, es normal que tengamos que tener en cuenta condiciones que influyen sobre la secuencia de pasos que hay que dar para resolver el problema. Estas  selectivas se utilizan para tomar decisiones lógicas; de ahí que se suelan denominar también estructuras de decisión o alternativas y son utilizadas en todos lenguajesde programación. Las estructuras selectivas son aquellas que dirigen la ejecución de un programa hacia urupo de senencias del resultado de la condición. Respondiendo a la necesidad der:

```
 Si condición
 entonces
    hacer acción X ...
    sino
      hacer acción Y ...
```


# Problemas donde se necesita el uso de la estructura de selección/decisión


### Exceso de velocidad
>  <img src="iconos/prob.png">
Construir un programa que lea por teclado un valor de velocidad y que escriba en pantalla un mensaje si la velocidad supera los 120 Km/h y en cuanta cantidad los supera

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  excesoVelocidad.psc](./Selectiva/excesoVelocidad.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Selectiva/excesoVelocidad.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ excesoVelocidad.c](./Selectiva/excesoVelocidad.c)



### Calcular la temperatura máxima
>  <img src="iconos/prob.png">
Construir un programa que lea por teclado dos valores de temperatura en grados centígrados y que determine e imprima en pantalla el mayor valor

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  temperaturaMaximaSelectivaSimple.psc](./Selectiva/temperaturaMaximaSelectivaSimple.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Selectiva/temperaturaMaximaSelectivaSimple.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ temperaturaMaximaSelectivaSimple.c](./Selectiva/temperaturaMaximaSelectivaSimple.c)



### Identificar el nivel del huracan
>  <img src="iconos/prob.png">
Construir un programa que lea por teclado el nivel de un huracán y que presente en pantalla la categoría (daño) asociada al mismo, según la clasificación de Saffir-Simpson


&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  huracanes.psc](./Selectiva/huracanes.psc) [Ver](https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Selectiva/huracanes.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ huracanes.c](./Selectiva/huracanes.c) &ensp;&ensp;&ensp;  <img src="iconos/c.png">[ huracanesalternativa.c](./Selectiva/huracanes2.c)


### Calcular el área de un triangulo
>  <img src="iconos/prob.png">
La fórmula de Herón halla el área de un triángulo del cual se conocen todos sus lados. El área se calcula a partir del semiperímetro del triángulo s y de la longitud de los lados (l_1, l_2 y l_3)



### Raices de una ecuación de segundo grado
>  <img src="iconos/prob.png">
Construir un programa que calcule e imprima en pantalla las raíces de la ecuación de segundo grado:
<img src="https://render.githubusercontent.com/render/math?math=Ax^2^ +Bx+C=0">, dados por teclado los coeficientes A, B y C


### Mayor de tres temperaturas
>  <img src="iconos/prob.png">
 Construir un programa que calcule e imprima la mayor de tres temperaturas (Centígrados) introducidas por teclado.
 
### Calcular la tarifa de taxi
>  <img src="iconos/prob.png">

La tarifa de un taxi es la siguiente:
 -     Una cantidad fija de 30 € si no se sobrepasan los 30 km de recorrido.
 -     Para más de 30 km se consideran los siguientes supuestos:
     -      Si no se sobrepasan los 100 km, 15 € por km que exceda de los 30, además de los 30 €.
     -      Si se sobrepasan los 100 km, 10 € por km que exceda de los 100, 15 € por km desde los 30 a los 100, y los 30 €.


### Intersección de dos segmentos en el plano
>  <img src="iconos/prob.png">
Construir un programa que determine si dos segmentos de línea recta en el plano XY se cruzan e imprima en pantalla el punto/segmento de intersección o un mensaje de texto en caso de que no se crucen, dados por teclado las coordenadas cartesianas (x,y) de dos parejas de puntos diferentes que definen cada uno de los segmentos.


### Calculo de autovectores
>  <img src="iconos/prob.png">
Construir un programa en C que calcule e imprima en pantalla el autovector (o autovectores) asociado(s) a un autovalor, dados por teclado los coeficientes del sistema lineal homogéneo de ecuaciones a resolver:

        a_11*x+a_12*y+a_13*z=0
        a_21*x+a_22*y+a_23*z=0$
        a_31*x+a_32*y+a_33*z=0$

El sistema debe de ser compatible indeterminado y los autovectores son soluciones no nulas, linealmente independientes. Para la determinación de los autovectores hay que analizar el rango de la matriz de coeficientes M: 

-   Rango=3
 
  **Determinante(M) <> 0**  Sistema compatible determinado. La única solución es (0,0,0) que no es un autovector, el sistema lineal de ecuaciones no se corresponde con ningún autovalor

-  Rango =2

	a_ij * a_kl-a_il * a_kj <> 0 Hay dos ecuaciones linealmente independientes (i y k):
     a * x + b * y + c * z=0         d * x + e * y + f * z=0
Las variables de las columnas j y l se pueden expresar en función de la tercera variable. Hay un autovector asociado al autovalor que se puede calcular asignando el valor 1 a la tercera variable, calculando los valores de las otras variables, y normalizando el vector resultante.   

-  Rango =1

a_ij <> 0  Solo hay una ecuación linealmente independiente (i):        a * x + b * y + c * z=0
La variable j se puede expresar en función de las otras dos. Hay dos autovectores asociados al autovalor, que se pueden calcular asignando alternativamente los valores 0 y 1 a las dos variables libres, calculando la tercera variable, y normalizando los dos vectores resultantes

-  Rango 0

a_ij=0, Hay tres autovectores asociados al autovalor: (1,0,0), (0,1,0)$ y $(0,0,1).


### Coincidencia de temperaturas
>  <img src="iconos/prob.png">
Diseñar un programa que lea por teclado tres temperaturas e imprima un mensaje en pantalla indicando si los tres valores coinciden, si al menos dos ellos coinciden o si los tres son diferentes.


### Lectura de datos de sensor de temperatura
>  <img src="iconos/prob.png">
Un indicador de temperatura de un automóvil normalmente lee temperaturas en el intervalo -30º a 120º y el voltaje que proporciona el sensor a la salida del motor está comprendido entre 5 y 10 voltios. Suponiendo que la relación es lineal, diseñar un programa que calcule e imprima en pantalla la temperatura a partir de un valor del voltaje introducido previamente por teclado. Para valores de voltaje fuera del rango considerado, imprimir un mensaje de error en la lectura de la temperatura

### Trasformación de coordenadas polares a coordenadas cartesianas
>  <img src="iconos/prob.png">
Diseñar un programa que permita pasar de coordenadas cartesianas bidimensionales a coordenadas polares. El programa leerá por teclado las coordenadas cartesianas e imprimirá en pantalla las coordenadas polares correspondientes.


### Juego de adivinar un número
>  <img src="iconos/prob.png">
Diseñar un programa para adivinar e imprimir en pantalla un número de un solo dígito teniendo como información de entrada por teclado un carácter que indique si el número es par ('p') o impar ('i') y el resto de la división del número entre 5.


###  Sumar dos ángulos
>  <img src="iconos/prob.png">
Construir un programa que lea por teclado dos ángulos y calcule e imprima en pantalla su suma. Cada ángulo vendrá dado en grados, minutos y segundos, los cuales serán leídos separadamente por teclado y adecuadamente validados (0<=grados<360, 0<=minutos<60, 0<=segundos<60). El resultado de la suma se presentará en pantalla con el mismo formato

### Calculadora para vectores
>  <img src="iconos/prob.png">
Construir un algoritmo que pida por teclado dos vectores y un símbolo de operador (“+”: suma, “-”: resta, “.”: producto escalar, “x”: producto vectorial), realice la operación seleccionada y escriba el resultado en la pantalla

### Ecuacion por reducción
>  <img src="iconos/prob.png">
Diseñar un programa que resuelva un sistema lineal de tres ecuaciones con tres incógnitas mediante el método de reducción, dados por teclado los coeficientes de las incógnitas y los términos independientes de cada ecuación, y que presente en pantalla las soluciones del mismo o un mensaje de error en el caso de que el sistema no tenga solución única (sistema incompatible o compatible indeterminado)




********************************
[Capítulo anterior. Secuencia](secuencia.md)
|
[Capítulo siguiente. Iterativa](iterativa.md)
