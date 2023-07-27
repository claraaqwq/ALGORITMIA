#include <iostream>
#define MAX 6
using namespace std;

//CREO MATRIZ GLOBAL
int almacen[][MAX] = {
	{1,2,9,1,2,3},
	{5,1,7,0,2,1},
	{0,7,0,3,8,1},
	{1,2,6,1,2,2},
	{0,6,9,5,0,5},
	{0,0,4,0,9,0}
};

int recorroH(int x, int i, int col){
	//El y es donde inicia, en este caso inicia en 0
	if(i==col) return 0; //saltá a la casilla y se cortá pq es el vacio
	return recorroH(x,i+1,col) + almacen[x][i]; //va sumando los pesos de la matriz
}

int recorroV(int i, int fil, int y){
	//El x es donde inicia, en este caso inicia en x+1
	if(i==fil) return 0; //saltá a la casilla y se cortá pq es el vacio
	return recorroV(i+1,fil,y) + almacen[i][y]; //va sumando los pesos de la matriz
}

int pesoMax(int x, int y , int fil, int col){
	int sumaHorizontal,sumaVertical,sumaTotal,parcial;
	//Condicion de parada
	if(col-1 == 0) return 0;
	
	//Realizo las sumas y recorro las casillas:
	//Empiezas en x, y va a ir avanzando y recorres hasta la columna
	sumaHorizontal =  recorroH(x,0,col);
	//Empiezas desde una casilla abajo de la que ya tomaste y recorrerás las filas, hasta la columna -1 
	//En este caso el y=col, porque está empezando desde la derecha e irá reduciendo
	sumaVertical   =  recorroV(x+1,fil,col-1);
	//Hallo la sumaTotal
	sumaTotal = sumaHorizontal + sumaVertical;
	
	//APLICO RECURSION PARA EVALUAR LOS SIGUIENTES, la fila baja y la columna retrocede
	//empiezo ahora en (1,0,6,5)
	parcial = pesoMax(x+1,y,fil,col-1);
	
	if(sumaTotal>parcial){
		return sumaTotal;
	}else{
		return parcial;
	}
	
}

int main(){
	
	int n=6; //numero de filas y numero de columnas
	cout<<"El peso maximo de todas las rutas es: "<<pesoMax(0,0,n,n)<<endl;
	
	
	return 0;
}
