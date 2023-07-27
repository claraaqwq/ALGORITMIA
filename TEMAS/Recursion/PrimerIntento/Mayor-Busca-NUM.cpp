#include <iostream>
#include <cmath>

using namespace std;
// [5,4,2,7,2,1,9] , 7 //
//INTENTAR DE NUEVO
int mayor(int arreglo[],int n){
	int max,resto;
	//Condicion de parada, cuando el arreglo solo tenga un elemento
	if(n==1){
		return arreglo[n-1]; //será el cero
	}
	//Caso que no sea el unico elemento
	//max = 9
	max = arreglo[n-1];
	//Este es el nuevo Universo --> n-1 
//  resto = [5,4,2,7,2,1] => mayor = 1 => resto = 1
	resto = mayor(arreglo,n-1);
	
// comparo 9<1 => return max
	if(max<resto){
		return resto;
	}else{
		return max;
	}
	
}

//APRENDIDO
int busca (int arreglo[], int n, int numero){
	//Iremos reduciendo el n
	if(n==0){
		return -1; //NO ENCONTRADO
	}
	//Condicion de parada cuando el arreglo quede con 1 solo digito
	if(arreglo[n-1]==numero){
		//retorna posicion del numero en el arreglo
		return n-1;
	}
	busca(arreglo,n-1,numero);
	
}

int main(){
	
	int arreglo[] = {5,4,2,7,2,1,9};
	int n=7; //numero de elementos en el arreglos
	
	cout<<mayor(arreglo,n)<<endl;
	cout<<busca(arreglo,n,7)<<endl;
	
	return 0;
}

/*
	OTRAS SOLUCIONES: busca menor, busca numero
*/
