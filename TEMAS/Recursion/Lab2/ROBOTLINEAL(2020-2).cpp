#include <iostream>

using namespace std;

//Creo una matriz global con los datos
int mapa[][6] = {
	{0,0,0,1,0,1},
	{0,0,1,0,0,0},
	{0,1,0,0,0,1},
	{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,0,0,1,0}
};

//X = posicion x || Y = posicion y || xm = movimiento x || ym = movimiento y || x1 = empieza en 0 || y1 = empieza en 0
int buscar (int x, int y, int xm, int ym, int x1, int y1, int fil, int col){
	//Creo un contador de 1's
	int contador = 0;
	
	//Condicion de parada: no nos podemos salir de los lados, ni abajo ni arriba
	if(x>=fil || x<0 || y>=col || y<0){
		return 0;
	}
	//Caso que la casilla en la que me encuentre sea un uno y todavia no me haya movido
	if(mapa[x][y]==1 && x1==0 && y1==0) contador++;
	
	//COMO PRIMER LLAMADO DE LA FUNCION, EN EL EJE X SUMARÉ CANTIDADES DE ARRIBA Y ABAJO
	if(x1==0){
		//Cuenta arriba
		for(int i=0;i<x;i++) contador+= mapa[i][y];
		//Cuenta abajo
		for(int i=x+1;i<fil;i++) contador+= mapa[i][y];
	}
	
	//COMO PRIMER LLAMADO DE LA FUNCION, EN EL EJE Y SUMARÉ CANTIDADES DE IZQUIERDA Y DERECHA
	if(y1==0){
		//Cuenta izquierda
		for(int i=0;i<y;i++) contador+= mapa[x][i];
		//Cuenta derecha
		for(int i=y+1;i<col;i++) contador+= mapa[x][i];
	}
	
	//TERMINÉ DE SUMAR LAS CANTIDADES EN CRUZ
	//Ahora quiero que se mueva en la direccion que se pidió y siga sumando
	//ENTENDIMIENTO: como en este caso me estaba moviendo a la derecha, siempre el xm=0 y el ym=1
	//por esa razon cuando aplique recursion ya no sumaré en horizontal, solo los verticales
	contador = contador + buscar(x+xm,y+ym,xm,ym,xm,ym,fil,col);
	
	return contador;
}

int main(){
	
	int n=6,m=6;  //fila y columna
	//te dice que se empezará en la posicion (3,2)
	// (posX,posY,noseMueveX,seMueveY,inicio,inicio,fil,col) //
	
	//Derecha   = x: 0 | y: 1
	//Izquierda = x: 0 | y:-1
	//Arriba    = x:-1 | y: 0
	//Abajo     = x: 1 | y: 0
	
	//										 (x,y,seMueveX,seMueveY,PivotX,PivotY,n,m)
	cout <<"El resultado de busqueda es: "<<buscar(3,2,0,1,0,0,n,m)<<" unidades"<<endl;

	return 0;	
}
