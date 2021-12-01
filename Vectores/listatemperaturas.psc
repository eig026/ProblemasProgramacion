Algoritmo Módulo_principal
Var      c: carácter
            media: real
            v: tipo_vector
            n: entero
Inicio   Repetir   Escribir("TEMPERATURAS POR DEBAJO DE LA MEDIA")
                             Llamar a leer_vector(v,n)
                             media  calcular_media(v,n)
                             Llamar a escribir_inferior_media(media,v,n)
                             Escribir("Desea efectura una nueva operación (S/N)? "
                             Leer(c)
             Hasta_que (c='N')ó(c='n')
Fin_algoritmo_principal

Procedimiento leer_vector(v: tipo_vector (S), n: entero (S))
Var	i: entero
Inicio	Escribir("Introduzca nº de datos: ")
              Llamar a leer_entero_rango(1,MAX,n)
              Escribir("Introduzca temperaturas")
	Desde i=1 Hasta n Hacer
	             Escribir("Temperatura [",i, "]: ")
	             Leer(v[i])
	Fin_desde
Fin_procedimiento

Procedimiento leer_entero_rango(a: entero (E), b: entero (E), m:entero(S))
Var	aux: entero
Inicio	Si(a>b)
	Entonces   aux=a
		      a=b
		      b=aux
	Fin_si
	Repetir	Escribir("Introduzca entero [",a, ",",b, "]: ")
		Leer(m)
	Hasta_que (m≥a)y(m≤b)
Fin_procedimiento

Función calcular_media(v: tipo_vector (E), n: entero (E)): real
Var	i: entero
              suma: real
Inicio	suma0
	Desde i=1 Hasta n Hacer
	             sumasuma+v[i]
	Fin_desde
              Devolver(suma/n)
Fin_función

Procedimiento escribir_inferior_media(media: real (E), v: tipo_vector (E),
                                                                        n: entero(E))
Var	i: entero
              cont: entero
Inicio	Escribir("Temperaturas inferiores a media (",media, ")")
               cont0
	Desde i=1 Hasta n Hacer
	             Si (v[i]<media)
                           Entonces   Escribir("Temperatura [",i, "]= ",v[i])
                                              contcont+1
	             Fin_si
	Fin_desde
              Si (cont=0)
              Entonces   Escribir("No hay ninguna")
              Fin_si
Fin_procedimiento
