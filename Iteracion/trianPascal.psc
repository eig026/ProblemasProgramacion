Algoritmo TrianguloPascal
//	programa que imprime en pantalla el triángulo de 	
//	Tartaglia dado por teclado el número de la última fila	
	MAX=20
	Repetir 
		Escribir "Introduzca numero de filas: "
		Leer filas 
	Hasta que (filas>0)y(filas<=MAX)
	n<-0
	Mientras (n<=filas) Hacer	// Espacios en blanco principio línea	
			m<-filas-n
			Mientras(m>0) Hacer	
				Escribir Sin Saltar "  "
				m<-m-1
			Finmientras
			// Coeficientes de la fila	
			coef<-1
			Escribir sin saltar coef "  "
			m<-1
			Mientras(m<=n) Hacer
				coef<- coef*(n-m+1)/m
				Escribir sin saltar coef "  "
				m<-m+1
			Finmientras
			Escribir " "
			n<-n+1
	Finmientras
Finalgoritmo
						
