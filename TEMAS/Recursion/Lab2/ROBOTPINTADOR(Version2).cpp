#include <iostream>
#include <fstream>
#define MAXFIL 10
#define MAXCOL 9
using namespace std;

int buscarMayor(int MatrizProductos[][MAXCOL],int inicio,int final,int fila){
	/*Inicializamos el indice con la primera columna*/
	int indice = inicio;
	/*Con esto saldremos de la iteracio, ya que sabremos cuando llegue a la primera columna*/
	if(inicio<final){
		/*Retornamos indice*/
		int siguienteIndice = buscarMayor(MatrizProductos,inicio+1,final,fila);
		/*Comparamos los indices y guardamos el mayor*/
		if(MatrizProductos[fila][siguienteIndice]>MatrizProductos[fila][indice]){
			indice = siguienteIndice;
		}
	}
	/*Retornamos el mayor de toda la columna*/
	return indice;
}

/*Buscamos el mayor de la fila, lo guardamos y eliminamos*/

void marcaMayor(int MatrizProductos[][MAXCOL],int inicio,int final,int MatrizProductos_Pintados[][MAXCOL],
				int fila,int P){
	int indiceMayor;;
	//CASO BASE: cuanto quiera pintar más de las casillas que estan permitidas, acaba
	if(inicio>=final){
		return ;
	}
	
	//buscamos el mayor de la fila
	//Recorre la cantidad de productos:  0 --> 9 y va ordenando
	indiceMayor = buscarMayor(MatrizProductos,0,P,fila);
	//YA TENGO EL MAYOR
	/*Lo guardamos en un arreglo en donde estarán los productos*/
	MatrizProductos_Pintados[fila][inicio] = MatrizProductos[fila][indiceMayor]; //ya ordenado
	//Como ya evalué ese mayor, lo pongo en cero para evaluar el siguiente, y tome al mayor como otro dato
	MatrizProductos[fila][indiceMayor] = 0;
	//RECURSION:
	marcaMayor(MatrizProductos,inicio+1,final,MatrizProductos_Pintados,fila,P);
	
}

void imprimirRecursivamente(int MatrizProductos_Pintados[][MAXCOL],int I, int primeraFila, int i){
	//CASO BASE: la posicion en la que me encuentre no puede sobrepasar la minima cant de prod a pintar
	if(i>=I){
		return;
	}
	
	cout<<MatrizProductos_Pintados[primeraFila][i]<<" ";
	imprimirRecursivamente(MatrizProductos_Pintados,I,primeraFila,i+1);
	
}

int RobotPinta(int MatrizProductos[][MAXCOL],int MatrizProductos_Pintados[][MAXCOL],int primeraFila,int ultimaFila,
			   int I,int N,int M,int P,int &desgaste){
	int bandera=0; //todav no termino de pintar las casillas que se pueden con el rodillo
	/*Recorremos todas las filas*/
	if(primeraFila>=ultimaFila){
		return ultimaFila;
	}
	
	//CASO BASE: Hasta que llegue a la cantMinimaPintar en este caso N = 4 --> I = 6
	if(N>I){
		return primeraFila;
	}
	
	/*Llenamos la matriz de prodPintados con los elementos de la primera fila*/
	/*Va a pintar las casillas de 0 -> 6, porque es la cantMinima que me piden primero*/
	marcaMayor(MatrizProductos,0,I,MatrizProductos_Pintados,primeraFila,P);
	cout<<primeraFila+1<<" "; //para el nmr de las filas
	/*Imprimimos los elementos de cada fila*/
	imprimirRecursivamente(MatrizProductos_Pintados,I,primeraFila,0);
	cout<<endl;
	
	//IMPRIME LAS FILAS HASTA ANTES DE LLEGAR A M=8 productos pintados -> itera el I
	if(I<M && desgaste==0){
		bandera=1;
		primeraFila = RobotPinta(MatrizProductos,MatrizProductos_Pintados,primeraFila+1,ultimaFila,I+1,N,M,P,desgaste);
	}
	//CASO QUE SE LLEGÓ A SER LA MISMA CANTIDAD DE PRODUCTOS PINTADOS QUE LA QUE PIDEN
	if(I==M && desgaste==0){
		bandera=1;
		desgaste=1; //SE ACABÓ LA PINTURA, aca tengo que empezar a bajar la cant de productos a pintar
		//pero primero imprimo esa fila sin modificaciones
		primeraFila = RobotPinta(MatrizProductos,MatrizProductos_Pintados,primeraFila+1,ultimaFila,I,N,M,P,desgaste);	
	}
	//CASO QUE SE LLEGÓ A ACABAR LA PINTURITA, EMPIEZO A BAJAR LA CANT DE PROD PINTAR
	if(bandera==0){
		//La ultima casilla que pinté fue en la posicion I
		primeraFila = RobotPinta(MatrizProductos,MatrizProductos_Pintados,primeraFila+1,ultimaFila,I-1,N,M,P,desgaste);
	}
	return primeraFila; //devuelve la cantidad de dias que duró el rodillo
}

int main(){
	
	//M = Max prod pintar || I = cant Pintar Inicio || N = Hasta que cant Pintar ||  D = Dias Totales || P = CantDeProductos
	int M,I,N,D,P;
	int desgaste=0;
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
	
	//Creo una matriz con los productos que voy a ir pintando e inicializo en cero
	int MatrizProductos_Pintados[MAXFIL][MAXCOL] = {0};
	// (matrizP,matrizV,primeraFila,ultimaFila,
	int cantDias = RobotPinta(MatrizProductos,MatrizProductos_Pintados,0,D,I,N,M,P-1,desgaste);
	cout<<"El rodillo durará "<<cantDias<<" dias.";
}
