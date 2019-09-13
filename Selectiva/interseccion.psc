Algoritmo intersecciondeSegmentos
// programa que calcula la intersección de dos 	
// segmentos de línea recta en el plano

Var
 	x1,y1,x2,y2: real	// extremos primer segmento	
	x3,y3,x4,y4: real	// extremos segundo segmento	
	double u1,u2: real 	// parámetros 			
	a1,b1,c1,a2,b2,c2: real	// coeficientes sist. lin. 2x2	
	aux: real			// Auxiliar para intercambio

	Escribir("Introduzca primer segmento:")
	Escribir("Primer extremo:")
	Leer x1,y1
	Escribir("Segundo extremo:")
	Leer x2,y2 
	Si((x1=x2)y(y1=y2))
		Entonces
		Escribir("Error: extremos iguales")		
	Sino
		Escribir("Introduzca segundo segmento:")
		Escribir("Primer extremo:")
		Leer x3,y3 
		Escribir("Segundo extremo:")
		Leer x4,y4 
		Si((x3=x4)y(y3=y4))
			Entonces
			Escribir("Error: extremos iguales")	
		Sino
			a1<-x2-x1
			a2<-y2-y1
			b1<-x4-x3
			b2<-y4-y3
			c1<-x3-x1
			c2<-y3-y1
			Si(a1*b2<>b1*a2)
				Entonces
				u1<-(-c1*b2+c2*b1)/(-a1*b2+a2*b1)
				u2<-(a1*c2-c1*a2)/(-a1*b2+a2*b1)
				Escribir("Rectas secantes: ")
				Si((0<u1)y(u1<1)y(0<u2)y(u2<1))
					Entonces	
					Escribir("Segm. se cortan")
					Escribir "(",x1+u1*a1,",",y1+u1*b1,")"
				Sino
					Escribir("Segm. no se cortan")
				Fin si
			Sino	
				Si((a1*c2=a2*c1)y(b1*c2=b2*c1))
					Entonces
					Escribir("Rectas iguales:")
					Si(b1<>0)
						Entonces
						u1<- -c1/b1
						u2<- (x2-x3)/b1
					Sino
						u1<--c2/b2
						u2<- (y2-y3)/b2
					Fin si
					Si(u1>u2)
						Entonces
						aux<-u1
						u1<-u2
						u2<-aux
					Fin si
					Si(u2<=0)
						Entonces
						Escribir("No intersectan")
					Sino	
						Si(u2<1)
							Entonces
							Si(u1<=0)
								Entonces
								Escribir("Segm. solapam.:")
								Escribir "(",x3,",",y3,")a(",x3+u2*b1,",",y3+u2*b2,")"
							Sino
								Escribir("Segm. solapam.:")
								Escribir "(",x3+u1*b1,",",y3+u1*b1,") a (",x3+u2*b2,",",y3+u2*b2
							Fin si
						Sino	
							Si(u1<=0)
								Entonces
								Escribir("Segm. solapamiento:")
								Escribir "(",x3,",",y3,") a (",	x4,",",y4,")"
							Sino
								Si(u1<1)
									Entonces
									Escribir("Segm. solapam.:")
									Escribir "(",x3+u1*b1,",",y3+u1*b2,") a (",	x4,",",y4,")"
								Sino
									Escribir("No intersectan")
								Fin si
							Fin si
						Fin si
					Fin si
				Sino	
					Escribir("Segmentos paralelos")
					Escribir("No hay punto de intersección")
				Fin si	
			Fin si	
		Fin si
	Fin si
FinAlgoritmo
