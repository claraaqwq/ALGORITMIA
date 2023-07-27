#include <iostream>
#include <cmath>
#define MAXPRED 3
using namespace std;

void cargabin (int num, int n, int cromo[]){
	int i, resto;
	for(i=0;i<n;i++) cromo[i] = 0; //inicializo el cromo en ceros
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}
}

struct Proyecto{
	int numProyecto;
	int ganancia;
	int costo;
	int predecesor[MAXPRED];
	int cantPredecesores;
};

int main(){
	int n,p,fil,i,costo,gananciaMax=0,ganancia,k,predecesor;
	
	cout<<"Ingrese numero máximo de proyectos"<<endl;
	cin>>n;
	cout<<"Ingrese el presupuesto "<<endl;
	cin>>p;
	
	int cromo[n];
	int ArrSoluciones[n];
	int opciones = (int) pow(2,n);
	
	Proyecto proyecto[n]; //saco la estructura a evaluar
	for(fil=0;fil<n;fil++){
		cout<<"Ingrese el costo, ganancia y predecedor del proyecto N° ";
		proyecto[fil].numProyecto = fil+1;
		proyecto[fil].cantPredecesores = 0;
		
		cout<<proyecto[fil].numProyecto<<":"<<endl;
		cout<<"Insertar costo: ";
		cin>>proyecto[fil].costo;
		cout<<"Insertar Ganancia: ";
		cin>>proyecto[fil].ganancia;
		cout<<"Insertar Predecedores (cuando haya terminado de insertar colocar un 0) :"<<endl;
		for(k=0;k<MAXPRED;k++){
			cin>>predecesor;
			if(predecesor==0) break;
			proyecto[fil].predecesor[k] = predecesor;
			proyecto[fil].cantPredecesores++;
		}
		cout<<endl;
	}
	
	
	
	for(i=0;i<opciones;i++){
		costo = 0;
		ganancia = 0;
		cargabin(i,n,cromo);
		
		for(fil=0;fil<n;fil++){
			//cout<<cromo[fil];
			costo = costo + cromo[fil]*proyecto[fil].costo;
			ganancia = ganancia + cromo[fil]*proyecto[fil].ganancia;
		}
		//cout<<endl;
	}
	
	
	return 0;
}




