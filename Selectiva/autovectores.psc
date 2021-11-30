Algoritmo calculoAutovectores
// programa que calcula los autovectores asociados a un   
// autovalor dado el sistema lineal homogéneo  a resolver 
Var
	a11,a12,a13: real   	// coeficientes sistema lineal
	a21,a22,a23: real 
	a31,a32,a33: real	
	rango: entero		// rango matriz de coeficientes
	a,b,c,d,e,f: real	// coeficientes ecuaciones l.i.	
	x,y,z,x2,y2,z2: real	// autovectores	
	norma: real		// modulo de un vector

	Escribir "Introduzca coeficientes: "
	Escribir "a11  a12  a13: "
	Leer a11,a12,a13
	Escribir "a21  a22  a23: " 
	Leer a21,a22,a23
	Escribir "a31  a32  a33: " 
	Leer a31,a32,a33
	
	Si  ((a11*a22*a33+a12*a23*a31+a13*a21*a32-a11*a23*a32-a21*a12*a33-a31*a22*a13)<>0)
		Entonces  
		rango<-3  	
	Sino
		Si((a11*a22-a12*a21<>0)o(a11*a23-a13*a21<>0)o(a12*a23-a13*a22<>0)) 
			Entonces
			a<-a11
			b<-a12
			c<-a13
			d<-a21
			e<-a22
			f<-a23
			rango<-2
		Sino
			Si((a11*a32-a12*a31<>0)o(a11*a33-a13*a31<>0)o(a12*a33-a13*a32<>0))
				Entonces
				a<-a11
				b<-a12
				c<-a13
				d<-a31
				e<-a32
				f<-a33
				rango<-2
			Sino	Si((a21*a32-a22*a31<>0)o (a21*a33-a23*a31<>0)o (a22*a33-a23*a32<>0))
					Entonces
					a<-a21
					b<-a22
					c<-a23
					d<-a31
					e<-a32
					f<-a33
					rango<-2
				Sino	Si(a11<>0)o(a12<>0)o(a13<>0)
						Entonces
						a=a11
						b=a12
						c=a13
						rango=1
					Sino
						Si(a21<>0)o(a22<>0)o(a23<>0)
							Entonces	
							a<-a21
							b<-a22
							c<-a23
							rango<-1
						Sino	
							Si(a31<>0)o(a32<>0)o(a33<>0)
								Entonces	
								a<-a31
								b<-a32
								c<-a33
								rango<-1
							Sino
								rango<-0
							Fin si
						Fin si
					Fin si
				Fin si
			Fin si
		Fin si
	Fin si
	
	Segun rango Hacer
		3: 	Escribir "No hay autovectores" 
		2: 	Escribir "Un autovector" 
			Si(a*e-b*d<>0)
				Entonces	
				x1<-(-c*e+b*f)/(a*e-b*d)
				y1<-(-a*f+c*d)/(a*e-b*d)
				z1<- 1
			Sino	Si(a*f-c*d<>0)
					Entonces
					x1<-(-b*f+e*c)/(a*f-c*d)
					z1<-(-a*e+d*b)/(a*f-c*d)
					y1<- 1
				Sino	
					x1<-1
					y1<-(-a*f+d*c)/(b*f-c*e)
					z1<-(-b*d+e*a)/(b*f-c*e)
				Fin si
			Fin si
			norma<-raiz(x1*x1+y1*y1+z1*z1)
			x1<-x1/norma
			y1<-y1/norma
			z1<-z1/norma
			Escribir x1,",",y1,",",xz
			
		1: 	Escribir "Dos autovectores:"
			Si(a<>0)
				Entonces
				x1<-(-b*1-c*0)/a
				norma<-raiz(x1*x1+1)
				x1<-x1/norma
				y1<-1/norma
				z1<-0
				x2<-(-b*0-c*1)/a
				norma<-raiz(x2*x2+1)
				x2<-x2/norma
				y2<-0
				z2<-1/norma
			Sino	
				Si(b<>0)
					Entonces
					y1<- (-a*1-c*0)/b
					norma<-raiz(y1*y1+1)
					x1<-1/norma
					y1<-y1/norma
					z1<-0
					y2<- (-a*0-c*1)/b
					norma<-raiz(y2*y2+1)
					x2<-0
					y2<-y2/norma
					z2<-1/norma
				Sino
					z1<- (-a*1-b*0)/c
					norma<-raiz(z1*z1+1)
					x1<-1/norma
					y1<-0
					z1<-z1/norma
					z2<-(-a*0-b*1)/c
					norma<-raiz(z2*z2+1)
					x2<-0
					y2<-1/norma
					z2<-z2/norma
				Fin si	
			Fin si
			Escribir  x1,",",y1,",",z1
			Escribir  x2,",",y2,",",z2
		0: 	Escribir "Tres autovectores:" 
			Escribir " (1,0,0),(0,1,0) y (0,0,1)"
	Fin Segun
Fin algoritmo