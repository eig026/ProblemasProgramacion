Algoritmo calculoVectorial
	// programa que suma dos vectores y calcula 	
	// su producto escalar y su producto vectorial	
Var 	
	v1x,v1y,v1z: real	// compon. vector1	
	v2x,v2y,v2z: real	// compon. vector2
	sx,sy,sz: real		// comp. vector suma	
	e: real			// producto escalar
	px,py,pz: real		// producto vectorial	

	Escribir "Introducir componentes v1: "
	Leer v1x,v1y,v1z
	Escribir "Introducir componentes v2:"
	Leer v2x,v2y,v2z
	sx <- v1x + v2x
	sy <- y1y +v2y
	sz <- v1z+ v2z
	e <- v1x*v2x+v1y*v2y+v1z*v2z
	px <- v1y*v2z-v1z*v2y
	py <- v1z*v2x-v1x*v2z
	pz <- v1x*v2y-v1y*v2x

	Escribir "Suma: (",sx,",",sy,",",sz,")"
	Escribir "Producto escalar: ",e
	Escribir "Prod.v:(",px,",",py,",",pz,")"
Finalgoritmo