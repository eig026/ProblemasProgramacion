Algoritmo RectanguloAsteriscos
	//	 Programa que imprime en pantalla las aristas de	
	//	 un rectangulo dadas la base y la altura del mismo	
	Repetir	
		Escribir "Introduzca ancho [3-40]: "
		Leer a 
	Hasta Que ((a>=3)y(a<=40))
	Repetir
		Escribir "Introduzca altura [3-20]: "
		Leer h 
	Hasta que ((h>=3)y(h<=20))
	// Arista superior 
	j<- 1
	Mientras(j<=a) Hacer
		Escribir Sin Saltar " *"
		j<- j+1
	Fin mientras
	Escribir " "
	//  Aristas laterales 
	i<- 2
	Mientras(i<h) Hacer	
		Escribir Sin Saltar " *"
		j<-2
		Mientras(j<a) Hacer
			Escribir sin saltar "  "
			j<-j+1
		Fin mientras
		Escribir " *" 
		i<-i+1
	Fin mientras
	// Arista inferior 
	j<-1
	Mientras(j<=a) Hacer	
		Escribir sin saltar " *"
		j<-j+1
	Fin mientras
Fin algoritmo