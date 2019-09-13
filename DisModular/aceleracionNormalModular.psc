Algoritmo modulo_principal
	Repetir	
		calcular_aceleracion_normal()
		Escribir "Ejecutar de nuevo (s/n)? "
		Leer c
	Hasta que (c='N')o(c='n')
Fin algoritmo 

funcion calcular_aceleracion_normal()
	Escribir "ACELERACION NORMAL (O CENTRIPETA)"
	Escribir "Introduzca velocidad angular (rad/sg): "
	Leer va 
	Escribir "Introduzca radio de la trayectoria (m): " 
	Leer r 
	an<-va*va*r
	Escribir "La aceleracion normal vale: ",an, "m/sg2"	
Fin funcion
