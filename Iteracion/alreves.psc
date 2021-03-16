Algoritmo alreves
	Escribir ('Que número deseas invertir')
	Leer num
	sum=0
	mientras num<>0 hacer
		r <- num MOD 10
		sum <- sum * 10+r
		Escribir " sum " sum " r " r 
		num <- trunc(num / 10)
		Escribir t
	Finmientras
	Escribir 'el número es:',sum
FinAlgoritmo

