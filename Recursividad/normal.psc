Procedimiento Normalizar (vx:entero (S) ,vy:entero (S))
	v<-raiz(vx*vx+vy*vy)
	vx<-vx/v
	vy<-vy/v
FinProcedimiento

Algoritmo ejemplo
    vx<-8
    vy<-6
    Normalizar(vx,vy)
    Escribir "V. Normalizado:"
    Escribir "(",vx, ",",vy, ")"
FinAlgoritmo
