#include <iostream>
#include <cmath>
#define MAXBAHIAS 3
using namespace std;

void cargabin (int num, int n, int cromo[],int &cantUnos){
	int i, resto;
	cantUnos=0;
	for(i=0;i<n;i++) cromo[i] = 0;
	i=0;
	while(num>0){
		resto = num %2;
		num = num/2;
		cromo[i] = resto;
		if(cromo[i]==1) cantUnos++;
		i++;
	}
}

int main(){
	
	int n,m,c,fil,col,parcial,cantUnos,mcomb;
	
	cout<<"Ingrese la cantidad de productos: "<<endl;
	cin>>n;
	cout<<"Ingrese la cantidad de divisiones: "<<endl;
	cin>>m;
	cout<<"Ingrese la cantidad de toneladas: "<<endl;
	cin>>c;
	
	int ArrCromo[MAXBAHIAS][n];
	int cromo[n*MAXBAHIAS], ArrSoluciones[n*MAXBAHIAS];
	int opciones = (int) pow(2,n*MAXBAHIAS);
	
	/*cout<<"Ingrese los pesos de los productos para cada bahia: "<<endl;
	for(fil=0;fil<MAXBAHIAS;fil++){
		cout<<"Bahia "<<fil+1<<": ";
		for(col=0;col<n;col++){
			cin>>ArrBahia[fil][col];
		}
		cout<<endl;
	}*/
	
	int ArrBahia[MAXBAHIAS][n] = {
		{2,5,6,10},
		{7,8,15,3},
		{11,9,6,4}
	};
	
	//creo la cantidad de opciones para mi cromo
	for(int i=0;i<opciones;i++){
		parcial=0;
		cargabin(i,n*MAXBAHIAS,cromo,cantUnos);
		
		//ahora evaluo el cromo
		//como me dan un numero total de productos que pueden estar, lo puedo hallar con cantidad de 1's
		if(cantUnos == m){
			int t=0;
			//En todas las columnas hay productos, se toma al cromo como una matriz --> guardar
			for(fil=0;fil<MAXBAHIAS;fil++){
				for(col=0;col<n;col++){
					ArrCromo[fil][col] = cromo[t]; //guardo el cromo como matriz
					parcial = parcial + ArrCromo[fil][col]*ArrBahia[fil][col]; //guardo la suma de pesos en ese cromo
					//cout<<cromo[t];
					t++;
				}
			}
			//cout<<endl;
			
			if(parcial == c){
				//devuelvo en que numero me dieron las 5 divisiones y la suma fue igual al c
				mcomb = i;
				cout<<"La combinacion es: "<<i<<endl;
				for(fil=0;fil<MAXBAHIAS;fil++){
					cout<<"Bahia "<<fil+1<<":";
					for(col=0;col<n;col++){
						if(ArrCromo[fil][col]==1){
							cout<<ArrBahia[fil][col]<<" ";
						}
					}
					cout<<endl;
				}
				
				cout<<endl;
			}
		}
	}
	
	return 0;
}
