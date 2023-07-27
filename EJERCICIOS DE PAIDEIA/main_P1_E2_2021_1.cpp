#include <iostream>
#define N 4
#define C 6

using namespace std;

int soluciones[C] = {0,0,0,0,0,0};
int posSolucion=0;
int cantSoluciones=0;
int costoTotal=0;

int esPosibleColocarVacuna(int vacuna,int ciudad,int refri[C],int colindantes[C][C], int ciudades){
	if (vacuna==1 && refri[ciudad]==0){
		return 0;
	}
	for (int i=0; i<ciudades; i++){
		if (colindantes[ciudad][i]==1 && soluciones[i]==vacuna){
			return 0;
		}
		if (colindantes[i][ciudad]==1 && soluciones[i]==vacuna){
			return 0;
		}
	}
	return 1;
}

int encontrarSoluciones(int vacunas,int costos[N],int refri[C],int colindantes[C][C],int ciudades,int pos){
	if (pos==ciudades){
		/*Imprimir la solucion encontrada*/
		cout << "Solucion " << ++cantSoluciones << endl;
		for (int i=0; i<ciudades; i++){
			cout << "Ciudad " << i << ": Vacuna: " << soluciones[i] << endl;
		}
		cout << "Costo: " << costoTotal << endl;
		//return 1;
		return 0;
	}
	/*Si estoy en una ciudad, debo ver que vacuna puedo colocar*/
	for (int vacuna=1; vacuna<=vacunas; vacuna++){
		if (esPosibleColocarVacuna(vacuna,pos,refri,colindantes,ciudades)){
			soluciones[posSolucion] = vacuna;
			posSolucion++;
			costoTotal = costoTotal + costos[vacuna-1];
			if (encontrarSoluciones(vacunas,costos,refri,colindantes,ciudades,pos+1)){
				return 1;
			}
			posSolucion--;
			soluciones[posSolucion] = 0;
			costoTotal = costoTotal - costos[vacuna-1];
		}
	}
	return 0;
}

int main(){
	int costos[N] = {10,5,12,8};
	int refri[C] = {0,0,1,0,1,0};
	int colindantes[C][C] = {{0,1,1,0,0,1},
							 {1,0,1,1,0,0},
							 {1,1,0,1,0,1},
							 {0,1,1,0,1,1},
							 {0,0,0,1,0,1},
							 {1,0,1,1,1,0}};
	int ciudades = 6;
	int vacunas = 4;
	encontrarSoluciones(vacunas,costos,refri,colindantes,ciudades,0);
	return 1;
}
