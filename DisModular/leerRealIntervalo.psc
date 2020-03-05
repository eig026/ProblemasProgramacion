Algoritmo principal
	Repetir 
		Escribir "LECTURA NUMERO INTERVALO "
		Escribir "Introduzca limites del intervalo: "
		Escribir "Izquierdo: " 
		Leer a 
		Escribir "Derecho: " 
		Leer b 
		x<-leer_real_intervalo(a,b)
		Escribir "Numero leido: ",x 
		Escribir "Ejecutar de nuevo (s/n)? "
		Leer c 
		Hasta que (c='N')o(c='n')
		
FinAlgoritmo	

Procedimiento leer_real_intervalo(a: real (E), b: real (E), x: real (S))
Inicio	Si(a=b)
	Entonces x<-a
	Sino	Si(a>b)
		Entonces  x<-a
			    a<-b
			    b<-x
		Fin_si
		Repetir Escribir "Introduzca numero en [", a, ",",b, "]: "
         	      Leer x
		Hasta_que (x>=a)y(x<=b)
	Fin_si
Fin procedimiento
