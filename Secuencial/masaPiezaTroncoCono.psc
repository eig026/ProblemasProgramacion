Algoritmo masaPiezaTroncoCono
	
Const	
	DENSIDAD=0.00786   // Kg/cm3 
	PI= 4*atan(1)
Var	
	a,b,h,v,m: real

	Escribir "MASA PIEZA DE HIERRO TRONCO CONO CIRCULAR RECTO" ;
	Escribir  "Introduzca longitudes de los radios (cm):" ;
	Escribir "Radio mayor (b): ";
	leer b ;
	Escribir "Radio menor (a): ";
	Leer a;
	Escribir "Altura: ";
	Leer h ;
	V<-PI*h*(a*a+a*b+b*b)/3;
	m<-DENSIDAD*v;
	Escribir "Masa: ",m," Kg";
FinAlgoritmo