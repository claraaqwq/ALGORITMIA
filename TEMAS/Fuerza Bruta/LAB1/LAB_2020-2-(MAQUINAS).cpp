#include <iostream>
#include <cmath>
#define MAXCOL 3
using namespace std;

void cargabin (int num, int n, int cromo[]){
	int resto, i;
	for(i=0;i<n;i++) cromo[i]=0; //inicializamos el cromo en cero
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto; //guardamos el num en el cromo
		i++;
	}
}

int main(){
	int n=8,p=250;
	int cromo[n],ArrSolucion[n];
	int opciones = (int) pow(2,n);
	int ganancia, costo, gananciaMax=0,costoTotal,fil,cantMaquinas,m1,m2,m3;
	int ArrTabla[n][MAXCOL] = {
		{40,150,1},
		{20,80,1},
		{100,300,2},
		{100,150,2},
		{50,80,2},
		{10,50,3},
		{50,120,3},
		{50,150,3}
	};
	
	//evaluamos las opciones de cromo
	for(int i=0;i<opciones;i++){
		ganancia=0;
		costo=0;
		m1=m2=m3=0;
		cargabin(i,n,cromo);
		//recorremos el cromo, por posiciones 
		for(fil=0;fil<n;fil++){
			
			ganancia = ganancia + cromo[fil]*ArrTabla[fil][1];
			costo = costo + cromo[fil]*ArrTabla[fil][0];
			//evaluamos los tipos de maquinas
			switch (ArrTabla[fil][2]){
				case 1: m1++;break;
				case 2: m2++;break;
				case 3: m3++;
			}
		
		}
		cantMaquinas = m1+m2+m3;
		
		//validamos las restricciones
		if(costo<=p && m1>=1 && m2>=1 && m3>=1 && cantMaquinas<=10 && gananciaMax<ganancia){
			gananciaMax = ganancia;
			costoTotal = costo;
			//guardo mi solucion
			for(int j=0;j<n;j++){
				ArrSolucion[j] = cromo[j];
			}
		}
	}
	
	//imprimo mi solucion
	cout<<"Maquinas: ";
	for(int i=0;i<n;i++){
		if(ArrSolucion[i]==1){
			cout<<i+1<<" ";
		}
	}
	cout<<". Costo de maquinas "<<costoTotal<<" (Millones de $) y una ganancia de "<<gananciaMax<<" (Millones de $)"<<endl;
	
	
}
