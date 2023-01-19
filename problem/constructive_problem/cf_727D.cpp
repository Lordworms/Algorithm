#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node
{
    vector<string>a;
    int id;
};
void solve()
{
  unordered_map<int,string>mp;
  unordered_map<string,int>name;
  auto get_vec=[&](string s)
  {
    vector<string>vec;
    string res;
    for(int i=0;i<s.size();++i)
    {   
        if(s[i]==',')
        {
            vec.push_back(res);
            res="";
        }
        else res+=s[i];
    }
    vec.push_back(res);
    return vec;
  };
  mp[0]="S";name["S"]=0;
  mp[1]="M";name["M"]=1;
  mp[2]="L";name["L"]=2;
  mp[3]="XL";name["XL"]=3;
  mp[4]="XXL";name["XXL"]=4;
  mp[5]="XXXL";name["XXXL"]=5;
  vector<int>number(6);
  for(int i=0;i<6;++i)cin>>number[i];
  vector<node*>vec;
  int n;cin>>n;
  string s;
  for(int i=0;i<n;++i)
  {
    cin>>s;
    node* tmp=new node;
    tmp->a=get_vec(s);
    tmp->id=i;
    vec.push_back(tmp);

  }
  sort(vec.begin(),vec.end(),[&](node* a,node* b)
  {
    if(a->a.size()==b->a.size())
    {
        if(name[a->a[0]]==name[b->a[0]]&&a->a.size()>1&&b->a.size()>1)
        {
            return name[a->a[1]]<name[b->a[1]];
        }
        return name[a->a[0]]<name[b->a[0]];
    }
    return a->a.size()<b->a.size();
  });
  bool isvalid=true;
  vector<string>ans(n);
  for(int i=0;i<n;++i)
  {
    bool valid=false;
    for(auto& k:vec[i]->a)
    {
        if(number[name[k]])
        {
            number[name[k]]--;
            valid=true;
            ans[vec[i]->id]=k;
            break;
        }
    }
    if(!valid)
    {
        isvalid=false;
        break;
    }
  }
  cout<<(isvalid?"YES":"NO")<<'\n';
  if(!isvalid)return;
  for(auto& k:ans)
  {
    cout<<k<<'\n';
  }
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}