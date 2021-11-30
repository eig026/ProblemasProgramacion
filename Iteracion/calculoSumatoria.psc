Algoritmo calculoSumatoria
	// programa que calcula: sumatorio (i/2i) donde el numero 	
	// de términos de la suma se introduce por teclado 		
Var	
	i: entero			// contador de iteraciones		
	n: entero			// numero de terminos suma	
	suma: real			// valor de la suma			
	x: real				// potencia: 1/2i				
	
	Repetir 
		Escribir "Introduzca num. sumandos: ";
		Leer n;
	Hasta que (n>0)
	suma<-0;
	x<-1;
	i<-1;
	Mientras (i<n) Hacer
		x<-x/2;
		suma<-suma+i*x;
		i<-i+1;
	Finmientras
	Escribir "Sumatoria = ",suma; 
Finalgoritmo