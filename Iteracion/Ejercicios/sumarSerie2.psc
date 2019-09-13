Algoritmo SumarSerie2
	
	Escribir "SUMA SERIE x-x**2/2+x**3/3-x**4/4..."
	Escribir "Introduzca valor de x (-1..+1): "
	Leer x
	Escribir "Introduzca precision (error): "
	Leer error 
	Si(x<=-1)o(x>=1)o(error<=0)
		Entonces	Escribir "Error en datos de entrada"
	Sino	
		suma<-0
		p<-x
		i<-1
		term<-p/i
		Mientras(abs(term)>=error) Hacer 
			suma<-suma+p/i
			p<-p*(-x)
			i<-i+1
			term<-p/i
		Finmientras
		Escribir "Suma= ", suma
	Finsi
FinAlgoritmo
