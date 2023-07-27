#include <iostream>

using namespace std;

int busqueda(int arr[],int pos, int inicio, int final){
	
	//CONDICION DE PARADA
	if(inicio>final){
		return -1; //No lo encontró
	}
	
	int medio = (inicio+final)/2; //en este caso 3
	
	if(arr[medio]==pos) return medio; //Retorna la posicion
	//Ahora vamos recorriendo por lados
	if(arr[medio]>pos){
		//Si el K es menor
		//buscaré de inicio al medio-1, porque ya evalué esa posicion
		return busqueda(arr,pos,inicio,medio-1);
	}else{
		//Si el K es mayor
		//buscaré de medio+1 al final, porque ya evalué esa posicion
		return busqueda(arr,pos,medio+1,final);
	}
	
	
}

int main(){
	int arr[] = {2,4,5,7,8,10,12,16};
	int n=8,k=5;
	
	cout<< busqueda(arr,k,0,n-1);	
	
	return 0;
}

