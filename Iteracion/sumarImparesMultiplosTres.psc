Algoritmo SumarImparesMultiplosTres
	
	Escribir "SUMA DE NUMEROS IMPARES MULTIPLOS DE 3" 
	Escribir "Introduzca limite superior (n): "
	Leer n 
	Si(n<0)
		Entonces	Escribir "Valor de n no valido"
	Sino	i<-3
		suma<-0
		Mientras(i<=n) Hacer
			suma<-suma+i
			i<-i+6
		FinMientras
		Escribir "La suma vale: ",suma
	Finsi
FinAlgoritmo