#include <iostream>
#include <iomanip>
#define N 4
#define C 6
using namespace std;

//variables globales
int soluciones[C] = {0,0,0,0,0,0};
int cantSoluciones = 0;
int costoTotal = 0;
int posSolucion = 0;

int esPosibleColocarVacuna(int vacuna,int posCiudad,int refrigeracion[C],int colindantes[C][C],
                           int ciudad){
    //caso sea vacuna fisher y no tenga refrigeracion especial, NO SE UTILIZA
    if(vacuna==1 && refrigeracion[posCiudad]==0){
        return 0;
    }
    //compruebo que las ciudades colindantes no sean la misma vacuna
    for(int i=0;i<ciudad;i++){
        //1 verifica si la ciudad de esa pos es colindante
        if(colindantes[posCiudad][i]==1 && soluciones[i]==vacuna){
            return 0;
        }
        //verifica de nuevo sus colindantes
        if(colindantes[i][posCiudad]==1 && soluciones[i]==vacuna){
            return 0;
        }
    }
    return 1;
}

int encontrarSoluciones(int vacunas,int costos[N],int refrigeracion[C],int colindantes[C][C],
                        int cantCiudades,int posicion){
    //caso se recorra hasta el final de la fila en la matriz, el programa se detiene
    if(posicion==cantCiudades){
        //imprime la solución que encuentra
        cout<<"Solucion: "<<++cantSoluciones<<endl;
        for(int i=0;i<cantCiudades;i++){
            cout<<"Ciudad: "<<i<<" || Vacuna: "<<soluciones[i]<<endl;
        }
        cout<<"Costo: "<<costoTotal<<endl;
        cout<<"--------------------------------"<<endl;
        //uso return 1, si solo quiero una solución
        return 0;//para que busque más soluciones
    }
    
    //si es que no coloqué vacuna en esa ciudad**
    for(int vacuna=1;vacuna<=vacunas;vacuna++){
    	
        if(esPosibleColocarVacuna(vacuna,posicion,refrigeracion,colindantes,cantCiudades)){
            soluciones[posSolucion] = vacuna;
            posSolucion++;
            
            costoTotal+= costos[vacuna-1];
            
            if(encontrarSoluciones(vacunas,costos,refrigeracion,colindantes,cantCiudades,posicion+1)){
                //si la encuentra la guardo
                return 1;
            }
            
            posSolucion--;
            soluciones[posSolucion] = 0;
            costoTotal-= costos[vacuna-1];
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    //              { 0,1, 2,3}
    int costos[N] = {10,5,12,8};
    int refrigeracion[C]={0,0,1,0,1,0};
    //para el caso de ciudades colindantes uso matriz para marcar espacios
    int colindantes[C][C] = {{0,1,1,0,0,1},
                             {1,0,1,1,0,0},
                             {1,1,0,1,0,1},
                             {0,1,1,0,1,1},
                             {0,0,0,1,0,1},
                             {1,0,1,1,1,0}};
    int cantCiudades = 6;
    int vacunas = 4;
    //la ultima es la posicion en la que inicia en la matriz
    encontrarSoluciones(vacunas,costos,refrigeracion,colindantes,cantCiudades,0);
    return 1;
}
