#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int>a={0,1,0,3,2,3};
  int n=a.size();
  vector<int>d(n+1);
  d[0]=INT_MIN;
  int ans=0;
  for(int& num:a){
    if(num>d[ans]){
        d[++ans]=num;
    }
    int l=0,r=ans,pos=0;
    while(l<=r){
        int m=(l+r)>>1;
        if(d[m]<num){
            l=m+1;
            pos=m;//pay attention now ! important
        }else{
            r=m-1;
        }
    }
    d[pos+1]=num;
  }
  cout<<ans<<'\n';
  int k=0;
  return 0;
}