
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 13 de junio de 2023, 11:09 AM
 */


#include <iostream>
#include <iomanip>

using namespace std;


//si no guardo las soluciones anteriores no es Programación Dinámica
int calculaMonedas(int mon[],int n){
    int F[n+1];
    /*condicion de entrada*/
    F[0] = 0; //no hay monedas, el valor maximo es 0
    F[1] = mon[0]; //solo tomo una moneda, el valor maximo es el valor de la moneda 1
    
    for(int i=2;i<=n;i++){
        /*Por definicion la forma es:
         *tiene como opcion escoger la moneda, o la suma con su adyacente
         *compara quien es mayor y esa escoge
         *F(n) = maximo(Cn + F(n-2), F(n-1))
         *F(1) = C(1) -> solo toma una moneda, la primera moneda
         *F(0) = 0    -> no tomo ninguna moneda
        */
        int act=mon[i-1]+F[i-2]; /*valor maximo incluyendo la moneda actual y si tras-anterior*/
        int ady=F[i-1]; /*valor maximo sin incluir la moneda actual*/
        
        if(act>ady) F[i]=act;
        else F[i]=ady;//valor maximo en la moneda acutal
        
    }
    /*PARA LA IMPRESION DE TODOS LOS RESULTADOS:*/
    for(int i=0;i<=n;i++){
        cout<<F[i]<<" ";
    }
    cout<<endl;
    return F[n];
}

int main(int argc, char** argv) {

    int monedas[]={5,1,2,10,6,2};
    int n=6;
    
    cout<<"El resultado es: "<<calculaMonedas(monedas,n);
    
    return 0;
}

