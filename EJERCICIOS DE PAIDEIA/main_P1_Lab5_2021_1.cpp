#include <iostream>
#define N 12
using namespace std;

/*La de proyectos*/

int calcularGananciaMaxima(int ganancias[N],int n){
	int solucion[n+1];
	solucion[0] = 0;
	solucion[1] = ganancias[0];
	if (ganancias[1]>solucion[1]){
		solucion[2] = ganancias[1];
	}
	else {
		solucion[2] = solucion[1];
	}
	/*El i va a manejar el indice del arreglo de soluciones*/
	for (int i=3; i<=n; i++){
		int suma = ganancias[i-1] + solucion[i-3];
		if (suma>solucion[i-1]){
			solucion[i] = suma;
		}
		else {
			solucion[i] = solucion[i-1];
		}
	}
	/*Imprimir los resultados parciales*/
	cout << " Soluciones Parciales: ";
	for (int i=0; i<=n; i++){
		cout << solucion[i] << " ";
	}
	cout << endl;
	/*Parte c, impresion de resultado*/
	int maximo = solucion[n];
	cout << "Las ganancias son: ";
	while (maximo>0){
		for (int i=0; i<=n; i++){
			if (solucion[i]==maximo){
				maximo = maximo - ganancias[i-1];
				cout << ganancias[i-1] << "k ";
				break;
			}
		}
	}
	cout << endl;
	return solucion[n];
}

int main(){
	
	int n=12;
	int ganancias[N] = {3,6,1,2,4,5,18,10,13,7,15,2};
	cout << "La ganancia maxima es: " << calcularGananciaMaxima(ganancias,n);
	return 0;
}
