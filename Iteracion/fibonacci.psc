Algoritmo fibonacci
// programa que calcula el termino n-esimo de la serie de
// Fibonacci, dado por teclado el n. del termino
Var	n: entero		// numero del termino
	fib: entero		// termino n-esimo
	i: entero		// contador de iteraciones
	fib_1,fib_2: entero	// dos terminos anteriores

	Repetir
		Escribir "Introduzca Nº de termino: ";
		Leer n;
	Hasta que (n>0)
	fib_1<-0;
	fib_2<-1;
	i<-1;
	Mientras (i<=n) Hacer
		fib<-fib_1+fib_2;
		fib_2<-fib_1;
		fib_1<-fib;
		i<-i+1;
	Finmientras
	Escribir "Termino ",n," de Fibonacci = ",fib;
Finalgoritmo
