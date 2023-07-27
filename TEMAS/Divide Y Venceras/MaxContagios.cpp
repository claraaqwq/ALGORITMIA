#include <iostream>
#include <cmath>

using namespace std;

int max2(int a, int b, int c){
	return (max(max(a,b),c));
}

int merge(int ini, int med, int fin, int arr[]){
	
}

int maxcontagios (int ini, int fin, int arr[]){
	
	int izq,cen,der;
	
	int med= (ini+fin/2);
	izq = maxcontagios(ini,med,arr);
	der = maxcontagios(med+1,fin,arr);
	cen = maxcontagios();
	
}

int main(){
	
	int n=10;
	int arreglo[]= {7,2,9,10,16,10,13,8,2,10};
	
	cout<<maxcontagios(0,n-1,arreglo);
	
	return 0;
}
