Algoritmo Factorial
	Escribir "FACTORIAL"
	Escribir "Introduzca numero natural: "
	Leer n 
	Si(n<0) 	
		Entonces  	Escribir "Error: dato no valido "
	Sino	
		fac<-1
		i<-1
		Mientras(i<=n) Hacer	
			fac<-fac*i
			i<-i+1
		Finmientras
		Escribir "Factorial: ",fac
	Finsi
FinAlgoritmo