Algoritmo temperaturaMaximaselectivasimple
// programa que calcula el mayor valor 	
// de dos temperaturas 				
Var
	t1,t2: real 		// dos valores de temperatura 	
	tmax: real		// temperatura máxima 		
		     
	Escribir "Introduzca dos temperaturas: " ;
	Leer t1,t2;	
	Si (t1>=t2) Entonces
		tmax <- t1;
	Sino	
		tmax <- t2;
	Finsi
	
	Escribir "Temperatura máxima: ", tmax;
Fin algoritmo