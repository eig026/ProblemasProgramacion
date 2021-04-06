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

><img src="iconos/prob.png">
> Construir un programa que calcule e imprima en pantalla la masa en kilogramos de una bola de hierro dado por teclado su diámetro en centímetros. Conocidos el valor de la densidad del hierro, densidad(Fe)=7.86 g/cm3

> #### Entrada
> - Diámetro de la masa
> - Debe ser un valor positivo
> - masa >0

> #### Fórmulas de cálculo:
> - masa=***densidad*** * ***volumen***
> - Densidad=<img src="https://render.githubusercontent.com/render/math?math=7.86 \quad g/cm^3">
> Volumen =<img src="https://render.githubusercontent.com/render/math?math=4/3*PI*radio^3">
> - PI=***3.141593***
> - radio=***diámetro/2***

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  CalculoMasaBolaHierro.psc](./Secuencial/CalcularMasaBolaHierro.psc) <https://github.com/MaterialesProgramacion/ProblemasProgramacion/blob/master/Secuencial/CalcularMasaBolaHierro.psc>
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ CalculoMasaBolaHierro.c](./Secuencial/CalcularMasaBolaHierro.c)


### Calculo vectorial básico

>  <img src="iconos/prob.png">
> Construir un programa que lea por teclado los componentes espaciales de dos vectores y que calcule e imprima en pantalla la suma de los dos vectores, su producto escalar y  vectorial.

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[calculoVectorial.psc](./Secuencial/calculoVectorial.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[  calculoVectorial.c](./Secuencial/calculoVectorial.c)


### Distribución de los envases

>   <img src="iconos/prob.png"> Una empresa de envasado automático de aceite dispone de diversos tipos de envases con capacidades de 50, 20, 10, 5, 2 y 1 litro, respectivamente. Construir un programa que dado por teclado un número entero de litros a envasar, determine el menor número de envases completos necesarios e indique el número de envases de cada tipo, presentándolos en pantalla

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[ calcularNumeroEnvases.psc](./Secuencial/calcularNumeroEnvases.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ calcularNumeroEnvases.c](./Secuencial/calcularNumeroEnvases.c)



### Aceleración Normal

>   <img src="iconos/prob.png"> Diseñar un programa que calcule la aceleración normal (o centrípeta) de una partícula con movimiento circular uniforme, dados por teclado la velocidad angular (<img src="https://render.githubusercontent.com/render/math?math=\omega">) de la misma *rad/sg* y el radio *R* de la trayectoria (*m*), y que presente el resultado en pantalla. Nota:	<img src="https://render.githubusercontent.com/render/math?math=a_N=\omega^2R">.


&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  aceleracionNormal.psc](./Secuencial/aceleracionNormal.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ aceleracionNormal.c](./Secuencial/aceleracionNormal.c)


### Centigrados to Fahrenheit

>   <img src="iconos/prob.png"> Diseñar un programa que convierta grados centígrados (Celsius) a Fahrenheit.

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  centigradosaFarenheit.psc](./Secuencial/centigradosaFarenheit.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ centigradosaFarenheit.c](./Secuencial/centigradosaFarenheit.c)

### Masa de un tronco cónico
>   <img src="iconos/prob.png"> Diseñar un programa que calcule e imprima la masa en kg de una pieza de hierro maciza con forma de tronco de cono circular recto, dados por teclado los valores de los radios *a* y *b* (cm), y el valor de la altura *h* (cm)
Volumen=<img src="https://render.githubusercontent.com/render/math?math=\pi h(a^2+ab+b^2)/3">
Densidad=<img src="https://render.githubusercontent.com/render/math?math=7.86 \quad g/cm^3">

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  masaPiezaTroncoCono.psc](./Secuencial/masaPiezaTroncoCono.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ masaPiezaTroncoCono.c](./Secuencial/masaPiezaTroncoCono.c)




### Momento de fuerza
>   <img src="iconos/prob.png"> Diseñar un programa que calcule el momento (M) de una fuerza con respecto a un punto, dados por teclado las componentes de la fuerza (F), las coordenadas momentoFuerza su punto de aplicación (A) y las del punto respecto del cual se calcula el momento (O). Presentar el resultado especificando el módulo y la dirección (momentoFuerzator unitario) de dicho vector

&ensp;&ensp;&ensp;  <img src="iconos/pseudo.png">[  momentoFuerza.psc](./Secuencial/momentoFuerza.psc)
&ensp;&ensp;&ensp;  <img src="iconos/c.png">[ momentoFuerza.c](./Secuencial/momentoFuerza.c)

### Momento angular
>   <img src="iconos/prob.png"> Diseñar un programa que calcule el momento angular (L) del sistema de la figura con respecto al punto O, dados por teclado el valor de la masa  **m** de cada esfera (Kg), la longitud del brazo **R** (metros) y la velocidad angular <img src="https://render.githubusercontent.com/render/math?math=$\omega$"> (rad/sg)


### Cambio de modenas
>   <img src="iconos/prob.png"> Diseñar un programa que calcule e imprima en pantalla el cambio que se debe devolver a un cliente, utilizando el menor número de billetes y/o monedas, por la compra de un artículo, dados por teclado su precio (euros y céntimos de euro) así como el importe pagado por el cliente (euros y céntimos de euro)

********************************
[Capítulo anterior. Primeros pasos](primerospasos.md)
|
[Capítulo siguiente. Selectiva ](selectiva.md)
