#include <iostream>
#include <cmath>
#define MAXCOL 3
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, resto;
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
	int n,p,fil,col,i,ganancia,costo,gananciaMax=0,j;
	int t1,t2,t3,maquinasTotales,costoTotal;
	cout<<"Ingrese la cantidad de maquinas a usar: "<<endl;
	cin>>n;
	cout<<"Ingrese el presupuesto: "<<endl;
	cin>>p;
	
	int opciones = (int) pow(2,n);
	int ArrCGT[n][MAXCOL], ArrSoluciones[n], cromo[n];
	
	for(fil=0;fil<n;fil++){
		cout<<"Ingrese el costo ganancia y tipo de la maquina "<<fil+1<<" :"<<endl;
		for(col=0;col<MAXCOL;col++){
			cin>>ArrCGT[fil][col];
		}
	}
	
	for(i=0;i<opciones;i++){
		ganancia=0;costo=0;
		t1=0;t2=0;t3=0;
		cargabin(i,n,cromo);
		
		for(fil=0;fil<n;fil++){
			ganancia = ganancia + cromo[fil]*ArrCGT[fil][1];
			costo = costo + cromo[fil]*ArrCGT[fil][0];
			
			if(cromo[fil]==1){
				switch(ArrCGT[fil][2]){
					case 1: t1++;break;
					case 2: t2++;break;
					case 3: t3++;
				}
			}
			//cout<<cromo[fil];
		}
		maquinasTotales = t1+t2+t3;
		//cout<<endl;
		//cout<<maquinasTotales<<endl;
		if(maquinasTotales<=10 && costo<=p && t1>=1 && t2>=1 && t3>=1 && gananciaMax<ganancia){
			gananciaMax = ganancia;
			costoTotal = costo;
			for(j=0;j<n;j++){
				ArrSoluciones[j] = cromo[j];
			}
		}
	}
	
	
	cout<<endl<<"Una de las soluciones para los datos mencionados seria: "<<endl;
	cout<<"Maquinas: ";
	for(i=0;i<n;i++){
		if(ArrSoluciones[i]==1){
			cout<<i+1<<" ";
		}
	}
	cout<<endl<<"Costo de maquinas "<<costoTotal<<" (Millones de $) y una ganancia de "<<gananciaMax<<" (Millones de $)"<<endl;
	
	
	return 0;
}


