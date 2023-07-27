
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 19 de junio de 2023, 03:36 PM
 */


#include <iostream>
#include <iomanip>
#define N 4
using namespace std;

void imprimirSolucion(int tablero[N][N]){
    cout<<"Solucion: "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int esvalido(int tablero[N][N],int fila, int columna){
    /*Ejmplo: me encuentro posicionada en la fila 2, col 2.*/
    /*Entonces para saber si es correcto posicionar ahi una reina tengo
     *validar que no choque con la izquierda, ni diagonal inferior izquierda o
     * diagonal superior derecha. Mejor visto en el OneNote(BackTracking)
    */
    /*Busco una reina en la misma fila a la izquierda*/
    for(int i=0; i<columna;i++){
        if(tablero[fila][i]==1){
            return 0;
        }
    }
    /*Validamos diagonal izquierda superior*/
    for(int i=fila-1,j=columna-1;i>=0 && j>=0;j--,i--){
        if(tablero[i][j]==1){
            return 0;
        }
    }
    /*Validamos diagonal izquierda inferior*/
    for(int i=fila+1,j=columna-1;i<N && j>=0;j--,i++){
        if(tablero[i][j]==1){
            return 0;
        }
    }
    return 1;
}

int resuelve(int tablero[N][N], int columna){
    
    /*caso se pase del tablero*/
    if(columna>=N){
        return 1;
    }
    
    /*Ahora revisa cada fila*/
    for(int i=0; i<N; i++){
        /*verifico si puedo colocar una reina en esa posicion*/
        if(esvalido(tablero,i,columna)){
            /*caso si se pueda, la pinto para no volverla a tocar despues*/
            tablero[i][columna] = 1; 
            /*reviso el resto de posiciones*/
            /*estaré validando la pos de la reina por columna en una fila*/
            /*va a barrer a la derecha*/
            if(resuelve(tablero,columna+1)){
                /*caso encuentre una solución coloca 1, sino pasa el return 0*/
                return 1;
            }
            /*caso no pueda encontrar una solución*/
            /*en la pos donde estaba le coloco cero, para que retroceda*/
            /*y pasa al return 0*/
            tablero[i][columna] = 0; /*BACK*/
        }
    }
    return 0;
}

int main(int argc, char** argv) {

    /*Creo Matriz vacia que después llenaré con las reinas*/
    int tablero[N][N] = { {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0}
                        };
    
    if(!resuelve(tablero,0)){
        cout<<"No existe solucion."<<endl;
    }
    
    imprimirSolucion(tablero);
    
    return 0;
}

