#include <iostream>
#include <cmath>
#define MAXCOL 4
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, resto;
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
	int i,p1,p2,p3,p4,fil,cruce,k,col;
	int hora[24];
	int n;
	cout<<"Ingrese la cantidad de productos a entregar: "<<endl;
	cin>>n;
	
	int tabla[n][MAXCOL];
	
	cout<<endl<<"Ingrese el cod del pedido + tipo del pedido + hora de entrega + cant tiempo invertido"<<endl;
	for(fil=0;fil<n;fil++){
		cout<<"Para el producto numero "<<fil+1<<": "<<endl;
		for(col=0;col<MAXCOL;col++){
			cin>>tabla[fil][col];
		}
		cout<<endl;
	}
	
	int cromo[n];
	int opciones = (int) pow(2,n);
	
	for(i=0;i<opciones;i++){
		p1=p2=p3=p4=0;cruce=0;
		cargabin(i,n,cromo);
		
		//inicializo el arreglo de las horas en cero//
		for(k=0;k<24;k++){
			hora[k]=0;
		}
		
		for(fil=0;fil<n;fil++){
			if(cromo[fil]==1){
				switch(tabla[fil][1]){
					case 1: p1++;break;
					case 2: p2++;break;
					case 3: p3++;break;
					case 4: p4++;
				}
				
				//valido que las horas no se crucen//
				for(k=tabla[fil][2];k<tabla[fil][2]+tabla[fil][3];k++){
					if(hora[k]==0){
						hora[k]=1; //está marcando la hora//
					}else{ //para las demás horas//
						cruce = 1; //pq ya tomó la hora//
						break;
					}
				}
				if(cruce==1) break;
			}
		}
		
		if(p1>=2 && p2>=2 && p3>=1 && p4>=1 && cruce==0){
			cout<<"La lista de reparto que cumple con las condiciones es: ";
			cout<<i<<endl<<endl;
			for(fil=0;fil<n;fil++){
				if(cromo[fil]==1){
					cout<<tabla[fil][0]<<" "<<tabla[fil][1]<<endl;
				}
			}
			break;
		}
		
	}
	
	return 0;
}



