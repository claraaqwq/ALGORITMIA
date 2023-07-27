
#include <iostream>

using namespace std;

int calcula(int mon[],int n){
	int F[n+1];	
	
	F[0] = 0;
	F[1] = mon[0];
	for(int i=2;i<=n;i++){
		int act=mon[i-1]+F[i-2];
		int ady=F[i-1];
		
		if(act>ady)F[i]=act;
		else F[i]=ady;
	}
	for(int i=0;i<=n;i++)
		cout << F[i] <<" ";
	cout <<endl;
	return F[n];	
}


int main(){
	int moneda[]={5,1,2,10,6,2};
	int n=6;

	cout <<"El resultado es: "<< calcula(moneda,n);
		
	return 0;
}
