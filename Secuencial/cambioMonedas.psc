Algoritmo cambioMonedas
Var
	p,pc: entero	// precio del articulo (euros+céntimos) 
	i,ic: entero 	// importe pagado (euros+centimos
	resto: entero	//resto de las divisiones sucesivas   
    	b500: entero 	//numero de billetes de 500 euros    
    	b200: entero	//numero de billetes de 200 euros    
    	b100: entero	//numero de billetes de 100            
    	b50: entero 	//numero de billetes de  50 euros  
    	b20: entero	//numero de billetes de  20 euros  
	b10: entero	//numero de billetes de  10 euros    
    	b5: entero 	//numero de billetes de   5 euros    
    	m2: entero	//numero de monedas de  2 euros 
    	m1: entero	//numero de monedas de  1 euros   
    	m50c: entero	//numero de monedas de 50 céntimos   
    	m20c: entero 	//numero de monedas de 20 céntimos    
    	m10c: entero	//numero de monedas de 10 céntimos   
    	m5c: entero  	//numero de monedas de  5 céntimos  
    	m2c: entero	// numero de monedas de  2 céntimos   
    	m1c: entero	//numero de monedas de  1 céntimo   

	Escribir "CALCULO DEL CAMBIO";
	Escribir  "Introduzca precio de artículo (euros+céntimos):";
	Leer p,pc;
	Escribir "Introduzca importe pagado (euros+céntimos):";
	Leer i,ic;
	resto<-i*100+ic-p*100-pc;
	b500<-Trunc(resto / 50000);
	resto<-resto MOD 50000;
	b200<- Trunc(resto / 20000);
	resto<-resto MOD 20000;
	b100<-Trunc(resto / 10000);
	resto<-resto MOD 10000;
	b50<-Trunc(resto / 5000);
	resto<-resto MOD 5000;
	b20<-Trunc(resto / 2000);
	resto<-resto MOD 2000;
	b10<-Trunc(resto / 1000);
	resto<-resto MOD 1000;
	b5<-Trunc(resto / 500);
	resto<-resto MOD 500;
	m2<-Trunc(resto / 200);
	resto<-resto MOD 200;
	m1<-Trunc(resto / 100);
	resto<-resto MOD 100;
	m50c<-Trunc(resto / 50);
	resto<-resto MOD 50;
	m20c<-Trunc(resto / 20);
	resto<-resto MOD 20;
	m10c<-Trunc(resto / 10);
	resto<-resto MOD 10;
	m5c<-Trunc(resto / 5);
	resto<-resto MOD 5;
	m2c<-Trunc(resto / 2);
	m1c<-resto MOD 2;
	Escribir "Numero de billetes y monedas del cambio:";
	Escribir "Billetes de 500 euros como ",b500;
	Escribir "Billetes de 200 euros como ",b200;
	Escribir "Billetes de 100 euros como ",b100;
	Escribir "Billetes de  50 euros como ",b50;
	Escribir "Billetes de  20 euros como ",b20;
	Escribir "Billetes de  10 euros como ",b10;
	Escribir "Billetes de   5 euros como ",b5;
	Escribir "Monedas de    2 euros como ",m2;
	Escribir "Monedas de    1 euro como  ",m1;
	Escribir "Monedas de   50 cents como ",m50c;
	Escribir "Monedas de   20 cents como ",m20c;
	Escribir "Monedas de   10 cents como ",m10c;
	Escribir "Monedas de    5 cents como ",m5c;
	Escribir "Monedas de    2 cents como ",m2c;
	Escribir "Monedas de    1 cents como ",m1c;
Finalgoritmo
