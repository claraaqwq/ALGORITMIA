#include <iostream>
#define MAX 6
using namespace std;

int almacen[][MAX] = {
	{1,2,9,1,2,3},
	{5,1,7,0,2,1},
	{0,7,0,3,8,1},
	{1,2,6,1,2,2},
	{0,6,9,5,0,5},
	{0,0,4,0,9,0}
};

int recorreh(int i,int n,int x){
	//el i es donde inicia, en este caso inicia en cero//
	if(i==n) return 0;//salta y corta, se va al vacio//
	return recorreh(i+1,n,x)+almacen[x][i]; //va sumando los pesos de la matriz//
}

int recorrev(int i, int n, int y){
	if(i==n) return 0;
	return recorrev(i+1,n,y)+almacen[i][y];
}

int pesomax(int x,int y,int n,int m){
	int sumav,sumah,sumat,parcial;
	if(m-1==0) return 0; //condicion de parada
	
	sumah = recorreh(0,m,x);
	//de donde empieza - fila - columna//
	sumav = recorrev(x+1,n,m-1);
	sumat = sumav + sumah;
	//baja al recorrido más pequeño y las columnas se reducen uno//
	parcial=pesomax(x+1,y,n,m-1);
	if(sumat>parcial){
		return sumat;
	}else{
		return parcial;
	}
}

int revisa(int p,int pedido[], int valor,int i){
	//condicion de parada//
	if(i==p) return 0; //cuando ya alcanzó la cant de pedidos 
	if(pedido[i]==valor){
		pedido[i]=0;
		return 1;
	}
	revisa(p,pedido,valor,i+1);
}

int busca(int x,int y,int n,int m,int p, int pedido[]){
	int aux[p],cont=0;
	if(m-1==0) return 0; //condicion de parada
	//p es la cantidad de pedidos
	for(int i=0;i<p;i++){
		aux[i]=pedido[i]; //copia del pedido, lo uso para poder borrar valores que ya se hallaron
	}
	
	//Para Horizontal
	for(int i=0;i<m;i++){
		if(almacen[x][i]!=0){//caso no exista
		//                (-,-,-,posicion desde q revisa)
			cont = cont + revisa(p,aux,almacen[x][i],0);
		}
	}
	//Para Vertical
	for(int i=x+1;i<n;i++){//caso no exista
		if(almacen[i][m-1]){
		//                (-,-,-,posicion desde q revisa)
			cont = cont + revisa(p,aux,almacen[i][m-1],0);
		}
	}
	
	if(cont==p || busca(x+2,y,m-1,n,p,pedido)) return 1;
	return 0;
}

int main(){
	int n=6; //numero de filas y columnas nxn//
	int p=3;
	int pedido[]={2,7,2};
	cout<<"El peso maximo es: "<<pesomax(0,0,n,n)<<endl;
	cout<<"Se puede atender: "<<busca(0,0,n,n,p,pedido);
	
	return 0;
}
