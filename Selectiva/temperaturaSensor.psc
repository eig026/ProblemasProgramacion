Algoritmo temperaturaSensor
Var	t,v; real	
	Escribir "TEMPERATURA A TRAVES DE SENSOR DE VOLTAJE"
	Escribir  "Introduzca voltaje proporcionado por sensor (voltios): "
	Leer v
	Si ((v<5)o(v>10))
		Entonces
		Escribir "Error en lectura de temperatura"
	Sino
		t<-30*(v-5)-30
		Escribir "Temperatura: ",t," grados centigrados"
	Finsi
FinAlgoritmo