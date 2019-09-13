Algoritmo modulo_principal
// programa que calcula la expresion: D = A *(B * C ), siendo * el producto vectorial	
Var		ax,ay,az: real
		bx,by,bz: real
		cx,cy,cz: real
 		dx,dy,dz: real
    
    leer_datos(ax,ay,az,bx,by,bz,cx,cy,cz)
	  calcular_expresion(ax,ay,az,bx,by,bz,cx,cy,cz,dx,dy,dz)
	  escribir_resultados(dx,dy,dz)
Finalgoritmo

Procedimiento leer_datos(ax:real(S), ay:real(S), az:real(S), bx:real(S), by:real(S), bz:real(S), cx:real(S), cy:real(S), cz:real(S))
    Escribir "Introduzca vector A:"
		leer_vector(ax,ay,az)
		Escribir "Introduzca vector B:"
		leer_vector(bx,by,bz)
    Escribir "Introduzca vector C:"
		leer_vector(cx,cy,cz)
Finprocedimiento

Procedimiento leer_vector(vx:real(S), vy:real(S), vz:real(S))
    Escribir "x: "
		Leer vx
		Escribir "y: "
		Leer vy
		Escribir "z: "
    Leer vz
Finprocedimiento

Procedimiento calcular_expresion(ax:real(E),ay:real(E),az:real(E), bx:real(E),by:real(E),bz:real(E),cx:real(E),cy:real(E),cz:real(E), dx:real(S),dy:real(S),dz:real(S))
Var		ex,ey,ez: real
		prod_vectorial(bx,by,bz,cx,cy,cz,ex,ey,ez)
		prod_vectorial(ax,ay,az,ex,ey,ez,dx,dy,dz)
Finprocedimiento

Procedimiento prod_vectorial(ax:real(E),ay:real(E),az:real(E), bx:real(E),by:real(E),bz:real(E), cx:real(S),cy:real(S),cz:real(S))
    cx<-ay*bz-az*by
		cy<-az*bx-ax*bz
    cz<-ax*by-ay*bx
Finprocedimiento

Procedimiento escribir_resultados(vx:real(E),vy:real(E),vz:real(E))
  Escribir "Componentes del vector D:" 
	Escribir "x= ",vx
  Escribir "y= ",vy 
	Escribir "z= ",vz
Finprocedimiento
