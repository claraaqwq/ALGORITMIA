/* 
 * File:   main.cpp
 * Author: danie
 *
 * Created on 14 de junio de 2023, 12:48 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>


using namespace std;

#define MAX 20

bool validar(int x, int y, int matriz[][MAX], int n){
    
    for(int i=0; i<n; i++){
        if(matriz[i][x]==1){
            return false;
        }
    }
    /*Validamos diagonal izquierda inferior*/
    for (int i=y-1,j=x-1; i>=0 && j>=0; j--, i--){
            if (matriz[i][j]==1)
                    return false;
    }
    for (int i=y-1,j=x+1; i>=0 && j<n; j++, i--){
            if (matriz[i][j]==1)
                    return false;
    }
    return true;
}


void mostrarSolucion(int matriz[][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int calcularReinas(int matriz[][MAX], int y, int n, int &cantSol ){
    if(y==n){
        mostrarSolucion(matriz, n);
        cantSol++;
        return 0;
    }
    
    for(int x=0; x<n; x++){
        if(validar(x,y, matriz, n )){
            matriz[y][x]=1;
            if(calcularReinas(matriz, y+1, n, cantSol)){
                return 1;
            }
            matriz[y][x]=0;
        }
    }
    return 0;
}


int main(int argc, char** argv) {

    int matriz[MAX][MAX];
    
    int n=8;
    /*inicio con tablero sin nada: lleno de ceros => vacio*/
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz[i][j]=0;
        }
    }
    int cantSol=0;
    calcularReinas(matriz, 0, n, cantSol);
    if(cantSol == 0){
        cout<<"No existe solución."<<endl;
    }else{
        cout<<"El numero de soluciones son: "<< cantSol<<endl;
    }
    return 0;
}

