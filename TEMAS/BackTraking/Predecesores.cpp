
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 19 de junio de 2023, 06:04 PM
 */


#include <iostream>
#include <iomanip>
//LABORATORIO 5: PREGUNTA 1 -> BACKTRACKING
using namespace std;

int lista[10];
/*Ayuda a guardar el tamaño que va a tener el arreglo => cant Soluciones*/
int y=0,x=0;

int valida(int k,int n, int pred[]){
    int contador=0;
    if(pred[k]==0){
        return 1;
    }
    for(int i=0;i<n;i++){
        /*significa que el predecesor ya se encuentra*/
        if(pred[k]==lista[i]){
            contador++;
        }
    }
    if(contador){
        /*caso esté en la lista*/
        return 1;
    }else{
        /*caso no este en la lista*/
        return 0;
    }
}

int Predecesor(int i,int n,int presupuesto,int costo[],int pred[],int proy[]){
    
    /*Condicion de parada: si el peso sobrepasa el deseado 
     * o si ya recorrimos todas las solus*/
    if(n==i || presupuesto<0){
       return 0; 
    }
    
    /*caso llegue a la cantidad que me piden*/
    if(valida(i,y,pred) && presupuesto==costo[i]){
        //cout<<paq[i]<<endl;
        /*La ultima solucion: */
        lista[y]=proy[i];
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
    lista[y]=proy[i];
    y++;
    
    /*Valida revisa si cumple todos sus presupuestos*/
    if(valida(i,y,pred) && Predecesor(i+1,n,presupuesto-costo[i],costo,pred,proy)){
        //cout<<paq[i]<<endl;
        return 1;
    }else{
        /*Si falla retrocedemos la cantidad de soluciones*/
        y--;
        /*Se hace back*/
        //cout<<"Back: "<<paq[i]<<endl;
        return  Predecesor(i+1,n,presupuesto,costo,pred,proy);
    }
    
}

int main(int argc, char** argv) {

    //Buscar los proyectos que esten dentro del costo
    //un solo predecesor
    int proyecto[] = {1,2,3,4,5};
    int costo[] = {7,1,3,2,5};
    int predecesor[] = {0,0,1,0,2};
    
    /*cantidad de predecesores*/
    int n=5;
    int presupuesto=10;
    Predecesor(0,n,presupuesto,costo,predecesor,proyecto);
    if(x){
        cout<<"Hay solución."<<endl;
    }else{
        cout<<"No hay solución."<<endl;
    }

    return 0;
}

