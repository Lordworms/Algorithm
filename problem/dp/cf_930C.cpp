#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int>dif(m+2);
  for(int i=0;i<n;++i){
    int l,r;
    cin>>l>>r;
    ++dif[l],--dif[r+1];
  }
  for(int i=1;i<=m;++i){
    dif[i]+=dif[i-1];
  }
  vector<int>seq(m+1);
  int len=0;
  vector<int>dp1(m+1),dp2(dp1);
  for(int i=1;i<=m;++i){
    if(dif[i]>=seq[len]){
      seq[++len]=dif[i];
    }else{
      int pos=upper_bound(seq.begin()+1,seq.begin()+len+1,dif[i])-seq.begin();
      seq[pos]=dif[i];
    }
    dp1[i]=len;
  }
  len=0;
  fill(seq.begin(),seq.end(),0);
  for(int i=m;i>=1;--i){
    if(dif[i]>=seq[len]){
      seq[++len]=dif[i];
    }else{
      int pos=upper_bound(seq.begin()+1,seq.begin()+len+1,dif[i])-seq.begin();
      seq[pos]=dif[i];
    }
    dp2[i]=len;
  }
  int ans=0;
  for(int i=1;i<=m;++i){
    ans=max(ans,dp1[i]+dp2[i]-1);
  }
  cout<<ans<<'\n';
}