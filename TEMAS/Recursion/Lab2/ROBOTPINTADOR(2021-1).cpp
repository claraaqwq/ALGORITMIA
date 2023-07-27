#include <iostream>
#include <fstream>
#define MAXFIL 10
#define MAXCOL 9
using namespace std;

void CompararMayor(int *arrProductosFila,int cantElementos,int &mayor,int &indice_mayor,int &indice){
	if(arrProductosFila[indice] > mayor){
		mayor = arrProductosFila[indice];
		indice_mayor = indice;
	}
	
	indice++;
	//CASO PARADA
	if(indice == cantElementos){
		//termina acá 
		return;
	}
	CompararMayor(arrProductosFila,cantElementos,mayor,indice_mayor,indice);
}

int EncontrarMayor(int *arrProductosFila,int cantElementos){
	
	//Como idea tengo que los indices mayores al i, tendré que rellenarlo con ceros, porque quedan vacias
	int mayor=0;
	int indice_mayor;
	
	int indice=0;
	CompararMayor(arrProductosFila,cantElementos,mayor,indice_mayor,indice);
	
	//Cada que encuentro el mayor, lo actualizo con cero, para que ya no tome a ese como mayor
	arrProductosFila[indice_mayor] = 0;
	
	return mayor;
	
}

void Pintar(int *arrProductosFila,int cantProdPintarxDia,int cantPintada,
			int MatrizProductos_Pintados[MAXFIL][MAXCOL],int fila){
			
	int mayor = EncontrarMayor(arrProductosFila,MAXCOL);
	
	//lo guardo en la matriz nueva
	MatrizProductos_Pintados[fila][cantPintada] = mayor;
	//Aumento la cantidad de casillas que voy pintando
	
	//CASO PARADA
	if(cantPintada == cantProdPintarxDia){
		//aca termino
		return;
	}else{
		Pintar(arrProductosFila,cantProdPintarxDia,cantPintada+1,MatrizProductos_Pintados,fila);
	}
		
}

void ElegirCantProdPintar(int *arrProductosFila,int cantProdPintarxDia,int MatrizProductos_Pintados[MAXFIL][MAXCOL],int fila){
	//Elegir el mayor y que lo vaya eliminando
	int cantPintada = 0;
	//Ahora empiezo a pintar 
	Pintar(arrProductosFila,cantProdPintarxDia,cantPintada,MatrizProductos_Pintados,fila);
}

//aumento en & pq va a cambiar, igual fila y cantProdPintarxDia
void RobotPintador(int MatrizProductos[MAXFIL][MAXCOL],int MatrizProductos_Pintados[MAXFIL][MAXCOL],int &fila,
                   int &cantProdPintarxDia,int M,int N, int &aumento){
   	
	//Tengo que eligir que cantidad de productos pintaré x Dia
	//La fila irá cambiando mientras vaya pintando cada columna
	ElegirCantProdPintar(MatrizProductos[fila],cantProdPintarxDia,MatrizProductos_Pintados,fila);
	
	//imprimo la fila de los pintados
	//Ejemplo: primero sabemos que imprimirá 6 productos
	for(int i=0;i<cantProdPintarxDia;i++){
		cout<<MatrizProductos_Pintados[fila][i]<<" ";
	}   
	cout<<endl;
	
	//CASO PARADA
	//Se sabe que dejará de pintar cuando haya llegado hasta el N=4
	if(cantProdPintarxDia==N){
		return ;
	}else{
		//Aca corroboramos que era necesario poner el aumento en &, porqué ira aumentando
		//mientras vaya pintando las filas
		//Ejemplo: ya pintó la primera fila, se sabe que la segunda tendrá que pintar una casilla más
		//Aumento vale 1
		// cant = 6 + 1;
		cantProdPintarxDia = cantProdPintarxDia + aumento;
		//Ahora tengo que validar que solo pintará hasta un M = 8
		//Es en este punto que empieza a pintar en 1 menos hasta llegar a N = 4
		if(cantProdPintarxDia > M){
			cantProdPintarxDia--;
			aumento = -1;
		}
		
		//La fila pasa a evaluar las de abajo, por eso aumento 1
		fila++;
		//Vuelvo a llamar a la funcion, para que pinte la segunda fila
		RobotPintador(MatrizProductos,MatrizProductos_Pintados,fila,cantProdPintarxDia,M,N,aumento);
	}             	
}


int main(){
	int M,I,N,D,P;
	
	ifstream arch ("Productos.txt",ios::in);
	
	//Empiezo a leer los datos
	arch>>M>>I>>N;
	arch>>D>>P;
	
	int MatrizProductos[MAXFIL][MAXCOL];
	for(int fil=0;fil<D;fil++){
		for(int col=0;col<P;col++){
			arch>>MatrizProductos[fil][col];
		}
	}
	
	/*Verifico que lei bien
	for(int fil=0;fil<D;fil++){
		for(int col=0;col<P;col++){
			cout<<MatrizProductos[fil][col]<<" ";
		}
		cout<<endl;
	}*/
	
	//Creo matriz que me mostrará las casillas pintadas
	int MatrizProductos_Pintados[MAXFIL][MAXCOL];
	int fila = 0; //Cant dias que durará hasta llegar al N
	int aumento = 1;
	//Creo una funcion que me empiece a pintar
	RobotPintador(MatrizProductos,MatrizProductos_Pintados,fila,I,M,N,aumento);
	
	cout<<"El rodillo durará: "<<fila+1<<" dias."<<endl;
	
	return 0;
}
