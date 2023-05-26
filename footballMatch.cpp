#include<bits/stdc++.h>
using namespace std;

int countGoalWays(int a, int b){
	if(a==0|| b==0){
		return 1;
	}
	else{
		return countGoalWays(a-1, b) + countGoalWays(a, b-1);
	}
}

int main(){
	int n;
	
	do{
		cin>>n;
	}while(n<=0|| n>100);
	
	int** inputArr = new int* [n];
	
	for(int i =0; i<n; i++){
		inputArr[i] = new int [2];
		
		do{
			cin>>inputArr[i][0]>>inputArr[i][1];
		}
		while(inputArr[i][0]<0||inputArr[i][0]>10||inputArr[i][1]>10||inputArr[i][1]<0);
	}
	
	for(int i =0; i<n; i++){
		cout<<countGoalWays(inputArr[i][0], inputArr[i][1])<<endl;
	}
	
	for(int i=0; i<n; i++){
		delete [] inputArr[i];
	}
	delete [] inputArr;
	
	return 0;
}
