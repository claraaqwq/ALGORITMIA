#include <iostream>
#include <iomanip>

#define MAXCOL 5
#define MAXFIL 5

using namespace std;

int m[8][2]; //defino matriz

//para los ejes y posiciones a las que se puede mover 
void cargamovimientos(){
	m[0][0]=-1;m[0][1]= 0;
	m[1][0]=-1;m[1][1]= 1;
	m[2][0]= 0;m[2][1]= 1;
	m[3][0]= 1;m[3][1]= 1;
	m[4][0]= 1;m[4][1]= 0;
	m[5][0]= 1;m[5][1]=-1;
	m[6][0]= 0;m[6][1]=-1;
	m[7][0]=-1;m[7][1]=-1;
	
}

int buscar(char letras[][MAXCOL],char patron[],char resultado[][MAXCOL],int n,int fila,int col){
	if(patron[0]!=letras[fila][col]) return 0; //no lo encontró//
	int i,j,nfila,ncol,k,l,s,flag=0;
	//hasta el nmr de movimientos que tenemos//
	for(i=0;i<8;i++){
		//para el tablero//
		nfila = fila + m[i][0];
		ncol = col + m[i][1];
		
		if(nfila<0 || nfila>=MAXFIL || ncol<0 || ncol>=MAXCOL)
			continue;
		else{
			for(j=1;j<n;j++){
				if(patron[j]!=letras[nfila][ncol])
					break;
				nfila = nfila + m[i][0];
				ncol  = ncol  + m[i][1];
			}
			//para comprobar si llegó a la ultima letra//
			if(j==n){
				for(k=0,l=0,s=0;s<n;k+=m[i][0],l+=m[i][1],s++){
					resultado[fila+k][col+l] = patron[s];
				}
				flag = 1;
			}
		}
	}
	if(flag==1) return 1;
	return 0;
}

void pupiletras(char letras[][MAXCOL],char patron[],char resultado[][MAXCOL],int n){
	//se utiliza 2 for's, uno para las filas y otro para las columnas//
	for(int i=0;i<MAXFIL;i++){
		for(int j=0;j<MAXCOL;j++){
			if(buscar(letras,patron,resultado,n,i,j)){
				cout<<"La palabra esta en: "<<i<<" "<<j<<endl;
			}
		}
	}
}

void imprime (char resultado[][MAXCOL]){
	for(int i=0;i<MAXFIL;i++){
		for(int j=0;j<MAXCOL;j++){
			cout<<resultado[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n=4; //n->tamaño del patron//
	char letras[][MAXCOL]={
	{'B','A','L','I','C'},
	{'N','B','I','C','A'},
	{'T','I','I','A','L'},
	{'P','C','P','C','M'},
	{'R','O','B','O','A'}
	};
	
	char resultado[][MAXCOL]={
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
	
//					0   1   2   3
	char patron[]={'B','I','C','A'};
	cargamovimientos();
	pupiletras(letras,patron,resultado,n); 
	imprime(resultado);
	
	return 0;
}
