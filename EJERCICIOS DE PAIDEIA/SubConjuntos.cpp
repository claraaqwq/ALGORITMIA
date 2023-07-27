#include <iostream>

using namespace std;

int buscaiguales(int arr[],int n){
	int sum=0;
	
	for(int i=0;i<n;i++) 
		sum = sum + arr[i];
	
	int dp[n+1][sum+1];
	
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=sum;i++) dp[0][i]=0; 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++){
			dp[i][j] = dp[i-1][j];
			if(arr[i-1]<=j && dp[i][j]==0)	
				dp[i][j]=dp[i-1][j-arr[i-1]];
		}
	for(int i=0;i<=n;i++){
		cout << endl;
		for(int j=0;j<=sum;j++)	
			cout << dp[i][j] <<" ";	
	} // solo para ver lo que se esta haciendo
	int dif=99999;
	for(int j=sum/2;j>=0;j--){
		if(dp[n][j]==1){
			dif=sum-2*j;
			if(dif==0)return 1;
			return 0; 
		}
	}
}

int main(){ 
	int arr[]={1,5,5,11};
	//No se olviden de ordenar el arreglo
	int n=4;
	
	cout << endl << "Son iguales?:" << buscaiguales(arr,n);
	
	return 0;
	
}
