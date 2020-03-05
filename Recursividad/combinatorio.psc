Algoritmo Combinatorio
	Escribir "ingrese número m"
	Leer m
	Escribir "ingrese número n"
	Leer n
	
	comb <- 1
	// Multiplicar por m!
	c<-1
	fact<-1
	Mientras c<=m Hacer
		fact<-fact*c
		c<-c+1
	FinMientras
	comb=comb*fact
	
	// dividir por (m-n)!
		fact<-1
	c<-1
	Mientras c<=(m-n) Hacer
		fact<-fact*c
		c<-c+1
	FinMientras
		comb <- comb / fact
	
	//dividir por n!
	fact<-1
	c<-1
	Mientras c<=n Hacer
		fact<-fact*c
		c<-c+1
	FinMientras
	
	comb <- comb / fact	
	Escribir "el numero combinatorio es " comb
FinAlgoritmo

