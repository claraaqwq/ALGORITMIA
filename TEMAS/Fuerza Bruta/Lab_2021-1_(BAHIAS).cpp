#include <iostream>
#include <cmath>

#define MAXBAHIAS
using namespace std;

void cargabin(int num, int n, int cromo[],int &cantUnos){
	int i, resto;
	for(i=0;i<n;i++) cromo[i]=0; //inicializo en cero el arreglo
	i=0,cantUnos=0;
	while(num>0){
		resto = num%2;
		num   = num/2;
		cromo[i] = resto;
		if(cromo[i]==1)cantUnos++;
		i++;
	}
}


int main(){
	int fila,col;
	int n= 4;//numero de paquetes//
	int peso = 20;
	int parcial, mcomb,mpeso=0,div=5;
	int paquetes[][4] = {
	{2,5,6,10},
	{7,8,15,3},
	{11,9,6,4}
	};
	//				numero de paquetes x bahia
	int opciones = (int) pow(2,n*3);
	int cromo[n*3];
	int cantUnos;
	int ArrMatriz[3][n];
	
	cout<<"Una de las soluciones para los datos mencionados sería: "<<endl;
	for(int i=0;i<opciones;i++){
		parcial = 0; //va a ser la cantidad total del peso//
		cargabin(i,n*3,cromo,cantUnos);
		//Como me dan un numero exacto de paquetes que pueden entrar en el camión//
		if(cantUnos == div){
			//para las filas con las bahias//
			int i=0;
			for(fila=0;fila<3;fila++){
				for(col=0;col<n;col++){
					ArrMatriz[fila][col] = cromo[i];
					parcial = parcial + ArrMatriz[fila][col]*paquetes[fila][col];
					//cout<<cromo[i];
					i++;
				}			
				
			}
			//cout<<endl;
			
			
			if(parcial==peso){
				cout<<endl;
				mcomb=i;
				cout<<"El numero de combinación fue: "<< mcomb<<endl;
				//1100//
				for(fila=0;fila<3;fila++){
					cout<<"Bahia "<<fila+1<<":";
					for(col=0;col<n;col++){
						if(ArrMatriz[fila][col]==1){
							cout<<paquetes[fila][col]<<" ";
						}
					}
					cout<<endl;
				}
			}
			
			if(parcial>peso && cantUnos>div){
				cout<<"No hay respuestas válidas"<<endl;
			}
		}
	}
	
	
	return 0;
}
