Algoritmo raicesEcuacionSegundoGrado
// programa que calcula e imprime en pantalla las 	
// soluciones de la ecuaci�n: A*x*x+B*x+C=0		
Var
	a,b,c: real		// coeficientes polinomio
d: real		// discriminante: b*b-4*a*c	
	x1,x2: real	// raices de la ecuacion

	Escribir "Introduzca coeficientes polinomio: ";
	Leer a,b,c;
	Si (a=0) Entonces
		Si (b=0) Entonces
			Si (c=0) Entonces
				Escribir "Igualdad 0=0";
			SiNo
				Escribir "Imposible 0=",c;
			FinSi
		SiNo
			Escribir "x=",-c/b;
		FinSi
	SiNo
		d <- b*b-4*a*c;
		Si (d<0) Entonces
			Escribir "Raices imaginarias";
		SiNo
			x1 <- (-b+raiz(d))/(2*a);
			x2 <- (-b+raiz(d))/(2*a);
			Escribir "x1=",x1;
			Escribir "x2=",x2;
		FinSi
	FinSi
FinAlgoritmo