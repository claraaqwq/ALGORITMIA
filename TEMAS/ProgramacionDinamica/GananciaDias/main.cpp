
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 20 de junio de 2023, 12:38 PM
 */


#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;

//EJERCICIO PROGRAMACION DINAMICA

//k = numero de compras de dolares -> 2
int maxganancia(int k, int n, int precios[]){
    
    int gana[k+1][n];
    
    for(int i=0;i<n;i++) gana[0][i]=0;
    for(int i=0;i<=k;i++) gana[i][0]=0;
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            //le doy el menor valor para un entero a la variable maximo
            int maximo = INT_MIN;
            for(int m=0;m<j;m++){
                //compara con la ganancia de la compra anterior
                maximo=max(maximo,precios[j]-precios[m]+gana[i-1][m]);
            }
            //selecciona entre el maximo local y el maximo de todo el recorrido
            //compara con la ganancia del dia anterior, si es mayor se queda con ese
            gana[i][j] = max(maximo,gana[i][j-1]);
        }
    }
    
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            cout<<setw(5)<<gana[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //gana[2][5]
    return gana[k][n-1];
}

int main(int argc, char** argv) {

    int k=2;
    
    int precios[] = {315,322,385,375,365,380};
    int n=6;
    
    cout<<"La maxima ganacia fue: "<<maxganancia(k,n,precios);
    
    return 0;
}

