#include <iostream>
#include <cmath>

using namespace std;

//USANDO COMPLEJIDAD LOG(N) --> no se usa for's

void buscapareja(int ini, int fin, int arr[]){
	
	if(ini==fin){
		cout << "El sin pareja: "<<arr[ini];
		return ;
	}
	
	//Existen 2 casos: medio par || medio impar
	int med = (ini+fin)/2;
	
	//Case1: ES PAR
	if(med%2==0){
		if(arr[med]==arr[med+1]){
			buscapareja(med+2,fin,arr);
		}else{
			buscapareja(ini,med,arr);
		}
	//Case2: ES IMPAR
	}else{
		if(arr[med]==arr[med-1]){
			buscapareja(med+1,fin,arr);
		}else{
			buscapareja(ini,med,arr);
		}
	}
	
}

int main(){
	
	int n=7;
	int arreglo[] = {8,3,3,4,4,7,7};
	//directamente te dice el numero que no tiene pareja
	buscapareja(0,n-1,arreglo);
	
	return 0;
}

