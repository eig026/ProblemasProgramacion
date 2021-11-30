Algoritmo excesoVelocidad
// programa que calcula el exceso de velocidad		
// con respecto a un límite dado 				
Const
 	LIMITE=120	//velocidad máxima permitida 	
Var
	v: real		// velocidad (km/h)			
	exceso: real	// exceso de velocidad 		

Escribir "Comprobacion Velocidad";
Escribir "Introducir velocidad (Km/h): ";
Leer v; 
	Si (v>LIMITE)	Entonces	
		exceso <- v-LIMITE;
		Escribir "Sobrepasado límite velocidad en  ", exceso, "Km/h";
	Finsi
Finalgoritmo