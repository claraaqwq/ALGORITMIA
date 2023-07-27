#include <iostream>
#include <cmath>
#define MAXCOL 2
using namespace std;

void cargabin (int num, int n, int cromo[]){
	int i, resto;
	for(i=0;i<n;i++) cromo[i] = 0; //empiezo el cromo en cero
	i=0;
	while(num>0){
		resto = num%2;
		num =  num/2;
		cromo[i] = resto;
		i++;
	}
}

int main(){
	
	int m,w,fil,col,parcial,ganancia,mejorGanancia=0,mcomb;
	cout<<"Ingrese la cantidad de productos: ";
	cin>>m;
	cout<<"Ingrese el peso que definido: ";
	cin>>w;
	
	int ArrArticulo[m][MAXCOL];
	
	cout<<"Ahora ingrese los pesos y ganancias de cada articulo"<<endl;
	for(fil=0; fil<m; fil++){
		cout<<"Para el articulo "<<fil+1<<")"<<endl;
		for(col=0; col<MAXCOL; col++){
			cin>>ArrArticulo[fil][col];
		}
	}
	
	int opciones = (int) pow(2,m);
	int cromo[m]; //si evaluo al cromo en m, significa que la lista de cromo será de m digitos y es vertical
	//ahora creamos los cromos y vemos sus posibilidades
	for(int i=0;i<opciones;i++){
		parcial = 0,ganancia=0;
		cargabin(i,m,cromo);
		//ya tengo el cromo ahora tengo que evaluar las ganancias y pesos
		//para ello recorro por filas
		//el cromo se guarda por filas
		for(fil=0;fil<m;fil++){
			parcial = parcial + cromo[fil]*ArrArticulo[fil][0];
			ganancia = ganancia + cromo[fil]*ArrArticulo[fil][1];
			//cout<<cromo[fil];
		}
		//cout<<endl;
		
		//evaluo las restricciones
		if(parcial<=w && mejorGanancia<ganancia){
			mejorGanancia = ganancia;
			mcomb = i;
		}
	}
	
	//imprimo
	
	cout<<endl<<"Articulos: "<<endl;
	cargabin(mcomb,m,cromo);
	
	for(fil=0;fil<m;fil++){
		if(cromo[fil]==1){
			cout<<fil+1<<" ";
		}
	}
	cout<<"                           "<<"Ganancia Total: "<<mejorGanancia;
		
	return 0;
}
