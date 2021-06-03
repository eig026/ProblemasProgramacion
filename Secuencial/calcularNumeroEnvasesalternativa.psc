Algoritmo CalcularNumeroenvases
	// programa que calcula el número mínimo de 
	// envases completos necesarios para n litros
	// envases disponibles: 50, 20, 10, 5, 2 y 1 litros

	Var	
		n: entero		// número de litros a envasar
		n50: entero	// n. de envases de 50 litros
		n20: entero	// n. de envases de 20 litros
		n10: entero	// n. de envases de 10 litros
		n5: entero		// n. de envases de 5 litros
		n2: entero		// n. de envases de 2 litros
		n1: entero		// n. de envases de 1 litros
		resto: entero	// resto de divisiones sucesivas	

	Escribir "Introduzca volumen del primer envase: ";
	Leer tam1 ;
	Escribir "Introduzca volumen del segundo envase: ";
	Leer tam2;
	Escribir "Introduzca volumen del tercer envase: ";
	Leer tam3;
	Escribir "Introduzca volumen del cuarto envase: ";
	Leer tam4;
	Escribir "Introduzca volumen del quinto envase: ";
	Leer tam5;
	
	Escribir "Introduzca número de litros a envasar: ";
	Leer n ;
	
	n1 <- Trunc(n / tam1);
	resto <- n MOD tam1;
	n2 <- Trunc(resto / tam2);
	resto <- resto MOD tam2;
	n3 <- Trunc(resto / tam3);
	resto <- resto MOD tam3;
	n4 <- Trunc(resto / tam4);
	resto <- resto MOD tam4;
	n5 <- Trunc(resto / tam5);
	n6 <- resto MOD 2;
	
	Escribir "Número de envases necesarios: " ;
	Escribir n1, " envases de 50 litros" ;
	Escribir n2, " envases de 20 litros" ;
	Escribir n3, " envases de 10 litros" ;
	Escribir n4, " envases de 5 litros" ;
	Escribir n5, " envases de 2 litros" ;
	Escribir n6, " envases de 1 litro" ;
Finalgoritmo