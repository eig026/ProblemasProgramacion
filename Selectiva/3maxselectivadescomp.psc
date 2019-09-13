Algoritmo 3tempdescompuesta
// programa que calcula la mayor de tres temperaturas 
Var
 	t1, t2, t3: real	// temperaturas leídas                      
	tmax: real	   	// temperatura máxima		   
		     
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
