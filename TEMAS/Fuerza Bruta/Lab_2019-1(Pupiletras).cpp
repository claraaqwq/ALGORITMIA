#include <iostream>
#include <cmath>
#define MAXCOL 5
#define MAXFIL 5
using namespace std;

int m[8][2];

void movimientos(){
	m[0][0]=-1;m[0][1]= 0;
	m[1][0]=-1;m[1][1]= 1;
	m[2][0]= 0;m[2][1]= 1;
	m[3][0]= 1;m[3][1]= 1;
	m[4][0]= 1;m[4][1]= 0;
	m[5][0]= 1;m[5][1]=-1;
	m[6][0]= 0;m[6][1]=-1;
	m[7][0]=-1;m[7][1]=-1;
}

int buscar(char palabra[],char tabla[][MAXCOL],char resultado[][MAXCOL],int n,int fil,int col){
	if(palabra[0]!=tabla[fil][col])return 0;
	
	int i,j,nfil,ncol,x,y,s,flag=0;
	//hasta el numero de movimientos que podemos realizar//
	for(i=0;i<8;i++){
		//busco la primera letra
		nfil = fil + m[i][0]; //para x
		ncol = col + m[i][1]; //para y
		
		//hasta que no llegue a los bordes del tablero
		if(nfil<0 || nfil>=MAXFIL || ncol<0 || ncol>=MAXCOL){
			continue;
		}else{
			//para la siguiente letra//
			for(j=1;j<n;j++){
				//si no encuentro la letra//
				if(palabra[j]!=tabla[nfil][ncol]){
					break;
				}
				//si es la letra, avanzo a la siguiente//
				nfil = nfil + m[i][0]; //para x
				ncol = ncol + m[i][1]; //para y
			}	
			//para comprobar que llegó a la ultima letra//
			if(j==n){
				for(x=0,y=0,s=0;s<n;x+=m[i][0],y+=m[i][1],s++){
					resultado[fil+x][col+y] = palabra[s];
				}
				flag = 1;
			}
		}
	}
	if(flag==1) return 1;
	return 0;
}

void buscarpalabras(char tabla[][MAXCOL],char palabra[],char resultado[][MAXCOL],int n){
	//un for para filas y otro para columnas//
	for(int fil=0;fil<MAXFIL;fil++){
		for(int col=0;col<MAXCOL;col++){
			if(buscar(palabra,tabla,resultado,n,fil,col)==1){
				cout<<"La palabra está en: ("<<fil<<","<<col<<")"<<endl;
			}
		}
	}
}

void imprime(char resultado[][MAXCOL]){
	int fil,col;
	for(fil=0;fil<MAXFIL;fil++){
		for(col=0;col<MAXCOL;col++){
			cout<<resultado[fil][col]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n=4; //la cantidad de letras en la palabra a buscar
	
	char tabla[][MAXCOL]={
	{'B','A','L','I','C'},
	{'N','B','I','C','A'},
	{'T','I','I','A','L'},
	{'P','C','P','C','M'},
	{'R','O','B','O','A'}
	};
	
	char resultado[][MAXCOL] = {
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
	
				//     0   1   2   3
	char palabra[] = {'B','I','C','A'}; 
	
	movimientos();
	buscarpalabras(tabla,palabra,resultado,n);
	imprime(resultado);
	
	return 0;
}


