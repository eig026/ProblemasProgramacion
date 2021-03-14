Algoritmo CeroFuncion
	Repetir	
		Escribir "DETERMINACION DE UN CERO DE UNA FUNCION" 
		Repetir	
			Escribir "Introduzca limites del intervalo:"
			Escribir "a: "
			Leer a
			Repetir	
				Escribir "b: "
				Leer b
			Hasta Que(b>=a)
			yizq<-a*a*a*a*a-a*a*a*a+a*a*a-3
			yder<-b*b*b*b*b-b*b*b*b+b*b*b-3
		Hasta Que((yizq*yder<=0)o(a=b))
				
	    Si(a<>b)
			Entonces
					Si(yizq<>0)y(yder<>0)
						Entonces	
						Repetir	
							Escribir "Introduzca precision: "
							Leer prec
						Hasta que  (prec>0)
							xizq<-a
							xder<-b
							xm<-(xizq+xder)/2
							i<-1
							ymed<-xm*xm*xm*xm*xm-xm*xm*xm*xm+xm*xm*xm-3
							
						Mientras ((ymed<>0)y((xder-xizq)> prec))	Hacer
								i<-i+1
								Si(yizq*ymed<0)
									Entonces	
									xder<-xm
									yder<-ymed
								Sino	xizq<-xm
									yizq<-ymed
								Finsi
								xm<-(xizq+xder)/2
								ymed<-xm*xm*xm*xm*xm-xm*xm*xm*xm+xm*xm*xm-3
			Finmientras
							Escribir "Raiz: ",xm, "f(x)= ",ymed,"Iter.",i
						Sino	Si(yizq=0)
								Entonces	
								Escribir"Raiz:  ",a
							Finsi
							Si(yder=0)
								Entonces
								Escribir "Raiz: ",b
							Finsi
						Finsi
		FinSi
	Hasta que(a=b)
FinAlgoritmo
