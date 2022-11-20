/*
  it is obviouly that we cannot check every number one by one
  so that we can use a universal way to check which is (r-l+1)%k==0
*/
#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
using ll=long long;
const int MAXN=3e5+5;
const int MAXQ=3e5+5;
const int T=50;
int cnt=0;
unordered_map<int,int>idMap;
int arr[MAXN];
bitset<MAXN+MAXQ>randomBits[T];
int n,q;
struct fenwick
{
	int PartialSum[MAXN];
	fenwick()
	{
		for(int i = 0; i < MAXN; i++)PartialSum[i] = 0;
	}
	inline void add(int index, bool increase)
	{
		while(index < MAXN)
		{
			PartialSum[index] += (increase? 1 : -1);
			index += index&-index;
		}
	}
	inline int get(int index)
	{
		int sum = 0;
		while(index)
		{
			sum += PartialSum[index];
			index -= index&-index;
		}
		return sum;
	}
}TREE[T]; 
inline int getId(int x)
{
    auto it=idMap.find(x);
    if(it==idMap.end())
    {
        return idMap[x]=cnt++;
    }
    else return (*it).second;
}
inline void query()
{
    int type,l,r,k,index,x;
    for(int i=0;i<q;++i)
    {
        cin>>type;
        if(type==1)
        {
            cin>>index>>x;
            --index;
            int preIndex=getId(arr[index]);
            int newIndex=getId(x);
            arr[index]=x;
            for(int i=0;i<T;++i)
            {
                if(randomBits[i][preIndex])TREE[i].add(index+1,false);
                if(randomBits[i][newIndex])TREE[i].add(index+1,true);
            }
        }
        if(type==2) 
        {
            cin>>l>>r>>k;
            --l;
            if(k==1)
            {
                cout<<"YES"<<"\n";
            }
            else if((r-l)%k!=0)
            {
                cout<<"NO"<<"\n";
            }
            else
            {
                bool isFalse=true;
                for(int i=0;i<T;++i)
                {
                    if((TREE[i].get(r)-TREE[i].get(l))%k!=0)
                    {
                        isFalse=false;
                        break;
                    }
                }
                cout<<(isFalse?"YES":"NO")<<"\n";
            }
        }
    }
}
inline void solve()
{
    cin>>n>>q;
    for(int i=0;i<T;++i)
    {
        for(int j=0;j<(MAXN+MAXQ);++j)
        {
            if(rnd()&1)
            {
                randomBits[i].set(j);
            }
        }
    }
    for(int i=0;i<n;++i)cin>>arr[i];
    for(int i=0;i<n;++i)
    {
        int id=getId(arr[i]);
        for(int j=0;j<T;++j)
        {
            if(randomBits[j][id])
            {
                TREE[j].add(i+1,true);//TREE contains the index 
            }
        }
    }
    query();
}   
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  solve();
  return 0;
}