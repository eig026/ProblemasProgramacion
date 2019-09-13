Algoritmo TablaMultiplicar
	Escribir Sin Saltar ("  *  ")
	i<-1
	Mientras (i<=9) Hacer
		Escribir Sin Saltar i,"  " 
		i<-i+1
	Fin mientras
	Escribir(" ") 	//	{ Siguiente línea}
	//{ Bucle externo	}
	i<-1 
	Mientras (i<=9) Hacer
		Escribir Sin Saltar "  ", i //{ Rótulo de la fila	}
		//{ Bucle interno: espacios en blanco	}
		j<-1
		Mientras(j<i) Hacer
			Escribir Sin Saltar "   "
			j<-j+1	
		Fin mientras
		j<-i
		//{ Bucle interno: multiplicaciones	}
		Mientras(j<=9) Hacer
			Si ((i*j)<10) Entonces
				Escribir Sin Saltar "  "
			SiNo
				Escribir Sin Saltar " "
			Fin Si
			
			Escribir Sin Saltar i*j
			j<-j+1
		Fin mientras
		Escribir " "
		i<-i+1
	Fin mientras
Fin algoritmo

											
											