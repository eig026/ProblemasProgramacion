Algoritmo resultanteFuerzasConcurrentes
	// programa que calcula la resultante de un conjunto de	
	// fuerzas concurrentes cuyas componentes se introducen	
	// por teclado. Finaliza la entrada con una fuerza nula  	
Var
	fx,fy,fz: real	// componentes de cada fuerza      	
	rx,ry,rz: real	// componentes de resultante		
	
	Escribir "Introducir componentes de Fuerza:"
	Leer fx,fy,fz
	rx<-0
	ry<-0
	rz<-0
	Mientras ((fx<>0)o(fy<>0)o(fz<>0)) Hacer
		rx<- rx+fx
		ry<-ry+fy
		rz<- rz+fz
		Escribir "Introducir compon. de Fuerza:"
		Leer fx,fy,fz
	Finmientras
	Escribir "Resultante: (",rx, ",",ry, ",",rz, ")"
Finalgoritmo