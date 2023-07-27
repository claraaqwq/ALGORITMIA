#include <iostream>
#define N 6

using namespace std;

int calcularCostoMayor(int monedas[N],int cantMonedas){
	int tabla[N+1];
	tabla[0] = 0;
	tabla[1] = monedas[0];
	for (int i=1; i<cantMonedas; i++){
		if (monedas[i]+tabla[i-1]>tabla[i]){
			tabla[i+1] = monedas[i]+tabla[i-1];
		}
		else {
			tabla[i+1] = tabla[i];
		}
	}
	return tabla[cantMonedas];
}

int main(){
	int monedas[N] = {5,1,2,10,6,2};
	int cantMonedas = 6;
	int costoMayor = calcularCostoMayor(monedas,cantMonedas);
	cout << "Costo Mayor: " << costoMayor;
	return 0;
}
