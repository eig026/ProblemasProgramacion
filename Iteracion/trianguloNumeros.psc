Algoritmo TrianguloNumeros
	MAXFILAS=20
	Escribir "TRIANGULO DE NUMEROS" 
	Repetir	
		Escribir "Introduzca nº de filas: " 
		Leer n
	Hasta que ((n>0)y(n<MAXFILAS))
	max<-n*(n+1)/2
	i<-1
	Mientras (i<=n) Hacer
		j<-1
		Mientras (j<=i) Hacer
			Escribir max 
			max<-max-1
			j=j+1
		FinMientras
		//	 Salto de línea 
		i<-i+1
	Finmientras
Finalgoritmo