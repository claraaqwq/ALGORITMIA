#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i,resto;
	for(i=0;i<n;i++) cromo[i] = 0; //lleno el arreglo de ceros
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}
}

int main(){
	/* PLANTEAMIENTO:
		-Este ejercicio lo podria trabajar con matrices, sin embargo al estar dividida la tabla se va a complicar 
		-por ello una idea seria poner toda la tabla en un arreglo, y pensar como podria hacer para dividirla en 2 tablas
	*/
	int n=4,j,p=23,peso,m=0,l,gananciaMax=0,ganancia;
	int cantProd = n*4;
	int productos[cantProd] = {7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11};
	int ganancias[cantProd] = {10,15,10,10,10,10,20,10,10,10,10,5,5,10,5,10};
	int cromo[cantProd];
	int opciones = (int) pow(2,cantProd);
	
	//creamos las opciones del cromo
	cout<<"Si se le solicita formar un pedido de "<<p<<" kilos, tendrá la siguientes soluciones"<<endl;
	for(int i=0;i<opciones;i++){
		peso=0,ganancia=0;
		cargabin(i,cantProd,cromo);
		
		//recorro el cromo
		for(j=0;j<cantProd;j++){
			peso = peso + cromo[j]*productos[j];
			ganancia = ganancia + cromo[j]*ganancias[j];
		}
		
		
		if(peso==23 && gananciaMax<ganancia){
			
			gananciaMax = ganancia;
			
			cout<<"Ganancia: "<< gananciaMax << " ";
			
			cout<<"Resultado ";
			cout<<setw(2)<<m+1<<": ";
			
			for(l=0;l<cantProd;l++){
				if(cromo[l]==1){
					cout<<productos[l]<<"k ";
				}
			}
			
			//ahora para escribir las posiciones
			cout<<"Ubicaciones: ";
			for(l=0;l<cantProd;l++){
				if(cromo[l]==1){
					if(l%4==0)  cout<<"IA"<<l/4+1<<" ";
					if(l%4==1)  cout<<"IB"<<l/4+1<<" ";
					if(l%4==2)  cout<<"DA"<<l/4+1<<" ";
					if(l%4==3)  cout<<"DB"<<l/4+1<<" ";
				}
			}
			
			cout<<endl;
			m++;
		}
		
	}
	
	
	return 0;
}





