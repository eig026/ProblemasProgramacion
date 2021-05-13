Algoritmo aceleracionNormal
Var	
	an,va,r: real

	Escribir "ACELERACION NORMAL (O CENTRIPETA)"
	Escribir "Introduzca velocidad angular (rad/sg): "
	Leer va;
	Escribir "Introduzca radio de la trayectoria (m): ";
	Leer r;
	an<-va*va*r;
	Escribir "La aceleración normal vale: ",an," m/sg2";
FinAlgoritmo