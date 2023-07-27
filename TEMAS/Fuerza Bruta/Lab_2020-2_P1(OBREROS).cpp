#include <iostream>
#include <cmath>
#define MAXCOL 2
using namespace std;

void cargabin(int num, int n, int cromo[],int &cantUnos){
	int i, resto;
	cantUnos=0;
	for(i=0;i<n;i++) cromo[i]=0;
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		if(cromo[i]==1) cantUnos++;
		i++;
	}
}

int main(){
	
	int n,m,p,fil,col,i,parcial,j,rotura,salarioT=0;
	int cantUnos;
	double roturaProm,roturaMin=99999;
	
	cout<<"Ingrese la cantidad de obreros: "<<endl;
	cin>>n;
	cout<<"Cuantos obreros como minimo deben trabajar: "<<endl;
	cin>>m;
	cout<<"Cuanto es el presupuesto: "<<endl;
	cin>>p;
	
	int ArrRS[n][MAXCOL],ArrSolucion[n];
	int cromo[n];
	int opciones = (int) pow(2,n);
	
	for(fil=0;fil<n;fil++){
		cout<<"Ingrese la rotura y el salario del obrero "<<fil+1<<":"<<endl;
		for(col=0;col<MAXCOL;col++){
			cin>>ArrRS[fil][col];
		}
	}
	
	for(i=0;i<opciones;i++){
		parcial = 0;rotura=0;
		cargabin(i,n,cromo,cantUnos);
		
		//para la cantidad de obreros, verifico//
		if(cantUnos>=m && cantUnos<=n){
			for(fil=0;fil<n;fil++){
				parcial = parcial + cromo[fil]*ArrRS[fil][1];
				rotura = rotura + cromo[fil]*ArrRS[fil][0];
			}
			roturaProm = (double) rotura/cantUnos;
			
			if(parcial<p && roturaProm<roturaMin){
				salarioT = parcial;
				roturaMin = roturaProm;
				for(j=0;j<n;j++){
					ArrSolucion[j] = cromo[j];
				}
			}
		}
		
	}
	//imprimo//
	cout<<"Obreros: ";
	for(j=0;j<n;j++){
		if(ArrSolucion[j]==1){
			cout<<j+1<<" ";
		}
	}
	cout<<endl<<"Costo de salarios de "<<salarioT<<"(Miles de $) y una rotura promedio de "<<roturaMin<<"."<<endl;
	
	
	return 0;
}
