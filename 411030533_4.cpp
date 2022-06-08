#include<bits/stdc++.h>
using namespace std;

int main() {
    int i=-1,j,a=-1,b=-1;
	int arr[60010];	
	while(scanf("%d",&a)!=EOF){
      while(1){
		  cin>>arr[j];
			if(getchar()=='\n')
			break;
		}
		b=arr[0]*j;
		
    for(i=1;i<j;i++){
		   b=b*a+arr[i]*(j-i);
		} 
    cout<<b<<endl;
	}
	return 0;
}