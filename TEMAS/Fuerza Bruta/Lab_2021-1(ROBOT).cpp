#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i,resto;
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
	int n,peso,parcial,i,col,j,k,num=0,ganancia,Mejorganancia=0;
	
	cout<<"Ingrese la cantidad de secciones: "<<endl;
	cin>>n;
	cout<<"Ingrese el peso pedido: "<<endl;
	cin>>peso;
	
	int prod[] = {7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11};
	int ganancias[] = {10,15,10,10,10,10,20,10,10,10,10,5,5,10,5,10};
	int cantProd = n*4; //lo pongo de esa manera pq quiero que mi cromo guarde 16 bits//
	int cromo[cantProd]; //cantidad de bits en un cromo // se guarda en vertical el cromo//
	int opciones = (int) pow(2,cantProd); //cantidad máxima de opciones//
	
	for(i=0;i<opciones;i++){
		parcial=0,ganancia=0;
		cargabin(i,cantProd,cromo);
		
		for(col=0;col<cantProd;col++){
			parcial = parcial + cromo[col]*prod[col];
			ganancia = ganancia + cromo[col]*ganancias[col];
		}
		
		if(parcial==peso && Mejorganancia<ganancia){
			Mejorganancia = ganancia;
			//se recorre el cromo de nuevo//
			
			cout<<"Ganancia: "<<Mejorganancia;
			
			cout<<setw(10)<<" "<<"Resultado ";
			cout.fill('0');
			cout<<setw(2)<<num<<": ";
			cout.fill(' ');
			
			for(k=0;k<cantProd;k++){
				if(cromo[k]==1){
					cout<<prod[k]<<"k ";	
				}
			}
			
			cout<<"Ubicaciones: ";
			for(j=0;j<cantProd;j++){
				if(cromo[j]==1){
					//PARA IZQUIERDA 0-1//PARA A->0//PARA B->1//
					if(j%4==0) cout<<"IA"<<j/4+1<<" "; //para el 0-4-8-12
					if(j%4==1) cout<<"IB"<<j/4+1<<" "; //para el 1-5-9-13
					//PARA DERECHA   2-3//PARA A->2//PARA B->3//
					if(j%4==2) cout<<"DA"<<j/4+1<<" "; //para el 2-6-10-14
					if(j%4==3) cout<<"DB"<<j/4+1<<" "; //para el 3-7-11-15
				}
			}
			
			num++;
			cout<<endl;
		}
		
	}
		
	
	return 0;
}




