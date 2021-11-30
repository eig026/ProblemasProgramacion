Algoritmo tresTemperaturas
Var	t1,t2,t3: real
	Escribir("TRES TEMPERATURAS: COMPROBAR SI COINCIDEN")
	Escribir ("Introduzca tres temperaturas:")
	Leer t1,t2,t3
	Si (t1=t2)
		Entonces
		Si (t1=t3)
			Entonces
			Escribir ("Las tres temperaturas son iguales")
		Sino
			Escribir ("Hay dos temperaturas iguales: t1 y t2")
		Finsi
	Sino
		
		Si  (t1=t3) 
			Entonces
			Escribir ("Hay dos temperaturas iguales: t1 y t3")
		Sino	
			Si (t2=t3) 
				Entonces
				Escribir ("Hay dos temperaturas iguales: t2 y t3")
			Sino	
				Escribir ("Las tres temperaturas son distintas")
			Finsi
		Finsi
	Finsi
FinAlgoritmo