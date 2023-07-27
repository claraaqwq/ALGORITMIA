#include <iostream>
#include <cmath>
#include <fstream>
#define MAXCOL 2
using namespace std;

void cargabin(int num, int n, int cromo[], int &cantUnos){
	int i,resto;
	cantUnos=0;
	for(i=0;i<n;i++) cromo[i] = 0; //inicializo mi cromo en cero
	i=0;
	while(num>0){
		resto = num%2;
		num =  num/2;
		cromo[i] = resto;
		if(cromo[i]==1) cantUnos++;
		i++;
	}
}

int main(){
	
	int salario,fil,col,n,m,p,salarioMax=0; 
	int salarioCant,roturaCant,mcomb,cantUnos,obreros;
	double roturaProm,menorPosible=999999.999;
	
	cout<<"Ingrese el numero max de obreros: ";
	cin>>n;
	cout<<"Ingrese el numero min de obreros: ";
	cin>>m;
	cout<<"Ingrese el presupuesto: ";
	cin>>p;
	
	int ArrObreros[n][MAXCOL];
	
	/*for(fil=0;fil<n;fil++){
		cout<<"Ingrese para el obrero "<<fil+1<<":"<<endl;
		for(col=0;col<MAXCOL;col++){
			cin>>ArrObreros[fil][col];
		}
		cout<<endl;
	}*/
	
	ifstream arch ("texto2.txt",ios::in);
	int rotura, i;
	while(true){
		arch>>rotura;
		if(arch.eof())break;
		arch>>salario;
		
		ArrObreros[i][0] = rotura;
		ArrObreros[i][1] = salario;
		i++;
	}
	
	int cromo[n];
	int ArrSoluciones[n];
	int opciones = (int) pow(2,n);
	
	//genero todas las opciones posibles del cromo
	for(i=0;i<opciones;i++){
		salarioCant=0;
		roturaCant=0;
		cargabin(i,n,cromo,cantUnos);
		//recorro el cromo
		if(cantUnos>=m && cantUnos<=n){
			for(fil=0;fil<n;fil++){
				salarioCant = salarioCant + cromo[fil]*ArrObreros[fil][1];
				roturaCant = roturaCant + cromo[fil]*ArrObreros[fil][0];
				//cout<<cromo[fil];
			}
			//Hallo la rotura promedio, que seria la cantidad de roturas entre cant de obreros
			roturaProm = ((double)roturaCant/(double)cantUnos);
			//cout<<endl;
			
			if(salarioCant<p && roturaProm<menorPosible){
				salarioMax = salarioCant;
				menorPosible = roturaProm;
				//guardo el cromo en un arrSoluciones
				for(int j=0;j<n;j++){
					ArrSoluciones[j] = cromo[j];
				}
			}
		}
	}
	
	
	cout<<"Obreros: ";
	for(int fil=0;fil<n;fil++){
		if(ArrSoluciones[fil]==1){
			cout<<fil+1<<" ";
		}
	}
	cout<<endl;
	cout<<"Costo de salarios de "<<salarioMax<<" (Miles de $) y una rotura promedio de "<<menorPosible<<".";
	
	return 0;
}
