Algoritmo temperaturaMaxima
// programa que calcula la mayor temperatura de
// un conjunto de datos de temperaturas             
// El numero de datos es conocido a priori 
Const
	Tfin=-999  	// valor centinela: termina E datos
Var     
	n: entero        // numero de datos a leer       
 	i: entero        // contador del bucle           
	t: real       	 // temperatura leida              
      	tmax: real   	// temperatura maxima

	tmax<--10^38
	final <- falso
	Mientras (no(final)) Hacer
		Escribir "Introd. Temp. (Fin=",Tfin, " ): "
		Leer t
		Si (t=Tfin) Entonces
			final<-verdadero
		Sino	
			Si (t>tmax) Entonces
				tmax<-t
			Finsi
		Finsi
	Finmientras
	Si (tmax<>-10^38) Entonces
		Escribir"Temperatura maxima: ", tmax
	Sino	Escribir "Sin datos validos"
	Finsi
Finalgoritmo
