#include <iostream>
#include <cmath>
#define MAX_BAHIAS 3
#define MAX 15 
using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i,resto;
	for(i=0;i<n;i++) cromo[i]=0; //llena con ceros
	i=0;
	while(num>0){
		resto = num%2;
		num = num/2;
		cromo[i] = resto;
		i++;
	}
	
}

void imprimeSolucion(int almacen[][MAX],int n1,int n2,int n3, int n){
	
	int cromo[n];
	int i;
	
	cargabin(n1,n,cromo);
	cout<<"Bahia 1: "<<endl;
	for(i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<almacen[0][i];
		}
	}
	cout<<"Bahia 2: "<<endl;
	cargabin(n2,n,cromo);
	for(i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<almacen[1][i];
		}
	}
	cout<<"Bahia 3: "<<endl;
	cargabin(n3,n,cromo);
	for(i=0;i<n;i++){
		if(cromo[i]==1){
			cout<<almacen[2][i];
		}
	}
	
}

int main(){
	int i,j,k,l,n,m,capacidad,fil,col,cont;
	int parcial,mpeso=0,mcomb,flag=0;
	
	cout<<"Ingrese el numero de productos por bahia: "<<endl;
	cin>>n;
	cout<<"Ingrese el numero de divisiones del camión: "<<endl;
	cin>>m;
	cout<<"Ingrese la capacidad máxima del camión: "<<endl;
	cin>>capacidad;
	
	int almacen[MAX_BAHIAS][MAX];
	int opciones = (int) pow(2,n*3);
	int cromo1[n],cromo2[n],cromo3[n];
	
	cout<<"Ingrese el peso de los productos x bahia: "<<endl;
	for(fil=0;fil<MAX_BAHIAS;fil++){
		cout<<"Bahia "<<fil+1<<": "<<endl;
		for(col=0;col<n;col++){
			cin>>almacen[fil][col];
		}
	}
	
	cout<<"Se imprimirá la lista de soluciones: "<<endl;
	for(i=0;i<opciones;i++){
		cargabin(i,n,cromo1);
		for(j=0;j<opciones;j++){
			cargabin(j,n,cromo2);
			for(k=0;k<opciones;k++){
				parcial = 0;
				cont=0;
				cargabin(k,n,cromo3);
				
				for(l=0;l<n;l++){
					if(cromo1[l]){
						cont++;
						parcial = parcial + almacen[0][l];
					}
					if(cromo2[l]){
						cont++;
						parcial = parcial + almacen[1][l];
					}
					if(cromo3[l]){
						cont++;
						parcial = parcial + almacen[2][l];
					}
				}
				if(cont == m && parcial == capacidad){
					mcomb = i;
					cout<<"Si hay solución"<<endl;
					imprimeSolucion(almacen,i,j,k,n);
					flag=1;
				}
			}
		}
	}
	
	if(flag = 0) cout<<"No se encontró solución"<<endl;
	
	return 0;
}
