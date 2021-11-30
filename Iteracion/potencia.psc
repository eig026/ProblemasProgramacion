Algoritmo Potencia
	Escribir "POTENCIA"
	Escribir "Introduzca numero base: "
	Leer b
	Escribir "Introduzca exponente: "
	Leer e
	Escribir "Potencia: ",b,"**",e,"="
	Si (b=0)
		Entonces
		Si (e=0)
			Entonces	Escribir "Indeterminacion"
		Sino		Si (e>0)
				Entonces 	Escribir "0"
			Sino		Escribir "infinito"
			Finsi
		Finsi
	Sino
		Si (e<0)
			Entonces	b<-1/b
			e<--e
		Finsi
		pot<-1
		i<-1
		Mientras(i<=e) Hacer
			pot<-pot*b
			i<-i+1
		Finmientras
		Escribir pot 
	Finsi
FinAlgoritmo