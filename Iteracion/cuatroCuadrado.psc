Algoritmo TeoremaCuatroCuadrados
	Repetir	
		Escribir "Introduzca numero natural: ";
		Leer n 
		Hasta Que (n>=0)
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
							Escribir n,"=",a*a,"+",b*b,"+",c*c,"+",d*d
						Finsi
						d<-d+1
					Finmientras
					c<-c+1
				Finmientras
				b<-b+1
			Finmientras
			a<-a+1
		Finmientras
Finalgoritmo