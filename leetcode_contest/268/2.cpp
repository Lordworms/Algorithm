#include <bits/stdc++.h>
using namespace std;
 
int minimumRounds(vector<int>& tasks) {
    unordered_map<int,int>count;
    for(int num:tasks)
    {
        count[num]++;
    }        
    int round=0;
    for(auto k:count)
    {
       
        if(k.second==1)return -1;
        if(k.second%3==0){round+=k.second/3;k.second=0;}
        else
        {
            if((k.second%3)%2)
            {
                if(k.second-3*(k.second/3-1)%2)
                {
                    round+=(k.second/3-1);
                    round+=2;
                    k.second=0;
                }
            }
            else
            {
                round+=k.second/3;
                round+=1;
                k.second=0;
            }
        }
        if(k.second)
        {
            return -1;
        }
    }
    return round;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   vector<int>test={2,2,3,3,2,4,4,4,4,4};
   cout<<minimumRounds(test);
   return 0;
}
