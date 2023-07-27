//FUNCIONALIDAD DE UN CROMO//

#include <iostream>
#include <cmath>

using namespace std;

//FUNCION PARA CAMBIAR UN NUMERO A BINARIO//
void cambiarBin(int num, int n, int cromo[]){
	int i, resto;
	for(i=0;i<n;i++) cromo[i]=0; //para llenar el cromo de ceros como inicial//
	i=0;
	while(num>0){
		resto = num%2;
		num   = num/2;
		cromo[i] = resto;
		i++;
	}
	
	//PARA SU IMPRESION//
	cromo[i] = num;
	for(int j=i;j>=0;j--){
		cout<<cromo[j];
	}
}

int main(){
	int i;
	int cromo[i];
	int num;
	cout<<"Ingrese un numero para convertirlo en binario: "<<endl;
	cin>>num;
	
	cambiarBin(num,i,cromo);
	
	return 0;
}
