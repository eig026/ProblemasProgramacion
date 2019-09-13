Funcion suma_cifras(n:entero(E)):entero
// Función que devuelve la suma de las cifras de un 		
// número entero positivo o nulo. Versión recursiva.		
// Nota: no usar esta función con argumentos negativos	

Si (n<10)	
Entonces	Devolver(n)
		Sino		Devolver(n MOD 10+suma_cifras(n DIV 10 ))
		Fin_si
Finfuncion
