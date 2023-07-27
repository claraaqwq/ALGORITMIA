#include <iostream>
#include <cmath>
#define MAXCOL 4
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i,resto;
	for(i=0;i<n;i++) cromo[i] = 0; //inicializar el cromo en cero
	i=0;
	while(num>0){
		resto = num%2;
		num   = num/2;
		cromo[i] = resto;
		i++;
	}
}

int main(){
	int n = 12; //12 posibilidades de productos//filas//
	int hora[24];
	int cromo[n];
	int datos[][4] = {
		{100, 4,  8,2},
		{101, 2, 10,2},
		{102, 3, 12,2},
		{103, 1, 13,2},
		{104, 3, 15,1},
		{105, 1, 10,2},
		{106, 4, 16,1},
		{107, 2,  8,2},
		{108, 3, 14,1},
		{109, 2, 18,2},
		{110, 1, 18,2},
		{111, 4, 14,2}
	};
	
	int opciones = (int)pow(2,n);
	int i,k,p1,p2,p3,p4,fil,cruce; //2 2 1 1//
	//lo paso a cromo//
	for(i=0;i<opciones;i++){
		p1=p2=p3=p4=0;
		cargabin(i,n,cromo);
		cruce = 0; //para ver que no se repitieron las horas//
		for(k=0;k<24;k++)
			hora[k]=0;
		for(fil=0;fil<n;fil++){
			//sumando prioridades//
			if(cromo[fil]==1){ //evaluamos los pedidos que si está tomando
				//sacamos la prioridad//
				switch(datos[fil][1]){
					case 1: p1++; break;
					case 2: p2++; break;
					case 3: p3++; break;
					case 4: p4++; 
				}
				/*
				if (datos[fil][1]==1) p1++;
				if (datos[fil][1]==2) p2++;
				if (datos[fil][1]==3) p3++;
				if (datos[fil][1]==4) p4++;
				*/
				
				//revisando cruces//
				for(k=datos[fil][2];k<datos[fil][2]+datos[fil][3];k++)
					if(hora[k]==0)
						hora[k]=1;
					else{
						cruce = 1; //porque ya tomó la hora
						break;
					}
				if(cruce==1)
				break; //para que pase a evaluar el otro cromo
			}
		}
		
		if(p1>=2 && p2>=2 && p3>=1 && p4>=1 && cruce==0){
			cout<<"La lista de reparto que cumple con las condiciones es: "<<endl;
			cout<<i<<endl<<endl;
			for(fil=0;fil<n;fil++)
				if(cromo[fil]==1)
					//imprimo el dato y la prioridad//
					cout<<datos[fil][0]<<" "<<datos[fil][1]<<endl;
			//pq piden una sola solución
			cout<<endl;
		}
		
	}
		
	return 0;
}
