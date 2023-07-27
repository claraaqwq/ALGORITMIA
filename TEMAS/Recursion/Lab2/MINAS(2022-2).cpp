#include <iostream>
#include <fstream>
#define MAXFIL 10
#define MAXCOL 10
using namespace std;

int MatrizSinMinas[MAXFIL][MAXCOL] = {
						//     0 1 2 3 4
							  {0,0,0,0,0}, //0 - 1
						 	  {0,0,0,0,0}, //1 - 2
						 	  {0,0,0,0,0}, //2 - 3
					     	  {0,0,0,0,0}, //3 - 4
						 	  {0,0,0,0,0}, //4 - 5
						 	  {0,0,0,0,0}, //5 - 6
						 	  {0,0,0,0,0}, //6 - 7
						 	  {0,0,0,0,0}, //7 - 8
						 	  {0,0,0,0,0}, //8 - 9

};

int RobotDetectaMinas(int MatrizTableroMina[][MAXCOL],int MatrizSinMinas[][MAXCOL],int x,int y,int fil,int col){
	
	//CASO BASE: cuando el recorrido se salga del tablero
	if(x>=fil-1 && y>=col-1) return 0;
	
	//Hallo la cantidad de pasos por cada movimiento
	//movimientos -> Derecha, Abajo, Diagonal (D+A)
	int cantPasosDerecha=9999, cantPasosAbajo=9999, cantPasosDiagonal=9999;
	//aplico recursion
	
	//OBSERVACION:
	/*Es necesario saber que pasa si existe mina en la posicion que queremos posicionarlo. Para ello la pintamos.
	  De forma que si esta pintada, en la matriz vacia le dará un espacio*/
	
	//DERECHA: se podrá si no se llegó al final del tablero y si donde me estoy posicionando no hay una mina = 1
	
	if(y+1<col && MatrizTableroMina[x][y+1] == 0){
		cantPasosDerecha = 1 + RobotDetectaMinas(MatrizTableroMina,MatrizSinMinas,x,y+1,fil,col);
	}else{
		if(MatrizTableroMina[x][y+1]==1){
			//PINTAMOS
			MatrizSinMinas[x][y+1] = 1;
		}
		if(MatrizTableroMina[x][y-1]==1)
			MatrizSinMinas[x][y-1] = 1;
	}
	
	//ABAJO: se podrá si no se llegó al final del tablero y si donde estoy posicionado no hay una mina = 1
	if(x+1<fil && MatrizTableroMina[x+1][y] == 0){
		cantPasosAbajo = 1 + RobotDetectaMinas(MatrizTableroMina,MatrizSinMinas,x+1,y,fil,col);
	}else{
		if(MatrizTableroMina[x+1][y]==1){
			//PINTAMOS
			MatrizSinMinas[x+1][y] = 1;
		}
	}
	
	//DIAGONAL: se podrá si no se llegó al final del tablo y si donde estoy posicionado no hay una mina = 1
	if(x+1<fil && y+1<col && MatrizTableroMina[x+1][y+1]==0){
		cantPasosDiagonal = 1 + RobotDetectaMinas(MatrizTableroMina,MatrizSinMinas,x+1,y+1,fil,col);
	}else{
		if(MatrizTableroMina[x+1][y+1]==1){
			//PINTAMOS
			MatrizSinMinas[x+1][y+1] = 1;
		}
	}
	
	//Ahora es necesario comprobar que Cantpasos es el minima
	if(cantPasosDerecha<=cantPasosAbajo && cantPasosDerecha<=cantPasosDiagonal){
		return cantPasosDerecha;
	}else{
		if(cantPasosAbajo<=cantPasosDerecha && cantPasosAbajo<=cantPasosDiagonal){
			return cantPasosAbajo;
		}else{
			if(cantPasosDiagonal<=cantPasosDerecha && cantPasosDiagonal<=cantPasosAbajo){
				return cantPasosDiagonal;
			}
		}
	}
	
}

int main(){
//      fil col
	int fil=9,col=5;
	//Leo el archivo con los datos
	ifstream arch ("minas.txt",ios::in);
	int MatrizTableroMina[MAXFIL][MAXCOL];
	
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			arch>>MatrizTableroMina[i][j];
		}
	}
	
	//Me piden hallar la cantidad minima de pasos
	int cantMinimaPasos = RobotDetectaMinas(MatrizTableroMina,MatrizSinMinas,0,0,fil,col);
	cout<<"La cantidad minima de pasos fue: "<<cantMinimaPasos<<endl;
	
	cout<<"*****************************************************"<<endl;
	cout<<"-------------------------RADAR-----------------------"<<endl;
	for(int fila=0;fila<fil;fila++){
		for(int colu=0;colu<col;colu++){
			if(MatrizSinMinas[fila][colu]==0){
				cout<<" - ";
			}else{
				cout<<" * ";
			}
		}
		cout<<endl;
	}
	cout<<"*****************************************************"<<endl;
	
}
