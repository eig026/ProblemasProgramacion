Algoritmo	  moduloPrincipal
// programa que calcula: 	1+sumatoria(xi/factorial(i)) 	donde el numero 	
// de términos de la suma se introduce por teclado 		
Var		n: entero		// Numero de sumandos  	
		x: real		// Numero real         		
		suma: real

    Llamar a leer_datos(x, n)
		suma <- calcular_suma(x,n)
		Llamar a escribir_resultados(x,n,suma)
    
Finalgoritmo

Procedimiento leer_datos(x:real(S), n:entero(S))
		Llamar a leer_real(x)
		Llamar a leer_num_sumandos(n)
Finprocedimiento

Procedimiento leer_real(x:real(S))
  	Escribir "Introduzca un numero real: "
		Leer x 
Finprocedimiento

Procedimiento leer_num_sumandos(n:entero(S))
  Repetir 
      Escribir "Introduzca numero de sumandos: "
			Leer n
		Hasta que(n>0)
Finprocedimiento

Funcion calcular_suma(x:real(E), n:entero(E)):real
Var		i: entero
		suma: real
Inicio
    suma<-1
		i<-1
		Mientras(i<=n) Hacer
	  		suma<-suma+potencia(x,i)/factorial(i)
	  		i<-i+1
		Finmientras
		Devolver (suma)
Finfuncion

Funcion potencia(x:real(E), n:entero(E)):real
Inicio
  Si(n=1)
		Entonces	Devolver(x)
	Sino		Devolver(x*potencia(x,n-1))
	Finsi
Finfuncion

Procedimiento escribir_resultados(x:real(E),n:entero(E),suma:real(E))
  Escribir "Suma de ",n, " terminos de "
  Escribir x,"**i/i! = ",suma
Finprocedimiento
