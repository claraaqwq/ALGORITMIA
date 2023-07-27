/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 9 de mayo de 2023, 12:10 PM
 */

#include <cstdlib>

#include "cola.h"

using namespace std;

void ordenarec(Cola &cola,int n){
    int min,i,aux;
    
    if(esColaVacia(cola)) return;
    min = desencolar(cola);
    i=1;
    while(i<n){
        aux = desencolar(cola);
        if(aux<min){
            encolar(cola,min);
            min = aux;
        }
        else
            encolar(cola,aux);
        i++;
    }
    ordenarec(cola,n-1);
    encolar(cola,min);
}



int main(int argc, char** argv) {
    Cola Ccola;
    
    construir(Ccola);
    encolar(Ccola,10);
    encolar(Ccola,11);
    encolar(Ccola,5);
    encolar(Ccola,20);
    mostrar(Ccola);
    ordenarec(Ccola,Ccola.longitud);
    mostrar(Ccola);
    return 0;
}

