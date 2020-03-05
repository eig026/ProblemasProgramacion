Algoritmo Modulo_principal
Var	c: caracter
	 n: entero
Repetir
	Escribir "TORRES DE HANOI"
	Escribir "Numero de discos: "
        leer_entero_positivo(n)
	mover_discos(n, 'i', 'd', 'c')
	Escribir "Desea efectuar una nueva operacion (s/n)? "
	Leer c 
Hasta que (c='N')o(c='n')
Finalgoritmo

Procedimiento leer_entero_positivo(n: entero (S))
Repetir	
	Escribir "Introduzca entero positivo: "
	Leer(n)
Hasta_que (n>0)
Finprocedimiento


Procedimiento mover_discos(n: entero (E), ori: caracter (E), des: caracter (E),  aux: caracter (E))
Inicio	Si (n=1)
	Entonces   mover_un_disco(1,ori,des)
               Sino           mover_discos(n-1,ori,aux,des)
 		     mover_un_disco(n,ori,des)
                                  mover_discos(n-1,aux,des,ori)
	Fin_si
Finprocedimiento

Procedimiento mover_un_disco(n: entero(E),ori: carácter(E), des: caracter(E))
	Escribir "Mover disco nº ",n, " del pivote " 
	escribir_pivote(ori)
	Escribir " al pivote "
	escribir_pivote(des)
Finprocedimiento

Procedimiento escribir_pivote(c: caracter (E))
  Segun sea (c) Hacer
              'i': Escribir "izquierdo"
              'd': Escribir "derecho"
              'i': Escribir "centro"
              Finsegun
Finprocedimiento
