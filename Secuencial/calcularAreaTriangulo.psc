Algoritmo calcularAreaTriangulo
// Calcula el área de un triangulo dadas las longitudes de sus lados			
	
	Escribir "Introducir longitudes de lados: " ;
	Leer l1,l2,l3;
	Si (l1<=0)o(l2<=0)ó (l3<=0) Entonces
		Escribir "Error en datos de entrada";
	Sino Si(l1<(l2+l3))y(l2<(l1+l3))y(l3<(l1+l2))
			Entonces	
			s<-(l1+l2+l3)/2;
			area <- RC(s*(s-l1)*(s-l2)*(s-l3));
			Escribir "Area=", area;
		Sino
			Escribir "No es un triangulo" ;
		Finsi
	Finsi
Finalgoritmo