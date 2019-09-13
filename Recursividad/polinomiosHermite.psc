Algoritmo Modulo_principal
Var      c: caracter
         i,n: entero
         x: real
   
    Repetir   
        Escribir "POLINOMIOS DE HERMITE"
        Escribir "Introduzca valor de x: "
        Leer x
        Escribir "Introduzca nº de polinomios: "
        leer_entero_no_negativo(n)
        i<-0
        Mientras(i<=n) Hacer
            Escribir "Polinomio nº ",i, "(",x, ")=",hermite(i,x)
            i<-i+1
        Finmientras
           Escribir "Ejecutar de nuevo (S/N): "
           Leer(c)
   Hasta_que (c='N') o (c='n')
Finalgoritmo

Procedimiento leer_entero_no_negativo(n: entero(S))
Repetir
  Escribir "Introduzca entero no negativo: "
  Leer n
Hastaque (n>=0)
Finprocedimiento

Funcion hermite(n: entero(E), x: real(E)): real
  
Si (n=0)
   Entonces Devolver (1)
   Sino
        Si (n=1)
          Entonces Devolver(x)
          Sino Devolver(2*x*hermite(n-1,x)-2*(n-1)*hermite(n-2,x))
        Finsi
Finsi
Finfuncion
