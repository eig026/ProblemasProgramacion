Algoritmo MediaDesviacionEstandar
FINAL=-99
Escribir "MEDIA Y DESVIACION ESTANDAR DE TEMPERATURAS"
suma<-0
suma2<-0
n<-0
Escribir "Introduza temperatura [-50,+50](FIN=-99): "
Leer t
Mientras (t<>FINAL) Hacer
	Si(t>=-50)y(t<=50)
		Entonces
		  n<-n+1
		  suma<-suma+t
		  suma2<-suma2+t*t
	Finsi
	Leer t 
Finmientras

Si(n>0)
	Entonces	media<-suma/n
	des<-raiz((suma2-n*media*media)/n)
	Escribir "Temperatura media:   ", media
	Escribir "Desviacion estandar:   ",des
	Escribir "Numero de datos:        ",n
Sino	
	Escribir "Ningun dato valido"
Finsi
FinAlgoritmo
