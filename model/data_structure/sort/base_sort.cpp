/*
    基数排序，为了基数排序的求sa数组打基础
    就是各个位排个序然后每个位都拍好了就ok了
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> base_sort(vector<int>arr)
{
    auto get_count=[&](int x){int ans=0;while(x){x/=10,ans++;}return ans;};    
    int n=arr.size();
    vector<int>cnt(n,0);
    int maxlen=get_count(*max_element(arr.begin(),arr.end()));
    int base=1,num;
    for(int i=0;i<maxlen;++i)
    {
        vector<int>tmp(n);
        for(int j=0;j<n;++j)
        {
            num=(arr[j]/base)%10;
            cnt[num]++;
        }
        for(int i=1;i<n;++i)cnt[i]+=cnt[i-1];
        for(int k=n-1;k>=0;--k)
        {
            num=(arr[k]/base)%10;
            tmp[--cnt[num]]=arr[k];
        }
        arr=move(tmp);
        fill(cnt.begin(),cnt.end(),0);
        base*=10;
    }
    return arr;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>arr={102,3132,3443,13,431,3213,434,2};
  vector<int>ans=base_sort(arr);
  for(auto& i:ans)cout<<i<<" ";
  return 0;
}