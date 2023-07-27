#include <iostream>
#include <cmath>
#define MAXCOL 3
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int resto,i;
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
	int predecedores,proyectos;
	int n=8, p=250,gananciaMax=0,ganancia,costo,fil,flag,mcomb,total;
	int ArrProyectos[n][3] = {
		{1,80,150},{2,20,80},{3,100,300},{4,100,150},{5,50,80},{6,10,50},{7,50,120},{8,50,150}
	};
	int ArrPredecedores[n][MAXCOL] = {{0,0,0},{0,0,0},{1,2,0},{0,0,0},{0,0,0},{2,0,0},{6,0,0},{6,0,0}};
	int cromo[n];
	int ArrSoluciones[n];
	int opciones = (int) pow(2,n);
	
	for(int i=0;i<opciones;i++){
		ganancia=0,costo=0;
		cargabin(i,n,cromo);
		
		//leo el cromo
		for(fil=0;fil<n;fil++){
			//cout<<cromo[fil];
			//Que solo verifique los proyectos seleccionados y sume sus ganancias y costos
			if(cromo[fil]==1){
				//voy a verificar si los predecedores coinciden, si es asi la bandera se activa
				flag=1; //asumo que si hay predecedores --> asumo que si chocan las compras
				for(predecedores=0;predecedores<MAXCOL;predecedores++){
					if(ArrPredecedores[fil][predecedores]!=0){ //no tomará los que van con cero
						//al realizar el cromo tenemos que restarle uno, pq nuestro cromo empieza a contar desde 0
						//por la tanto, en posiciones nuestro proyecto 1, seria la posicion 0 del cromo, el 2 seria pos 1...
						if(cromo[ArrPredecedores[fil][predecedores]-1]==0){
							flag = 0; //no hay predecedores --> no chocan las compras
							break;
						}
					}
				}
				
				if(flag==1){ // si flag == 0, realizo calculos -> pq no chocan las compras
					//acumulo costos y ganancias
					ganancia = ganancia + cromo[fil]*ArrProyectos[fil][2];
					costo = costo + cromo[fil]*ArrProyectos[fil][1];
				}else{
					ganancia = 0;
					costo = 0;
					break;
				}		
			}
		}
		//cout<<endl;
		//tenemos acumulado el costo y la ganancia del cromo
		//ahora se analiza si cumple con las restricciones
		if(costo<=p && gananciaMax<=ganancia){
			total = costo;
			gananciaMax = ganancia;
			mcomb = i;
		}	
	}
	
	
	//imprimimos resultados
	cargabin(mcomb,n,cromo);
	//imprimo predecedores a usar
	cout<<"Mejor Solucion"<<endl;
	cout<<"Predecedores : ";
	for(int j=0;j<n;j++){
		if(cromo[j]==1){
			cout<<j+1<<" ";
		}
	}
	cout<<endl;
	cout<<"El costo total fue de "<<total<<" soles"<<endl;
	cout<<"La maxima ganancia es de "<<gananciaMax<<" soles";
	
	return 0;
}
