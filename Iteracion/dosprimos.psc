Algoritmo sumaDosPrimos
    Escribir "Introduce un número positivo"
	leer n
	i=2
	//contamos en orden ascendiente hasta n/2
	Mientras  (i<=n/2)
		flg1 = 1;
		flg2 = 1;
		j=2
		// buscamos el primer primo
		Mientras (j < i)
			Si (i MOD j = 0) 
				flg1 = 0;
				j = i;
			Finsi
			j=j+1
		FinMientras
		j=2
		// vemos si lo que queda (n-i) es primo
		Mientras (j < n - i)
			
			si((n - i) MOD j = 0) 
			flg2 = 0;
			j = n - i;
			finsi
		j=j+1
		finmientras
		// si ambos son primos distintos Éxito!!!
		si (flg1 = 1 y flg2 = 1 y i<>(n-i))  
			//quitar la última operación de relacion para quese pueda repetir el primo
			Escribir n " = " i  " + "  n - i 
			flg3 = 1
		finsi
		i=i+1
    finmientras
	
    si (flg3 = 0) 
    	Escribir n " No se puede expresar como la suma de dos primos distintos" 
    finsi
FinAlgoritmo
