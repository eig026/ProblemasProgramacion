Algoritmo velocidadMediaTramo
Escribir "VELOCIDAD MEDIA POR TRAMO"
	Repetir	Escribir "Introduzca num. tramos trayectoria: "
		Leer n
	Hasta que (n>0)
	vmax<--1038
	i<-1
	dtotal<-0
	ttotal<-0
	Mientras(i<=n) 		Hacer	
		Escribir "Tramo ",i 
		Repetir
			Escribir "Distancia recorrida (m): "
				Leer d
			Hasta que (d>0)
			Repetir	
				Escribir "Tiempo empleado (sg): "
				Leer  t
			Hasta que (t>0)
			v<-d/t
			Si(v>vmax)
				Entonces	vmax<-v
				imax<-i
			Finsi
			dtotal<-dtotal+d
			ttotal<-ttotal+t
			i<-i+1
		Finmientras
		vm<- dtotal/ttotal
		Escribir "Velocidad media trayectoria: ",vm," m/s"
		Escribir "Tramo ",imax,"  velocidad maxima por tramo= ",vmax," m/s"
Finalgoritmo
