Algoritmo cartesiana_a_polares
Const	PI=3.141592
Var	x,y,r,a: real
	Escribir "COORDENADAS CARTESIANAS --> POLARES" 
	Escribir  "Introduzca x: " 
	Leer xcoor
	Escribir  "Introduzca y: " 
	Leer ycoor
	r<-raiz(xcoor*xcoor+ycoor*ycoor)
	Si (r=0)
		Entonces
		a<-0
	Sino	
		a<-asen(ycoor/r)
		Si(xcoor<0)
			Entonces
			a<-PI-a
		Finsi
	Finsi
	Si(a<0)
		Entonces
		a<-2*PI+a
	Finsi
	a<-80*a/PI
	Escribir "Coordenadas polares: r=",r,"  ang=",a," grados"
FinAlgoritmo