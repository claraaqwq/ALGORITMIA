#include <iostream>

using namespace std;

void imprime(int a, int b){
	if(a==b) return;
	if(a<b) cout<<" * ";
	imprime(a,b);
}

void triangulo (int a, int b){
	
	//NOTA: a<=b <-SIEMPRE
	//triangulo (6,6)
	if(a>b) return; // se devuelve el control al nivel anterior de la recursion -> (4,5)
	//Me imprimirá -> * * *
	imprime(0,a);
	cout<<endl;
	
	//FUNCION RECURSIVA
	//triangulo (3,5)
	//triangulo (4,5)
	//SE LLEGÓ AL FINAL DEL TRIANGULO, se devuelve el control al nivel anterior de la recursion -> (4,5)
	//triangulo (5,5)
	triangulo(a+1,b);
	
	//ACA EMPIEZA LA RECURSIVA, se tiene que volver a la instancia que se empezó triangulo (3,5)
	//Para ello comienza a decaer
	//triangulo(5,5) -> triangulo(4,5) -> triangulo(3,5)
	//a = 5 -> a = 4 -> a = 3
	for(int i=0;i<a;i++){
		cout<<" * ";
	}
	cout<<endl;
	//Acaba cuando se retorna a triangulo (3,5)
}

int main(){
	int a,b;
	cout<<"Mejor cantidad de puntitos: ";
	cin>>a;
	cout<<"Mayor cantidad de puntitos: ";
	cin>>b;
	
	a = 3, b = 5;
	triangulo(3,5);
	
}
