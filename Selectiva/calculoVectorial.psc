Algoritmo CalculoVectorial
Var	c: caracter
	v1x,v1y,v1z,v2x,v2y,v2z: real
	e,vx,vy,vz: real
	
	Escribir "CALCULO VECTORIAL"
	Escribir "Introduzca primer vector:"
	Leer v1x,v1y,v1z
	Escribir "Introduzca segundo vector:"
	Leer v2x,v2y,v2z
	Escribir "Operaciones a realizar:"
	Escribir "+  Suma de vectores"
	Escribir "-  Resta de vectores" 
	Escribir ". Producto escalar"
	Escribir "x  Producto vectorial"
	Escribir "Introduzca opcion: "
	Leer c 
	Segun c Hacer
		'+':	
			Escribir "Suma de vectores:"
			vx<-v1x+v2x
			vy<-v1y+v2y
			vz<-v1z+v2z
			Escribir "(",v1x,",",v1y,",",v1z,")+"
			Escribir "(",v2x,",",v2y,",",v2z,")="
			Escribir "(",vx,",",vy,",",vz,")"
		'-':
			Escribir "Resta de vectores:"
			vx<-v1x-v2x
			vy<-v1y-v2y
			vz<-v1z-v2z
			Escribir "(",v1x,",",v1y,",",v1z,")-"
			Escribir "(",v2x,",",v2y,",",v2z,")="
			Escribir "(",vx,",",vy,",",vz,")"
		'.':
			Escribir "Producto escalar:"
			e<-v1x*v2x+v1y*v2y+v1z*v2z
			Escribir "(",v1x,",",v1y,",",v1z,")."
			Escribir "(",v2x,",",v2y,",",v2z,")=" 
			Escribir(e);
		'x', 'X':
			Escribir "Producto vectorial:"
			vx<-v1y*v2z-v1z*v2y
			vy<-v1z*v2x-v1x*v2z
			vz<-v1x*v2y-v1y*v2x
			Escribir "(",v1x,",",v1y,",",v1z,")x"
			Escribir "(",v2x,",",v2y,",",v2z,")="
			Escribir "(",vx,",",vy,",",vz,")"
		De Otro Modo:
			Escribir("Opcion no valida")
	Finsegun
FinAlgoritmo