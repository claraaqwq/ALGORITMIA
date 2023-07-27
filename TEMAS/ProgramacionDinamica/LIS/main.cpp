
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 13 de junio de 2023, 12:14 PM
 */

/*PROGRAMACION DINÁMICA*/

#include <iostream>
#include <iomanip>

using namespace std;

int calculaLis(int lis[], int n){
    int maxlis = 1;
    int Flis[n];
    
    for(int i = 0; i < n ; i++){
        Flis[i]=1;//si solo hay un elemento en LIS, es necesario tener para el Ãºnico elemento
        for(int j = 0; j < i ; j++){
            if(lis[i]>lis[j]){
                /*Es igual al que acabo de revisar más el mismo*/
                Flis[i]=Flis[j]+1;
            }
        }
        if(Flis[i]>maxlis) maxlis=Flis[i];
    }  
    return maxlis; //no se retorna F[n] xq puede ser menor   
}

int main(int argc, char** argv) {

    int LIS[]={-7, 10, 9, 2, 3, 8, 8, 1};
    //int LIS[]={2, 3, -1, 5, 4, -3, -2};
    int n=8;
    
    cout<< "El resultado es: "<<calculaLis(LIS, n)<<endl; 
    
    return 0;
}

