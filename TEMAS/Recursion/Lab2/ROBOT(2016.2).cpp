#include <iostream>
#define MAX 20

using namespace std;

//EJERCICIO DEL ROBOT CON RECURSION --> SOLO SE PODRÁ POVER DERECHA Y ABAJO
int robot (int x, int y, int fil, int col ,int tablero[][MAX]){
	int abajo=-99999,derecha=-99999; //LE PONGO VALORES NEGATIVOS MUY GRANDE POR SI EN EL TABLERO HAY UN NEGATIVO
	//LA CONDICION DE PARADA ES QUE LLEGUE AL ULTIMO CASILLERO
	if(x==fil-1 && y==col-1){
		return tablero[x][y]; //Retorna valor de la posicion
	}
	
	//CONDICION DE AVANCE: tengo que validar q el x+1 | y+1 sean menor a la fil y col
	if(y+1<col) derecha = robot(x,y+1,fil,col,tablero); // -20
	if(x+1<fil) abajo   = robot(x+1,y,fil,col,tablero);
	
	//VER QUE ESTÁ HACIENDO
	//cout<<derecha<<" "<<abajo<<endl;
	
	//MOVIMIENTOS = 2 UNIVERSOS => DERECHA Y ABAJO
	//comparar la suma, quien es mayor?
	if(derecha < abajo)
		return abajo + tablero[x][y];
	else 
		return derecha + tablero[x][y];
	
}


int main(){
	//Llenamos el tablero
	int tablero[][MAX] = {
		{0,3,1},
		{2,7,6},
		{20,5,4}
	};
	int n=3,m=3,i,j;
	//posicion (x,y) , fil, col, tablero
	cout<<robot(0,0,n,m,tablero);
	
	
	return 0;
}
