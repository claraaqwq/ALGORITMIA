#include <iostream>
#define MAX 10

using namespace std;

int fila_in = 0, prod_ubicados = 0;

void imprimir_anaqule (int Anaquel[][MAX], int f, int c){
	cout<<"Impresion del anaquel:" <<endl;
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			cout<<Anaquel[i][j]<<" ";
		}
		cout<<endl;
	}
}

//Porque es cambiante la cantProdXfila, va por referencia        1              2
void LlenarAnaquel(int Anaquel[MAX][MAX],int f,int c,int p,int &cantProdXFila,int &centro){
	//CASO BASE: si completé la cantidad de prod a pintar
	if(p==prod_ubicados) return;
	
	int col=centro;
	int cant;
	for(cant=0;cant<cantProdXFila;cant++,col++){
		if(Anaquel[fila_in][col]!=1 && prod_ubicados<p){
			Anaquel[fila_in][col] = 5;
			prod_ubicados ++;
		}
		
	}
	
	fila_in++;
	//Llamo recursivamente para pasar a la otra fila
	
	if(cantProdXFila<5){
		cantProdXFila =  cantProdXFila+2;
		centro--; //va retrocediendo hasta llegar a la primera columna
	}
	
	LlenarAnaquel(Anaquel,f,c,p,cantProdXFila,centro);
	
}

int main(){
	
	int f=5,c=5,p=16;
	
	/*cout<<"Ingrese la cantidad de filas: ";
	cin>>f;
	cout<<"Ingrese la cantidad de columnas: ";
	cin>>c;
	cout<<"Ingrese la cantidad de productos: ";
	cin>>p;
	
	int Anaquel[MAX][MAX];
	//Guardo la matriz
	for(int fil=0;fil<f;fil++){
		for(int col=0;col<c;col++){
			cin>>Anaquel[fil][col];
		}
	}*/
	
	int Anaquel[MAX][MAX] = {{0,0,0,0,0},
						     {0,0,0,0,0},
						     {0,0,0,1,0},
						     {0,1,0,0,0},
						     {0,0,0,0,0}};
	//Necesario saber con que posicion empezaré a pintar
	//Si C es impar *1 --> Si C es par *2
	int cantProdXFila = (c%2==1)*1 + (c%2==0)*2;
	int centro = (c-1)/2; // col:2
	LlenarAnaquel(Anaquel,f,c,p,cantProdXFila,centro);
	imprimir_anaqule(Anaquel,f,c);
	
	return 0;
}
