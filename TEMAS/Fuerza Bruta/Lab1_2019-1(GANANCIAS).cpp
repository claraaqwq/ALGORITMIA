#include <iostream>
#include <cmath>

using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, resto;
	//n -> elementos del cromo //
	for(i=0;i<n;i++) cromo[i]=0;
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i]=resto;
		i++;
	}
}


int main (){
	
	int paq[][2] = {{8,15},{2,20},{10,5},{10,10},{5,8},{5,5}};
	int i,j,parcial,mpeso=0,mcomb,peso=25;
	int n=6; //numero de articulos
	int valor,mvalor=0;
	int opcion = (int)pow(2,n);
	int cromo[n];
	
	for(i=0;i<opcion;i++){
		parcial=0;
		valor=0;
		cargabin(i,n,cromo); //toma el i y lo vuelve binario en cromo//
		for(j=0;j<n;j++){
			parcial = parcial + cromo[j]*paq[j][0]; //para su peso//
			valor   = valor   + cromo[j]*paq[j][1];
		}
		
		if(parcial<=peso && valor > mvalor){
			//mpeso = parcial;
			mvalor = valor;
			mcomb = i;
		}
		
	}
	
	cout<< "Respuesta: "<<endl;
	cout<< "Combinacion "<< mcomb<<endl;
	//11011//
	cout<< "El mejor valor es: "<< mvalor<<endl;
	cout<< "Articulos :"<<endl;
	cargabin(mcomb,n,cromo);
	
	for(j=0;j<n;j++){
		if(cromo[j]==1){
			cout<<j+1<<" ";
		}
	}
	
	return 0;
}


