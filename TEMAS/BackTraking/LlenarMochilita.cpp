
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 19 de junio de 2023, 04:30 PM
 */


#include <iostream>
#include <iomanip>

using namespace std;
/*BACK TRACKING*/

int lista[10];
/*Ayuda a guardar el tamaño que va a tener el arreglo => cant Soluciones*/
int y=0,x=0;

int empaca(int i,int n,int peso,int paq[]){
    /*Condicion de parada: si el peso sobrepasa el deseado 
     * o si ya recorrimos todas las solus*/
    if(n==i || peso<0){
       return 0; 
    }
    
    if(peso==paq[i]){
        //cout<<paq[i]<<endl;
        /*La ultima solucion: */
        lista[y]=paq[i];
        /*IMPRIME RESPUESTA COMPLETA: */
        for(int j=0;j<=y;j++){
            cout<<lista[j]<<" ";
        }
        cout<<endl;
        /*le quito el return 1, para que siga buscando soluciones*/
        //return 1;
        x=1;
    }
    
    /*Para ir guardando la cantidad de soluciones*/
    lista[y]=paq[i];
    y++;
    
    if(empaca(i+1,n,peso-paq[i],paq)){
        //cout<<paq[i]<<endl;
        return 1;
    }else{
        /*Si falla retrocedemos la cantidad de soluciones*/
        y--;
        /*Se hace back*/
        //cout<<"Back: "<<paq[i]<<endl;
        return empaca(i+1,n,peso,paq);
    }
    
}

int main(int argc, char** argv) {
    
    int paquete[]={2,4,6,8,3};
    int n=5;
    int peso=11; /*queremos que sume 11 de peso*/
    
    /*Desde que posicion empezará a evaluar*/
    empaca(0,n,peso,paquete);
    if(x){
        cout<<"Hay solución."<<endl;
    }else{
        cout<<"No hay solución."<<endl;
    }
    
    return 0;
}

