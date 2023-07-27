#include <iostream>
#define N 6
#define M 6

using namespace std;

void calcularMayorCantidadProductos(int almacen[N][M],int n,int m,int p,int q){
	/*Ahora vamos a trabajar incluyendo una columna y fila adicional para trabajar todo bajo la misma logica*/
	int soluciones[p+1][q+1];
	/*Vamos a inicializar la fila 0 y columna 0 (adicionales) con el valor de 0 para que sea nuestro caso inicial*/
	/*La columna 0*/
	for (int i=0; i<=p; i++){
		soluciones[i][0] = 0;
	}
	/*La fila 0*/
	for (int j=0; j<=q; j++){
		soluciones[0][j] = 0;
	}
	for (int i=1; i<p+1; i++){
		for (int j=1; j<q+1; j++){
			if (soluciones[i-1][j]>soluciones[i][j-1]){
				soluciones[i][j] = soluciones[i-1][j] + almacen[i-1][j-1];
			}
			else {
				soluciones[i][j] = soluciones[i][j-1] + almacen[i-1][j-1];
			}
		}
	}
	cout << "La solucion a esta disposicion es de: " << soluciones[p][q] << endl;
	/*Ahora vamos a mostrar los resultados del tablero de seguimiento*/
	cout << "El tablero de productos es: " << endl;
	for (int i=1; i<p+1; i++){
		for (int j=1; j<q+1; j++){
			cout << soluciones[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int almacen[N][M] = {{1,2,9,1,2,3},
						 {5,1,7,1,2,1},
						 {1,7,1,3,8,1},
						 {2,2,6,1,2,2},
						 {3,6,9,5,1,5},
						 {1,1,4,1,9,1}};
	int n=6, m=6;
	int p=6, q=6;
	calcularMayorCantidadProductos(almacen,n,m,p,q);	
	return 0;
}
