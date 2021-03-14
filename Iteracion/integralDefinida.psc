Algoritmo IntegralDefinida
Var	a,b,base: real
	signo: entero
	x,suma,area,yizq,yder: real
	
	Escribir "INTEGRAL DEFINIDA EN UN INTERVALO" 
	Escribir "Introduzca intervalo de integracion:" 
	Escribir "limite izquierdo: " 
	Leer a 
	Escribir "limite derecho: "
	Leer b 
	signo<-1
	Si(b<a)
		Entonces	
		xcoo<-a
		a<-b
		b<-xcoo
		signo<--1
	Finsi
	Repetir		
		Escribir "Introduzca valor de incremento (base): "
		Leer base
	Hasta que (base>0)
	suma<-0
	xcoo<-a
	yder<-xcoo*xcoo*xcoo-3*xcoo*xcoo+5
	xcoo<-xcoo+base
	Mientras(xcoo+base<=b) 		Hacer
		yizq<-yder
		xcoo<-xcoo+base
		yder<-xcoo*xcoo*xcoo-3*xcoo*xcoo+5
		area<-base*(yizq+yder)/2
		suma<-suma+area
	Finmientras
	Si(xcoo<b)
		Entonces	yizq<-yder
		yder<-b*b*b-3*b*b+5
		area<-(b-xcoo)*(yizq+yder)/2
		suma<-suma+area	
	Finsi
	suma<-signo*suma
	Escribir "Integral definida: ",suma
Finalgoritmo
