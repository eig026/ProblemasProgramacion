Algoritmo Módulo_principal
Var	c: caracter
	 n,m: entero
	 comb: entero
Inicio	Repetir 	 Escribir("CALCULO DE COMBINACIONES")
	               Leer_datos(n,m)
		comb<-calcular_combinaciones(n,m)
		Escribir_resultados(n,m,comb)
		Escribir("Desea efectuar una nueva operacion (s/n)? ")
		Leer(c)
	Hasta_que (c='N')ó(c='n')
Fin_algoritmo_principal

Procedimiento Leer_datos(n: entero(S), m: entero(S))
Inicio     Escribir("Introduzca numero de objetos: ")
	leer_entero_positivo(n)
	Escribir("Introduzca m: ")
	leer_entero_rango(1,n,m)
Fin_procedimiento

Procedimiento leer_entero_positivo(n: entero (S))
Inicio	Repetir	Escribir("Introduzca entero positivo: ")
		Leer(n)
	Hasta_que (n>0)
Fin_procedimiento

Procedimiento leer_entero_rango(a: entero (E), b: entero (E), m:entero(S))
Var	aux: entero
Inicio	Si(a>b)
	Entonces   aux<-a
		      a<-b
		      b
              <-aux
	Fin_si
	Repetir	Escribir("Introduzca entero [",a, ",",b, "]: ")
		Leer(m)
	Hasta_que (m≥a)y(m≤b)
Fin_procedimiento

Funcion calcular_combinaciones(n: entero (E), m: entero(E)): entero
Inicio	Devolver(factorial(n)/(factorial(m)*factorial(n-m)))
Fin_función

Funcion factorial(n: entero (E)):entero
Var	 i: entero
	 fac: entero
Inicio	fac<-1
	i<-1
	Mientras (i≤n) Hacer
		fac<-fac*i
		i<-i+1
	Fin_mientras
	Devolver(fac)
Fin_funcion

Procedimiento escribir_resultados(n,m,c: entero (E))
Inicio	Escribir("Combinaciones de ",n, " elementos tomados de ")
              Escribir(m, " en ",m, "= ",c)
Fin_procedimiento
