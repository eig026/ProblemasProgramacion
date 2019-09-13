Algoritmo temperaturaMaximaselectivasimple
// programa que calcula el mayor valor 	
// de dos temperaturas 				
Var
	t1,t2: real 		// dos valores de temperatura 	
	tmax: real		// temperatura máxima 		
		     
	Escribir "Introduzca tres temperaturas: " ;
	Leer t1,t2,t3;
	Si (t1>=t2) Entonces
		Si (t1>=t3) Entonces
			tmax <- t1;
		Sino	
			tmax <- t3;
		Finsi
	Sino	Si (t2>=t3) Entonces
			tmax <-t2;
		Sino	
			tmax<-t3;
		Finsi
	Finsi
	Escribir "Temperatura máxima: ", tmax;
Fin algoritmo
