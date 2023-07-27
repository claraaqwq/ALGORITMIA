#include <iostream>
#include <cmath>
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int resto, i;
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
	int n = 12; //12 posibilidades de productos//filas//
	int hora[24]; // arreglo de horas --> [0,0,0,0,0,0,0,...,0]
	int cromo[n];
	int p1,p2,p3,p4; //prioridades (1-4)
	int k,HoraTomada,mcomb,fil;
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
	
	int opciones = (int) pow(2,n);
	int ArrSoluciones[n];
	
	for(int i=0;i<opciones;i++){
		cargabin(i,n,cromo);
		p1=p2=p3=p4=0;
		HoraTomada=0;
		//inicializo el arreglo de horas en cero, para despues ir llenando
		for(int h=0;h<24;h++){
			hora[h] = 0; // termina de esta forma hora[0,0,0,0,...,0]
		}
		
		//recorro el cromo por sus posiciones, de forma VERTICAL "tablero"
		//cromo[0] = [0,0,0,0,0]
		for(fil=0;fil<n;fil++){
			
			//ponemos evaluar de frente solo los pedidos que si está tomando
			if(cromo[fil] == 1){
				//observamos las prioridades y las empezamos a contar
				switch (datos[fil][1]){
					case 1: p1++; break;
					case 2: p2++; break;
					case 3: p3++; break;
					case 4: p4++; 
				}
				
				//ahora verificamos el cruce de horarios
				//Planteamiento = la hora total será la suma de la hora de entrega + cantTiempoTomado
				//cada que tomes una hora, no la puedes repetir. Por ello usamos una bandera que avisé si ya la usamos
				//empezamos a contar desde datos[fil][2]
				
				for(k=datos[fil][2];k<datos[fil][2]+datos[fil][3];k++){
					//primero la hora esta disponible
					//hora[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
					if(hora[k] == 0){
						//marcamos que ya usamos la hora
						hora[k]=1;
						//hora[0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
					}else{
						//significa que la hora ya se tomó
						HoraTomada = 1;
						break;
					}
				}
				if(HoraTomada==1) break; //pasa a evaluar otro cromo
			}
			
		}
		
		//ahora validamos todo lo que nos piden
		if(p1>=2 && p2>=2 && p3>=1 && p4>=1 && HoraTomada==0){
			mcomb=i;
			//break;
			//eso uso si solo quiero que me imprima una solu
			cout<<"La lista de reparto que cumple con las siguientes condiciones es: ";
			cout<<mcomb<<endl;
			for(int j=0;j<n;j++){
				if(cromo[j]==1){
					cout<<datos[j][0]<<"     "<<datos[j][1]<<endl;
				}
			}	
			
		}
		
	}
	
	/*
	//ESTO SI QUIERO QUE ME IMPRIMA LA ULTIMA
	//imprimimos
	cargabin(mcomb,n,cromo);
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	cout<<"La lista de reparto que cumple con las siguientes condiciones es: ";
	cout<<mcomb<<endl;
	for(int i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<datos[i][0]<<"     "<<datos[i][1]<<endl;
		}
	}
	*/
	
	return 0;
}


