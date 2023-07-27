#include <iostream> 
#define MAX_MOV 8
#define N 10
#define M 10

int cont=0;
int mov[MAX_MOV][2];

using namespace std;

void generarpos(){
	mov[0][0] = 1;	mov[0][1] = 0;  
	mov[1][0] = 1;	mov[1][1] = 1;
	mov[2][0] = 0;	mov[2][1] = 1;
	mov[3][0] = -1;	mov[3][1] = 0;
	
	mov[4][0] = 0;	mov[4][1] = -1;
	mov[5][0] = -1;	mov[5][1] = -1;
	mov[6][0] = 1;	mov[6][1] = -1;
	mov[7][0] = -1;	mov[7][1] = 1;
}
void inicializa(char tabla[N][M],int n,int m){
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			tabla[i][j]='0';
	
}
void print(char a[N][M], int n,int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%c ", a[i][j]);
        printf("\n");
    }
}
int validar(char tabla[N][M],int x,int y,int n,int m){
	if(x<n && y<m && x>=0 && y>=0 && tabla[x][y]=='0')
		return 1;
	return 0;	
}

void descubreminas(char tabla[N][M],int n,int m,int x,int y,
	char solu[N][M]){
		int nx,ny;
		
	for(int i=0;i<MAX_MOV;i++){
		nx = x + mov[i][0];
		ny = y + mov[i][1];		
		if(validar(solu,nx,ny,n,m) 
			&& tabla[nx][ny]=='*') solu[nx][ny]='*';
	}	

}
void cargaminas(char a[N][M]){
        a[0][4]='*';
        a[2][2]='*';
	a[4][1]='*';
	a[4][2]='*';
	a[4][4]='*';
	a[5][1]='*';
	a[5][2]='*';
	a[5][4]='*';	
	a[6][1]='*';
        a[6][3]='*';
	a[7][0]='*';	
	a[7][1]='*';
        a[7][2]='*';
        a[7][3]='*';
	
}

int caminarobot(char tabla[N][M],char solu[N][M],
	int n,int m,int x,int y,char letra){
	int nx,ny;
	if(cont==20) return 1;
	if(x==n-1 && y==m-1){
		print(solu,n,m);
		cont++;
		cout << endl;
		return 0;
	}
	
	descubreminas(tabla,n,m,x,y,solu);
	for(int i=0;i<MAX_MOV;i++){
		nx = x + mov[i][0];
		ny = y + mov[i][1];			
		
		if(validar(solu,nx,ny,n,m)){
			solu[nx][ny] = letra+1;
			if(caminarobot(tabla,solu,n,m,nx,ny,letra+1))
				return 1;
			solu[nx][ny]='0';	
		}
	}
	return 0;
}


int main(){
	int n=9,m=5;
	char letra='A';
	char tabla[N][M];
	char solu[N][M];
	generarpos();
	inicializa(tabla,n,m);	
	inicializa(solu,n,m);
	cargaminas(tabla);
	solu[0][0]=letra;
	caminarobot(tabla,solu,n,m,0,0,letra);
	
	return 0;
}

