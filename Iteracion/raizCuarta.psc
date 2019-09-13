Algoritmo Calculoderaizcuarta
	MAX=10
	
	Repetir	
		Escribir "Introduzca num. positivo: "
		Leer n
	Hasta que (n>=0)
	Repetir	
		Escribir "Introduzca num. decimales: "
		Leer d 
		Hasta que((d>=0)y(d<=MAX))
		
		ra <- 0
		i <- 0
		inc <- 10
		
	Mientras (i<=d) Hacer
		inc <- inc/10
		
		Mientras(ra*ra*ra*ra<n) Hacer
			ra <-ra+inc
		Fin Mientras
		
		Si (ra*ra*ra*ra>n)
			Entonces	ra <-ra-inc
		Fin si
	Fin mientras
	
	Escribir "Raiz cuarta = ", ra
Fin algoritmo
	
