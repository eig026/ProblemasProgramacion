Algoritmo tarifaTaxi
// calcula y muestra la tarifa de un taxi según los km recorridos
Const
	FIJO=30	   // Tarifa fija				
	T1=15	   // Tarifa 1: euro/km de 30-100 km 
	T2= 10	   // Tarifa 2: euro/km >100 km 	
Var	
	km: real		// kilómetros recorridos
	total: real		// Total a cobrar en euros
	
	Escribir("Introduzca kms recorridos: ")
	Leer km
	Si km<=0
		Entonces
		Escribir("Error: datos de E no válidos")
	Sino
		Si(km<=30)
			Entonces 
			total<-FIJO;
		Sino	Si(km<=100)
				Entonces total<-FIJO+(km-30)*T1
			Sino	total<-FIJO+(100-30)*T1+(km-100)*T2
			Finsi
		Finsi
		Escribir "Total a pagar: ", total
	Finsi
Finalgoritmo
