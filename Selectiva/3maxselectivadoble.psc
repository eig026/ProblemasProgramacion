Algoritmo 3tempdoble
  Leer t1, t2, t3
  Si (t1>=t2) y (t1>=t3)
  	Entonces tmax<-t1
  Fin si
  Si (t2>=t1) y (t2>=t3)
  Entonces tmax<-t2
  Sino  Si (t3<=t1)y(t3<=t2)
        Entonces tmax<-t3
        Finsi
  Finsi
  Escribir tmax
Fin Algoritmo

