#include <iostream>
#define N 7

using namespace std;

int calcularPesoMaximo(int pavos[N],int n,int k){
	int solucion[n+1];
	solucion[0] = 0; /*Porque no hay combos de 2 formados al inicio*/
	solucion[1] = 0; /*Porque con el primer pavo no se puede formar un combo*/
	for (int i=2; i<=n; i++){
		if ((pavos[i-1] - pavos[i-2])<k){
			solucion[i] = pavos[i-1] + pavos[i-2] + solucion[i-2];	
		}
		else {
			solucion[i] = solucion[i-1];	
		}
	}
	
	int pesoMaximo = solucion[n];
	while (pesoMaximo>0){
		for (int i=0; i<=n; i++){
			if (solucion[i]==pesoMaximo){
				cout << "{" << pavos[i-2] << "," << pavos[i-1] << "}";
				pesoMaximo = pesoMaximo - pavos[i-2] - pavos[i-1];
				break; 
			}
		}
		if (pesoMaximo>0){
			cout << ",";
		}
		else {
			cout << endl;
		}
	}
	return solucion[n];
}

int main(){
	/*Tu mismo eres ordenando :) */
	int pavos[N] = {3,4,6,12,15,18,25};
	int k=5;
	int n=7;
	cout << "El peso maximo es: " << calcularPesoMaximo(pavos,n,k);
	return 0;
}
