Algoritmo momentoFuerza
Var	
	ox,oy,oz,ax,ay,az,fx,fy,fz: real
	rx,ry,rz,mx,my,mz: real
	m: real     		// Módulo del momento

	Escribir "MOMENTO DE UNA FUERZA" ;
	Escribir "Introduzca componentes de la fuerza: ";
	Leer fx,fy,fz; 
	Escribir "Introduzca coordenadas del punto de aplicación de la fuerza: " ;
	Leer ax,ay,az ;
	Escribir "Introduzca coordenadas del punto respecto del cual se calcula el momento:";
	Leer ox,oy,oz;
	rx<-ax-ox;
	ry<-ay-oy;
	rz<-az-oz;
	mx<-ry*fz-rz*fy;
	my<-rz*fx-rx*fz;
	mz<-rx*fy-ry*fx;
	Escribir "El momento vale: (",mx,",",my,",",mz,")";
	m<-raiz(mx*mx+my*my+mz*mz);
	Escribir "Modulo: ",m;
	Si(m>0)
		Entonces Escribir "Vector unitario: (",mx/m,",",my/m,",",mz/m,")";
	Finsi
FinAlgoritmo