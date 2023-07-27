#include <iostream>
using namespace std;

int fibo(int n)
{
	int fib[n+1];
	
	//Casos de partida ó Condición de partida
	fib[0]=0;//por definición del problema
	fib[1]=1;//por definición del problema
	
	//Utilizando Programación Dinámica: utilizando las instancia ya creadas
	for (int i=2 ;i<n+1; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	return fib[n];	
}
int main()
{
	int n;
	cout << "Ingrese el número n: "<< endl;
	cin >>n ;
	
	int resultado= fibo(n);
	cout << "Fibonacci de n="<<n<< " es igual a "<<resultado;
	return 0;
}
