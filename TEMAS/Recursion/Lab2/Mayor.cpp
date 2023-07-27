#include <iostream>
#include <cmath>
using namespace std;

int mayor(int arreglo[],int n){
	int max,resto;
	//Condicion de parada
	if(n==1){
		return arreglo[n-1]; //será el cero
	}
	
	/*METODO: el ultimo lo va comparando con su anterior, y va retornando el valor y sigue comparando*/
	
	//Caso que no sea el unico elemento
	max = arreglo[n-1];
	//Este es el nuevo Universo --> n-1 
	resto = mayor(arreglo,n-1);
	
	if(max<resto){
		return resto;
	}else{
		return max;
	}
	
}

int main(){
	
	int arreglo[] = {5,4,2,7,2,1,9};
	int n=7; //numero de elementos en el arreglos
	
	cout<<mayor(arreglo,n)<<endl;
	
	return 0;
}
