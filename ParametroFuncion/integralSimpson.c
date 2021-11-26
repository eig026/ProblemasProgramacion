#include <stdio.h>
#include <ctype.h>
#include <math.h>

double f(double x);
double integral_simpson(double (*f)(double x),double a, double b, long n);

int main(){
	char c;
	double a,b;
	long n;

	do{ 	      system("cls||clear");
			printf("REGLA DE SIMPSON\n");
			printf("================\n\n");
			printf("\ta: ");
			scanf(" %lf",&a);
			do{	printf("\tb: ");
					scanf(" %lf",&b);
			}while(b<a);
			do{	printf("\tn: ");
					scanf(" %ld",&n);
			}while(n<=0);
			printf("\nIntegral: %.6f",integral_simpson(f,a,b,n));
			printf("\n\nDesea efectuar una nueva operacion (s/n)? ");
			scanf(" %c",&c);   
	}while ((c!='N') && (c!='n'));
	return 0;
}

double integral_simpson(double (*f)(double x),double a, double b, long n){
	double inc,xi;
	long i;
	double aux,suma;

	if(n%2)
		n++;
	if(b<a){
		aux=a;
		a=b;
		b=aux;
	}
	inc=(b-a)/n;
	xi=a;
	suma=f(a)+f(b);
	for(i=1;i<n;++i){
		xi+=inc;
		if(i%2)
			suma+=4*f(xi);
		else suma+=2*f(xi);
	}
	return(inc*suma/3);
}


double f(double x){
	//return(x*x*x-3*x*x+5);
	//return(exp(-x*x));
	return(sin(x)*exp(-x));
}