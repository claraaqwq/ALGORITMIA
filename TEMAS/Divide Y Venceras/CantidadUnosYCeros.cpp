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
		//el fin se toma como med-1, porque en ese momento está posicionado en el cero
		//y quiero saber cuantos hay a la izquierda
		//Entonces irá del inicio hasta el medio-1
		return cuenta(ini,med-1,arr,fin-med+1+cont); //está contando los 0's
	}else{
		//en ese momento está posicionado en un 1
		//Entonces solo busco a la derecha
		return cuenta(med+1,fin,arr,cont);
	}
	
	/*EJEMPLO:
		 0 1 2 3 4 5 6
		(1,1,1,1,0,0,0)
		medio = 0+6/2 = 3
		--Inicias en 1 -> recorre hacia la derecha
		--> cuenta(4,6,arr,0)
		--> cuenta(5,6,arr,1)
		--> cuenta(6,6,arr,2)
		--> if(inicio==final) and arr[inicio]==0 -> cont+1
		--> Entonces cont termina siendo igual a 3;
		-----------------------------------------------------
		--Inicias en 0 -> recorre de inicio a medio-1
		 0 1 2 3 4 5 6
		(1,1,1,0,0,0,0)
		--> cuenta(0,2,arr,6-3+1+0) -> (0,2,arr,4)
		--> cuenta(0,1,arr,2-1+1+1) -> (0,1,arr,2)
		--> cuenta(0,0,arr,1-0+1+2) -> (0,0,arr,4)
		--> if(inicio==final) and arr[inicio]==1 -> cont
		--> Entonces cont termina siendo igual a 4
	*/
}

int main(){
	int n=7;	//   0 1 2 3 4 5 6 
	int arreglo[] = {1,0,0,0,0,0,0};
	cout<< cuenta (0,n-1,arreglo,0);
	
	return 0;
}
