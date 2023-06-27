#include <bits/stdc++.h>
using namespace std;
const int INF=1e4;
int main(){
   int n,t,nsd,csd,overtake_cnt=0;
   vector<int>pre_sp;
   pre_sp.push_back(INF);
   cin>>n;
   int ans=0;
   while(n--){
    cin>>t;
    if(t==1||t==3){//change speed or speed limit
        cin>>nsd;
    }
    if(t==1){
        csd=nsd;
        while(pre_sp.size()&&pre_sp.back()<csd){
            pre_sp.pop_back();
            ++ans;
        }
    }
    if(t==3){//speed limit
       if(csd>nsd){
            ++ans;
       }else{
            pre_sp.push_back(nsd);
       }
    }
    if(t==2){//overtake other car
        ans+=overtake_cnt;
        overtake_cnt=0;
    }
    if(t==4){//allow overtakes
        overtake_cnt=0;
    }
    if(t==5){//no speed limit
        pre_sp.push_back(INF);
    }
    if(t==6){//no overtake
        overtake_cnt++;
    }   
   } 
   cout<<ans<<'\n';
}