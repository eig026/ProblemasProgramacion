Algoritmo MaximoComunDivisor

	Repetir
		Escribir "Introduzca num. positivo: " 
		Leer n1
	Hasta que (n1>0)
	Repetir	
		Escribir "Introduzca otro numero positivo: " 
		Leer n2 
	Hasta que (n2>0)
	Si (n1<=n2)
		Entonces 	mcd<-n1
	Sino		 	mcd<-n2
	Finsi
	
	Mientras (((n1 MOD mcd) <> 0) o ((n2 MOD mcd) <> 0)) Hacer
		mcd<-mcd-1
	Finmientras
	Escribir "Maximo comun denominador: ",mcd
Finalgoritmo