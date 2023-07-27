#include <iostream>
#include <cmath>

using namespace std;

//FUNCION IMPRIME CON RECURSION//
void imprime(int a, int b){
	if(a==b)return;
	if(a<b) cout<<" * ";
	imprime(a+1,b);
}

void triangulo(int a, int b){
	int i;
	if(a>b) return;
	//a -> 3 y b->5//
	//for(i=0;i<a;i++) cout<<" * ";
	imprime(0,a);
	cout<<endl;
	
	//       ( 4 ,5)
	//       ( 5 ,5)
	triangulo(a+1,b);
	
	for(i=0;i<a;i++){
		cout<<" * ";
	}
	cout<<endl;
	
}

int main(){
	
	triangulo(3,5);
	
	return 0;
}
