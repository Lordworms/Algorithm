#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct LB
{
   vector<ll>p;
   int base;
   LB(int base)
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
   friend inline LB operator + (const LB& a,const LB& b)
   {
        LB c(a.base);
        for(int i=0;i<b.base;++i)c.p[i]=a.p[i];
        for(int i=0;i<b.base;++i)c.insert(b.p[i]);
        return c;
   }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}