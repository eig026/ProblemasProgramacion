Algoritmo ResistenciaEquivalente

Escribir "RESISTENCIA EQUIVALENTE CONJUNTO DE RESISTENCIAS EN PARALELO"
	rt<-0
	i<-0
	Escribir "Introduzca valor resistencia (ohmios): "
	Leer r
	Mientras((i<MAX)y(r<>0)) Hacer
		Si(r>0)
				Entonces	
				i<-i+1
				rt<-rt+1/r
				Finsi
				Si(i<MAX)
					Entonces	Escribir "Introduzca valor resistencia (ohmios): "
					Leer r
					Finsi
					Finmientras
					Si(i>0)
						Entonces	rt<-1/rt
						Escribir "Resistencia equivalente (ohmios): ",rt
					Sino		Escribir "No hay ninguna resistencia"
					Finsi
FinAlgoritmo	