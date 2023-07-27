#include <iostream>
#include <cmath>
#define MAX 20
using namespace std;

void cargaAlma(int x, int y,int n,int m,int almacen[][MAX]){
	
	if(x>=n || y>=m) return;//condicion de parada//
	
	if(x==n-1 && y==m-1) cout<<almacen[x][y];
	
	for(int i=y;i<m-1;i++){
		cout<<almacen[x][i]<<" ";
	}
	
	for(int i=x;i<n-1;i++){
		cout<<almacen[i][m-1]<<" ";
	}
	
	for(int i=m-1;i>y;i--){
		cout<<almacen[n-1][i]<<" ";
	}
	
	for(int i=n-1;i>x;i--){
		cout<<almacen[i][y]<<" ";
	}
	
	//recursion//
	cargaAlma(x+1,y+1,n-1,m-1,almacen);
	
}

int main(){
	
	int almacen[MAX][MAX];
	int n=5,m=5; //filas && columnas//
	int cont=1;
	
	//FILAS//
	for(int i=0;i<n;i++){
		//COLUMNAS//
		for(int j=0;j<m;j++){
			almacen[i][j] = cont++;
		}
	}
	//funcion recursive//
	cargaAlma(0,0,n,m,almacen);
	
	return 0;
}
