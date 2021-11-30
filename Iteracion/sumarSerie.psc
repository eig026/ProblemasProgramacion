Algoritmo SumarSerie
	
	Escribir "SUMA SERIE x-x**2/2+x**3/3-x**4/4..."
	Escribir "Introduzca valor de x (-1..+1): "
	Leer x 
	Escribir "Introduzca nº de sumandos: "
	Leer n 
	Si(x<=-1)o(x>=1)o(n<=0)
		Entonces	
		Escribir "Error en datos de entrada" 
	Sino	
		suma<-0
		p<- -1
		i<-1
		Mientras(i<=n)	Hacer
		        p<-p*(-x)
			suma<-suma+p/i
			i<-i+1
		Finmientras
		Escribir "Suma= ", suma
	Finsi
FinAlgoritmo