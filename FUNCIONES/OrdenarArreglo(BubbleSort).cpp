#include <iostream>
#include <iomanip>

using namespace std;

void ordenarArreglo(int num[],int cantCifras){
    int i,j,aux;
    for(i=0;i<=cantCifras-2;i++){
        for(j=0;j<=cantCifras-2-i;j++){
            if(num[j+1]<num[j]){
                //hago switch
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
            }
        }
    }
}

