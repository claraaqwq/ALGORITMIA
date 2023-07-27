#include <iostream>
#include <cmath>
#define MAXCOL 3
using namespace std;

void cargabin(int num, int n, int cromo[],int &cantUnos){
	int resto, i;
	cantUnos = 0;
	for(i=0;i<n;i++) cromo[i] = 0;//lleno el arreglo de ceros 
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		if(cromo[i]==1)cantUnos++;
		i++;
	}
}

int main(){
	int m,p,precio,montoTotal,cantHerramientas,fil,cantUnos;
	int cantTotalHerramientas=0,x=0;
	
	cout<<"Cuantos tipos de herramientas como maximo escogeras? :";
	cin>>m;
	cout<<"De cuanto es su presupuesto: ";
	cin>>p;
	
	int ArrHerramientas[8][MAXCOL] = {
		{1,4,3}, {2,5,2}, {3,4,1}, {4,2,1}, {5,6,3}, {6,3,3}, {7,4,2}, {8,1,4}
	};
	int cromo[8],ArrSoluciones[8];
	int opciones = (int) pow(2,8);
	
	//creo los cromos con sus opciones
	for(int i=0;i<opciones;i++){
		precio= 0,cantHerramientas=0;
		cargabin(i,8,cromo,cantUnos);
		
		//recorro el cromo
		for(fil=0;fil<8;fil++){
			precio = precio + cromo[fil]*ArrHerramientas[fil][1]*ArrHerramientas[fil][2];
			cantHerramientas = cantHerramientas + cromo[fil]*ArrHerramientas[fil][2];
			//cout<<cromo[fil];
		}
		//	cout<<endl;
		
		
		if( cantHerramientas>cantTotalHerramientas && precio<= p && cantUnos<=m ){
			cout<<"Solucion "<<x+1<<":" <<endl;
			
			for(int j=0;j<8;j++){
				if(cromo[j]==1){
					cout<<ArrHerramientas[j][0]<<" ";
				}
			}
			cout<<endl;
			cout<<"Monto Total: "<<precio<<endl;
			cout<<"Cantidad de Herramientas: "<<cantHerramientas<<endl;
				
			x++;
		}
		
		if( cantHerramientas>cantTotalHerramientas && precio<= p && cantUnos==m ){
			montoTotal = precio;
			cantTotalHerramientas = cantHerramientas;
			for(int j=0;j<8;j++){
				ArrSoluciones[j] = cromo[j];
			}
				
		}
		
	}
	
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	//imprimimos
	cout<<"Mejor Solucion: "<<endl;
	for(int l=0;l<8;l++){
		if(ArrSoluciones[l]==1){
			cout<<ArrHerramientas[l][0]<<" ";
		}
	}
	cout<<endl;
	cout<<"Monto Total: "<<montoTotal<<endl;
	cout<<"Cantidad de Herramientas: "<<cantTotalHerramientas<<endl;
	
	
	return 0;
}
