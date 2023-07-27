#include <iostream>
#include <cmath>
#define MAXCOLUM 3
using namespace std;

int robot(int x, int y,int n, int m, int tablero[][MAXCOLUM]){
	int derecha=-99999, abajo=-99999; //para los casos que tengan negativos//
	//condicion de parada//
	//cuando llegue a 2//
	if(x==n-1 && y==m-1)
		return tablero[x][y];
	//recursion//
	if(y+1<m) derecha = robot(x,y+1,n,m,tablero);
	if(x+1<n) abajo = robot(x+1,y,n,m,tablero);
	
	if(derecha>abajo)
		return derecha+tablero[x][y];
	return abajo+tablero[x][y];
}

int main(){
	
	int n=3,m=MAXCOLUM;
	//int tablero[n][m];
	int tablero[][MAXCOLUM] = {
		{2,3, 5},
		{4,3,-1},
		{6,-2,2}
	};
	
	cout<< robot(0,0,n,m,tablero);
	/*
		for(int fil=0;fil<n;fil++){
			cout<<"Fila "<<fil+1<<":"<<endl;
			for(int col=0;col<m;col++){
				cin>>tablero[fil][col];
			}
			cout<<endl;
		}
	*/
	
	return 0;
}
