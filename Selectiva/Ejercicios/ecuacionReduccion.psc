Algoritmo SistemaLineal3x3
Var	a11,a12,a13,a14,a21,a22,a23,a24,a31,a32,a33,a34: real           { Sistema 3x3 inicial }
	x,y,z: real					{ Soluciones del sistema                    }
	det: real					{ determinante matriz coeficientes  }
	b11,b12,b13,b21,b22,b23,b31,b32,b33: real	{ Coeficientes Sistema 1ª reducción }
	c11,c12,c21,c22,c31,c32: real			{ Coeficientes Sistema 2ª reducción }
Inicio	Escribir("RESOLUCION SISTEMA LINEAL DE ECUACIONES 3x3")
	Escribir("    (Metodo de reduccion)")
	Escribir("a11 * x + a12 * y + a13 * z = a14")
	Escribir("a21 * x + a22 * y + a23 * z = a24")
	Escribir("a31 * x + a32 * y + a33 * z = a34")
	Escribir("Introduzca coeficientes primera ecuación: ")
	Leer(a11,a12,a13,a14)
Escribir("Introduzca coeficientes segunda ecuación: ")
	Leer(a21,a22,a23,a24)
Escribir("Introduzca coeficientes tercera ecuación: ")
	Leer(a31,a32,a33,a34)
deta11*a22*a33+a12*a23*a31+a13*a21*a32
		    -a11*a23*a32-a12*a21*a33-a13*a22*a31
	Si(det=0)
	Entonces	Escribir("Sistema sin solución única ")
	Sino		{ Eliminamos la variable x }
			b11a21*a12-a11*a22
			b12a21*a13-a11*a23
			b13a21*a14-a11*a24
			b21a31*a12-a11*a32
			b22a31*a13-a11*a33
			b23a31*a14-a11*a34
			b31 a31*a22-a21*a32
			b32 a31*a23-a21*a33
			b33 a31*a24-a21*a34
			{ Eliminamos la variable y }
			c11b21*b12-b11*b22
			c12b21*b13-b11*b23
			c21b31*b12-b11*b32
			c22b31*b13-b11*b33
			c31 b31*b22-b21*b32
			c32 b31*b23-b21*b33
			{ Determinamos el valor de z }
			Si(c11≠0)
			Entonces	zc12/c11
			Sino		Si(c21≠0)
				Entonces	zc22/c21
				Sino		zc32/c31
				Fin_si
			Fin_si
			{ Determinamos el valor de y }
			Si(b11≠0)
			Entonces	y(b13-b12*z)/b11
			Sino		Si(b21≠0)
				Entonces	y(b23-b22*z)/b21
				Sino		y(b33-b32*z)/b31
				Fin_si
			Fin_si
			{ Determinamos el valor de x }
			Si(a11≠0)
			Entonces	x(a14-a12*y-a13*z)/a11
			Sino		Si(a21≠0)
				Entonces	x(a24-a22*y-a23*z)/a21
				Sino		x(a34-a32*y-a33*z)/a31
				Fin_si
			Fin_si
			{ Presentacion de resultados }
			Escribir("Soluciones:")
			Escribir("x = ",x)
			Escribir("y = ",y)
			Escribir("z = ",z)
	Fin_si
Fin_Algoritmo
