Algoritmo temperaturaMaxima
// programa que calcula la mayor temperatura de
// un conjunto de datos de temperaturas             
// El numero de datos es conocido a priori     
Var     
	n: entero        // numero de datos a leer       
 	i: entero        // contador del bucle           
	t: real       	 // temperatura leida              
      	tmax: real   	// temperatura maxima       
	
	Escribir "Introduzca numero de datos: " 
	Leer n;
	Si n=0 
		Entonces	Escribir "Sin datos a leer"
	SiNo	
		tmax <- -10^38
		i <- 1
		Mientras i<=n Hacer
			Escribir "Introd. temperatura: "
			Leer t 
			Si t>tmax Entonces
				tmax<- t
			Finsi
			i<- i+1
		Finmientras
		Escribir "Temp. maxima: ", tmax
	Finsi
Finalgoritmo
