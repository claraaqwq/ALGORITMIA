
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 13 de junio de 2023, 11:55 AM
 */



#include <iostream>

#define MAX 6

int vacSOl[MAX]={0};
int y=0;


using namespace std;

//vac : la vacuna
//matriz de ciudades
//ini: es el indice de la ciudad donde estamos
//num de ciudades
//info del congelador
int valida(int vac, int ciudades[][MAX], int ind, int n, int arrCongelador[]){
    
    if(vac==1 && arrCongelador[ind]!=1){//?? la vacuna es el unico que necesita congelador
        return 0;
    }
    
    for(int i=0; i<MAX; i++){
        if(ciudades[ind][i]==1)
    }
}


//i: posicion-<ciudad inicial
int buscaVacuna(int ini, int ciudades[][MAX], int n, int nVac, int arrCostos, 
        int arrCongelador){
    
    if(ini==n){//condicion de parada
        //aqui termina
        return 0; //si se quiere todas la solucion ->0
                    //           solo una sol. -< 1
    }
    
    for(int i=0; i<nVac; i++){
        //primero: validar, si esa vacuna se puede colocar ahÃ­, en esa ciudad
        if(valida(i, ciudades, ini, n, arrCongelador)){
            vacSOl[ini]=i;
        }
        
        
        
    }
    
    
}

int main() {//CUANDO VEAS CIUDADS, Y CONEXIONES  -<HACER MATRICES
    int n=MAX; //la cantidad de ciudades
    int nVac=4; //la cantidad de vacunas
    //SIMILAR A problemas de puentes
    int ciudades[MAX][MAX]={
        {0, 1, 1, 0, 0, 1}, //0
        {1, 0, 1, 1, 0, 0}, //1
        {1, 1, 0, 1, 0, 1}, //2
        {0, 1, 1, 0, 1, 1},  //3
        {0, 0, 0, 1, 0, 1}, //4
        {1, 0, 1, 1, 1, 0} //5
    };
    
    int arrCongelador[MAX]={0, 0, 1, 0, 1, 0};
    int arrCostos[]={10, 5, 12, 8};
    
    /*
     Implemente una funciÃ³n que, utilizando backtracking, muestre todas las posibles soluciones de
     distribuciÃ³n de las vacunas por cada ciudad
     */
    
    //colocamos 1,1,1,1,1,1-<pero no se puede dar, ya que no se permite las mismas vacunas en ciudades colindantes
    
    
    
    return 0;
}
