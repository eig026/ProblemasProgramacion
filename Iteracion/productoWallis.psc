Algoritmo ProductoWallis
// Programa que calcula el valor de PI/2 mediante	
// el producto de Wallis				
Var	
	pre: real	// Precision del ultimo factor	
	wal: real	// Producto de Wallis			
	fac: real	// factor (termino)			
	num,den: real	// numerador y denominador	
	aux: real     	// auxiliar para alm. temporal	}

	Repetir
		Escribir "Introduzca precision: "
		Leer pre
	Hasta que (pre>0)
	num<-2
	den<-1
	wal<-1
	fac<-num/den
	Mientras abs(1-fac)>=pre Hacer
		wal<-wal*fac
		aux<-num
		num<-den+1
		den<-aux+1
		fac<-num/den
	Finmientras
	Escribir "Resultado: ",wal
Finalgoritmo