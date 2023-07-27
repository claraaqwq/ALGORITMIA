#include <iostream>
#include <cmath>

using namespace std;
//Ejercicio de la mochila sin help

void cargabin(int num, int n, int cromo[]){
	int i, resto;
	//n es la cantidad de elementos en el cromo//
	//como no sabemos si el cromo esta lleno o vacio, lo inicializamos en cero//
	for(i=0;i<n;i++) cromo[i] = 0;
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}
	
}

int main(){
	//i=     	 0 1 2 3  4
	int paq[] = {1,2,4,12,1};
	int n=5;
	int opciones = (int) pow(2,n);
	int parcial, mpeso=0, mcomb;
	int peso = 15;
	int cromo[n];
	
	for(int i=0;i<opciones;i++){
		//iniciamos la suma de todos los pesos como cero
		parcial = 0;
		cargabin(i,n,cromo);
		for(int j=0;j<n;j++){
			parcial = parcial + cromo[j]*paq[j];
			cout<<cromo[j];
		}
		cout<<endl;
		if(parcial<=peso && mpeso<=parcial){
			mpeso = parcial;
			mcomb = i;
		}
	}
	
	/*
	cargabin(mcomb,n,cromo);
	cout<<"Combinacion: "<<mcomb<<endl;
	cout<<"Peso: "<<mpeso<<endl;
	cout<<"Paquetes: "<<endl;
	for(int i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<paq[i]<<endl;
		}
	}
	*/
	

	return 0;
}
