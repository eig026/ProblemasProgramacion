Algoritmo TeoremaCuatroCuadrados
	
	Repetir	
		Escribir("Introduzca n� natural: ")
		Leer n
	Hasta que (n>=0)
	a<-0
	amax<-raiz(n)
	Mientras(a<=amax) Hacer
		b<-a
		bmax<-raiz(n-a*a)
		Mientras(b<=bmax) Hacer
			c<-b
			cmax<-raiz(n-a*a-b*b)
			Mientras(c<=cmax) Hacer
				d<-c
				dmax<-raiz(n-a*a-b*b-c*c)
				Mientras(d<=dmax) Hacer
					Si(n=a*a+b*b+c*c+d*d)
						Entonces	
						Escribir n,"=",a*a, "+",b*b,"+",c*c,"+",d*d
					Fin si
					d<-d+1
				Fin mientras
				c<-c+1
			Fin mientras
			b<-b+1
		Fin mientras
		a<-a+1
	Fin mientras
Fin algoritmo