#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int armacombo(int arr[],int n,int k){
	
	int dp[n+1];
	
	dp[0]=0;
	
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1];
		if(arr[i]-arr[i-1]<k){
			if(i>=2)
				dp[i]=dp[i-2]+arr[i]+arr[i-1]; //por revisar
				//dp[i]=max(dp[i],dp[i-2]+arr[i]+arr[i-1]);
			else
				dp[i]=max(dp[i],arr[i]+arr[i-1]);
			
		}		
		
	}
	
	return dp[n-1];
}


int main(){
	int arr[]={3,4,6,12,15,18,25};
	int n=7,k=5;
	
	cout << armacombo(arr,n,k);
	
	return 0;
	
}
