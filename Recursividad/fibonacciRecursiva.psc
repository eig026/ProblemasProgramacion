Función Fibonacci(n:entero(E)):entero
// Función que devuelve el término n-ésimo de la serie 	
// de Fibonacci (n debe ser un entero positivo nulo). 		
// Versión recursiva.								
// Nota: no usar esta función con argumentos negativos	
Si ((n=1)ó(n=2))	
Entonces	Devolver(1)
		Sino		Devolver(Fibonacci(n-1)+Fibonacci(n-2))
		Finsi
Finfuncion
