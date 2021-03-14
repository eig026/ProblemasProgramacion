Algoritmo SumarAngulos
Var	g,m,s,g1,m1,s1,g2,m2,s2: entero
	Escribir "SUMAS DE ANGULOS"
	Escribir "Introduzca primer angulo (grados, minutos y segundos: "
	Leer g1,m1,s1 
	Escribir "Introduzca segundo angulo (grados, minutos y segundos: " 
	Leer g2,m2,s2
	Si((g1<0)o(g1>359)o(m1<0)o(m1>59)o(s1<0)o(s1>59)o(g1<0)o(g1>359)o(m1<0)o(m1>59)o(s1<0)o(s1>59))
		
		Entonces
		Escribir "Error: datos no validos"
	Sino		
		s<-s1+s2
		m<-m1+m2
		g<-g1+g2
		Si(s>=60)
			Entonces
			s<-s-60
			m<-m+1
		Finsi
		Si(m>=60)
			Entonces
			m<-m-60
			g<-g+1
		Finsi
		Si(g>=360)
			Entonces	
			g<-g-360
		Finsi
		Escribir g1," grados",m1," minutos",s1," segundos +"
		Escribir g2," grados",m2," minutos",s2," segundos ="
		Escribir g," grados",m," minutos",s," segundos"
	Finsi
FinAlgoritmo
