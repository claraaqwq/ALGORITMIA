#include <iostream>
#include <cmath>

using namespace std;

int cargabin(int num, int n, int cromo[]){
	int i,resto;
	for(i=0;i<n;i++) cromo[i]=0;
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}
}

int main(){
	int n,p,t,i,acciones,col,j,maxAcciones=0;
	double ganancia,maxGanancia=0.0,gananciaTotal;
	
	cout<<"Ingrese la cant limite de acciones: "<<endl;
	cin>>t;
	cout<<"Ingrese el precio por accion: "<<endl;
	cin>>p;
	cout<<"Ingrese la cantidad de clientes: "<<endl;
	cin>>n;
	
	double tabla[][2] = {
	{3000,0.1},
	{3800,0.02},
	{2800,0.15},
	{3500,0.05},
	{3200,0.08},
	{3400,0.03}
	};
	int cromo[n],ArrSoluciones[n];
	int opciones = (int) pow(2,n);
	
	for(i=0;i<opciones;i++){
		acciones=0,gananciaTotal=0.0;
		cargabin(i,n,cromo);
		
		for(col=0;col<n;col++){
			//cout<<cromo[col];
			acciones = acciones + cromo[col]*tabla[col][0];//para la columna de acciones
			ganancia = tabla[col][0]*tabla[col][1]*p; //para la columna de comision
			gananciaTotal = ganancia*cromo[col] + gananciaTotal;
		}
		//cout<<endl;
		//cout<<"A: "<<comision<<endl;
		
		
		if(acciones<t && maxGanancia<gananciaTotal){
			maxGanancia = gananciaTotal;
			maxAcciones = acciones;
			for(j=0;j<n;j++) ArrSoluciones[j] = cromo[j];
			//cout<<maxGanancia<<endl;
		}
		
	}
	
	
	//imprimir
	cout<<endl<<"Resultado: "<<endl;
	cout<<"Para este conjunto de datos, una solucion con la máxima ganancia debido a las"<<endl;
	cout<<"comisiones seria de "<<maxGanancia<<" dolares por un total de "<<maxAcciones<<" acciones"<<endl;
			
	cout<<"Clientes que se deben elegir para obtener la mayor ganancia son:"<<endl;
	for(j=0;j<n;j++){
		if(ArrSoluciones[j]==1){
			cout<<"El cliente "<<j+1<<" otorga una ganancia de "<<p*tabla[j][0]*tabla[j][1]<<" dolares por comprar "<<
			tabla[j][0]<<" acciones"<<endl;
		}
	}


	return 0;
}
