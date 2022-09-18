#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=150000 + 10,M=310;
ll a[M],b[M],t[M];
int n,m,d;
ll dp[2][N];
int q[N];
int h,ta;
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        unordered_map<string,int>mp;
        for(string s:words)
        {
            string k;
            for(int i=0;i<s.size();++i)
            {
                k+=s[i];
                mp[k]++;
            }
        }
        for(string s:words)
        {
            string k;
            int now=0;
            for(int i=0;i<s.size();++i)
            {
                k+=s[i];
                if(mp[k]>0)now+=mp[k]-1;
            }
            ans.push_back(now);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<string>arr={"abc","ab","bc","b"};
  sol.sumPrefixScores(arr);
  return 0;
}