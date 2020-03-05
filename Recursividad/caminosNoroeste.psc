Funcion caminos_NE(x1:entero(E), y1:entero(E),
				  x2:entero(E), y2:entero(E)):entero
// Función que devuelve el nº de caminos NE entre dos	
// puntos de coordenadas enteras: (x1,y1) a (x2,y2)		
// Versión recursiva.								
Si (x1>x2) Entonces
			Devolver(0)
		Sino	Si(x1=x2) Entonces
		Si(y1≥y2) Entonces	
			Devolver(0)
		Sino	Devolver(1)
		Fin_si
	Sino	Si(y1>y2) Entonces	
			Devolver(0)
		Sino	Si(y1=y2) Entonces
				Devolver(1)
			Sino Devolver(
				   caminos_NE(x1+1,y1,x2,y2)+
					            caminos_NE(x,y1+1,x2,y2))
					Finsi
				Finsi
			Finsi
		Finsi
Finfuncion
