#include <iostream>
#include <fstream>
#define MAXFIL 10
#define MAXCOL 10
using namespace std;

int recorrerHorizontal (int x, int i, int col,int MatrizRutas[][MAXCOL]){
	//CASO BASE: recorre hasta que llegue a la ultima columna
	if(i == col) return 0;
	return recorrerHorizontal(x,i+1,col,MatrizRutas) + MatrizRutas[x][i];
}

int recorrerVertical (int i,int y,int fil,int MatrizRutas[][MAXCOL]){
	//CASO BASE: recorre hasta llegar a la ultima fila
	if(i == fil) return 0;
	return recorrerVertical(i+1,y,fil,MatrizRutas) + MatrizRutas[i][y];
}

int calcularRuta(int x,int y,int MatrizRutas[][MAXCOL],int fil,int col){
	
	int sumaHorizontal, sumaVertical, sumaTotal, parcial;
	//CASO BASE: cuando la ruta a recorrer sea la esquina inferior izquierda
	if(col-1==0) return 0;
	
	//Recorre la primera fila, el y va a iterar porque se moverá a la derecha y la columna ayuda al caso base
	sumaHorizontal = recorrerHorizontal(x,0,col,MatrizRutas);
	//Recorre ultima columna y va a iterar porque se moverá hacia abajo y la fila ayuda al caso base
	sumaVertical = recorrerVertical(x+1,col-1,fil,MatrizRutas);
	
	//Ahora realizo una suma total de esos 2 movimientos
	sumaTotal = sumaHorizontal + sumaVertical;
	
	//Ahora si se aplica recursion, esta será para hallar la suma total del caso q fil-1 y col-1
	parcial = calcularRuta(x+1,y,MatrizRutas,fil,col-1);
	
	//Comparamos sumas
	if(sumaTotal<parcial){
		return parcial;
	}else{
		return sumaTotal;
	}
	
}

int main(){
	
	int fil=6, col=6;
	int MatrizRutas[MAXFIL][MAXCOL];
	
	ifstream arch ("rutas.txt",ios::in);
	
	//guardo los datos
	for(int fila=0;fila<fil;fila++){
		for(int cola=0;cola<col;cola++){
			arch>>MatrizRutas[fila][cola];
		}
	}
	
	//Ahora llamo a la funcion para hacer el proceso de recursion
	int rutaMax = calcularRuta(0,0,MatrizRutas,fil,col);
	cout<<"La mejor rutá será: "<<rutaMax<<" ."<<endl;
	
	return 0;
}
