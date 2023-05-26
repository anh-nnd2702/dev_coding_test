#include<bits/stdc++.h>
using namespace std;

int minGoldUsed(int m, int d, int k, int c){
	if ((d==k && m>1)||(d<k)) {
		return -1;
	}
	else if((d==k && m==1)||k==0||m==0||c==0){
		return 0;
	}
	else{
		int maxKill, repairCnt, maxLastKill;
		
		if(d%k == 0){
			maxKill = (d/k) -1;
			maxLastKill = d/k;
		}
		else{
			maxKill = (d/k);
			maxLastKill = d%k;
		}
				
		if((m-maxLastKill)%maxKill == 0){
			repairCnt = ((m-maxLastKill)/maxKill);
		}
		else{
			repairCnt = ((m-maxLastKill)/maxKill)+1;
		}
		
		return (repairCnt*c);
	}
}


int main(){
	int m, d, c, k;
	do{
		cin>>m>>d>>k>>c;
	}
	while(m<0||m>1000||k<0||k>1000||c<0||c>1000||d<=0||d>1000);
	
	cout<<minGoldUsed(m, d, k, c);

	return 0;
}
