#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct LB
{
   vector<ll>p;
   int base;
   LB(int base=64)
   {
        p.resize(base);
        this->base=base;
   }   
   inline bool insert(ll x)
   {
        for(int i=base-1;i>=0;--i)
        {
            if(!(x>>i))continue;
            if(!p[i])
            {
                p[i]=x;
                break;
            }
            x^=p[i];
        }
        return x==0;
   }
   inline ll query(int x=0)
   {
        unsigned long long ans=0;
        for(int i=base-1;i>=0;--i)
        {
            ans=max(ans,ans^p[i]);
        }
        return ans;
   }
   void merge(const LB& aa)
   {
        for(int i=base-1;i>=0;--i)
        {
            if(aa.p[i])
            {
                insert(aa.p[i]);
            }
        }
   }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}