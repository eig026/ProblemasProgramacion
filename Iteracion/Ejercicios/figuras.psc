Algoritmo Figuras
	MAX=20
	Escribir "FIGURAS: ROMBOS y TRIANGULOS"
	Repetir	
		Escribir "Introduzca numero positivo (0-",MAX,"): "
		Leer n 
	Hasta que ((n>0)y(n<MAX))
	
	Si(n MOD 2=1)    
		Entonces	i<-1
		Mientras (i<=n) Hacer
			j<-1
			Mientras (j<=abs(n/2-i+1)) Hacer
				Escribir " "
						j<-j+1
			Finmientras
					j<-1
			Mientras j<=(n/2+1-abs(n/2+1-i)) Hacer
				Escribir sin saltar "* "
					j<-j+1
			Finmientras
						Escribir " "   //  salto de línea 
						i<-i+1
					Finmientras
				Sino	i<-1
					Mientras (i<=n) Hacer
						j<-1
						Mientras (j<=i) Hacer
							Escribir sin Saltar "* "
									j<-j+1
						Finmientras
							Escribir " "  //	 salto de línea 
								i<-i+1
					Finmientras
			Finsi
Finalgoritmo
