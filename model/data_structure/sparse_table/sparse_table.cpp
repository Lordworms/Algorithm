/*
    本次介绍st表，st表用于解决静态查找区间最值的问题，也就是不需要维护这个数据结构（比如线段树和树状数组）建立st表的复杂度为O(nlogn)，查询复杂度为O(n)
    查询的时候，首先需要明白一点，设区间长度为len,则我们有2^log(len/2)>=len/2;
    log2(x)表示小于等于a的最大的2的几次方
    t=r-l+1;
    所以我们查询的时候呢，就直接比较func(st[l][lg[t]],st[r-(1<<lg[t])][lg[t]])即可，因为2^lg(t)永远不可能超过t
    注意第二层循环的时候i+(1<<j)<=n  (小于等于很关键)
    再就是查询的时候，注意一点，注意是func(st[][])
    这里以max为例
*/
#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
vector<vector<int>>st;
vector<int>lg;
int query(int l,int r)
{
    return max(st[l][lg[r-l+1]],st[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);//不是区间对半分，是一人一个
}
void init_lg()
{
    lg.resize(arr.size()+1);
    lg[0]=lg[1]=0;
    for(int i=2;i<=arr.size();++i)lg[i]=lg[i/2]+1;
}
void init_st()
{
    st=vector<vector<int>>(arr.size()+1,vector<int>(lg[arr.size()]+1));
    for(int i=0;i<arr.size();++i)st[i][0]=arr[i];
    for(int j=1;j<=lg[arr.size()];++j)
    {
        for(int i=0;i+(1<<j)<=arr.size();++i)
        {
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}