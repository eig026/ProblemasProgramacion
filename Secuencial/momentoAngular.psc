Algoritmo momentoAngular
Var	
	m,va,r,i,l: real

	Escribir "MOMENTO ANGULAR";
	Escribir "Introduzca masa (Kg): " ;
	Leer m; 
	Escribir  "Introduzca longitud del brazo (m): " ;
	Leer r;
	Escribir  "Introduzca velocidad angular (rad/sg): ";
	Leer va;
	i<-2*m*r*r;
	l<-i*va;
	Escribir "Momento principal de inercia: ",i," kg*m2";
	Escribir "Momento angular: ",l," kg*m2/sg";
FinAlgoritmo
