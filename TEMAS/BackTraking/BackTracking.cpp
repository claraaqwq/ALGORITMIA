
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 6 de junio de 2023, 11:00 AM
 */


#include <iostream>
#include <iomanip>

using namespace std;

/*BACKTRACKING es si falla retroceder y cambiar el valor */

/*VARIABLES GLOBALES*/
int lista[10],flag=0;
int y;

int empaca(int i, int n, int peso, int paq[]){
    /*caso el peso no le de o si se sale del arreglo y no encontró el peso*/
    if(i==n || peso<0) return 0;
    /*caso positivo => tengo que peso que queria*/
    if(paq[i]==peso){
        lista[y] = paq[i]; //agrego el paquete que si valida el que estamos buscando
        for(int j=0;j<=y;j++){
            cout<<lista[j]<<" ";
        }
        cout<<endl;
        flag++;
        //return 1;
    }
    lista[y] = paq[i]; //guardamos el paquete
    y++;
    /*Condicion de avance*/
    if(empaca(i+1,n,peso-paq[i],paq)) return 1;
    else{
        y--; //lista[y] = 0; elimino el paquete
        /*sigo avanzando sin considerar el peso del paquete*/
        return (empaca(i+1,n,peso,paq));
    }
}

/*
  - Los casos de impresión con return 0 imprimen todas las respuestas posibles.
  - Los casos de impresión con return 1 imprimen solo la primera respuesta.
*/

int main(int argc, char** argv) {

    int n=5;
    int paq[]={8,5,3,4,3};
    int peso = 8;
    
    cout<<"COMBINACIONES QUE CUMPLEN EL PESO "<<peso<<" :"<<endl;
    empaca(0,n,peso,paq);
    if(flag){
        cout<<"Que bueno lo encontro, son "<<flag<<endl;
    }else{
        cout<<"Que pena no entra"<<endl;
    }
    
    
    return 0;
}

