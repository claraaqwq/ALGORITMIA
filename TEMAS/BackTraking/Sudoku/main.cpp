/* 
 * File:   main.cpp
 * Author: danie
 *
 * Created on 14 de junio de 2023, 05:33 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#define MAX 20

void mostrarSolucion(int sudoku[][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool validar(int sudoku[][MAX], int x, int y, int num, int n){
    for(int i=0; i<n; i++){
        if(sudoku[y][i]==num){
            return false;
        }
    }
    for(int i=0; i<n; i++){
        if(sudoku[i][x]==num){
            return false;
        }
    }
    int inX, inY;
    if(y<3){
        inY=0;
        if(x<3)
            inX=0;
        else if( x<6)
            inX=3;
        else
            inX=6;
    }
    else if( y<6){
        inY=3;
        if(x<3)
            inX=0;
        else if( x<6)
            inX=3;
        else
            inX=6;
    }
    else{
        inY=6;
        if(x<3)
            inX=0;
        else if( x<6)
            inX=3;
        else
            inX=6;
    }
    for(int i=inY; i<inY+3; i++){
        for(int j=inX; j<inX+3; j++){
            if(sudoku[i][j]==num){
                return false;
            }
        }
    }
    return true;
    
}

int realizarSudoku(int sudoku[][MAX], int x, int y, int n){
    if(x==n && y==n-1){
        mostrarSolucion(sudoku, n);
        return 0;
    }
    if(x==n){
//        mostrarSolucion(sudoku, n);
//        cout<<endl;
        if(realizarSudoku(sudoku, 0, y+1, n)){
            return 1;
        }
        return 0;
    }
    
    if(sudoku[y][x]==0){
        for(int i=1; i<=9; i++){
            if(validar(sudoku, x, y, i, n)){
                sudoku[y][x]=i;
                if(realizarSudoku(sudoku, x+1,y, n)){
                    return 1;
                }
                sudoku[y][x]=0;
            }
        }
        return 0;
    }
    else{
        if(realizarSudoku(sudoku, x+1,y, n)){
            return 1;
        }
        return 0;
    }
}


int main(int argc, char** argv) {

    int sudoku [MAX][MAX];
    int n=9;
    ifstream archDatos("datos.txt", ios::in);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            archDatos>>sudoku[i][j];
        }
    }
    realizarSudoku(sudoku, 0,0, n);
    return 0;
}

