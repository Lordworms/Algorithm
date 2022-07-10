/*
    什么是后缀数组呢，首先清楚两个概念，第一个是在这里讨论的所有字符串下标都以1开头，另一个是后缀i表示以第i个char开头的后缀
    其中有两个数组，分别为 sa和rk，其中sa[i]表示将所有后缀排序后第i小的序号，rk[i]表示后缀i的排名
    我们有三个问题
    1.后缀数组sa怎么求
        1.倍增方法，代码在下面，首先我们对每一个字符进行排名，之后我们进行倍增，从2^k-1 转移到2^k的长度，每次转移的时候，我们重新对sa数组
        排序即可
        2.倍增+基数排序的方式
    2.光有一个sa，是完全不够的，还需要一个height数组，height数组维护的是相邻(i-1,i)rank的两个后缀的最长公共前缀
        怎么求呢？：我们按照原串的顺序从前往后求，每次求i开头的后缀以及sa[rk[i]-1]开头的后缀，这表示排名第rk[i]和排名第rk[i-1]的后缀
        假设目前已经求出h[rk[i]]=h,sa[rk[i]]=k
        那么有两种情况：
            1.h!=0 此时从后缀的开头继续向后找
            2.h!=0 下次求i+1和k+1 这两个后缀的长度至少为h-1（去掉第i和第k位）
        我们需要一个引理：h[rk[i]]>=h[rk[i-1]]-1 证明这个引理还需要另一个引理 lcp(i,j)=min(lcp[k],rk[i]<=k<=rk[j])（这是很显然的，因为lcp(i,j)=min(lcp(i,i+1),lcp(i+1,i+2),lcp[j-1,j])）
            证明如下：（看这个链接的证明https://zhuanlan.zhihu.com/p/346305506）
                另sa[i-1]=aAD,另sa[rk[i-1]-1]=aAB,按照后缀数组的定义，D的字典序小于B的字典序,len(a)=h[i-1]-1;
                那么sa[i]=AD sa[rk[i-1]-1]+1=AB
                又根据上面的引理lcp(i,sa[rk[i-1]-1]+1)=A=height[i-1]-1<=h[i]
                那么得证
        看这个网址就行了https://blog.csdn.net/zjllll123/article/details/107369473

*/
#include <bits/stdc++.h>
using namespace std;
vector<int>getSa(string s)
{
    int n=s.size(),m=130;//
    vector<int>sa(n+1,0),rk(n+1,0),pos(n+1,0),cnt(m,0);
    auto base_sort=[&](){
        fill(cnt.begin(),cnt.begin()+m+1,0);
        for(int i=1;i<=n;++i)cnt[rk[i]]++;
        for(int i=2;i<m;++i)cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;--i)sa[cnt[rk[pos[i]]]--]=pos[i];//此时第一位的次序依旧不变，此时还是用的前一次的rank，
        //不同的是pos[i]的改变，对于rk[pos[i]]==rk[pos[j]]来说，如果你i<j，那么你的会慢一点遍历到，对应的sa值也就会小
    };
    auto check=[&](int x,int y,int k){
         if(pos[x]!=pos[y])
         {
            return false;
         }
         int r1=x+k>n?-1:pos[x+k];
         int r2=y+k>n?-1:pos[y+k];
         return r1==r2;
    };
    for(int i=1;i<=n;++i)rk[i]=s[i-1],pos[i]=i;
    base_sort();
    for(int k=1;k<=n;k<<=1)
    {
        int rank=0;for(int i=n-k+1;i<=n;++i)pos[++rank]=i;
        for(int i=1;i<=n;++i)if(sa[i]>k)pos[++rank]=sa[i]-k;
        base_sort();
        swap(rk,pos);
        rank=1;rk[sa[1]]=rank;
        //这个时候的pos数组是rk
        for(int i=2;i<=n;++i){if(!check(sa[i],sa[i-1],k))++rank;rk[sa[i]]=rank;}
        if(rank==n)break;//完全排好序了
        m=rank;
    }
    return sa;
}
//获得height数组
vector<int>getLcp(string s)
{
    int n=s.size();
    vector<int>sa=getSa(s);
    vector<int>rk(n+1,0);
    vector<int>lcp(n+1,0);
    for(int i=1;i<=n;++i)rk[sa[i]]=i;
    int h=0;
    lcp[1]=0;
    for(int i=1;i<=n;++i)
    {
        int k=sa[rk[i]-1];
        if(h>0)--h;
        for(;k+h<=n&&i+h<=n;++h)
        {
            if(s[i+h-1]!=s[k+h-1])break;
        }
        lcp[rk[i]]=h;
    }
    return lcp;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>ans=getSa("abab");
  for(auto& i:ans)cout<<i<<" ";
  return 0;
}
/*
    直接便携式用：
        vector<int>rk(n+1,0),sa(n+1,0),pos(n+1,0),cnt(m,0),lcp(n+1,0);;
        auto base_sort=[&](){
            fill(cnt.begin(),cnt.end(),0);
            for(int i=1;i<=n;++i)cnt[rk[i]]++;
            for(int i=2;i<m;++i)cnt[i]+=cnt[i-1];
            for(int i=n;i>=1;--i)sa[cnt[rk[pos[i]]]--]=pos[i];
        };
        auto getSa=[&](){
            auto check=[&](int x,int y,int k){
                if(pos[x]!=pos[y])
                {
                    return false;
                }
                int r1=x+k>n?-1:pos[x+k];
                int r2=y+k>n?-1:pos[y+k];
                return r1==r2;
            };
            for(int i=1;i<=n;++i)pos[i]=i,rk[i]=s[i-1];
            base_sort();
            for(int k=1;k<=n;k<<=1)
            {
                int rank=0;for(int i=n-k+1;i<=n;++i)pos[++rank]=i;
                for(int i=1;i<=n;++i)if(sa[i]>k)pos[++rank]=sa[i]-k;
                base_sort();
                swap(rk,pos);
                rk[sa[1]]=rank=1;
                for(int i=2;i<=n;++i){if(!check(sa[i],sa[i-1],k))++rank;rk[sa[i]]=rank;}
                if(rank==n)break;
                m=rank;
            }
        };
        auto getHeight=[&]()
        {
            getSa();
            int h=0;
            lcp[rk[1]]=0;
            for(int i=1;i<=n;++i)
            {
                int k=sa[rk[i]-1];//sa[i-1]的开始位置
                if(!k)continue;
                if(h)--h;
                for(;k+h<=n&&i+h<=n;++h)if(s[k+h-1]!=s[i+h-1])break;
                lcp[rk[i]]=h;
            }
        };

*/