#include <iostream>
#include <cmath>
#define MAXCOL 2
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i,resto;
	for(i=0;i<n;i++) cromo[i]=0; //inicializo en cero//
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}
}


int main(){
	
	int m,w,fil,col,parcial,i,ganancia,mganancia=0,mcomb;
	
	cout<<"Ingresar la cantidad de productos: "<<endl;
	cin>>m;
	cout<<"Ingresar el peso máximo: "<<endl;
	cin>>w;
	
	int ArrProd[m][MAXCOL];
	
	for(fil=0;fil<m;fil++){
		cout<<"Ingrese el peso y la ganancia del Art "<<fil+1<<":"<<endl;
		for(col=0;col<MAXCOL;col++){
			cin>>ArrProd[fil][col];
		}
	}
	
	int ArrMatriz[m][MAXCOL];
	int cromo[m]; //cantidad de articulos en el cromo//
	int opciones = (int) pow(2,m);
	
	for(i=0;i<opciones;i++){
		parcial=0;
		cargabin(i,m,cromo);
		ganancia=0;
		
		for(fil=0;fil<m;fil++){
			//me piden que la cantidad de peso maximo sea el w//
			//cout<<ArrMatriz[fil][col];
			parcial = parcial + ArrProd[fil][0]*cromo[fil];
			ganancia = ganancia + ArrProd[fil][1]*cromo[fil];
			
		}
		
		if(parcial<=w && mganancia<ganancia){
			mganancia = ganancia;
			mcomb=i;
		}
		
	}
	
	cout<<endl<<"Articulos: "<<endl;
	cargabin(mcomb,m,cromo);
	
	for(i=0;i<m;i++){
		
		if(cromo[i]==1){
			cout<<i+1<<" ";
		}
	}
	
	cout<<"                      Ganancia Total: "<<mganancia<<endl;
	
	
	return 0;
}
