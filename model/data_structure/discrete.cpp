/*
    这个文件涵盖所有的离散化方法，离散化就是把数据的范围下压
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> discrete(vector<int>a) {
    vector<int>b(a);//复制一份
    sort(b.begin(),b.end());//排序，等待去重
    b.erase(unique(b.begin(),b.end()),b.end());//去重
    for(int i=0;i<a.size();++i)
    {
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    }
    return a;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>arr={1,5000,2,400,400,30,30};
  vector<int>d=discrete(arr);
  return 0;
}