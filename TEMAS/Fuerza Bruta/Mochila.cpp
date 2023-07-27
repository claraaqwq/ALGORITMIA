#include <iostream>
#include <math.h>
#define N 7

using namespace std;


void cargabin(int num, int n, int cromo[]){
	int i=0, resto;
	// n -> elementos del cromo - arreglo //
	//como no se sabe si las posiciones del cromo estan llenos o vacias -> lo inicializamos en cero//
	//for(i=0;i<n;i++) cromo[i] = 0; // 0 0 0 0 0 //
	
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}	
}

int main(){
	int paq[] = {1,2,4,12,1};
	int n=5; //cantidad de paquetes
	int peso=15,parcial,mpeso=0,mcomb;
	int opciones = (int)pow(2,n); //numero máximo de soluciones //
	int cromo[n]; //el arreglo estará formado de 5 paquetes //
	
	for(int i=0;i<opciones;i++){
		parcial = 0;
		cargabin(i,n,cromo); //toma el numero decimal (i) y lo convierte en binario en cromo //
		for(int j=0;j<n;j++){
			//para hallar la cantidad del peso//
			parcial = parcial + paq[j]*cromo[j];
		}
		if(parcial <= peso && mpeso<=parcial){
				mpeso = parcial;
				mcomb = i;
		}
	}
	
	cout <<"Mejor Peso: "<<mpeso<<" / i = "<<mcomb<<endl;
	cout <<"Paquetes:"<<endl;
	cargabin(mcomb, n, cromo);
	
	for(int i = 0;i < n; i++){
		if(cromo[i] == 1)
			cout<<paq[i]<<endl; 
	}
	
	return 0;
}
