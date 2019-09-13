Algoritmo RectanguloAsteriscos
	//	{ Programa que imprime en pantalla las aristas de	}
	//	{ un rectángulo dadas la base y la altura del mismo	}
	Repetir	
		Escribir("Introduzca ancho [3-40]: ")
		Leer a 
	Hasta Que ((a>=3)y(a<=40))
	Repetir
		Escribir("Introduzca altura [3-20]: ")
		Leer h 
	Hasta que ((h>=3)y(h<=20))
	Repetir
	Escribir("Introduzca profundidad [3-20]: ")
	Leer z 
    Hasta Que ((z>=3)y(z<=20))
	//{ Arista superior }
	j<- 1
	Mientras(j<z) Hacer
		Escribir Sin Saltar("  ")
		j<- j+1
	Fin mientras
	j<-1
	Mientras(j<=a) Hacer
		Escribir Sin Saltar(" *")
		j<- j+1
	Fin mientras
	Escribir("  ")
	altura <- 1
	//Cara superior
	i<- 2
	Mientras(i<z) Hacer	
		j<-1
		Mientras(j<=z-i) Hacer
			Escribir sin saltar("  ")
			j<-j+1
		Fin mientras		
		
		Escribir Sin Saltar(" *")
		k<-2
		Mientras(k<a) Hacer
			Escribir sin saltar("  ")
			k<-k+1
		Fin mientras
		Escribir sin saltar(" *")
		m<-1
		//revisar hasta altura
		Mientras(m<i-1) Hacer
			Escribir sin saltar("  ")
			m<-m+1
		Fin mientras
		Escribir (" *")
		i<-i+1
	Fin mientras
	
	//Arista superior en alzado
	
	j<- 1
	Mientras(j<=a) Hacer
		Escribir Sin Saltar(" *")
		j<- j+1
	Fin mientras
	j<- 2
	Mientras(j<z) Hacer
		Escribir Sin Saltar("  ")
		j<- j+1
	Fin mientras
	Escribir(" *")
	
	
	
	
	//{ Aristas alzado hasta altura
	i<- 2
	Mientras(i<=h-z) Hacer	
		Escribir Sin Saltar(" *")
		j<-2
		Mientras(j<a) Hacer
			Escribir sin saltar("  ")
			j<-j+1
		Fin mientras
		Escribir sin saltar(" *")
		j<-2
		Mientras(j<z) Hacer
			Escribir sin saltar("  ")
			j<-j+1
		Fin mientras		
		
		Escribir (" *")				
		
		i<-i+1
	Fin mientras
	
	
	//{ Aristas alzado finales
	i<- 2
	Mientras(i<=z) Hacer	
		Escribir Sin Saltar(" *")
		j<-2
		Mientras(j<a) Hacer
			Escribir sin saltar("  ")
			j<-j+1
		Fin mientras
		Escribir sin saltar(" *")
		//comprobar la altura
		
		j<-1
		Mientras(j<=z-i) Hacer
			Escribir sin saltar("  ")
			j<-j+1
		Fin mientras		
		
		Escribir (" *")				
		
		i<-i+1
	Fin mientras
	
	
	
	
	//{ Arista inferior }
	j<-1
	Mientras(j<=a) Hacer	
		Escribir sin saltar(" *")
		j<-j+1
	Fin mientras
	Escribir sin saltar("        ")
Fin algoritmo
				