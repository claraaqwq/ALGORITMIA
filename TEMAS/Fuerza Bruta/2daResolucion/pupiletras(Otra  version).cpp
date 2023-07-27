#include <iostream>
#include <cmath>
#define MAXCOL 	10
#define MAXFIL	4
using namespace std;

//defino matriz global
//movimiento -> coordenada
int m[8][2];


void movimientos(){ //Movimientos de un rey//
	m[0][0] = -1; m[0][1] = -1;
	m[1][0] =  0; m[1][1] = -1;
	m[2][0] =  1; m[2][1] = -1;
	m[3][0] = -1; m[3][1] =  0;
	m[4][0] =  1; m[4][1] =  0;
	m[5][0] = -1; m[5][1] =  1;
	m[6][0] =  0; m[6][1] =  1;
	m[7][0] =  1; m[7][1] =  1;
	
}

int busca(char tabla[][MAXCOL],char word[],int fil, int col, int n,char resultado[][MAXCOL]){
	if(tabla[fil][col]!=word[0]) return 0; //no encuentra la primera letra de la palabra//
	int i,j,nfil,ncol,k,l,s;
	//hasta el nmr máx de movimientos//
	for(i=0;i<8;i++){
		nfil = fil + m[i][0];
		ncol = col + m[i][1];
		//buscamos la palabra,empieza en 1 pq ya recorri la primera letra//
		for(j=1;j<n;j++){
			
			if(nfil >= MAXFIL || nfil<0 || ncol>=MAXCOL || ncol<0) break;
			if(tabla[nfil][ncol]!=word[j]) break;
			//si es la letra, avanzo a la siguiente
			nfil = nfil + m[i][0];
			ncol = ncol + m[i][1];
			
		}
		//cuando ya llegó a la ultima letra//
		if(j==n){
			//OBSERVAR//
			for(k=0,l=0,s=0;s<n;k+=m[i][0],l+=m[i][1],s++){
					resultado[fil+k][col+l] = word[s];
			}
			return 1;
		}
	}
	//A veces da returns falsos, con valores que no son reales//
	return 0;
}

void buscarpalabras(char tabla[][MAXCOL],char word[],int n,char resultado[][MAXCOL]){
	int i,j;
	
	//2 for's, pq recorrerá fila y columna
	for(i=0;i<MAXFIL;i++){
		for(j=0;j<MAXCOL;j++){
			if(busca(tabla,word,i,j,n,resultado)){
				cout<<"Esta en la posicion: ("<<i<<","<<j<<")"<<endl;
			}
		}
	}
}
//OBSERVAR//
void imprime (char resultado[][MAXCOL]){
	for(int i=0;i<MAXFIL;i++){
		for(int j=0;j<MAXCOL;j++){
			cout<<resultado[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	
	char tabla[][MAXCOL] = {
	{ 'H','J','A','S','S' },
	{ 'S','G','G','O','L' },
	{ 'A','O','J','K','E' },
	{ 'J','L','D','G','G' }
	};
	
	char resultado[][MAXCOL]={
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
	
	//				   0   1   2	
	char palabra[] = {'G','O','L'};
	int n = 3;
	movimientos();
	buscarpalabras(tabla,palabra,n,resultado);	
	imprime(resultado);
	
	return 0;
}

