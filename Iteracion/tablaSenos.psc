Algoritmo TablasSenos
	// Programa que imprime en pantalla las tablas de	
	// la funcion seno(n*x) para valores de n de 1 a 10	
	// en el primer cuadrante (x: [0,90]), de 0.1 de incr.	
	INC=0.1		
	
	n<-1		
	Mientras(n<=10) Hacer	// Bucle externo 
		// Cabecera de la tabla 
		Escribir sin saltar "Seno("
		Escribir sin saltar n
		Escribir sin saltar "*x)"
		Escribir  " " 
		j<-1
		x<-0
		Mientras(j<=10) Hacer
			x<-x+INC
			Escribir sin saltar  x 
			Escribir sin saltar  " " 
			j<-j+1
		Fin mientras
		Escribir " " 
		x<-0
		i<-0
		Mientras(i<90) Hacer // Bucle intermedio 
			Escribir x
			// Bucle interior 
			j<-1
			Mientras(j<=10) Hacer
				x<-x+INC
				Escribir sin saltar sen(n*x*PI/180)
				j<-j+1
			Fin mientras
			Escribir " " 
			i<-i+1
		Fin mientras
		n<-n+1
	Fin mientras
Fin algoritmo
