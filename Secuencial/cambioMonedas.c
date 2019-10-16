/*
 * @authors Equipo docente programacion grado de ingenieria
 * @university  UAL
 * @date 2019-02-06

*/



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void main(){
	char c;
	int p,pc;   /* precio del articulo (euros+céntimos)*/
	int i,ic;   /* importe pagado (euros+centimos      */
	int resto;  /* resto de las divisiones sucesivas   */
	int b500;   /* numero de billetes de 500 euros     */
	int b200;   /* numero de billetes de 200 euros     */
	int b100;   /* numero de billetes de 100 euros     */
	int b50;    /* numero de billetes de  50 euros     */
	int b20;    /* numero de billetes de  20 euros     */
	int b10;    /* numero de billetes de  10 euros     */
	int b5;     /* numero de billetes de   5 euros     */
	int m2;     /* numero de monedas de  2 euros       */
	int m1;     /* numero de monedas de  1 euros       */
	int m50c;   /* numero de monedas de 50 céntimos    */
	int m20c;   /* numero de monedas de 20 céntimos    */
	int m10c;   /* numero de monedas de 10 céntimos    */
	int m5c;    /* numero de monedas de  5 céntimos    */
	int m2c;    /* numero de monedas de  2 céntimos    */
	int m1c;    /* numero de monedas de  1 céntimo     */

	do{	system("cls");
		printf("CALCULO DEL CAMBIO\n");
		printf("==================\n\n");
		printf("Introduzca precio de articulo:\n");
		printf("\tEuros: ");
		scanf(" %d",&p);
		printf("\tCentimos: ");
		scanf(" %d",&pc);
		printf("Introduzca importe pagado:\n");
		printf("\tEuros: ");
		scanf(" %d",&i);
		printf("\tCentimos: ");
		scanf(" %d",&ic);
		resto=i*100+ic-p*100-pc;
		b500=resto/50000;
		resto=resto%50000;
		b200=resto/20000;
		resto=resto%20000;
		b100=resto/10000;
		resto=resto%10000;
		b50=resto/5000;
		resto=resto%5000;
		b20=resto/2000;
		resto=resto%2000;
		b10=resto/1000;
		resto=resto%1000;
		b5=resto/500;
		resto=resto%500;
		m2=resto/200;
		resto=resto%200;
		m1=resto/100;
		resto=resto%100;
		m50c=resto/50;
		resto=resto%50;
		m20c=resto/20;
		resto=resto%20;
		m10c=resto/10;
		resto=resto%10;
		m5c=resto/5;
		resto=resto%5;
		m2c=resto/2;
		m1c=resto%2;
		printf("\nNumero de billetes y monedas del cambio:\n");
		printf("\tBilletes de 500 euros: %4d\n",b500);
		printf("\tBilletes de 200 euros: %4d\n",b200);
		printf("\tBilletes de 100 euros: %4d\n",b100);
		printf("\tBilletes de  50 euros: %4d\n",b50);
		printf("\tBilletes de  20 euros: %4d\n",b20);
		printf("\tBilletes de  10 euros: %4d\n",b10);
		printf("\tBilletes de   5 euros: %4d\n",b5);
		printf("\tMonedas de    2 euros: %4d\n",m2);
		printf("\tMonedas de    1 euro:  %4d\n",m1);
		printf("\tMonedas de   50 cents: %4d\n",m50c);
		printf("\tMonedas de   20 cents: %4d\n",m20c);
		printf("\tMonedas de   10 cents: %4d\n",m10c);
		printf("\tMonedas de    5 cents: %4d\n",m5c);
		printf("\tMonedas de    2 cents: %4d\n",m2c);
		printf("\tMonedas de    1 cents: %4d\n",m1c);
		printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
		c=toupper(getch());
	}while (c!='N');
	return 0;
}
