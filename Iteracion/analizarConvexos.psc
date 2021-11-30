Algoritmo ConcavidadConvexidadPoligono
	//	 Programa que determina si un poligono es 		
	//		 concavo o convexo a partir de las coordenadas 	
	//		 de sus vertices							
	Repetir
		Escribir "Introduzca numero de vertices: "
		Leer n 
	Hasta que (n>3)
	i <-1
	pos <-0
	neg <-0
	Escribir "Coordenadas vertice ",i,": "
	Leer x1,y1
	i <-2
	Escribir "Coordenadas vertice ",i,": "
	Leer xant,yant 
	e1x <-xant-x1
	e1y <-yant-y1
	eantx <-e1x
	eanty <-e1y
	i <-3
	
	Mientras(i<=n) Hacer
		Escribir "Coordenadas vertice ",i,": " 
		Leer x,yy
		ex <-x-xant
		ey <-yy-yant
		z <-eantx*ey-eanty*ex
		Si(z>0)
			Entonces	pos <-pos+1
		Sino		Si(z<0)
				Entonces	neg <-neg+1
			Fin si
		Fin si
		xant <-x
		yant <-yy
		eantx <-ex
		eanty <-ey
		i <-i+1
	Fin mientras
	
	ex <-x1-xant
	ey <-y1-yant
	z <-eantx*ey-eanty*ex
	Si(z>0)
		Entonces	pos <-pos+1
	Sino		Si(z<0)
			neg <-neg+1
		Fin si
	Fin si
	z <-ex*e1y-ey*e1x
	Si(z>0)
		Entonces	pos <-pos+1
	Sino		
		Si(z<0)
			neg <-neg+1
		Fin si
	Fin si
	
	Si(pos>0)
		Entonces
		Si(neg>0)
			Entonces	
			Escribir "Poligono concavo"
		Sino
			Escribir "Poligono convexo"
		Fin si
	Sino		Si(neg>0)
			Entonces
			Escribir "Poligono convexo"
		Sino
			Escribir "Polig. degenerado"
		Fin si
	Fin si
Fin algoritmo