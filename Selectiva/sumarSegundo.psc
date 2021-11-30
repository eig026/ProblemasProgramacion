Algoritmo sumarunsegundo

	Escribir  "Introduzca Hora:"
    	Leer h
	Escribir "Introduzca Minutos:"
    	Leer m
	Escribir "Introduzca Segundos:"
    	Leer s

	Si (h<0 o m<0 o s<0) o (h>=24 o m>=60 o s>=60)
		Entonces
		Escribir "Valores no válidos"
	SiNo
		s<-s+1;
		Si s=60 Entonces
			s<-0
			m<-m+1
		FinSi
		Si m=60 Entonces
			m<-0
			h<-h+1
		FinSi
		Si h=24 Entonces
			h<-0
		FinSi

		Escribir sin saltar "la hora es ", h
		Escribir sin saltar ", los minutos son ", m
		Escribir sin saltar ", los segundos son ", s
	FinSi
FinAlgoritmo