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

*/
#include <bits/stdc++.h>
using namespace std;
//获得sa数组
vector<int>getSa_increase(string s)
{
    int n=s.size();
    vector<int>sa(n+1,0),rk(n+1,0);
    for(int i=1;i<=n;++i)sa[i]=i,rk[i]=s[i-1];
    int k=0;
    auto cmp=[&](int i,int j){
        if(rk[i]!=rk[j])
        {
            return rk[i]<rk[j];
        }
        int ri=(i+k<=n?rk[i+k]:-1);
        int rj=(j+k<=n?rk[j+k]:-1);
        return ri<rj;
    };
    vector<int>rk2(n+1,0);
    for(k=1;k<=n;k<<=1)
    {
        sort(sa.begin()+1,sa.begin()+n+1,cmp);
        rk2[sa[1]]=1;
        for(int i=2;i<=n;++i)
        {
            rk2[sa[i]]=rk2[sa[i-1]]+cmp(sa[i-1],sa[i]);;
        }
        for(int i=1;i<=n;++i)rk[i]=rk2[i];
    }
    return sa;
}
/*
    rank[i]表示编号为i的排名 
    sa[i]表示排名为i的编号 
    cnt[i]计数排序的桶 
    pos[i]表示当前第二关键字已经排好序时第i名第二关键字所对应的第一关键字位置
    tmp[i]
    排序时：表示当前排序中编号为i的排名
    排序后：表示调整rank前的排名
*/
vector<int>getSa(string s)//计数排序，时间复杂度为nlog(m)
{
   int lim=130;//对应的位数，'z'的值为122，所以这里设置成130，保险起见
   int n=s.size();
   vector<int>sa(n+1,0),rk(n+1,0),pos(n+1,0),tmp(n+1,0);//pos数组表示当前第二关键字已经排好序的时候第i名第二关键字所对应的第一关键字位置
   vector<int>cnt(lim,0);//cnt为基数排序的桶，由于对于单个字符来说'z'的排名为122，保险起见设置成130
   auto check=[&](int x,int y,int k){return tmp[x]==tmp[y]&&tmp[x+k]==tmp[y+k];};
   int i,k;
   for(i=1;i<=n;++i)rk[i]=s[i-1],cnt[rk[i]]++;//rk[i]此时对单个字符进行排名，随后对应的桶++
   for(i=1;i<=lim;++i)cnt[i]+=cnt[i-1];//我们累加对应的cnt
   for(i=n;i>=1;--i)sa[cnt[rk[i]]--]=i;//计数排序，排出长度为1的字符的排名
   for(k=1;k<n;k<<=1)//现在开始弄长度为[2,n]的后缀
   {
        int len=0;for(i=n-k+1;i<=n;++i)pos[++len]=i;//如果第二关键字为0的话，确定最小，所以先加入pos,从n-k+1位置开始，这些第二关键字都为0，所以分别为第0.。。len名
        for(i=1;i<=n;++i)if(sa[i]>k)pos[++len]=sa[i]-k;//对应的前一位置的排名
        fill(cnt.begin(),cnt.end(),0);//重置一下cnt数组
        for(i=1;i<=n;++i)tmp[i]=rk[pos[i]],cnt[tmp[i]]++;//tmp保存上一个位置的排名，cnt保存上一位
        for(i=1;i<=lim;++i)cnt[i]+=cnt[i-1];
        for(i=n;i>=1;--i)sa[cnt[tmp[i]]--]=pos[i];
        for(i=1;i<=n;++i)tmp[i]=rk[i];
        len=1,rk[sa[1]]=1;
        for(i=2;i<=n;++i){if(!check(sa[i],sa[i-1],k))++len;rk[sa[i]]=len;}
        if(len==n)break;lim=len;

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