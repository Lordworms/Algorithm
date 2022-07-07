/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
vector<int>getSa(string s)//计数排序，时间复杂度为nlog(m)
{
   int lim=130;//对应的位数，'z'的值为122，所以这里设置成130，保险起见
   int n=s.size();
   vector<int>sa(n+1,0),rk(n+1,0),pos(n+1,0),tmp(n+1,0);//pos数组表示当前第二关键字已经排好序的时候第i名第二关键字所对应的第一关键字位置
   vector<int>cnt(lim,0);//cnt为基数排序的桶，由于对于单个字符来说'z'的排名为122，保险起见设置成130
   //检查两个字符串是否前后两部分都相等
   auto check=[&](int x,int y,int k){return tmp[x]==tmp[y]&&tmp[x+k]==tmp[y+k];};
   int i,k;
   //对单个字符进行排名
   for(i=1;i<=n;++i)rk[i]=s[i-1],cnt[rk[i]]++;//rk[i]此时对单个字符进行排名，随后对应的桶++
   for(i=1;i<=lim;++i)cnt[i]+=cnt[i-1];//我们累加对应的cnt
   for(i=n;i>=1;--i)sa[cnt[rk[i]]--]=i;//计数排序，排出长度为1的字符的排名
   for(k=1;k<n;k<<=1)//现在开始弄长度为[2,n]的后缀
   {
        int len=0;for(i=n-k+1;i<=n;++i)pos[++len]=i;//如果第二关键字为0的话，确定最小，所以先加入pos,从n-k+1位置开始，这些第二关键字都为0，所以分别为第0.。。len名
        for(i=1;i<=n;++i)if(sa[i]>k)pos[++len]=sa[i]-k;//对应的前一位置的位置
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>sa=getSa()
  return 0;
}