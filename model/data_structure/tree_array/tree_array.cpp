/*
    树状数组的思想：用一个辅助数组tree，tree中每个下标的末尾0的数量设为k，那么每个下标管辖的数字数量就是2^k然后不断求和即可
    对于更新操作，对于末尾含有k个0的数字来说，它需要管辖2^k个数字，所以更新的时候操作sum的时候需要从下往上进行操作，每次加上lowbit
    而取sum的时候，我们反其道而行之，就每次减去lowbit
    树状数组求逆序对:我们是怎么做的呢，我们先创建一个离散化数组d，然后根据原arr的大小对该离散化数组进行倒序排序
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
class Solution {
public:
    vector<int>discrete(vector<int>nums)
    {
        vector<int>b(nums);
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(int i=0;i<nums.size();++i)
            nums[i]=lower_bound(b.begin(),b.end(),nums[i])-b.begin()+1;
        return nums;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>tree(n+1,0);
        auto lowbit=[&](int x){return x&-x;};
        auto add=[&](int x,int v){while(x<=n){tree[x]+=v,x+=lowbit(x);}};
        auto sum=[&](int x){int ans=0;while(x){ans+=tree[x],x-=lowbit(x);}return ans;};
        nums=discrete(nums);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=sum(n)-sum(nums[i]);//计算逆序对
            add(nums[i],1);
        }
        return ans;
    }
};
int c[MAXN],a[MAXN];
int n;
//获得x末尾有多少个0
int lowbit(int x)
{
    return x&-x;
}
int getSum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x,int value)
{
    a[x]+=value;
    while(x<=n)
    {
        c[x]+=value;
        x+=lowbit(x);
    }
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
    int x,v,T;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    
   return 0;
}
