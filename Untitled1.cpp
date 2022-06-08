#include<iostream>
#include<string.h>
#include<map>
using namespace std;
int main(){
   int m,n;cin>>m>>n;
   map<string,int>hay;
   while(m--){
      string s;int p;
      cin>>s>>p;
      hay[s]=p;
   }
   while(n--){
      int ans=0;
      cin>>s;
      //while(cin>>s,s!=".") ans+=hay[s];
      cout<<ans<<endl;
   }
}
