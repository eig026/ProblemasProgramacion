Funcion Potencia(x:real(E), n:entero(E)):real
// Devuelve xn, con n>0							
// No usar esta función con argumentos negativos o nulos	
	Si(n=1)
		Entonces	Devolver(x)
		Sino		Devolver(x*Potencia(x,n-1))
		Finsi
Finfuncion
