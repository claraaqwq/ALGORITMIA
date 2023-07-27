#include <iostream>

using namespace std;

int minIndex(int arr[],int inicio,int final){
	int min_val = arr[inicio];
    int min_index = inicio;
    for (int i = inicio + 1; i <= final; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

void OrdenaMenorMayor(int arr[],int inicio, int final){
	if(inicio>=final){
		return ;
	}
	int min_index;
	int temporal;
	//Asumir que minIndex retorna el indice del minimo valor en el arreglo
	min_index = minIndex(arr,inicio,final);
	
	temporal = arr[inicio];
	arr[inicio] = arr[min_index];
	arr[min_index] = temporal;
	
	OrdenaMenorMayor(arr,inicio+1,final);
}

int main(){
	int n=7,i;
	int arr[]={13,3,5,1,65,12,6};
	
	int a = minIndex(arr,0,n-1);
	cout<<"El indice menor es: "<<a<<endl;
	cout<<"Impresion Arreglo Desordenado: "<<endl;
	for (i=0; i<n;i++)
		cout<< arr[i] <<" ";
	cout<<endl;
	OrdenaMenorMayor(arr,0,n-1);
	cout<<"Impresion Arreglo Ordenado: "<<endl;
	for (i=0; i<n;i++)
		cout<< arr[i] <<" ";
	
	
}
