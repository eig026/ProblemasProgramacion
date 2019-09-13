Funcion Factorial(n:entero(E)):entero
// Función que devuelve el factorial de un número entero
// positivo o nulo. Versión recursiva.					
// Nota: no usar esta función con argumentos negativos	
Si (n=0)	
Entonces	Devolver(1)
		Sino		Devolver(n*Factorial(n-1))
		Fin_si
Finfuncion
