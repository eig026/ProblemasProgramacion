Funcion mcd(a:entero(E), b:entero(E)):entero
// Devuelve el máximo común divisor de dos números	
// positivos. Versión recursiva						
// No usar esta función con argumentos negativos o nulos	
Si(a MOD b <>0)
		Entonces	Devolver(mcd(b,a MOD b)
		Sino		Devolver(b)
		Finsi
Finfuncion
