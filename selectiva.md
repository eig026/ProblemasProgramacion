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
 
  **Determinante(M)\not =0**  Sistema compatible determinado. La única solución es (0,0,0) que no es un autovector, el sistema lineal de ecuaciones no se corresponde con ningún autovalor

-  Rango =2

	a_ij * a_kl-a_il * a_kj <> 0 Hay dos ecuaciones linealmente independientes (i y k):
     a * x + b * y + c * z=0         d * x + e * y + f * z=0
Las variables de las columnas j y l se pueden expresar en función de la tercera variable. Hay un autovector asociado al autovalor que se puede calcular asignando el valor 1 a la tercera variable, calculando los valores de las otras variables, y normalizando el vector resultante.   

-  Rango =1





********************************
[Capítulo anterior. Secuencia](secuencia.md)
|
[Capítulo siguiente. Iterativa](iterativa.md)
