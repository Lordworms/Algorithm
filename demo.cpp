#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
mt19937 rnd(time(0));
 
const int N = 300'000 + 5; 
const int Q = 300'000 + 5; 
const int T = 50;
bitset<N+Q> RandomSet[T];
unordered_map<int, int> id; int cnt_id = 0;
int n, q, A[N];
 
struct fenwick
{
	int PartialSum[N];
	fenwick()
	{
		for(int i = 0; i < N; i++)PartialSum[i] = 0;
	}
	inline void add(int index, bool increase)
	{
		while(index < N)
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
}Fen[T];
 
inline int GetId(const int x)
{
	auto id_iterator = id.find(x);
	if(id_iterator == id.end())
	{
		return id[x] = cnt_id++;
	}
	else return (*id_iterator).second;
}
 
inline void ChooseRandomSets()
{
	for(int i = 0; i < T; i++)
	{
		for(int j = 0; j < N+Q; j++)
		{
			if(rnd()&1)RandomSet[i].set(j);
		}
	}
}
 
inline void AddArrayToFenwick()
{
	for(int i = 0; i < n; i++)
	{
		int MyId = GetId(A[i]);
		for(int j = 0; j < T; j++)
		{
			if(RandomSet[j][MyId])Fen[j].add(i+1, true);
		}
	}
}
	
inline void Query()
{
	int index, l, r, k, x, type;
	for(int i = 0; i < q; i++)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> index >> x;
			index --;
			int IdPre = GetId(A[index]);
			int IdNew = GetId(x);
			A[index] = x;
			for(int j = 0; j < T; j++)
			{
				if(RandomSet[j][IdPre])Fen[j].add(index+1, false);
				if(RandomSet[j][IdNew])Fen[j].add(index+1, true);
			}
		}
		if(type == 2)
		{
			cin >> l >> r >> k;
			l--;
			if(k == 1){cout << "YES\n"; continue;}
			else if((r-l)%k != 0){cout << "NO\n"; continue;}
			bool answer = true;
			for(int j = 0; j < T; j++)
			{
				if((Fen[j].get(r)-Fen[j].get(l))%k != 0){answer = false; break;}
			}
			cout << (answer?"YES":"NO") << '\n';
		}
	}
}
 
int main()
{
    ios::sync_with_stdio(false) , cin.tie(0);
    #ifdef LOCAL
    freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
    freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
    #endif
    ChooseRandomSets();
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> A[i];
    AddArrayToFenwick();
    Query();
    return 0;
}