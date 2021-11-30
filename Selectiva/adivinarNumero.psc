Algoritmo AdivinarNumero
Var	c: caracter
	n,r: entero
	Escribir "ADIVINAR NUMERO DE UN DIGITO\n"
	Escribir "Introduzca P (par) o I (impar): "
	Leer c
	Escribir "Introduzca resto de division entre 5: "
	Leer r
	Si(c='P')o(c='p')
		Entonces	
		Si(r MOD 2=1)
			Entonces	n<-r+5
		Sino		n<-r
		Finsi
		Escribir "El numero es: ", n
	Sino
		Si(c='I')o(c='i')
			Entonces
			Si (r MOD 2=1)
				Entonces	n<-r
			Sino		n<-r+5
			Finsi
			Escribir "El numero es: ", n
		Sino
			Escribir "Error en datos de entrada"
		Finsi
	Finsi
FinAlgoritmo