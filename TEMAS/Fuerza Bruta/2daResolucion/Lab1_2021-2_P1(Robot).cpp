#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, res;
	for(i=0;i<n;i++)cromo[i]=0; //para inicializar el arreglo en cero//
	i=0;
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}



int main(){
	int n=16; //nmr de paquetes
	int peso=23,parcial;
	int opciones = (int) pow(2,n); //nmr de combinaciones totales;
	int paq[]={7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11};
	int cromo[n]; //arreglo del numero de paquetes
	int l=0;
	
	for(int i=0;i<opciones;i++){
		cargabin(i,n,cromo);
		parcial=0;
		//se recorre el cromo//
		for(int j=0;j<n;j++){
			//para hallar la cantidad del peso//
			parcial = parcial + paq[j]*cromo[j];
		}
		//verificamos la condición
		if(parcial==peso){
			//se recorre el cromo otra vez//
			cout<<"Ubicacion "<<l+1<<":";
			for(int k=0;k<n;k++){ //k -> numero que esta en un bit del cromo//
				if(cromo[k]){
					if(k%4==0) cout<<"IA"<<k/4+1<<" ";
					if(k%4==1) cout<<"IB"<<k/4+1<<" "; 
					if(k%4==2) cout<<"DA"<<k/4+1<<" ";
					if(k%4==3) cout<<"DB"<<k/4+1<<" ";
				}
			}
			cout<<endl;
			l++;
		}
	}
	
	
	return 0;
}
