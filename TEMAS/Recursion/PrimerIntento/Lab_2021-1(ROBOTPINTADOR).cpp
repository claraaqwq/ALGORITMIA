#include <iostream>
#include <fstream>
#define MAX_FIL 10
#define MAX_COL 10
using namespace std;

/*
M = Maximo de productos x dia
N = Minimo de productos x dia
D = El numero de dias
P = El numero de productos x dia
*/

int EncontrarMayor(int *arrProd, int cantElem){
	int mayor = 0;
	int indice_mayor;
	int indice = 0;
	CompararMayor (arrProd,cantElem,mayor,indice_mayor,indice);
	
	//Cambiar al mayor por cero
	if
	
}

void CompararMayor (int *arrProd,int cantElem,int &mayor,int &indice_mayor,int &indice){
	if(arrProd[indice]>mayor){
		mayor = arrProd[indice];
		indice_mayor = indice;
	}
	
	indice++;
	if(indice == cantElem){
		return;
	}
	CompararMayor(arrProd,cantElem,mayor,indice_mayor,indice);
}

void Pintar(int *arrProdFila,int cantProdPintarxDia,int &cantPintada, int matriz_CodPro_Pintados[MAX_FIL][MAX_COL],int fila){
	
	int mayor = EncontrarMayor(arrProdFila); //cambiarlo por cero
	matriz_CodPro_Pintados[fila][cantPintada] = mayor;
	cantPintada++;
	//para detener
	if(cantPintada == cantProdPintarxDia){
		return; //se acabó
	}else{
		Pintar(arrProdFila,cantProdPintarxDia,cantPintada,matriz_CodPro_Pintados,fila);
	}
	
}

void ElegirProdPintar(int *arrProdFila,int cantProdPintarxDia,int matriz_CodPro_Pintados[MAX_FIL][MAX_COL],int fila){
	//Elegir el mayor y que lo vaya eliminando
	int cantPintada = 0;
	Pintar(arrProdFila,cantProdPintarxDia,cantPintada,matriz_CodPro_Pintados,fila);
}

//aumento en & pq va a cambiar, igual fila y cantProdPintarxDia
void robotPintador(int matriz_CodPro[MAX_FIL][MAX_COL],int matriz_CodPro_Pintados[MAX_FIL][MAX_COL],
				   int &fila,int &cantProdPintarxDia,int M,int N,int &aum){
	
	ElegirProdPintar(matriz_CodPro[fila],cantProdPintarxDia,matriz_CodPro_Pintados,fila);
	
	//imprimir fila
	for(int i=0;i<cantProdPintarxDia;i++){
		cout<<matriz_CodPro_Pintados[fila][i]<<" ";
	}
	cout<<endl;
	
	//CONDICION DE PARADA
	if(cantProdPintarxDia==N){
		//stop
		return ;
	}else{
		//Si no llegó al minimo
		//Elegir la cantProdPintarxDia de la fila
		cantProdPintarxDia = cantProdPintarxDia + aum ; //7 -> 8 -> 9
		
		//verifico que no me pasé el maximo de prod
		if(cantProdPintarxDia>M){ // 9 > 8
			cantProdPintarxDia--; // -> conviertelo en 8prod nuevamente 
			aum = -1;
		}
		fila++; //1 -> 2
		robotPintador(matriz_CodPro,matriz_CodPro_Pintados,fila,cantProdPintarxDia,M,N,aum);
	}
	
}


int main(){
	
	ifstream archPro("Productos.txt",ios::in);
	int M,I,N,D,P;
	//Datos: Vida de los Rollos
	archPro>>M>>I>>N;
	//Datos: Calendario de productos
	archPro>>D>>P;
	
	int matriz_CodPro[MAX_FIL][MAX_COL];
	
	int fil,col;
	for(fil=0;fil<D;fil++){
		for(col=0;col<P;col++){
			archPro>>matriz_CodPro[fil][col];
		}
	}
	
/*	for(fil=0;fil<D;fil++){
		for(col=0;col<P;col++){
			cout<<matriz_CodPro[fil][col]<<" ";
		}
		cout<<endl;
	}
*/
	//Lo inicializo en cero**********
	int matriz_CodPro_Pintados[MAX_FIL][MAX_COL];
	
	//funcion(matrizCodigos,matrizLLenar,fila,cantPro(varia),maxPro,minPro)
	int fila=0; //iniciamos en la primera fila
	int cantProdPintarxDia = I; //ejemplo = 6 productos
	int aumento=1;
	//Para el movimiento se necesitan las filas y columnas --> D y P
	robotPintador(matriz_CodPro,matriz_CodPro_Pintados,fila,cantProdPintarxDia,M,N,aumento);

	//imprimir(matriz_CodPro_Pintados)
	cout<<"El rodillo durará "<<fila+1<<" dias.";

	
	return 0;
}

