#include <iostream>

using namespace std;

//matriz global//
int mapa[][6] = {
		{0,0,0,1,0,1},
		{0,0,1,0,0,0},
		{0,1,0,0,0,1},
		{1,0,0,0,0,0},
		{0,1,0,0,0,0},
		{0,0,0,0,1,0}
	};

//x = posicion x , y= posicion y , xm = movimiento X , ym= movimiento y , n = fila, m = col //
int buscar(int x, int y, int xm, int ym, int x1, int y1,
		   int fil, int col){
	int cont=0;
	if(x>=fil || x<0 || y>=col || y<0) return 0;
	if(mapa[x][y]==1 && x1==0 && y1==0) cont++;
	
	if(x1==0){
		//hacia abajo//
		for(int i=x+1;i<fil;i++) cont+= mapa[i][y];
		//hacia arriba//
		for(int i=0;i<x;i++) cont+= mapa[i][y];
	}
	
	if(y1==0){
		//hacia los lados//
		for(int i=y+1;i<col;i++) cont+=mapa[x][i];
		for(int i=0;i<y;i++) cont+=mapa[x][i];
	}
	
	cont = cont + buscar(x+xm,y+ym,xm,ym,xm,ym,fil,col);
	
	return cont;
}

int main(){
	
	int n=6,m=6;
	
	cout<< buscar(3,2,0,1,0,0,n,m);
	
	return 0;
}
