#include <iostream>
using namespace std;


void rombo(int a, int b,int &espacios){
	//Empieza en a = 1 y b = 5
	//CASO BASE: para cuando el a sea mayor a b
	if(a>b) return;
	for(int x=0;x<espacios;x++) cout<<" ";// 5 -> 4 -> 3 -> 2 -> 1
	espacios--;
	for(int i=0;i<a;i++) cout<<"* "; // 1 -> 2 -> 3 -> 4 -> 5
	cout<<endl;
	//PARA QUE ME IMPRIMA LA SIGUIENTE LINEA
	rombo(a+1,b,espacios);
	
	//ACA EMPIEZA LA RECURSIVIDAD, empezará a volver donde empezó -> (3,5)
	//Terminó en (5,5)
	//rombo (5,5) -> ****** || rombo (4,4) -> **** || rombo (3,4) -> *** || rombo (2,4) -> ** || rombo (1,4) -> *
	//espacios = 1 -> 2 -> 3 -> 4 -> 5
	 
	for(int i=0;i<a;i++){
		cout<<" *";
	}
	cout<<endl;
	
}

int main(){
	int a=1,b=5;
	//a = cantidad minima de puntos
	//b = cantidad maxima de puntos
	rombo(a,b,0);
}
