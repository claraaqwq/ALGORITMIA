#include <iostream>
#include <fstream>
#include <cmath>
#define MAXCOL 2
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int resto, i;
	//llena de ceros 
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
	
	int t,p,n,fil,col,acciones,maxAccion=0;
	double comision,ganancias,maxGanancia;
	
	ifstream arch ("texto1.txt",ios::in);
	
	cout<<"Ingresa la cantidad de acciones maximas: ";
	cin>>t;
	cout<<"Ingrese el precio de una accion: ";
	cin>>p;
	cout<<"Ingrese la cantidad de clientes: ";
	cin>>n;
	
	double ArrAcciones[n][MAXCOL],ArrSoluciones[n];
	int opciones = (int) pow(2,n);
	int cromo[n], i=0;
	
	int accionesA;
	double porcentaje;
	
	while(true){
		arch>>accionesA;
		if(arch.eof()) break;
		arch>>porcentaje;
		ArrAcciones[i][0]=accionesA;
		ArrAcciones[i][1]=porcentaje;
		i++;
	}
	
	/*for(int j=0; j<i; j++){
		cout << ArrAcciones[j][0] << " " << ArrAcciones[j][1]<< endl;
	}*/
	
	cout<<"Ingrese la cantidad de acciones a comprar y el porcentaje de comision"<<endl;
	for(fil=0;fil<n;fil++){
		cout<<"Para el cliente "<<fil+1<<":"<<endl;
		for(col=0;col<MAXCOL;col++){
			cin>>ArrAcciones[fil][col];
		}
		cout<<endl;
	}*/
	
	//empiezo definiendo la cantidad de opciones del binario
	for(int i=0;i<opciones;i++){
		acciones = 0,ganancias=0;
		cargabin(i,n,cromo);
		
		//recorro el cromo
		for(fil=0;fil<n;fil++){
			acciones = acciones + cromo[fil]*ArrAcciones[fil][0];
			comision = ArrAcciones[fil][0]*ArrAcciones[fil][1]*p;
			ganancias = ganancias+ comision*cromo[fil] ;
			//cout<<cromo[fil];
		}
		//cout<<endl;
		
		if(acciones<=t && maxGanancia<ganancias){
			maxAccion = acciones;
			maxGanancia = ganancias;
			for(int j=0;j<n;j++){
				ArrSoluciones[j] = cromo[j];
			}
		}
	}
	
	cout<<"Resultado:"<<endl;
	cout<<"Para este conjunto de datos, una solucion con la máxima ganancia debido a las"<<endl;
	cout<<"comisiones seria de "<<maxGanancia<<"dolares por un total de "<<maxAccion<<" acciones"<<endl;
	cout<<"Clientes que se deben elegir para obtener la mayor ganancia son: "<<endl;
	
	for(fil=0;fil<n;fil++){
		if(ArrSoluciones[fil] == 1){
			cout<<"- El cliente "<<fil+1<<" otorga una ganancia de "<<p*ArrAcciones[fil][0]*ArrAcciones[fil][1]<<
			" dolares por comprar "<<ArrAcciones[fil][0]<<" acciones.";
		}
		cout<<endl;
	}
	
	return 0;
}
