Algoritmo  huracanes
// programa que presenta en pantalla la categoría		
// de un huracán a partir de su nivel, según			
// clasificación de Saffir-Simpson 					
Var
	nivel: entero	// nivel del huracán: 1,2,3,4,5	

	Escribir "CLASIFICACION DE HURACANES";
	Escribir "Introduzca el nivel del huracán: "
	Leer nivel; 
	Segun nivel Hacer
		1:	Escribir "Clasificación: mínimo" ;
		2:	Escribir "Clasificación: moderado" ;
		3:	Escribir "Clasificación: extenso" ;
		4:	Escribir "Clasificación: extremo" ;
		5:	Escribir "Clasificación: catastrófico" ;
		de otro modo:	Escribir "Error: nivel no válido";
	FinSegun
Finalgoritmo