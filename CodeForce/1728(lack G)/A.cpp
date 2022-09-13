#include <bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int T,n;
struct node{int v,c;};
node arr[MAXN];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>T;
  int x;
  while(T--)
  {
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;++i)cin>>x,arr.push_back(x);
    cout<<std::max_element(arr.begin(),arr.end())-arr.begin()+1<<endl;
  }
  return 0;
}