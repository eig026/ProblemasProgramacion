Algoritmo temperaturaMaxima
	// programa que calcula la mayor temperatura de
	// un conjunto de datos de temperaturas             
	// El numero de datos es conocido a priori 
Const
	Tfin=-999	// valor centinela: termina E datos
Var     
	n: entero	// numero de datos a leer       
 	i: entero	// contador del bucle           
	t: real		// temperatura leida              
    tmax: real	// temperatura maxima       

	Escribir "Introd. Temperatura (Fin=',Tfin,' ): "
	Leer t
	tmax <- t
	Mientras (t<>Tfin) Hacer
		Si (t>tmax) Entonces
			tmax <- t
		FinSi
		Escribir "Introd. Temp. (Fin=',Tfin,' ): "
		Leer t
	FinMientras
	Si (tmax<>Tfin) Entonces
		Escribir "Temperatura maxima: ",tmax
	SiNo
		Escribir "Sin datos validos"
	FinSi
FinAlgoritmo