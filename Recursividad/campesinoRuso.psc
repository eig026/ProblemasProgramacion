Funcion mcr(a:entero(E), b:entero(E)):entero
// Función que multiplica dos números naturales 		
// mediante el método del campesino ruso.				
// Versión recursiva.								
// Nota: no usar esta función con argumentos negativos	
Si (a=1)	
Entonces	Devolver(b)
		Sino		Si(a MOD 2 =0)
				Entonces	Devolver(mcr(a DIV 2, 2*b)
				Sino		Devolver(mcr (a DIV 2, 2*b)+b)
				Finsi
		Finsi
Finfuncion
