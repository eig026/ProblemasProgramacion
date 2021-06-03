Algoritmo CalcularNumeroenvases
	// programa que calcula el numero mínimo de 
	// envases completos necesarios para n litros
	// envases disponibles: 50, 20, 10, 5, 2 y 1 litros

	Var	
		n: entero		// número de litros a envasar
		n50: entero	// n. de envases de 50 litros
		n20: entero	// n. de envases de 20 litros
		n10: entero	// n. de envases de 10 litros
		n5: entero	// n. de envases de 5 litros
		n2: entero	// n. de envases de 2 litros
		n1: entero	// n. de envases de 1 litros
		resto: entero	// resto de divisiones sucesivas	
	
	Escribir "Introduzca número de litros a envasar: ";
	Leer n; 
	
	n50 <- Trunc(n / 50);    // Operacion DIV
	resto <- n MOD 50;
	n20 <- Trunc(resto / 20);
	resto <- resto MOD 20;
	n10 <- Trunc(resto / 10);
	resto <- resto MOD 10;
	n5 <- Trunc(resto / 5);
	resto <- resto MOD 5;
	n2 <- Trunc(resto / 2);
	n1 <- resto MOD 2;
	
	Escribir "Número de envases necesarios: " ;
	Escribir n50, " envases de 50 litros" ;
	Escribir n20, " envases de 20 litros" ;
	Escribir n10, " envases de 10 litros" ;
	Escribir n5, " envases de 5 litros" ;
	Escribir n2, " envases de 2 litros" ;
	Escribir n1, " envases de 1 litro" ;
Finalgoritmo