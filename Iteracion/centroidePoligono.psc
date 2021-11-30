Algoritmo CentroidePoligono
Var	n,i: entero
	x,y,xant,yant,x1,y1: real
	a,xcentro,ycentro: real
	suma,sumax,sumay: real
	
	Escribir "CENTROIDE DE UN POLIGONO REGULAR" 
	Repetir	
		Escribir "Introduzca num. de lados: " 
		Leer n 
	Hasta que (n>=3)
	suma<-0
	sumax<-0
	sumay<-0
	Escribir "Coordenadas vertice (x,y): " 
	Leer xcoo,ycoo 
	x1<-xcoo
	y1<-ycoo
	i<-2
	Mientras (i<=n)	Hacer	
		xant<-xcoo
		yant<-ycoo
		Escribir "Coordenadas vertice (x,y): " 
		Leer xcoo,ycoo 
		suma<-suma+(xant*ycoo-xcoo*yant)
		sumax<-sumax+((xcoo+xant)*(xant*ycoo-xcoo*yant))
		sumay<-sumay+((ycoo+yant)*(xant*ycoo-xcoo*yant))
		i<-i+1
	Finmientras
	suma<-suma+(xcoo*y1-x1*ycoo)
	sumax<-sumax+((x1+xcoo)*(xcoo*y1-x1*ycoo))
	sumay<-sumay+((y1+ycoo)*(xcoo*y1-x1*ycoo))
	a<-suma/2
	Si (a<>0)
		Entonces	xcentro<-sumax/(6*a)
		ycentro<-sumay/(6*a)
		Escribir "Area del poligono:  ",a 
		Escribir "Centroide: (",xcentro, ",",ycentro, ")"
	Sino
		Escribir "Poligono no valido" 
	Finsi
Finalgoritmo