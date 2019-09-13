Algoritmo 3tempsimple
	Leer t1, t2, t3
	Si (t1>=t2) y (t1>=t3)
		Entonces tmax<-t1
	Fin si
	Si (t2>=t1) y (t2>=t3)
		Entonces tmax<-t2
	Fin si
	Si (t3>=t1) y (t3>=t2)
		Entonces tmax<-t3
	Fin si	
	Escribir tmax
FinAlgoritmo
