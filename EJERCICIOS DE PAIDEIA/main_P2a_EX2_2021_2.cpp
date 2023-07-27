#include <iostream>
#include <math.h>

#define N 4
#define M 4

using namespace std;

int calcularMenor(int movAbajo,int movDerecha,int movDiagonal){
	int menor;
	if (movAbajo<=movDerecha && movAbajo<=movDiagonal){
		menor = movAbajo;
	}
	else {
		if (movDerecha<=movAbajo && movDerecha<=movDiagonal){
			menor = movDerecha;
		}
		else {
			menor = movDiagonal;
		}
	}
	return menor;
}

int mostrarDistanciasDron(int almacen[N][M],int n,int m,int filas,int columnas){
	int soluciones[filas][columnas];
	soluciones[0][0] = 0; /*Esto se coloca porque en la posicion 0,0 no nos hemos movido para nada*/
	/*Vamos a procesar la primera fila, que es un caso particular porque siempre viene de la derecha*/
	for (int j=1; j<columnas; j++){
		soluciones[0][j] = abs(almacen[0][j] - almacen[0][j-1]) + soluciones[0][j-1];
	}
	/*Vamos a procesar la primera columna, que es un caso particular porque siempre viene de la arriba*/
	for (int i=1; i<filas; i++){
		soluciones[i][0] = abs(almacen[i][0] - almacen[i-1][0]) + soluciones[i-1][0];
	}
	/*Ahora si viene o bueno hay que evaluar las 3 posibles direcciones*/
	for (int i=1; i<n; i++){
		for (int j=1; j<m; j++){
			int movAbajo = abs(almacen[i][j] - almacen[i-1][j]) + soluciones[i-1][j];
			int movDerecha = abs(almacen[i][j] - almacen[i][j-1]) + soluciones[i][j-1];
			int movDiagonal = abs(almacen[i][j] - almacen[i-1][j-1]) + soluciones[i-1][j-1];
			int menor = calcularMenor(movAbajo,movDerecha,movDiagonal);
			soluciones[i][j] = menor;
		}
	}
	
	cout << "Tablero de distancias: " << endl;
	/*Imprimimos el tablero resultado*/
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << soluciones[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int almacen[N][M] = {{4,2,2,4},
						 {1,4,6,8},
						 {2,5,9,1},
						 {1,3,11,12}};
	int n=4, m=4;
	int filas=4, columnas=4;
	mostrarDistanciasDron(almacen,n,m,filas,columnas);
	return 0;
}
