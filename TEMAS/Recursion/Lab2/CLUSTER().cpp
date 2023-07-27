#include <iostream>
#define M 9
#define N 7
using namespace std;

/*Revisemos solo horizontal y vertical*/

int cuadroPintar[N][M] = {    {0,0,0,0,0,0,0,0,0}, //0 - 1
						 	  {0,0,0,0,0,0,0,0,0}, //1 - 2
						 	  {0,0,0,0,0,0,0,0,0}, //2 - 3
					     	  {0,0,0,0,0,0,0,0,0}, //3 - 4
						 	  {0,0,0,0,0,0,0,0,0}, //4 - 5
						 	  {0,0,0,0,0,0,0,0,0}, //5 - 6
						 	  {0,0,0,0,0,0,0,0,0}, //6 - 7
						 };

int calcular_cluster(int x, int y, int tablero[][M]){
	
	//diagonal arriba, diagonal abajo, diagonal derecha, diagonal izq
	int arriba=0, abajo=0, izquierda=0, derecha=0;
	
	//Condicion de parada -> cuando caiga en ceros o cuando se sale del tablero
	//Si donde me voy a posicionar aparece 1 en el cuadro pintado, significa que no puedo posicionarme ahi y end
	if(tablero[x][y]==0 || cuadroPintar[x][y]==1){
		return 0;
	}
	
	if(x==N && y==M) return 0;
	
	//ES NECESARIO CORROBORAR QUE NO PASEMOS POR LOS MISMOS
	cuadroPintar[x][y] = 1;
	
	if(x+1<N){
		abajo     = calcular_cluster(x+1,y,tablero);
	}
	
	if(x-1>=0){
		arriba    = calcular_cluster(x-1,y,tablero);

	}
	
	if(y+1<M){
		derecha   = calcular_cluster(x,y+1,tablero);
	}
	
	if(y-1>=0){
		izquierda = calcular_cluster(x,y-1,tablero);
	}
	
	
	return derecha+izquierda+abajo+arriba+1;
}


int main(){			//M	//1 2 3 4 5 6 7 8 9
						//0 1 2 3 4 5 6 7 8         N
	int tablero[N][M] = {{0,0,0,0,0,0,0,0,0}, //0 - 1
						 {1,0,0,1,0,0,0,1,0}, //1 - 2
						 {0,1,0,0,0,0,0,1,0}, //2 - 3
					     {0,1,0,0,0,1,0,1,0}, //3 - 4
						 {0,1,0,0,0,0,1,1,0}, //4 - 5
						 {0,1,1,1,0,0,0,1,1}, //5 - 6
						 {0,0,0,0,0,0,0,1,1}, //6 - 7
						};
						
	int x,y;
	cout<<"Ingrese una coordenada: "<<endl;
	cin>>x>>y;
	//Caso x=3 and y=4
	//En tablero: x=2 and y=3
	//Se le pasa x-1 and y-1 porque el tablero va de 0->n-1
	cout<<"El tamano del cluster es: "<<calcular_cluster(x-1,y-1,tablero);
	
}

