#include <iostream>
#include <cmath>

using namespace std;

int cuenta(int ini,int fin, int arr[], int cont){
	
	//realizo condicion de parada
	if(ini==fin) {
		if(arr[ini]==0) return cont+1;
		else return cont; //retorna solo lo que encontró
	}
	//empiezo por el medio
	int med = (ini+fin)/2;
	//si es cero me voy del inicio al medio
	if(arr[med]==0){
		//el fin se toma como med-1, porque en ese momento está posicionado en el cero y quiero los unos
		return cuenta(ini,med-1,arr,fin-med+1+cont); //está contando los 1's
		//6-4+1+0 = 3
	}else{
		//caso que cuente los ceros
		//en ese momento está posicionado en un 1
		return cuenta(med+1,fin,arr,cont);
	}
	
	/*EJEMPLO:
		 0 1 2 3 4 5 6
		(1,1,1,1,0,0,0)
		
		--Inicias en 0 -> 1
		--> cuenta(4,6,arr,0)
		--> cuenta(5,6,arr,3)
		--Se posiciona en el primer 0
		--> cuenta(0,2,arr,6-5+0)
		--> cuenta(2,3,arr,2-
	
	*/
}

int main(){
	int n=7;	//   0 1 2 3 4 5 6 
	int arreglo[] = {1,1,1,0,0,0,0};
	cout<< cuenta (0,n-1,arreglo,0);
	
	return 0;
}
