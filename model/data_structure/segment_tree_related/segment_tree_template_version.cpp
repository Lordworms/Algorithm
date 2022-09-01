/*
    线段树可以在O(logn)的时间复杂度内实现单点修改、区间修改、区间查询（区间求和，求区间最大值，求区间最小值）等操作。
    segment_tree终极版子，可以适用于基本所有情况

*/
#include <bits/stdc++.h>
using namespace std;
int mod;
template<typename T>
class segmentTree{
    vector<T>tree,lazy;
    vector<T>arr;
    int n,root,n4,end;
    //build(0,n,1)
    void build(int l,int r,int c)
    {
        if(s==t)
        {
            tree[c]=arr[s];
            return;
        }
        int m=(l+r)>>1;
        build(l,m,c<<1);
        build(m+1,r,c<<1|1);
        tree[c]=tree[c<<1]+tree[c<<1|1];
    }
    void push_down(int cl,int cr,int c)//传递懒标记，懒标记的值已经作用过该层了，只需要往下传家就行惹
    {
        int cm=(cl+cr)>>1;    
        if(lazy[c]&&cl!=cr)
        {
            lazy[c<<1]+=lazy[c];
            lazy[c<<1|1]+=lazy[c];
            tree[c<<1]+=(cm-cl+1)*lazy[c];
            tree[c<<1|1]+=(cr-cm)*lazy[c];
            lazy[c]=0;
        }
    }
    void push_up(int c)//根据不同的需求进行更改
    {
        tree[c]=tree[c<<1]+tree[c<<1|1];
    }
    //求l-r的区间和
    T range_sum(int l,int r,int cl,int cr,int c)
    {
        if(l>cr||r<cl)return 0;//没有，直接干掉
        if(l<=cl&&r>=cr)
        {
            return tree[c];
        }
        int cm=(cl+cr)>>1;
        T sum=0;
        push_down(cl,cr,c);
        sum+=range_sum(l,r,cl,cm,c<<1);
        sum+=range_sum(l,r,cm+1,cr,c<<1|1);
        return sum;
    }
    //区间加和
    T range_add(int l,int r,int cl,int cr,int c,T val)
    {
        if(l>cr||r<cl)return 0;//没有，直接干掉
        if(l<=cl&&r>=cr)
        {
            lazy[c]+=val;
            tree[c]+=(cr-cl+1)*lazy[c];
            return;
        }
        int cm=(cr+cl)>>1;
        push_down(cl,cr,c);
        range_add(l,r,cl,cm,c<<1,val);
        range_add(l,r,cm+1,cr,c<<1|1,val);
        push_up(c);
    }
public:
    segmentTree(vector<T>arr)
    {
        for(auto i:arr)this->arr.push_back(i);
        n=arr.size();
        n4=4*n;
        end=n-1;
        root=1;
        build(0,end,1);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}